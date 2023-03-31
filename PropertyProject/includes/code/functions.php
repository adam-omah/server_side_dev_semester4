<!-- Here is the functions for my project, mainly validation or re-useable function -->
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
// this code is not used but was an attempt to move valid end date into a seperate function
function validateEndDate($validStartDate, $endDate, $isValidEndDate,$validEndDate,$startDateFormated, $endDateFormated){
  if(isset($_POST['endDate'])){
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
// this code is not used but was an attempt to move valid start date into a seperate function
function validateStartDate($startDate,$isValidStartDate,$validStartDate,$startDateFormated){
  if(isset($_POST['startDate'])){
    // set variable startDate to post
    $startDate = $_POST['startDate'];
    if ($startDate =='') {
      // Highlight that is invalid.
      $isValidStartDate = "is-invalid";
    }else {
      $todaysDate = $todaysDate = date("Y-m-d");
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

 ?>
