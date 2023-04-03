<div class="find-owner-form">
  <!-- this $parentPage allows the re-use of the find owner function. -->
  <!-- this form passes information to either remove owner or select owner. -->
  <form class="" action="<?php echo $parentPage; ?>" method="post">
    <div class="form-group row">
      <div class="col-md-12">
        <label for="ownerSurname" class="form-label mt-2">Owner Surname: </label>
        <input type="text" class="form-control form-control-sm <?php echo $isValidSurname; ?>" name="ownerSurname" value="">
        <div class="invalid-feedback">Sorry, Surname cannot be empty, or is invalid!</div>
      </div>
    </div>
    <div class="form-buttons">
      <input class="btn btn-primary" type="submit" name="newForm" value="Start New Form"><input class="btn btn-primary" type="submit" name="findOwner" value="Find Owners">
    </div>
  </form>
</div>
