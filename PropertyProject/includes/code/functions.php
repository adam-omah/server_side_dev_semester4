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
 ?>
