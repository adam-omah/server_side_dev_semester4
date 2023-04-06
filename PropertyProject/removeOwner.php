
<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <!-- remove owner code is in the includes, under code folder -->
    <?php include 'includes/code/removeOwnerCode.inc';  ?>
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
        <div class="col-8">
          <?php

          if($ownerSearched){
            include 'includes/forms/removeOwner.inc';
          }else if ($ownerRemoveFailed){
            include 'includes/results/removeOwnerFailed.inc';
          }else if ($ownerRemoved){
            include 'includes/results/removeOwnerSuccess.inc';
          }else{
            include 'includes/forms/findOwners.inc';
          }

         ?>
        </div>
      </div>
    </div>


  </body>
</html>
