<form class="" action="rentProperty.php" method="post">
    <div class="form-group row">
      <div class="sub-heading-form-group">
        <h3 class="mt-4" >Rental Details:</h3>
      </div>

      <div class="col-md-6">
        <label for="tenantID" class="form-label mt-2">Tenant ID: </label>
        <input type="text" class="form-control form-control-sm <?php echo $isValidTenantID; ?>" name="tenantID" value="<?php echo $tenantID ?>" readonly="readonly">
        <!-- technically there should be no way to active this but putting in anyway -->
        <div class="invalid-feedback">Sorry, Tenant ID is invalid, add the tenant again.</div>
      </div>

      <div class="col-md-6">
        <label for="eircode" class="form-label mt-2">Eircode: </label>
        <input type="text" class="form-control form-control-sm <?php echo $isValidEircode; ?>" name="eircode" value="<?php echo $eircode ?>" readonly="readonly">
        <!-- technically there should be no way to active this but putting in anyway -->
        <div class="invalid-feedback">Sorry, eircode is invalid, please search again for a property.</div>
      </div>
      <div class="col-md-6">
        <label for="startDate" class="form-label mt-2">Start Date: </label>
        <input type="datetime-local" class="form-control form-control-sm <?php echo $isValidStartDate; ?>" name="startDate" value="<?php echo $startDate; ?>">
        <div class="invalid-feedback">Sorry, Start Date invalid Or Unavailable! Must be a date in the future!</div>
      </div>

      <div class="col-md-6">
        <label for="endDate" class="form-label mt-2 ">End Date:</label>
        <input type="datetime-local" class="form-control form-control-sm <?php echo $isValidEndDate; ?>" name="endDate" value="<?php echo $endDate; ?>">
        <div class="invalid-feedback">End Date invalid Or Unavailable! Must be after Start Date.</div>
      </div>
      <div class="error-message">
              <?php echo $datesNotAvailableMessage; ?>
      </div>
    </div>


    <div class="form-buttons">
      <input class="btn btn-primary" type="submit" name="newForm" value="Start New Rental"><input class="btn btn-primary" type="submit" name="rentProperty" value="Rent Property">
    </div>
</form>
