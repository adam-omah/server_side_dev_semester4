<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">


    <?php
    $firstName ="";
    $lastName ="";
    $phone = "";
    $eircode ="";

    $validFistName = false;
    $validLastName = false;
    $validEircode = false;
    $validPhone = false;


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
          }else {
            $validFistName = true;
          }

        }

        if(isset($_POST['lastName'])){
          // set variable lastname to post
          $lastName = $_POST['lastName'];
          //last name not empty & max 40 chars.
          if (strlen($lastName) > 40 || $lastName =='') {
            // Highlight that is invalid.
          }else {
            $validLastName = true;
          }

        }


        if(isset($_POST['phone'])){
          // set variable Phone to post
          $phone = $_POST['phone'];
          // phone is valid number & < 15 chars long.
          if (strlen($phone) > 40 || $phone =='') {
            // Highlight that is invalid.
          }else {
            $validPhone = true;
          }
        }

        if(isset($_POST['eircode'])){
          // set variable eircode to post
          $eircode = $_POST['eircode'];
          // valid Eircode & 7 chars long.
          if (strlen($eircode) != 7) {
            // Highlight that is invalid.
          }else {
            $validEircode = true;
          }

        }

        // if all valid add to owners.
        if($validFistName && $validLastName && $validPhone && $validEircode){
          // add to owners.
          try{
            $pdo = new PDO('mysql:host=localhost;dbname=propertyrental; charset=utf8', 'root', '');

            $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

            $sql = "INSERT INTO Owners (firstName,lastName,phone,eircode) VALUES(:fname, :lname, :phn ,:eir )";

            $stmt = $pdo->prepare($sql);

            $stmt->bindValue(':fname', $firstName);
            $stmt->bindValue(':lname', $lastName);
            $stmt->bindValue(':phn', $phone);
            $stmt->bindValue(':eir', $eircode);

            $stmt->execute();

            unset($_POST);
            $firstName ="";
            $lastName ="";
            $phone = "";
            $eircode ="";
            echo "<script>alert('The Owner has been successfully added,<br>The form will be reset and you can add another.');</script>";
          }
          catch (PDOException $e) {

            $title = 'An error has occurred';

            $output = 'Database error: ' . $e->getMessage() . ' in ' . $e->getFile() . ':' . $e->getLine();

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
          <form class="" action="addOwner.php" method="post">
              <div class="form-group row">
                <div class="col-md-6">
                  <label for="firstName" class="form-label mt-2">First Name: </label>
                  <input type="text" class="form-control form-control-sm" name="firstName" value="<?php echo $firstName; ?>">
                </div>

                <div class="col-md-6">
                  <label for="lastName" class="form-label mt-2">Last Name:</label>
                  <input type="text" class="form-control form-control-sm" name="lastName" value="<?php echo $lastName; ?>">
                </div>


                <div class="col-md-6">
                  <label for="eircode" class="form-label mt-2">Eircode:</label>
                  <input type="text" class="form-control form-control-sm form-control-sm" name="eircode" value="<?php echo $eircode; ?>">
                </div>


                <div class="col-md-6">
                  <label for="phone" class="form-label mt-2">Phone Number:</label>
                  <input type="text" class="form-control form-control-sm" name="phone" value="<?php echo $phone; ?>">
                </div>

              </div>

              <div class="form-buttons">
                <input class="btn btn-primary" type="submit" name="newOwner" value="Start New Owner Form"><input class="btn btn-primary" type="submit" name="addOwner" value="Add Owner">
              </div>
          </form>
        </div>
      </div>
    </div>


  </body>
</html>
