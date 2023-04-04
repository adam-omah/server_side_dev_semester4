<?php
$parentPage = "updateOwner.php";

$ownerUpdated = false;
$ownerSearched = false;
$ownerSelected = false;
$ownerUpdateFailed = false;

$ownerStatusASelected = "";
$ownerStatusISelected = "";

$ownerStatus = "";
$ownerID = "";

$firstName ="";
$lastName ="";
$phone = "";
$email = "";
$eircode ="";


$validID = false;
$validStatus = false;
$validFirstName = false;
$validLastName = false;
$validEircode = false;
$validPhone = false;
$validEmail =false;

$isValidID = "";
$isValidFirst = "";
$isValidLast = "";
$isValidEircode = "";
$isValidPhone = "";
$isValidEmail ="";
$isValidStatus = "";


// try connect to the database:
try {
  // try make a connection, to search for the owner.
  $pdo = new PDO('mysql:host=localhost;dbname=propertyrental; charset=utf8', 'root', '');
  $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch (PDOException $e) {
  echo  'An error has occurred';
  $output = 'Database error: ' . $e->getMessage() . ' in ' . $e->getFile() . ':' . $e->getLine();
  echo $output;
  }
if ($_SERVER['REQUEST_METHOD'] === 'POST'){

if (isset($_POST['newForm'])) {
  // Reset the Form and post data if starting new property.
  unset($_POST);
}

if (isset($_POST['findOwner'])) {
  if (strlen($_POST['ownerSurname'])  > 40 || $_POST['ownerSurname'] == '' ) {
    // invalid owner surname, still include find owners.
    $isValidSurname = "is-invalid";
    $ownerSearched = false;
  }else {
    $ownerSearched = true;
  }
}

if(isset($_POST['updateOwner'])){
  // Validate that Onwer fields.
    // check that an owner Id was passed.
    validateOwnerID();
    // Check Status and set correct to true.
    validateOwnerStatus();
    validateFirstName();
    validateLastName();
    validatePhone();
    validateEircode();
    validateEmail();

    // if all valid add to owners.
    if($validID && $validStatus  && $validFirstName && $validLastName && $validPhone && $validEircode && $validEmail){
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
        $ownerUpdated = true;

      }
      catch (PDOException $e) {
        $ownerUpdateFailed= true;
        }
    }else {
      $ownerUpdateFailed= true;
    }
}

// if owner is selected load them into the form.
if(isset($_POST['selectOwner'])){
  if (isset($_POST['ownerID'])) {
    $ownerID = $_POST['ownerID'];
    try {
      // search for the owner.
    $sql = "SELECT * FROM owners where ownerID = :oid";
    $result = $pdo->prepare($sql);
    $result->bindValue(':oid', $_POST['ownerID']);
    $result->execute();

    if ($result->rowCount() == 0) {
      echo "<h5 class ='mt-4'> Sorry no Owners with matching ID found, please Start form again. </h5>";
    }else{
      $row = $result->fetch();

      $ownerStatus = substr($row['status'], 0, 1);
      if($ownerStatus == "A"){
        $ownerStatusASelected = "selected";
      }else if ($ownerStatus == "I") {
        $ownerStatusISelected = "selected";
      }
      $ownerID = $row['ownerID'];
      $firstName = $row['firstName'];
      $lastName = $row['lastName'];
      $phone = $row['phone'];
      $email = $row['email'];
      $eircode = $row['eircode'];

      $ownerSelected = true;
      }
    } catch (\Exception $e) {

      }
    }
  }
}

 ?>
