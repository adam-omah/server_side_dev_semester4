<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">


    <?php
    $parentPage = "updateOwner.php";

    $ownerStatusASelected = "";
    $ownerStatusISelected = "";

    $ownerID = "";

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
    if (isset($_POST['newForm'])) {
      // Reset the Form and post data if starting new property.
      unset($_POST);
    }

    if(isset($_POST['updateOwner'])){
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
          if (strlen($phone) > 15 || $phone =='') {
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
          if (strlen($eircode) != 7) {
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

            $sql = "INSERT INTO Owners (firstName,lastName,phone,email,eircode) VALUES(:fname, :lname,:phn, :eml ,:eir )";

            $stmt = $pdo->prepare($sql);

            $stmt->bindValue(':fname', $firstName);
            $stmt->bindValue(':lname', $lastName);
            $stmt->bindValue(':phn', $phone);
            $stmt->bindValue(':eml', $email);
            $stmt->bindValue(':eir', $eircode);

            $stmt->execute();

            // reset everything, change to sucess window
            unset($_POST);

            $ownerAdded = true;


          }
          catch (PDOException $e) {

            $title = 'An error has occurred';

            $output = 'Database error: ' . $e->getMessage() . ' in ' . $e->getFile() . ':' . $e->getLine();

            }

        }
    }

    // if owner is selected load them into the form.
    if(isset($_POST['selectOwner'])){
      if (isset($_POST['ownerID'])) {
        $ownerID = $_POST['ownerID'];
        try {
          // try make a connection, to search for the owner.
        $pdo = new PDO('mysql:host=localhost;dbname=propertyrental; charset=utf8', 'root', '');
        $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
        $sql = "SELECT * FROM owners where ownerID = '$ownerID'";
        $result = $pdo->query($sql);

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

        }
        } catch (\Exception $e) {

        }

      }
    }

     ?>
     <?php
     // incled the links in head information.
     include 'includes/links.inc';
     ?>

    <title>Add a new Owner</title>
  </head>
  <body>
    <?php include 'includes/header.inc'; ?>

    <div class="container-fluid">
      <div class="row justify-content-center">
        <div class="col-6 ">
          <?php
          if (isset($_POST['findOwner'])) {
            if (strlen($_POST['ownerSurname'])  > 40 || $_POST['ownerSurname'] == '' ) {
              // invalid owner surname, still include find owners.
              $isValidSurname = "is-invalid";
              include 'includes/findOwners.inc';
            }else{
              // if valid surname searched.
              include 'includes/selectOwner.inc';
            }
          }else if (isset($_POST['selectOwner'])) {
            if (isset($_POST['ownerID'])) {
              include 'includes/forms/updateOwnerForm.inc';
            }else {
              // invalid owner ID, go back to find owner.
              $isValidSurname = "is-invalid";
              include 'includes/findOwners.inc';
            }

          }
          else{
            include 'includes/findOwners.inc';
          }
         ?>
        </div>
      </div>
    </div>


  </body>
</html>
