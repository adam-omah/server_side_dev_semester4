<div class="main-property-form">
  <form class="" action="addProperty.php" method="post">
      <div class="form-group row">
        <div class="col-md-6">
          <label for="ownerID" class="form-label mt-2">Owner ID: </label>
          <input type="text" class="form-control form-control-sm" name="ownerID" value="<?php echo $ownerID ?>" disabled="">
        </div>

        <div class="col-md-6">
          <label for="eircode" class="form-label mt-2">Eircode:</label>
          <input type="text" class="form-control form-control-sm form-control-sm" name="eircode" value="">
        </div>

        <div class="col-md-6">
          <label for="town" class="form-label mt-2">Town:</label>
          <input type="text" class="form-control form-control-sm" name="town" value="">
        </div>
        <div class="col-md-6">
          <label for="propTypes" class="form-label mt-2">Property Type:</label>
          <!-- need to swap this for real data. -->
          <select class="form-select form-select-sm" name="propTypes" id="propTypes">
            <option value="SD">SD - standard double.</option>
            <option value="DD">DD - Detactched Double.</option>
          </select>
        </div>
      </div>


      <label for="address" class="form-label mt-2">Address:</label>
      <input class="form-control form-control-sm" type="text" name="address" value="">

      <label for="description" class="form-label mt-2">Description:</label>
      <textarea class="form-control form-control-sm" name="description" rows="6" cols="80"></textarea>

      <div class="form-group row">
        <div class="col-md-6">
          <label for="rent" class="form-label mt-2">Rent:</label>
          <input class="form-control form-control-sm" type="text" name="rent" value="">

        </div>
        <div class="col-md-6">
          <label for="parking" class="form-label mt-2">Parking Spaces:</label>
          <input class="form-control form-control-sm" type="text" name="parking" value="">
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
