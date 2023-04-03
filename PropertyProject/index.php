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
    <title>Perfect Fit Rentals - Home Page.</title>
  </head>
  <body>
    <?php include 'includes/header.inc'; ?>
    <div class="container-fluid">
      <div class="row justify-content-center">
        <div class="col-10 ">
          <div class="row justify-content-center">
            <div class="col-12 text-center">
              <img class="logo-homepage" src="images/PFR.png" alt="Perfect Fit Rentals Logo">
            </div>
            <div class="col-12 text-center">
              <h2>Perfect Fit Rentals</h2>
              <h4>Find your perfect rental.</h4>
            </div>
          </div>
          <div class="row justify-content-center">
            <div class="col-12 text-center">
              <a class="btn m-4 p-4 btn-primary" href="rentProperty.php"> Rent A Property.</a>
              <a class="btn m-4 p-4 btn-primary" href="addProperty.php"> Add Property.</a>
              <a class="btn m-4 p-4 btn-primary" href="updateOwner.php"> Update an Owner.</a>
              <a class="btn m-4 p-4 btn-primary" href="addOwner.php"> Add Owner.</a>
              <a class="btn m-4 p-4 btn-primary" href="removeOwner.php"> Remove an Owner.</a>
            </div>
          </div>
        </div>
      </div>
    </div>

  </body>
</html>
