<div class="select-Property-form">
  <!-- this $parentPage allows the re-use of the find owner function. -->
  <form class="" action="<?php echo $parentPage; ?>" method="post">
    <div class="form-group row">
      <div class="col-md-12">
        <?php
        $hideSelect = "";
        try {

          // try make a connection, try search for surnames.
        $pdo = new PDO('mysql:host=localhost;dbname=propertyrental; charset=utf8', 'root', '');
        $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
        if (isset($_POST['townSearch'])){
        $townSearch = $_POST['townSearch'];
        $sql = "SELECT * FROM properties where town like '%$townSearch%' ORDER BY 'bedrooms'";
        $result = $pdo->query($sql);
        if ($result->rowCount() == 0) {
          $hideSelect = "d-none";
          echo "<h5 class ='mt-4'> Sorry no Properties with matching Town found, please search another Town</h5>";

        }else{
        echo "<label for='propertySelected'> Please Select a Property from the Properties found below: </label>";
        echo("<select multiple='' class='form-select' name='propertySelected'>");

        while ($row = $result->fetch()) {
        $propertyId = $row['eircode'];
        $property = "Eircode: $row[eircode] , beds: $row[bedrooms] , bathrooms: $row[bathrooms] , Monthly Rent: $row[rent], Parking Spaces: $row[parkingSpaces] ,Pets Allowed? $row[petsAllowed], Garden? $row[gardenspace], Owner Occupied? $row[ownerOccupied]";
        ?>

        <option style="white-space: pre-wrap;" value="<?php echo $propertyId; ?>">
        <?php echo $property; ?>

        </option>
        <?php }

        echo("</select>");
        }
        }


        }
        catch (PDOException $e) {
        $output = 'Unable to connect to the database server: ' . $e->getMessage() . ' in ' . $e->getFile() . ':' . $e->getLine();
        echo "$output";
        }

       ?>

      </div>
    </div>
    <div class="form-buttons">
      <input class="btn btn-primary" type="submit" name="newForm" value="Start New Form"><input class="btn btn-primary <?php echo $hideSelect ?>" type="submit" name="selectProperty" value="Rent Selected Property">
    </div>
  </form>
</div>
