<form class="" action="updateOwner.php" method="post">
    <div class="form-group row">
      <div class="col-md-6">
        <label for="ownerID" class="form-label mt-2">Owner ID: </label>
        <input type="text" class="form-control form-control-sm <?php echo $isValidID; ?>" name="ownerID" value="<?php echo $ownerID ?>" readonly="readonly">
        <!-- technically there should be no way to active this but putting in anyway -->
        <div class="invalid-feedback">Sorry, ID is invalid, please search again for an owner.</div>
      </div>
      <div class="col-md-6">
        <label for="ownerStatus" class="form-label mt-2">Owner Status: </label>
        <select class="form-select form-select-sm<?php echo $isValidStatus; ?>" name="ownerStatus" id="ownerStatus">
        <option value="A" <?php echo $ownerStatusASelected ?>>A - Active</option>
        <option value="I" <?php echo $ownerStatusISelected ?>>I - Inactive</option>
      </select>
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
        <label for="eircode" class="form-label mt-2">Eircode:</label>
        <input type="text" class="form-control form-control-sm form-control-sm <?php echo $isValidEircode; ?>" name="eircode" value="<?php echo $eircode; ?>">
        <div class="invalid-feedback">Sorry, invalid Eircode!</div>
      </div>


      <div class="col-md-6">
        <label for="phone" class="form-label mt-2">Phone Number:</label>
        <input type="text" class="form-control form-control-sm <?php echo $isValidPhone; ?>" name="phone" value="<?php echo $phone; ?>">
        <div class="invalid-feedback">Sorry, invalid Phone Number!</div>
      </div>

      <div class="col-md-12">
        <label for="email" class="form-label mt-2">Email Address:</label>
        <input type="text" class="form-control form-control-sm <?php echo $isValidEmail; ?>" name="email" value="<?php echo $email; ?>">
        <div class="invalid-feedback">Sorry, invalid Email!</div>
      </div>

    </div>

    <div class="form-buttons">
      <input class="btn btn-primary" type="submit" name="newForm" value="Start New Update Form"><input class="btn btn-primary" type="submit" name="updateOwner" value="Update Owner">
    </div>
</form>
