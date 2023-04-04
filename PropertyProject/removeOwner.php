
<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <!-- remove owner code is in the includes, under code folder -->
    <?php include 'includes/code/removeOwnerCode.inc';  ?>
    <?php
    // incled the links in head information.
    include 'includes/links.inc';
    ?>

    <title>Add a new Owner</title>
  </head>
  <body>
    <?php include 'includes/header.inc'; ?>

    <div class="container-fluid">
      <div class="row justify-content-center">
        <div class="col-8">
          <?php
            if (isset($_POST['findOwner'])) {
              // check valid find owner
              if (strlen($_POST['ownerSurname'])  > 40 || $_POST['ownerSurname'] == '' ) {
                // invalid owner surname, still include find owners.
                $isValidSurname = "is-invalid";
                include 'includes/findOwners.inc';
              }else{
                // if valid surname searched.
                include 'includes/code/removeOwner.inc';
              }
            }else if (isset($_POST['removeOwner'])) {
              // owner was removed or not.
              if ($ownerRemoved) {
                include 'includes/results/removeOwnerSuccess.inc';
              }else {
                include 'includes/results/removeOwnerFailed.inc';
              }
            }else {
              include 'includes/code/findOwners.inc';
            }
         ?>
        </div>
      </div>
    </div>


  </body>
</html>
