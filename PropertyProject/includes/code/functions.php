<!-- Here is the functions for my project, mainly validation or re-useable function Or just to tidy up functions on pages. -->
<?php
function isValidPhone($phone)
{
  $phonePattern = "/^[0-9]{7,15}$/";

  $result = preg_match($phonePattern, $phone);

  if ($result == 1) {
    return true;
  }else {
    return false;
  }

}

function isValidEircode($eircode)
{
  $eircodePatern = "/^[AC-FHKNPRTV-Y][0-9]{2}[0-9AC-FHKNPRTV-Y]{4}$/i";
  $result = preg_match($eircodePatern, $eircode);

  if ($result == 1) {
    return true;
  }else {
    return false;
  }
}

function isValidEmail($email)
{
  $emailPatern = "/^([a-z0-9_\.-]+)@([\da-z\.-]+)\.([a-z\.]{2,6})$/i";
  $result = preg_match($emailPatern, $email);

  if ($result == 1) {
    return true;
  }else {
    return false;
  }
}

function isValidTinyInt($number)
{
  // tiny int for the property values max is 99.
  $numberPattern = "/^([0-9][0-9]?)$/i";
  $result = preg_match($numberPattern, $number);

  if ($result == 1) {
    return true;
  }else {
    return false;
  }
}

function isValidDecimal($number)
{
  // Decimal pattern checking for the monthly rent.
  $numberPattern = "/^([0-9][0-9]{0,7}\.?[0-9]{0,2}?)$/i";
  $result = preg_match($numberPattern, $number);

  if ($result == 1) {
    return true;
  }else {
    return false;
  }
}

