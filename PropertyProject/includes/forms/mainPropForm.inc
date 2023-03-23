<div class="main-property-form">
  <form class="" action="addProperty.php" method="post">
      <div class="form-group row">
        <div class="col-md-6">
          <label for="ownerID" class="form-label mt-2">Owner ID: </label>
          <input type="text" class="form-control form-control-sm <?php echo $isValidID; ?>" name="ownerID" value="<?php echo $ownerID ?>" readonly="readonly">
          <!-- technically there should be no way to active this but putting in anyway -->
          <div class="invalid-feedback">Sorry, ID is invalid, please search again for an owner.</div>
        </div>

        <div class="col-md-6">
          <label for="eircode" class="form-label mt-2">Eircode:</label>
          <input type="text" class="form-control form-control-sm form-control-sm <?php echo $isValidEircode; ?>" name="eircode" value="<?php echo $eircode ?>">
          <div class="invalid-feedback">Sorry, invalid Eircode!</div>
        </div>

        <div class="col-md-6">
          <label for="town" class="form-label mt-2">Town:</label>
          <input type="text" class="form-control form-control-sm <?php echo $isValidTown; ?>" name="town" value="<?php echo $town ?>">
          <div class="invalid-feedback">Sorry, Town cannot be empty</div>
        </div>


        <div class="col-md-6">
          <label for="propType" class="form-label mt-2">Property Type:</label>
          <select class="form-select form-select-sm" name="propType" id="propTypes">
            <option value="Semi Detatched" <?php echo $selectedSD; ?>>SD - Semi Detatched .</option>
            <option value="Detactched House" <?php echo $selectedDH; ?>>DH - Detactched House.</option>
            <option value="Bungalow" <?php echo $selectedBG; ?>>BG - Bungalow.</option>
            <option value="Town House" <?php echo $selectedTH; ?>>TH - Town House.</option>
            <option value="Apartment" <?php echo $selectedAP; ?>>AP - Apartment.</option>
          </select>
        </div>
      </div>
      <div class="col-md-12">
        <label for="address" class="form-label mt-2">Address:</label>
        <input class="form-control form-control-sm <?php echo $isValidAddress; ?>" type="text" name="address" value="<?php echo $address ?>">
        <div class="invalid-feedback">Sorry, Address cannot be empty</div>
      </div>
      <div class="col-md-12">
        <label for="description" class="form-label mt-2">Description:</label>
        <textarea class="form-control form-control-sm <?php echo $isValidDescription; ?>" name="description" rows="6" cols="80">
          <?php echo $description ?>
        </textarea>
        <div class="invalid-feedback">Sorry, Description cannot be empty</div>
      </div>

      <div class="form-group row">
        <div class="col-md-6">
          <label for="rent" class="form-label mt-2">Monthly Rent:</label>
          <input class="form-control form-control-sm <?php echo $isValidRent; ?>" type="text" name="rent" value="<?php echo $rent ?>">
          <div class="invalid-feedback">Sorry, Rent cannot be empty & must be a positive number.</div>
        </div>

        <div class="col-md-6">
          <label for="bedrooms" class="form-label mt-2">Bedrooms:</label>
          <input class="form-control form-control-sm <?php echo $isValidBedroom; ?>" type="text" name="bedrooms" value="<?php echo $bedrooms ?>">
          <div class="invalid-feedback">Sorry, Bedrooms cannot be empty & must be a positive number.</div>
        </div>

        <div class="col-md-6">
          <label for="Bathrooms" class="form-label mt-2">Bathrooms:</label>
          <input class="form-control form-control-sm <?php echo $isValidBathroom; ?>" type="text" name="Bathrooms" value="<?php echo $bathrooms ?>">
          <div class="invalid-feedback">Sorry, Bathrooms cannot be empty & must be a positive number.</div>
        </div>

        <div class="col-md-6">
          <label for="parking" class="form-label mt-2">Parking Spaces:</label>
          <input class="form-control form-control-sm <?php echo $isValidParking; ?>" type="text" name="parking" value="<?php echo $parking ?>">
          <div class="invalid-feedback">Sorry, Parking Spaces cannot be empty & must be a positive number.</div>
        </div>
      </div>



      <div class="chkBoxes">
        <div class="chkBox-item">
          <label for="garden" class="form-check-label">Garden Space?</label>
          <input class="form-check-input" type="checkbox" name="garden" value="garden" <?php echo $chkGarden;  ?>>
        </div>
        <div class="chkBox-item">
          <label for="pets" class="form-check-label">Pets allowed?</label>
          <input class="form-check-input" type="checkbox" name="pets" value="pets" <?php echo $chkPets;  ?>>
        </div>
        <div class="chkBox-item">
          <label for="ownerO" class="form-check-label">Owner Occupied?</label>
          <input class="form-check-input" type="checkbox" name="ownerO" value="ownerO" <?php echo $chkOwnerO;  ?>>
        </div>
      </div>
      <div class="form-buttons">
        <input class="btn btn-primary" type="submit" name="newProp" value="Start New Property"><input class="btn btn-primary" type="submit" name="addProp" value="Add Property">
      </div>
  </form>
</div>
