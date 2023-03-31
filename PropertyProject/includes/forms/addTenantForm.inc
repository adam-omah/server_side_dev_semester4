<form class="" action="rentProperty.php" method="post">
    <div class="form-group row">

      <div class="sub-heading-form-group">
        <h3 class="mt-4">Rental Details:</h3>
      </div>
      <div class="col-md-6">
        <label for="eircode" class="form-label mt-2">Eircode: </label>
        <input type="text" class="form-control form-control-sm <?php echo $isValidEircode; ?>" name="eircode" value="<?php echo $eircode ?>" readonly="readonly">
        <!-- technically there should be no way to active this but putting in anyway -->
        <div class="invalid-feedback">Sorry, Eircode is invalid, please search again for a property.</div>
      </div>
      <div class="col-md-6">
        <label for="startDate" class="form-label mt-2">Start Date: </label>
        <input type="text" class="form-control form-control-sm " name="startDate" value="<?php echo $startDateFormated ?>" readonly="readonly">
      </div>
      <div class="col-md-6">
        <label for="endDate" class="form-label mt-2">End Date: </label>
        <input type="text" class="form-control form-control-sm " name="endDate" value="<?php echo $endDateFormated ?>" readonly="readonly">
      </div>

      <div class="sub-heading-form-group">
        <h3 class="mt-4">Tenant Details:</h3>
      </div>

      <div class="col-md-6">
        <label for="firstName" class="form-label mt-2">First Name: </label>
        <input type="text" class="form-control form-control-sm <?php echo $isValidFirst; ?>" name="firstName" value="<?php echo $firstName; ?>">
        <div class="invalid-feedback">Sorry, First Name cannot be empty</div>
      </div>

      <div class="col-md-6">
        <label for="lastName" class="form-label mt-2 ">Last Name:</label>
        <input type="text" class="form-control form-control-sm <?php echo $isValidLast; ?>" name="lastName" value="<?php echo $lastName; ?>">
        <div class="invalid-feedback">Sorry, Last Name cannot be empty</div>
      </div>

      <div class="col-md-6">
        <label for="phone" class="form-label mt-2">Phone Number:</label>
        <input type="text" class="form-control form-control-sm <?php echo $isValidPhone; ?>" name="phone" value="<?php echo $phone; ?>">
        <div class="invalid-feedback">Invalid Phone Number! Numbers Allowed only!</div>
      </div>
      <div class="col-md-6">
        <label for="email" class="form-label mt-2">Email Address:</label>
        <input type="text" class="form-control form-control-sm <?php echo $isValidEmail; ?>" name="email" value="<?php echo $email; ?>">
        <div class="invalid-feedback">Sorry, invalid Email!</div>
      </div>
    </div>

    <div class="form-buttons">
      <input class="btn btn-primary" type="submit" name="newForm" value="Start New Rental"><input class="btn btn-primary" type="submit" name="addTenant" value="Add Tenant">
    </div>
</form>
