<div class="select-Property-to-rent-form">
  <!-- this $parentPage allows the re-use of the find owner function. -->
  <form class="" action="<?php echo $parentPage; ?>" method="post">
    <div class="form-group row">
      <div class="col-md-12">
      <h4 class="mt-4">property Search Details: </h4>
      <div class="col-md-12">
        <label for="tenantID" class="form-label mt-2">Town Searched: </label>
        <input type="text" class="form-control form-control-sm " name="townSearch" value="<?php echo $townSearch ?>" readonly="readonly">
      </div>
      </div>
      <div class="col-md-6">
        <label for="startDateFormated" class="form-label mt-2">Start Date: </label>
        <input type="text" class="form-control form-control-sm " name="startDateFormated" value="<?php echo $startDateFormated ?>" readonly="readonly">
      </div>
      <div class="col-md-6">
        <label for="endDateFormated" class="form-label mt-2">End Date: </label>
        <input type="text" class="form-control form-control-sm " name="startDateFormated" value="<?php echo $endDateFormated ?>" readonly="readonly">
      </div>

      <div class="col-md-12">
      <h4 class="mt-4">Properties Found:</h4>
        <?php
        include 'includes/code/propertiesFoundCode.inc';
         ?>

      </div>
    </div>
    <div class="form-buttons">
      <input class="btn btn-primary" type="submit" name="newForm" value="Start New Form"><input class="btn btn-primary <?php echo $hideSelect ?>" type="submit" name="selectProperty" value="Rent Selected Property">
    </div>
  </form>
</div>