function validateEircode(){
  if(isset($_POST['eircode'])){
    global $eircode, $isValidEircode, $validEircode;
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
}

function validatePhone(){
  if(isset($_POST['phone'])){
    global $phone, $isValidPhone, $validPhone;
    // set variable Phone to post
    $phone = $_POST['phone'];
    // phone is valid number & < 15 chars long.
    if (strlen($phone) > 15 || !isValidPhone($phone)) {
      // Highlight that is invalid.#
      $isValidPhone = "is-invalid";
    }else {
      $validPhone = true;
      $isValidPhone = "is-valid";
    }
  }
}

function validateEmail(){
  if(isset($_POST['email'])){
    // set variable Phone to post
    global $email, $isValidEmail, $validEmail;
    $email = $_POST['email'];
    // phone is valid number & < 15 chars long.
    if (strlen($email) > 50 || !isValidEmail($email)) {
      // Highlight that is invalid.#
      $isValidEmail = "is-invalid";
    }else {
      $validEmail = true;
      $isValidEmail = "is-valid";
    }
  }
}

function validateFirstName(){
  if(isset($_POST['firstName'])){
    global $firstName, $isValidFirst, $validFirstName;
    // set variable firstname to post
    $firstName = $_POST['firstName'];
    // First Name not empty & max 30 chars.
    if (strlen($firstName) > 30 || $firstName =='' ) {
      // Highlight that is invalid.
      $isValidFirst = "is-invalid";
    }else {
      $validFirstName = true;
      $isValidFirst = "is-valid";
    }
  }
}

function validateLastName(){
  if(isset($_POST['lastName'])){
    global $lastName, $isValidLast, $validLastName;
    // set variable lastname to post
    $lastName = $_POST['lastName'];
    //last name not empty & max 40 chars.
    if (strlen($lastName) > 40 || $lastName =='') {
      // Highlight that is invalid.
      $isValidLast = "is-invalid";
    }else{
      $validLastName = true;
      $isValidLast = "is-valid";
    }
  }
}

function validateOwnerID(){
  if (isset($_POST['ownerID'])) {
    global $ownerID, $isValidID, $validID;
    $ownerID = $_POST['ownerID'];
    if($ownerID == "") {
      // Highlight that is invalid.
      $isValidID = "is-invalid";
    }else{
      $validID = true;
      $isValidID = "is-valid;";
    }
  }
}

function validateOwnerStatus(){
  if (isset($_POST['ownerStatus'])) {
    global $ownerStatus, $validStatus, $isValidStatus;
    $ownerStatus = $_POST['ownerStatus'];
    if ($ownerStatus == 'A' || $ownerStatus == 'I') {
      $validStatus = true;
      $isValidStatus = "is-valid;";
    }else{
      $validStatus = false;
      $isValidStatus = "is-invalid";
    }
  }
}

function validateTown(){
  if(isset($_POST['town'])){
    global $town, $isValidTown, $validTown;
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
}

function validateAddress(){
  if(isset($_POST['address'])){
    global $address, $isValidAddress, $validAddress;
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
}

function validateDescription(){
  if(isset($_POST['description'])){
    global $description, $isValidDescription, $validDescription;
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
}

function validateRent(){
  if(isset($_POST['rent'])){
    // set variable rent to post
    global $rent, $isValidRent, $validRent;
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
}

function validateBedrooms(){
  if(isset($_POST['bedrooms'])){
    // set variable bedrooms to post
    global $bedrooms, $isValidBedroom, $validBedrooms;
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
}

function validateBathrooms(){
  if(isset($_POST['bathrooms'])){
    // set variable bathrooms to post
    global $bathrooms, $isValidBathroom, $validBathrooms;
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
}

function validateParking(){
  if(isset($_POST['parking'])){
    // set variable parking to post
    global $parking, $isValidParking, $validParking;
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
}

function validateTownSearch(){
  if (isset($_POST['townSearch'])) {
    global $townSearch, $isValidTown, $townSearched, $validTown;
    $townSearch = $_POST['townSearch'];
    if (strlen($townSearch)  > 50 || $townSearch == '' ) {
      // invalid Town searched.
      $isValidTown = "is-invalid";
      $townSearched = false;
    }else{
      // if valid Town searched.
      $validTown = true;
    }
  }
}

function validateStartDate(){
  if(isset($_POST['startDate'])){
    global $startDate, $startDateFormated, $todaysDate, $validStartDate, $isValidStartDate;
    // set variable startDate to post
    $startDate = $_POST['startDate'];
    if ($startDate =='') {
      // Highlight that is invalid.
      $isValidStartDate = "is-invalid";
    }else {
      // need to test if start day is before current date.
      $startDateFormated =date("Y-m-d",strtotime($startDate));
      if ($startDateFormated >= $todaysDate) {
        $validStartDate = true;
        $isValidStartDate = "is-valid";
      }else {
        // Highlight that is invalid.
        $isValidStartDate = "is-invalid";
      }
    }
  }
}

function validateEndDate(){
  if(isset($_POST['endDate'])){
    global $endDate, $endDateFormated, $validEndDate, $isValidEndDate, $startDateFormated, $validStartDate;
    // set variable endDate to post
    $endDate = $_POST['endDate'];

    //last name not empty & max 40 chars.
    if ($endDate =='') {
      // Highlight that is invalid.
      $isValidEndDate = "is-invalid";
    }else {
      // not empty so chekc if end date is greater than start date.
      $endDateFormated =date("Y-m-d",strtotime($endDate));
      if($validStartDate == true && ($endDateFormated > $startDateFormated)){
        $validEndDate = true;
        $isValidEndDate = "is-valid";
      }else{
        // Highlight that is invalid.
        $isValidEndDate = "is-invalid";
      }
    }
  }
}

function validatePropertySelected(){
  if (isset($_POST['propertySelected'])) {
    global $eircode, $isValidEircode, $validEircode;
    $eircode = $_POST['propertySelected'];
    // valid Eircode & 7 chars long. and valid eircode
    if (strlen($eircode) != 7 || !isValidEircode($eircode)) {
      // Highlight that is invalid.
      $isValidEircode = "is-invalid";
    }else {
      $validEircode = true;
      $isValidEircode = "is-valid";
    }
  }
}


function calculateDaysOfRental(){
  // this function was used then incorporated into the validate Property to rent function.
  // calculte days of the rental: the / 60 * 60 * 24 is to turn into days value. since strtotime will give in seconds.
  global $daysOfRental,$startDate, $endDate;
  $daysOfRental = (int)(strtotime($endDate) - strtotime($startDate)) / (60 * 60 * 24);
}

function setCostOfRental(){
  // this function was used then incorporated into the validate Property to rent function.
  // set rent cost rounded to 2 decimals.
  global $rentCost,$rentalMonthPrice, $daysOfRental;
  $rentCost = round(($rentalMonthPrice/30)*$daysOfRental,2);
}

function validatePropertyToRent(){
  global $sqlProp,$eircode,$resultProp, $pdo, $datesNotAvailableMessage, $validPropertyRental,
  $rentalMonthPrice, $rentCost,$rentalMonthPrice, $daysOfRental, $startDate, $endDate;
  // calculte days of the rental: the / 60 * 60 * 24 is to turn into days value. since strtotime will give in seconds.
  $daysOfRental = (int)(strtotime($endDate) - strtotime($startDate)) / (60 * 60 * 24);
  try {
    $sqlProp = "SELECT * FROM properties where eircode = '$eircode'";
    $resultProp = $pdo->query($sqlProp);
    if ($resultProp->rowCount() == 0) {
      $datesNotAvailableMessage = "<h5 class ='mt-4'> Sorry Error finding property with matching eircode row count 0, please start search again. </h5>";
      $validPropertyRental = false;
    }else{
      while ($propRow = $resultProp->fetch())
        {
          $rentalMonthPrice = (float)$propRow['rent'];
        }
      if ($rentalMonthPrice > 0 && $daysOfRental > 0) {
        // set rent cost rounded to 2 decimals.
        $rentCost = round(($rentalMonthPrice/30)*$daysOfRental,2);
        // set rental to true. if it hits here then it will reload to where you can fill in the tenant details.
        $validPropertyRental = true;
      }
    }
  } catch (\Exception $e) {
    $datesNotAvailableMessage = "<h5 class ='mt-4'> Sorry Error finding property with matching eircode, please start search again. </h5>";
  }
}


 ?>
