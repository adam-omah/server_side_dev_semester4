<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">


    <?php
    // need to move this to own file when polishing.

    $chkGarden = "unchecked";
    $chkPets = "unchecked";
    $chkOwnerO = "unchecked";

    $hideOwnersForm = "";

    if (isset($_POST['newProp'])) {
      // Reset the Form and post data if starting new property.
      unset($_POST);
    }


    if(isset($_POST['addProp'])){
      if(isset($_POST['pets'])){
        if ($_POST['pets'] = "pets") {
          $chkPets = "checked";
        }
      }
      if(isset($_POST['ownerO'])){
        if ($_POST['ownerO'] = "ownerO") {
          $chkOwnerO = "checked";
        }
      }
      if(isset($_POST['garden'])){
        if ($_POST['garden'] = "garden") {
          $chkGarden = "checked";
        }
      }



    }else{

    }

     ?>
     <?php
     // incled the links in head information.
     include 'includes/links.inc';
     ?>

    <title>Add a new Property</title>
  </head>
  <body>
    <?php include 'includes/header.inc'; ?>

    <div class="container-fluid">
      <div class="row justify-content-center">
        <div class="col-6 ">
            <?php
            if (isset($_POST['findOwner'])) {

              include 'includes/mainPropForm.inc';
            }else {
              include 'includes/findOwners.inc';
            }
           ?>
        </div>
      </div>
    </div>


  </body>
</html>
