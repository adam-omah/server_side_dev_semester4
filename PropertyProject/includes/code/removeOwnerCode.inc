<?php

$parentPage="removeOwner.php";

$ownerRemoved = false;

if (isset($_POST['newForm'])) {
  // Reset the Form and post data if starting new property.
  unset($_POST);
}
// remove owner was called.
if(isset($_POST['removeOwner'])){
  if (isset($_POST['ownerID'])) {
    $ownerID = $_POST['ownerID'];
    //try to connect to db and search if onwer is in a property
    try {

    $pdo = new PDO('mysql:host=localhost;dbname=propertyrental; charset=utf8', 'root', '');

    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    $sql = 'DELETE FROM owners WHERE ownerID = :oid';

    $result = $pdo->prepare($sql);

    $result->bindValue(':oid', $_POST['ownerID']);

    $result->execute();

    $ownerRemoved = true;

    }

    catch (PDOException $e) {
      // remove failed, dont change ownerRemoved bool
    }
  }
}

 ?>
