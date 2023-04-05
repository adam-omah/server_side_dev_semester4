<?php
$parentPage = "rentProperty.php";

// control variables, depending on which is true to code will generate different forms.
$townSearched = false;
$validPropertyRental = false;
$rentSucess = false;
$tenantAdded = false;
$failedToAddTenant = false;

// These are error message and more logic gates.
$datesNotAvailable = false;
$datesNotAvailableMessage = "";

// eircode of property selected:
$eircode = "";
$townSearch = "";

$daysOfRental = 0;
$rentalMonthPrice = 0;
$rentCost = 0;

$firstName ="";
$lastName ="";
$phone = "";
$email = "";

$tenantID = "";
$startDate = "";
$endDate = "";

$todaysDate = date("Y-m-d");

$validEircode = false;

$validTown = false;
$validFirstName = false;
$validLastName = false;
$validEircode = false;
$validPhone = false;
$validEmail =false;


$validTenantID = false;
$validStartDate = false;
$validEndDate = false;

$isValidEircode = "";
$isValidTown = "";

$isValidFirst = "";
$isValidLast = "";
$isValidPhone = "";
$isValidEmail ="";

$isValidTenantID = "";
$isValidStartDate = "";
$isValidEndDate = "";


// try connect to the database:
try {
  // try make a connection, to search for the owner.
  $pdo = new PDO('mysql:host=localhost;dbname=propertyrental; charset=utf8', 'root', '');
  $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch (PDOException $e) {

  $output = 'Database error: ' . $e->getMessage() . ' in ' . $e->getFile() . ':' . $e->getLine();
  echo $output;
  }


if ($_SERVER['REQUEST_METHOD'] === 'POST'){

  if (isset($_POST['newForm'])) {
    // Reset the Form and post data if starting new property.
    unset($_POST);
  }

  if (isset($_POST['findProperties'])) {
      validateTownSearch();
      validateStartDate();
      validateEndDate();
      // if all valid search forms are true
      if($validEndDate && $validStartDate && $validTown){
        $townSearched = true;
      }
  }


  // if Property is selected
  if(isset($_POST['selectProperty'])){
    validatePropertySelected();
    validateStartDate();
    validateEndDate();

    // used for testing.
    //echo "Valid start = $validStartDate, valid End = $validEndDate, valid eircode = $validEircode, eircode = $eircode";
    if ( $validStartDate && $validEndDate && $validEircode) {
      validatePropertyToRent();
    }
  }


  if(isset($_POST['rentProperty'])){

    //validate tenant values:
    validateFirstName();
    validateLastName();
    validatePhone();
    validateEmail();

    //add tenant to the Database
    if($validFirstName && $validLastName && $validPhone && $validEmail){
      // add to Tenants
      try{

        $sql = "INSERT INTO Tenants (firstName,lastName,phone,email,status) VALUES(:fname, :lname,:phn, :eml, :stat)";
        $stmt = $pdo->prepare($sql);

        $stmt->bindValue(':fname', $firstName);
        $stmt->bindValue(':lname', $lastName);
        $stmt->bindValue(':phn', $phone);
        $stmt->bindValue(':eml', $email);
        $stmt->bindValue(':stat', 'A');
        $stmt->execute();
        $tenantAdded = true;
        $last_id = $pdo->lastInsertId();
        // since adding the tenant is true, this tenant id is true.
        $tenantID = $last_id;
        $validTenantID = true;
        $isValidTenantID = "is-valid;";

      }
      catch (PDOException $e) {
        echo "An error has occured, Tenant not added";
        echo "Values were : $firstName, $lastName, $phone, $email";
      }
    }else{
      //Tenant was not added, go back to the property selected page.
      //validate eircode still correct:
      validateEircode();
      validateStartDate();
      validateEndDate();

      if ( $validStartDate && $validEndDate && $validEircode) {
        validatePropertyToRent();
        // if the above checks out go back to rental form, otherwise user will have to start agian.
        $failedToAddTenant = true;

        }
    }

    if ($tenantAdded) {
      //validate eircode still correct:

      validateEircode();
      validateStartDate();
      validateEndDate();

      if ( $validStartDate && $validEndDate && $validEircode) {
        validatePropertyToRent();
      }

      if ($validPropertyRental) {
        // valid rental details, in theory, unless eircode was changed by malicious behaviour.
        // if so then we need to check if it is still avialble for those dates:
        try{
          // retrieve all rentals that are active with this eircode:
          $sql = "SELECT * FROM rentals where eircode = '$eircode' and status = 'A'";
          $result = $pdo->query($sql);
          if ($result->rowCount() == 0) {
            // no rentals are found, go ahead and rent the property
            // nothing to do here just continue on.
          }else{
          while ($row = $result->fetch()) {
          $rentID = $row['rentID'];
          $rentalFoundStart = $row['startDate'];
          $rentalFoundEnd = $row['endDate'];
          // now set this to date:
          $rentalFoundStartFormatted = date("Y-m-d",strtotime($rentalFoundStart));
          $rentalFoundEndFormatted = date("Y-m-d",strtotime($rentalFoundEnd));
          // check if new date hits any already rented dates:
          if (($startDateFormated <= $rentalFoundEndFormatted) && ($endDateFormated >= $rentalFoundStartFormatted)) {
            // Rental start date fall within found ranges.
            // start date not available:
            if($startDateFormated >= $rentalFoundStartFormatted){
              $isValidStartDate = false;
              $isValidStartDate = "is-invalid";
            } else if ($endDateFormated <= $rentalFoundEndFormatted){
              $isValidEndDate = false;
              $isValidEndDate = "is-invalid";
            } else {
              //both unavailable whole range overlaps
              $isValidEndDate = false;
              $isValidEndDate = "is-invalid";
              $isValidStartDate = false;
              $isValidStartDate = "is-invalid";
            }
            $datesNotAvailable = true;
          }

          }
          }

          // if rental allowed rent the property.
          if($datesNotAvailable == false){
            $sql = "INSERT INTO rentals (startDate,endDate,status,eircode,tenantID,rentCost) VALUES(:sday, :eday,:stat, :eir, :tid, :rcst)";

            $stmt = $pdo->prepare($sql);

            $stmt->bindValue(':sday', $startDateFormated);
            $stmt->bindValue(':eday', $endDateFormated);
            $stmt->bindValue(':tid', $tenantID);
            $stmt->bindValue(':eir', strtoupper($eircode));
            $stmt->bindValue(':rcst', $rentCost);
            $stmt->bindValue(':stat', 'A');


            $stmt->execute();
            // go to rent sucess component.
            $rentSucess = true;
          }else{
            // display dates not available message.
            $datesNotAvailableMessage = "<h4 class='text-danger'> Sorry this property is not available during these dates Or something has gone wrong, please start again.  </h4>";
          }

      }catch (PDOException $e) {
        $datesNotAvailableMessage = "<h4 class='text-danger'> Sorry this property is not available during these dates Or something has gone wrong, please start again. </h4>";
        }


    }
    }

  }
}


 ?>
