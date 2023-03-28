<?php

$parentPage = "addProperty.php";
$errorMsg = "";
$propertyAdded = false;

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
$pets = 'N';
$garden = 'N';
$ownerO = 'N';

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
    if ($_POST['pets'] == "pets") {
    $chkPets = "checked";
    $pets = 'Y';
    }
  }
  if(isset($_POST['ownerO'])){
    if ($_POST['ownerO'] == "ownerO") {
      $chkOwnerO = "checked";
      $ownerO = 'Y';
    }
  }
  if(isset($_POST['garden'])){
    if ($_POST['garden'] == "garden") {
      $chkGarden = "checked";
      $garden = 'Y';
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

  // Number validations :
  //rent decimal
  if(isset($_POST['rent'])){
    // set variable rent to post
    $rent = $_POST['rent'];
    // valid rent decimal number and not null.
    if ($rent =='' || !isValidDecimal($rent)) {
      // Highlight that is invalid.
      $isValidRent = "is-invalid";
    }else {
      $validRent = true;
      $isValidRent = "is-valid";
    }
  }
  //tiny ints:
  if(isset($_POST['bedrooms'])){
    // set variable bedrooms to post
    $bedrooms = $_POST['bedrooms'];
    // valid bedrooms small number and not null max 99.
    if ($bedrooms =='' || !isValidTinyInt($bedrooms)) {
      // Highlight that is invalid.
      $isValidBedroom = "is-invalid";
    }else {
      $validBedrooms = true;
      $isValidBedroom = "is-valid";
    }
  }

  if(isset($_POST['bathrooms'])){
    // set variable bathrooms to post
    $bathrooms = $_POST['bathrooms'];
    // valid bathrooms small number and not null max 99.
    if ($bathrooms =='' || !isValidTinyInt($bathrooms)) {
      // Highlight that is invalid.
      $isValidBathroom = "is-invalid";
    }else {
      $validBathrooms = true;
      $isValidBathroom = "is-valid";
    }
  }

  if(isset($_POST['parking'])){
    // set variable parking to post
    $parking = $_POST['parking'];
    // valid parkingSpaces small number and not null max 99.
    if ($parking =='' || !isValidTinyInt($parking)) {
      // Highlight that is invalid.
      $isValidParking = "is-invalid";
    }else {
      $validParking = true;
      $isValidParking = "is-valid";
    }
  }

  // Set selection box to correct value.
  if (isset($_POST['propType'])) {
    // set prop type to value sent over.
    $propType = $_POST['propType'];
    if($propType == "Semi Detatched"){
      $selectedSD = "selected";
    }else if ($propType == "Detactched House") {
      $selectedDH = "selected";
    }else if ($propType == "Bungalow") {
      $selectedBG = "selected";
    }else if ($propType == "Town House") {
      $selectedTH = "selected";
    }else if ($propType == "Apartment") {
      $selectedAP = "selected";
    }
  }



  // if all valid:
  if ($validID && $validEircode && $validTown && $validAddress && $validDescription && $validRent && $validBedrooms && $validBathrooms && $validParking) {

    try{
    // check if property already exists.
    $pdo = new PDO('mysql:host=localhost;dbname=propertyrental; charset=utf8', 'root', '');

    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    $sql = "SELECT * FROM properties where eircode = '$eircode'";
    $result = $pdo->query($sql);
    if ($result->rowCount() == 0) {
      // if the row count is 0 try to add property
      try{
        $pdo = new PDO('mysql:host=localhost;dbname=propertyrental; charset=utf8', 'root', '');

        $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

        $sql = "INSERT INTO Properties (eircode, town, address, description, rent, bedrooms, bathrooms, parkingspaces, gardenspace, petsAllowed, ownerOccupied, status, ownerID, type)
        VALUES(:eir, :twn,:add, :des,:ren, :bed, :bth, :prk, :gar, :pet, :owo, :stat, :owd, :typ)";

        $stmt = $pdo->prepare($sql);

        $stmt->bindValue(':eir', $eircode);
        $stmt->bindValue(':twn', $town);
        $stmt->bindValue(':add', $address);
        $stmt->bindValue(':des', $description);
        $stmt->bindValue(':ren', $rent);
        $stmt->bindValue(':bed', $bedrooms);
        $stmt->bindValue(':bth', $bathrooms);
        $stmt->bindValue(':prk', $parking);
        $stmt->bindValue(':gar', $garden);
        $stmt->bindValue(':pet', $pets);
        $stmt->bindValue(':owo', $ownerO);
        $stmt->bindValue(':owd', $ownerID);
        $stmt->bindValue(':typ', $propType);
        $stmt->bindValue(':stat', 'A');

        $stmt->execute();

        // reset everything, change to sucess window
        unset($_POST);

        // go to sucess screen
        $propertyAdded = true;

      }
      catch (PDOException $e) {

        echo "An error has occured, Property not added";
        echo "Values were :  $eircode , $town ,
         $address, $description, $rent, $bedrooms,
        $bathrooms, $parking, $garden, $pets, $ownerO, $ownerID, $propType, 'A'";
        }


    }else{
      // Eircode alread exists, show this to the user.
      $errorMsg = "<h5 class ='mt-4'> Sorry this eircode already exists on our system! Please use another eircode. </h5>";
    }
  } catch (PDOException $e) {

    echo "An error has occured, Property not added";
    echo "Values were :  $eircode , $town ,
     $address, $description, $rent, $bedrooms,
    $bathrooms, $parking, $garden, $pets, $ownerO, $ownerID, $propType, 'A'";

  }


  }
}

 ?>
