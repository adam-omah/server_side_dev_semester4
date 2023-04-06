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
          if ($_SERVER['REQUEST_METHOD'] === 'POST'){
            if ($rentSucess) {
              include 'includes/results/rentSucess.inc';
            }else if ($validPropertyRental) {
              include 'includes/forms/rentPropertyForm.inc';
            }else if ($townSearched) {
              include 'includes/forms/selectPropertyToRent.inc';
            }else if($failedToAddTenant){
              include 'includes/forms/rentPropertyForm.inc';
            }else {
              include 'includes/forms/findProperties.inc';
            }
          }else {
            include 'includes/forms/findProperties.inc';
          }
         ?>
        </div>
      </div>
    </div>


  </body>
</html>
