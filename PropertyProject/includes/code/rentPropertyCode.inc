<?php
$parentPage = "rentProperty.php";

$rentSucess = false;

// eircode of property selected:
$eircode = "";
$townSearch = "";

$firstName ="";
$lastName ="";
$phone = "";
$email = "";


$validEircode = false;

$validFistName = false;
$validLastName = false;
$validEircode = false;
$validPhone = false;
$validEmail =false;

$isValidEircode = "";
$isValidTown = "";

$isValidFirst = "";
$isValidLast = "";
$isValidPhone = "";
$isValidEmail ="";


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
      if($ownerID == "") {
        // Highlight that is invalid.
        $isValidID = "is-invalid";
      }else{
        $validID = true;
        $isValidID = "is-valid;";
      }
    }

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

    if(isset($_POST['email'])){
      // set variable Phone to post
      $email = $_POST['email'];
      // phone is valid number & < 15 chars long.
      if (strlen($email) > 50 || $email =='') {
        // Highlight that is invalid.#
        $isValidEmail = "is-invalid";
      }else {
        $validEmail = true;
        $isValidEmail = "is-valid";
      }
    }

    // if all valid add to owners.
    if($validID && $validStatus  && $validFistName && $validLastName && $validPhone && $validEircode && $validEmail){
      // Update the owner.
      try{
        // used this to test, as status had an error.
        // echo "<script> alert('Trying to update owner  status is : $ownerStatus')</script>";

        $sql = "Update Owners set firstName=:fname, lastName = :lname, phone = :phn, email = :eml , eircode = :eir, status = :stat where ownerID = :oid";

        $stmt = $pdo->prepare($sql);

        $stmt->bindValue(':oid', $ownerID);
        $stmt->bindValue(':fname', $firstName);
        $stmt->bindValue(':lname', $lastName);
        $stmt->bindValue(':phn', $phone);
        $stmt->bindValue(':eml', $email);
        $stmt->bindValue(':eir', $eircode);
        $stmt->bindValue(':stat', $ownerStatus);

        $stmt->execute();

        // reset everything, change to sucess window
        unset($_POST);
        $rentSucess = true;

      }
      catch (PDOException $e) {

        $title = 'An error has occurred';

        $output = 'Database error: ' . $e->getMessage() . ' in ' . $e->getFile() . ':' . $e->getLine();

        }

    }
} else if (isset($_POST['addTenant'])) {
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

      // reset everything, change to sucess window
      unset($_POST);

      $ownerAdded = true;

    }
    catch (PDOException $e) {
      echo "An error has occured, owner not added";
      echo "Values were : $firstName, $lastName, $phone, $email";
    }
  }
}

 ?>
