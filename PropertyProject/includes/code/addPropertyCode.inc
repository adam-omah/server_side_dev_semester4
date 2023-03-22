<?php
// need to move this to own file when polishing.
$parentPage = "addProperty.php";
$ownerID = "";
$eircode ="";
$town = "";
$typeSelected = "";



$chkGarden = "unchecked";
$chkPets = "unchecked";
$chkOwnerO = "unchecked";

$isValidSurname = "";

if (isset($_POST['newForm'])) {
  // Reset the Form and post data if starting new property.
  unset($_POST);
}

if (isset($_POST['selectOwner'])) {
  if (isset($_POST['ownerID'])) {
    $ownerID = $_POST['ownerID'];
  }
}

// property form php
if(isset($_POST['addProp'])){
  // Check boxes dont need validation, but need to remember the vlaues if somethign else is invalid.
  if(isset($_POST['pets'])){
    if ($_POST['pets'] = "pets") {
      $chkPets = "checked";
    }
  }
  if(isset($_POST['ownerO'])){
    if ($_POST['ownerO'] = "ownerO") {
      $chkOwnerO = "checked";
    }
  }
  if(isset($_POST['garden'])){
    if ($_POST['garden'] = "garden") {
      $chkGarden = "checked";
    }
  }


  // if all valid:
  if (condition) {
    // check if property already exists.
    $sql = "SELECT * FROM properties where eircode = '$eircode'";
    $result = $pdo->query($sql);
    if ($result->rowCount() == 0) {
      $hideSelect = "d-none";
      echo "<h5 class ='mt-4'> Sorry no Owners with matching surname found, please search another surname </h5>";

    }else{
      // Eircode alread exists, show this to the user.
    }
  }
}else{

  }

 ?>
