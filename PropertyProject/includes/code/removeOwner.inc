<div class="remove-owner-form">
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
        if (isset($_POST['ownerSurname'])){
        $ownerSurname = $_POST['ownerSurname'];
        $sql = "SELECT ownerID, firstName, lastName, phone FROM owners where lastName like '%$ownerSurname%'";
        $result = $pdo->query($sql);
        if ($result->rowCount() == 0) {
          $hideSelect = "d-none";
          echo "<h5 class ='mt-4'> Sorry no Owners with matching surname found, please search another surname </h5>";

        }else{
        echo "<label for='ownerId'> Please Select an owner from the owners found below: </label>";
        echo("<select multiple='' class='form-select' name='ownerID'>");

        while ($row = $result->fetch()) {
        $ownID = $row['ownerID'];
        $owners = "$row[ownerID] , $row[firstName] $row[lastName] , $row[phone]";
        $ownersCount++;
        ?>

        <option value="<?php echo $ownID; ?>">
        <?php echo $owners; ?>

        </option>
        <?php }

        echo("</select>");
        }
        }


        }
        catch (PDOException $e) {

        $output = 'Unable to connect to the database server: ' . $e->getMessage() . ' in ' . $e->getFile() . ':' . $e->getLine();
        echo $output;
        }

       ?>

      </div>
    </div>
    <div class="form-buttons">
      <input class="btn btn-primary" type="submit" name="newForm" value="Start New Form"><input class="btn btn-warning <?php echo $hideSelect ?>" type="submit" name="removeOwner" value="Remove Selected Owner">
    </div>
  </form>
</div>
