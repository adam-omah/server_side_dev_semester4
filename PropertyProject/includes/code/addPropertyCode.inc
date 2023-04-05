<?php

$parentPage = "addProperty.php";
$errorMsg = "";
$propertyAdded = false;
$ownerSelected = false;
$ownerSearched = false;
$propertyAddFailed = false;

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


// try connect to the database:
try {
  // try make a connection, to search for the owner.
  $pdo = new PDO('mysql:host=localhost;dbname=propertyrental; charset=utf8', 'root', '');
  $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch (PDOException $e) {
  echo  'An error has occurred';
  $output = 'Database error: ' . $e->getMessage() . ' in ' . $e->getFile() . ':' . $e->getLine();
  echo $output;
  }
if ($_SERVER['REQUEST_METHOD'] === 'POST'){
  if (isset($_POST['newForm'])) {
    // Reset the Form and post data if starting new property.
    unset($_POST);
  }

  if (isset($_POST['selectOwner'])) {
    if (isset($_POST['ownerID'])) {
      $ownerID = $_POST['ownerID'];
      $validID = true;
      $ownerSelected = true;
    }
  }

  if (isset($_POST['findOwner'])) {
      if (strlen($_POST['ownerSurname'])  > 40 || $_POST['ownerSurname'] == '' ) {
        // invalid owner surname, still include find owners.
        $isValidSurname = "is-invalid";
      }else{
        $ownerSearched = true;
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
    validateOwnerID();
    validateEircode();
    validateTown();
    validateAddress();
    validateDescription();

    // Number validations :
    //rent decimal
    validateRent();
    //tiny ints:
    validateBedrooms();
    validateBathrooms();
    validateParking();

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
    if ($validID && $validEircode && $validTown && $validAddress && $validDescription
    && $validRent && $validBedrooms && $validBathrooms && $validParking) {

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

          $stmt->bindValue(':eir', strtoupper($eircode));
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
          $propertyAddFailed = true;
          echo "An error has occured, Property not added";
          echo "Values were :  $eircode , $town ,
           $address, $description, $rent, $bedrooms,
          $bathrooms, $parking, $garden, $pets, $ownerO, $ownerID, $propType, 'A'";
          }


      }else{
        // Eircode alread exists, show this to the user.
        $errorMsg = "<h5 class ='mt-4'> Sorry this eircode already exists on our system! Please use another eircode. </h5>";
        $propertyAddFailed = true;
        $isValidEircode = "is-invalid";
      }
    } catch (PDOException $e) {
      $propertyAddFailed = true;
      echo "An error has occured, Property not added";
      echo "Values were :  $eircode , $town ,
       $address, $description, $rent, $bedrooms,
      $bathrooms, $parking, $garden, $pets, $ownerO, $ownerID, $propType, 'A'";

    }


  }else {
    // the validation failed:
    $propertyAddFailed = true;
  }
  }
}

 ?>
