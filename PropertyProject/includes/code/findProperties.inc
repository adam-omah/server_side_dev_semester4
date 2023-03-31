<div class="find-Properties-form">
  <!-- this $parentPage allows the re-use of the find owner function. -->
  <!-- this form passes information to select property. -->
  <form class="" action="<?php echo $parentPage; ?>" method="post">
    <div class="form-group row">
      <div class="col-md-12">
        <label for="townSearch" class="form-label mt-2">Town To Search: </label>
        <input type="text" class="form-control form-control-sm <?php echo $isValidTown; ?>" name="townSearch" value="<?php echo $townSearch; ?>">
        <div class="invalid-feedback">Sorry, Town cannot be empty, or is invalid!</div>
      </div>

      <div class="col-md-6">
        <label for="startDate" class="form-label mt-2">Start Date: </label>
        <input type="datetime-local" class="form-control form-control-sm <?php echo $isValidStartDate; ?>" name="startDate" value="<?php echo $startDate; ?>">
        <div class="invalid-feedback">Sorry, Start Date invalid! Must be a date in the future!</div>
      </div>

      <div class="col-md-6">
        <label for="endDate" class="form-label mt-2 ">End Date:</label>
        <input type="datetime-local" class="form-control form-control-sm <?php echo $isValidEndDate; ?>" name="endDate" value="<?php echo $endDate; ?>">
        <div class="invalid-feedback">End Date invalid! Must be after Start Date.</div>
      </div>
    </div>

    <div class="form-buttons">
      <input class="btn btn-primary" type="submit" name="newForm" value="Start New Form"><input class="btn btn-primary" type="submit" name="findProperties" value="Find Properties">
    </div>
  </form>
</div>
