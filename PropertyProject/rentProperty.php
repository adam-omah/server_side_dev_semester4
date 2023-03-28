<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <?php
    // incled the links in head information.
    include 'includes/links.inc';
    ?>

    <?php include 'includes/code/rentPropertyCode.inc';  ?>

    <title>Rent a Property</title>
  </head>
  <body>
    <?php include 'includes/header.inc'; ?>

    <div class="container-fluid">
      <div class="row justify-content-center">
        <div class="col-10 ">
          <?php
          if ($rentSucess) {
            include 'includes/results/rentSucess.inc';
          }else{
            if (isset($_POST['findProperties'])) {
              if (strlen($_POST['townSearch'])  > 50 || $_POST['townSearch'] == '' ) {
                // invalid Town searched.
                $isValidTown = "is-invalid";
                include 'includes/code/findProperties.inc';
              }else{
                // if valid Town searched.
                include 'includes/code/selectProperty.inc';
              }
            }else if (isset($_POST['selectProperty'])) {
              if (isset($_POST['propertySelected']) && isValidEircode($_POST['propertySelected'])) {
                include 'includes/forms/updateOwnerForm.inc';
              }else {
                // invalid eircode found go back to town search.
                include 'includes/code/findProperties.inc';
              }
            }else if(isset($_POST['updateOwner'])){
              include 'includes/forms/updateOwnerForm.inc';
            }
            else{
              include 'includes/code/findProperties.inc';
            }
          }
         ?>
        </div>
      </div>
    </div>


  </body>
</html>
