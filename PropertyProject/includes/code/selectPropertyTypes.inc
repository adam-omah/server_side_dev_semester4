<?php
try {

  // try make a connection, try search for surnames.
$pdo = new PDO('mysql:host=localhost;dbname=propertyrental; charset=utf8', 'root', '');
$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
$sql = "SELECT * FROM propertytypes";
$result = $pdo->query($sql);
if ($result->rowCount() == 0) {
  $hideSelect = "d-none";
  echo "<h5 class ='mt-4'> Sorry no Property Types are added, please add one to start. </h5>";

}else{
echo "<label for='ownerId'> Please Select an owner from the owners found below: </label>";
echo("<select class='form-select' name='propertyType'>");

while ($row = $result->fetch()) {
$typeCode = $row['typeCode'];
$type = "$row[typeCode] - $row[description]";
?>

<option value="<?php echo $typeCode; ?>">
<?php echo $type; ?>

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
 ?>
