<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <?php
    // incled the links in head information.
    include 'includes/links.inc';
    ?>

    <?php include 'includes/code/updateOwnerCode.inc';  ?>

    <title>Update an Owner</title>
  </head>
  <body>
    <?php include 'includes/header.inc'; ?>

    <div class="container-fluid">
      <div class="row justify-content-center">
        <div class="col-6 ">
          <?php
          if ($ownerUpdated) {
            include 'includes/results/updateOwnerSuccess.inc';
          }else{
            if (isset($_POST['findOwner'])) {
              if (strlen($_POST['ownerSurname'])  > 40 || $_POST['ownerSurname'] == '' ) {
                // invalid owner surname, still include find owners.
                $isValidSurname = "is-invalid";
                include 'includes/code/findOwners.inc';
              }else{
                // if valid surname searched.
                include 'includes/code/selectOwner.inc';
              }
            }else if (isset($_POST['selectOwner'])) {
              if (isset($_POST['ownerID'])) {
                include 'includes/forms/updateOwnerForm.inc';
              }else {
                // invalid owner ID, go back to find owner.
                $isValidSurname = "is-invalid";
                include 'includes/code/findOwners.inc';
              }
            }else if(isset($_POST['updateOwner'])){
              include 'includes/forms/updateOwnerForm.inc';
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
