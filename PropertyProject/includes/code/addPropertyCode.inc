<?php
// need to move this to own file when polishing.
$parentPage = "addProperty.php";
$ownerID = "";
$eircode ="";
$town = "";
$propType = "";
$address = "";
$description = "";
$rent = "";
$bedrooms = "";
$bathrooms = "";
$parking = "";

$isValidID = "";
$isValidEircode = "";
$isValidTown = "";
$isValidAddress ="";
$isValidDescription = "";
$isValidRent = "";
$isValidBedroom ="";
$isValidBathroom ="";
$isValidParking = "";


$validID = false;
$validEircode = false;
$validTown = false;
$validAddress = false;
$validDescription =false;
$validRent = false;
$validBedrooms = false;
$validBathrooms = false;
$validParking = false;

$chkGarden = "unchecked";
$chkPets = "unchecked";
$chkOwnerO = "unchecked";

$selectedSD = "";
$selectedDH = "";
$selectedBG = "";
$selectedTH = "";
$selectedAP = "";

if (isset($_POST['newForm'])) {
  // Reset the Form and post data if starting new property.
  unset($_POST);
}

if (isset($_POST['selectOwner'])) {
  if (isset($_POST['ownerID'])) {
    $ownerID = $_POST['ownerID'];
    $validID = true;
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

  // Check if text boxes are valid:

  if (isset($_POST['ownerID'])) {
    $ownerID = $_POST['ownerID'];
    if($ownerID == "") {
      // Highlight that is invalid.
      $isValidID = "is-invalid";
    }else{
      $validID = true;
      $isValidID = "is-valid;";
    }
  }

  if(isset($_POST['eircode'])){
    // set variable eircode to post
    $eircode = $_POST['eircode'];
    // valid Eircode & 7 chars long. and valid eircode
    if (strlen($eircode) != 7 || !isValidEircode($eircode)) {
      // Highlight that is invalid.
      $isValidEircode = "is-invalid";
    }else {
      $validEircode = true;
      $isValidEircode = "is-valid";
    }
  }

  if(isset($_POST['town'])){
    // set variable town to post
    $town = $_POST['town'];
    // town not empty & max 50 chars.
    if (strlen($town) > 50 || $town =='' ) {
      // Highlight that is invalid.
      $isValidTown = "is-invalid";
    }else {
      $validTown = true;
      $isValidTown = "is-valid";
    }
  }

  if(isset($_POST['address'])){
    // set variable Address to post
    $address = $_POST['address'];
    // Address not empty & max 100 chars.
    if (strlen($address) > 100 || $address =='' ) {
      // Highlight that is invalid.
      $isValidAddress = "is-invalid";
    }else {
      $validAddress = true;
      $isValidAddress = "is-valid";
    }
  }

  if(isset($_POST['description'])){
    // set variable description to post
    $description = $_POST['description'];
    // description not empty & max 200 chars.
    if (strlen($description) > 200 || $description =='' ) {
      // Highlight that is invalid.
      $isValidDescription = "is-invalid";
    }else {
      $validDescription = true;
      $isValidDescription = "is-valid";
    }
  }

  // Need to make validation for numbers and use for the next inputs.




  // if all valid:
  if ($validID) {
    // check if property already exists.
    $sql = "SELECT * FROM properties where eircode = '$eircode'";
    $result = $pdo->query($sql);
    if ($result->rowCount() == 0) {
      // if the row count is 0 try to add property


    }else{
      // Eircode alread exists, show this to the user.
      echo "<h5 class ='mt-4'> Sorry this eircode already exists on our system! Please use another eircode. </h5>";
    }
  }
}

 ?>
