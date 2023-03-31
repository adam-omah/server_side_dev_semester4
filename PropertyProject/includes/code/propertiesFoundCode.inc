<?php
$hideSelect = "";
try
{
  if (isset($_POST['townSearch']))
  {
    // search for properties in town.
    $townSearch = $_POST['townSearch'];
    $sql = "SELECT * FROM properties where town like '%$townSearch%' ORDER BY 'bedrooms'";
    $result = $pdo->query($sql);
    if ($result->rowCount() == 0)
    {
      $hideSelect = "d-none";
      echo "<h5 class ='mt-4'> Sorry no Properties in your town were found, please search another Town</h5>";
    }
    else
    {
      echo "<label for='propertySelected'> Please Select a Property from the available Properties found below: </label>";
      echo("<select multiple='' class='form-select' name='propertySelected'>");
      $propertyCount = 0;
        while ($row = $result->fetch())
        {
        //check if property is available for the dates:
        $propertyAvaialble = true;
        $propertyId= $row['eircode'];

        // check if property has rentals during these dates:
        try
        {
          // retrieve all rentals that are active with this eircode:
          $sql2 = "SELECT * FROM rentals where eircode = '$propertyId' and status = 'A'";
          $rentResult = $pdo->query($sql2);
          if ($rentResult->rowCount() == 0)
          {
            // no rentals are found, go ahead and rent the property
            // nothing to do here just continue on.
          }
          else
          {
            while ($rentRow = $rentResult->fetch())
              {
                $rentID = $rentRow['rentID'];
                $rentalFoundStart = $rentRow['startDate'];
                $rentalFoundEnd = $rentRow['endDate'];
                // now set this to date:

                $rentalFoundStartFormatted = date("Y-m-d",strtotime($rentalFoundStart));
                $rentalFoundEndFormatted = date("Y-m-d",strtotime($rentalFoundEnd));
                // check if new date hits any already rented dates:
                if (($startDateFormated <= $rentalFoundEndFormatted) && ($endDateFormated >= $rentalFoundStartFormatted))
                {
                  // if this condition is met then the property is rented during this period.
                  $propertyAvaialble = false;
                }
              }
            }
        }
        catch (\Exception $e)
        {
          echo "Problem Looking for rentals on this property with eircode: $propertyId";
        }
          if ($propertyAvaialble)
          {
            $property = "Eircode: $row[eircode] , beds: $row[bedrooms] , bathrooms: $row[bathrooms] , Monthly Rent: $row[rent], Parking Spaces: $row[parkingSpaces] ,Pets Allowed? $row[petsAllowed], Garden? $row[gardenspace], Owner Occupied? $row[ownerOccupied]";
            $propertyOption = "<option style='white-space: pre-wrap;' value='$propertyId'> $property </option>";
            echo $propertyOption;
            $propertyCount++;
          }
        }
      echo("</select>");
      if ($propertyCount == 0)
      {
        $hideSelect = "d-none";
        echo "<h5 class ='mt-4'> Sorry no Properties in your town were available for your dates, please search another Town or dates.</h5>";
      }
    }
  }
}
catch (PDOException $e)
{
$output = 'Unable to connect to the database server: ' . $e->getMessage() . ' in ' . $e->getFile() . ':' . $e->getLine();
echo "$output";
}

?>
