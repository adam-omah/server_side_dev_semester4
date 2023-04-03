<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">




     <?php
     // incled the links in head information.
     include 'includes/links.inc';
     ?>

     <?php include 'includes/code/addPropertyCode.inc';  ?>

    <title>Add a new Property</title>
  </head>
  <body>
    <?php include 'includes/header.inc'; ?>

    <div class="container-fluid">
      <div class="row justify-content-center">
        <div class="col-8 ">
            <?php

            //load correct form for where the user is.
            if ($propertyAdded) {
              // Load Success form
              include 'includes/results/addPropertySuccess.inc';
            }else {
              if (isset($_POST['findOwner'])) {
                if (strlen($_POST['ownerSurname'])  > 40 || $_POST['ownerSurname'] == '' ) {
                  // invalid owner surname, still include find owners.
                  $isValidSurname = "is-invalid";
                  include 'includes/code/findOwners.inc';
                }else{
                  // if valid surname searched.
                  include 'includes/code/selectOwner.inc';
                }
              }elseif (isset($_POST['selectOwner']) || isset($_POST['addProp'])) {
                //just a high level error message, incase eircode is already used.
                echo $errorMsg;
                include 'includes/forms/mainPropForm.inc';
              }
              else{
                include 'includes/code/findOwners.inc';
              }
            }

           ?>
        </div>
      </div>
    </div>


  </body>
</html>
