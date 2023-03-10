<div class="find-owner-form">
  <!-- this $parentPage allows the re-use of the find owner function. -->
  <form class="" action="<?php echo $parentPage; ?>" method="post">
    <div class="form-group row">
      <div class="col-md-10">
        <label for="ownerId"> Please Select an owner from the owners found below: </label>
        <?php
        try {
        $pdo = new PDO('mysql:host=localhost;dbname=propertyrental; charset=utf8', 'root', '');
        $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
        if (isset($_POST['ownerSurname'])){
        $ownerSurname = $_POST['ownerSurname'];
        $sql = "SELECT ownerID, firstName, lastName, phone FROM owners where lastName like '%$ownerSurname%'";
        $result = $pdo->query($sql);
        echo("<select name='ownerID'>");

        while ($row = $result->fetch()) {
        $bt = "$row[ownerID] , $row[firstName] $row[lastName] , $row[phone]";
        ?>

        <option value="<?php echo $bt; ?>">
        <?php echo $bt; ?>

        </option>
        <?php }

        echo("</select>");
        }

        }
        catch (PDOException $e) {
        $output = 'Unable to connect to the database server: ' . $e->getMessage() . ' in ' . $e->getFile() . ':' . $e->getLine();
        }
       ?>

      </div>
    </div>
    <div class="form-buttons">
      <input class="btn btn-primary" type="submit" name="newForm" value="Start New Form"><input class="btn btn-primary" type="submit" name="selectOwner" value="Select Owner">
    </div>
  </form>
</div>
