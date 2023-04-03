<div class="sucess-sections">
  <h2 class="text-center m-5">Property Rented Successfully!</h2>
  <h4 class="text-center m-5"><?php echo "Thank you $firstName $lastName, contact: $email"; ?></h4>
  <h4 class="text-center m-5"><?php echo "You have rented the property at eircode: $eircode"; ?></h4>
  <h4 class="text-center m-5"><?php echo "The Cost of your stay is: $rentCost, you have rented from: $startDate, Until: $endDate"; ?></h4>
  <?php
  // unset everything now that proeprty was rented and data shown.
  unset($_POST);
   ?>
  <div class="form-buttons">
    <a class="btn btn-primary" href="index.php">Home</a> <a class="btn btn-primary" href="rentProperty.php"> Rent Another Property.</a>
  </div>
</div>
