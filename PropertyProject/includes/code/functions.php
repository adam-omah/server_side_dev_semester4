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

 ?>
