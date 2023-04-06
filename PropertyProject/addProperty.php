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

            if ($propertyAdded) {
              // Load Success form
              include 'includes/results/addPropertySuccess.inc';
            }else if($ownerSearched){
              include 'includes/forms/selectOwner.inc';
            }else if ($ownerSelected || $propertyAddFailed){
              echo $errorMsg;
              include 'includes/forms/mainPropForm.inc';
            }else{
              include 'includes/forms/findOwners.inc';
            }
           ?>
        </div>
      </div>
    </div>


  </body>
</html>
