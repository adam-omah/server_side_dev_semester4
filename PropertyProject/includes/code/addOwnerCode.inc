<?php
$firstName ="";
$lastName ="";
$phone = "";
$email = "";
$eircode ="";


$validFirstName = false;
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

    validateFirstName();
    validateLastName();
    validatePhone();
    validateEircode();
    validateEmail();

    // if all valid add to owners.
    if($validFirstName && $validLastName && $validPhone && $validEircode && $validEmail){
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
        $stmt->bindValue(':eir', strtoupper($eircode));
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
