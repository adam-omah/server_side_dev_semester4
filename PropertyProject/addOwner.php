<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">


     <?php
     // incled the links in head information.
     include 'includes/links.inc';
     ?>

     <?php include 'includes/code/addOwnerCode.inc';  ?>

    <title>Add a new Owner</title>
  </head>
  <body>
    <?php include 'includes/header.inc'; ?>

    <div class="container-fluid">
      <div class="row justify-content-center">
        <div class="col-6 ">
          <?php
          if ($ownerAdded) {
            include 'includes/results/addOwnerSuccess.inc';
          }else{
            include 'includes/forms/addOwnerForm.inc';
          } ?>
        </div>
      </div>
    </div>


  </body>
</html>
