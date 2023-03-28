<div class="find-Properties-form">
  <!-- this $parentPage allows the re-use of the find owner function. -->
  <form class="" action="<?php echo $parentPage; ?>" method="post">
    <div class="form-group row">
      <div class="col-md-6">
        <label for="townSearch" class="form-label mt-2">Town To Search: </label>
        <input type="text" class="form-control form-control-sm <?php echo $isValidTown; ?>" name="townSearch" value="">
        <div class="invalid-feedback">Sorry, Town cannot be empty, or is invalid!</div>
      </div>
    </div>
    <div class="form-buttons">
      <input class="btn btn-primary" type="submit" name="newForm" value="Start New Form"><input class="btn btn-primary" type="submit" name="findProperties" value="Find Properties">
    </div>
  </form>
</div>
