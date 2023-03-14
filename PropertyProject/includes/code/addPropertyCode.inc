<?php
// need to move this to own file when polishing.
$parentPage = "addProperty.php";
$ownerID = "";

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



}else{

}

 ?>
