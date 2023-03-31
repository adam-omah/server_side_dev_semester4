<?php
$parentPage = "rentProperty.php";

$rentSucess = false;
$tenantAdded = false;
$datesNotAvailable = false;
$datesNotAvailableMessage = "";

// eircode of property selected:
$eircode = "";
$townSearch = "";

$firstName ="";
$lastName ="";
$phone = "";
$email = "";

$tenantID = "";
$startDate = "";
$endDate = "";

$todaysDate = date("Y-m-d");

$validEircode = false;


$validFistName = false;
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

  $title = 'An error has occurred';

  $output = 'Database error: ' . $e->getMessage() . ' in ' . $e->getFile() . ':' . $e->getLine();

  }



if (isset($_POST['newForm'])) {
  // Reset the Form and post data if starting new property.
  unset($_POST);
}

// if Property is selected
if(isset($_POST['selectProperty'])){
  if (isset($_POST['propertySelected'])) {
    $eircode = $_POST['propertySelected'];
    // valid Eircode & 7 chars long. and valid eircode
    if (strlen($eircode) != 7 || !isValidEircode($eircode)) {
      // Highlight that is invalid.
      $isValidEircode = "is-invalid";
    }else {
      $validEircode = true;
      $isValidEircode = "is-valid";
    }
  }
}


if(isset($_POST['rentProperty'])){

  // Validate Rental fields.
    if (isset($_POST['tenantID'])) {
      $tenantID = $_POST['tenantID'];
      if($tenantID == "") {
        // Highlight that is invalid.
        $validTenantID = "is-invalid";
      }else{
        $validTenantID = true;
        $isValidTenantID = "is-valid;";
      }
    }

    if(isset($_POST['eircode'])){
      // set variable eircode to post
      $eircode = $_POST['eircode'];
      // valid Eircode & 7 chars long.
      if (strlen($eircode) != 7 || !isValidEircode($eircode)) {
        // Highlight that is invalid.
        $isValidEircode = "is-invalid";
      }else {
        $validEircode = true;
        $isValidEircode = "is-valid";
      }
    }

    if(isset($_POST['startDate'])){
      // set variable startDate to post
      $startDate = $_POST['startDate'];


      if ($startDate =='') {
        // Highlight that is invalid.
        $isValidStartDate = "is-invalid";
      }else {
        // need to test if start day is before current date.
        $startDateFormated =date("Y-m-d",strtotime($startDate));
        if ($startDateFormated >= $todaysDate) {
          $validStartDate = true;
          $isValidStartDate = "is-valid";
        }else {
          // Highlight that is invalid.
          $isValidStartDate = "is-invalid";
        }

      }

    }

    if(isset($_POST['endDate'])){
      // set variable endDate to post
      $endDate = $_POST['endDate'];

      //last name not empty & max 40 chars.
      if ($endDate =='') {
        // Highlight that is invalid.
        $isValidEndDate = "is-invalid";
      }else {
        // not empty so chekc if end date is greater than start date.
        $endDateFormated =date("Y-m-d",strtotime($endDate));
        if($validStartDate == true && ($endDateFormated > $startDateFormated)){
          $validEndDate = true;
          $isValidEndDate = "is-valid";
        }else{
          // Highlight that is invalid.
          $isValidEndDate = "is-invalid";
        }

      }

    }

    // if all valid add to owners.
    if($validTenantID && $validEircode  && $validStartDate && $validEndDate){
      // Check Rental is allowed
      try{
        // some code used for testing/ figuring out how to format correctly:
        // echo "<h2> TenantId = $tenantID, Eircode = $eircode, startDate = $startDateFormated, endDate = $endDateFormated </h2>";

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
          // (StartA <= EndB)  and  (EndA >= StartB)
          // set to not available;
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
          $sql = "INSERT INTO rentals (startDate,endDate,status,eircode,tenantID) VALUES(:sday, :eday,:stat, :eir, :tid)";

          $stmt = $pdo->prepare($sql);

          $stmt->bindValue(':sday', $startDateFormated);
          $stmt->bindValue(':eday', $endDateFormated);
          $stmt->bindValue(':tid', $tenantID);
          $stmt->bindValue(':eir', $eircode);
          $stmt->bindValue(':stat', 'A');

          $stmt->execute();

          // // reset everything, change to sucess window
          // unset($_POST);
          $rentSucess = true;
        }else{
          // display dates not available message.
          $datesNotAvailableMessage = "<h4 class='text-danger'> Sorry this property is not available during these dates. </h4>";
        }


      }
      catch (PDOException $e) {

        $title = 'An error has occurred';

        $output = 'Database error: ' . $e->getMessage() . ' in ' . $e->getFile() . ':' . $e->getLine();

        }

    }
} else if (isset($_POST['addTenant']) && $tenantAdded == false) {
  // if tenant is added but the property is not yet attempted to be rented.
  //validate eircode still correct:
  if (isset($_POST['eircode'])) {
    $eircode = $_POST['eircode'];
    // valid Eircode & 7 chars long. and valid eircode
    if (strlen($eircode) != 7 || !isValidEircode($eircode)) {
      // Highlight that is invalid.
      $isValidEircode = "is-invalid";
    }else {
      $validEircode = true;
      $isValidEircode = "is-valid";
    }
  }



  //validate tenant values:
  if(isset($_POST['firstName'])){
    // set variable firstname to post
    $firstName = $_POST['firstName'];
    // First Name not empty & max 30 chars.
    if (strlen($firstName) > 30 || $firstName =='' ) {
      // Highlight that is invalid.
      $isValidFirst = "is-invalid";
    }else {
      $validFistName = true;
      $isValidFirst = "is-valid";
    }
  }

  if(isset($_POST['lastName'])){
    // set variable lastname to post
    $lastName = $_POST['lastName'];
    //last name not empty & max 40 chars.
    if (strlen($lastName) > 40 || $lastName =='') {
      // Highlight that is invalid.
      $isValidLast = "is-invalid";
    }else {
      $validLastName = true;
      $isValidLast = "is-valid";
    }

  }


  if(isset($_POST['phone'])){
    // set variable Phone to post
    $phone = $_POST['phone'];
    // phone is valid number & < 15 chars long.
    if (strlen($phone) > 15 || !isValidPhone($phone)) {
      // Highlight that is invalid.#
      $isValidPhone = "is-invalid";
    }else {
      $validPhone = true;
      $isValidPhone = "is-valid";
    }
  }

  if(isset($_POST['email'])){
    // set variable Phone to post
    $email = $_POST['email'];
    // phone is valid number & < 15 chars long.
    if (strlen($email) > 50 || !isValidEmail($email)) {
      // Highlight that is invalid.#
      $isValidEmail = "is-invalid";
    }else {
      $validEmail = true;
      $isValidEmail = "is-valid";
    }
  }
  //add tenant to the Database

  if($validFistName && $validLastName && $validPhone && $validEmail && $validEircode){
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
  }
}

 ?>
