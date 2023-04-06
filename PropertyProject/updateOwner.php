<?php
declare(strict_types=1);
?>
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
        <div class="col-8 ">
          <?php
          if ($ownerUpdated) {
            include 'includes/results/updateOwnerSuccess.inc';
          }else if($ownerSearched){
            include 'includes/forms/selectOwner.inc';
          }else if ($ownerSelected){
            include 'includes/forms/updateOwnerForm.inc';
          }else if($ownerUpdateFailed) {
            include 'includes/forms/updateOwnerForm.inc';
          }else {
            include 'includes/forms/findOwners.inc';
          }
         ?>
        </div>
      </div>
    </div>


  </body>
</html>
