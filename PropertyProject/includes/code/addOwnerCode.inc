<?php
$firstName ="";
$lastName ="";
$phone = "";
$email = "";
$eircode ="";


$validFistName = false;
$validLastName = false;
$validEircode = false;
$validPhone = false;
$validEmail =false;

$isValidFirst = "";
$isValidLast = "";
$isValidEircode = "";
$isValidPhone = "";
$isValidEmail ="";

$ownerAdded = false;

// need to move this to own file when polishing.
if (isset($_POST['newOwner'])) {
  // Reset the Form and post data if starting new property.
  unset($_POST);
}
if(isset($_POST['addOwner'])){
  // Validate that Onwer fields.

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
      // valid Eircode & 7 chars long. and valid eircode
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
    if($validFistName && $validLastName && $validPhone && $validEircode && $validEmail){
      // add to owners.
      try{
        $pdo = new PDO('mysql:host=localhost;dbname=propertyrental; charset=utf8', 'root', '');

        $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

        $sql = "INSERT INTO Owners (firstName,lastName,phone,email,eircode,status) VALUES(:fname, :lname,:phn, :eml ,:eir, :stat)";

        $stmt = $pdo->prepare($sql);

        $stmt->bindValue(':fname', $firstName);
        $stmt->bindValue(':lname', $lastName);
        $stmt->bindValue(':phn', $phone);
        $stmt->bindValue(':eml', $email);
        $stmt->bindValue(':eir', $eircode);
        $stmt->bindValue(':stat', 'A');

        $stmt->execute();

        // reset everything, change to sucess window
        unset($_POST);

        $ownerAdded = true;

      }
      catch (PDOException $e) {

        echo "An error has occured, owner not added";
        echo "Values were : $firstName, $lastName, $phone, $email, $eircode";

        }

    }
}

 ?>
