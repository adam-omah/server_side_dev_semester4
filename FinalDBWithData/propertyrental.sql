-- MariaDB dump 10.19  Distrib 10.4.27-MariaDB, for Win64 (AMD64)
--
-- Host: localhost    Database: propertyrental
-- ------------------------------------------------------
-- Server version	10.4.27-MariaDB

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `owners`
--

DROP TABLE IF EXISTS `owners`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `owners` (
  `ownerID` smallint(5) unsigned NOT NULL AUTO_INCREMENT,
  `firstName` char(30) NOT NULL,
  `lastName` char(40) NOT NULL,
  `phone` varchar(15) NOT NULL,
  `email` varchar(50) NOT NULL,
  `eircode` char(7) NOT NULL,
  `status` char(1) NOT NULL DEFAULT 'A',
  PRIMARY KEY (`ownerID`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `owners`
--

LOCK TABLES `owners` WRITE;
/*!40000 ALTER TABLE `owners` DISABLE KEYS */;
INSERT INTO `owners` VALUES (4,'Adam','O\'Testing','087777777777','adam@testing.com','V92CCCC','A'),(5,'Helena','O\'Testing','0877777777777','Helena@testing.com','V92CCCC','A'),(6,'John','Tested','08999999999999','john@tested.com','V92FFFF','A'),(7,'Anne','Tests','089999999999','anne@tests.com','V92HHHH','A');
/*!40000 ALTER TABLE `owners` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `properties`
--

DROP TABLE IF EXISTS `properties`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `properties` (
  `eircode` char(7) NOT NULL,
  `town` char(50) NOT NULL,
  `address` varchar(100) NOT NULL,
  `description` varchar(200) NOT NULL,
  `rent` decimal(10,2) NOT NULL CHECK (`rent` > 0),
  `bedrooms` tinyint(2) unsigned NOT NULL DEFAULT 0 CHECK ('bedrooms' >= 0),
  `bathrooms` tinyint(2) unsigned NOT NULL DEFAULT 0 CHECK ('bathrooms' >= 0),
  `parkingSpaces` tinyint(2) unsigned NOT NULL DEFAULT 0 CHECK ('parkingSpaces' >= 0),
  `gardenspace` char(1) NOT NULL DEFAULT 'N' CHECK (`gardenspace` = 'N' or `gardenspace` = 'Y'),
  `petsAllowed` char(1) NOT NULL DEFAULT 'N' CHECK (`petsAllowed` = 'N' or `petsAllowed` = 'Y'),
  `ownerOccupied` char(1) NOT NULL DEFAULT 'N' CHECK (`ownerOccupied` = 'N' or `ownerOccupied` = 'Y'),
  `status` char(1) NOT NULL DEFAULT 'A' CHECK (`status` = 'A' or `status` = 'U'),
  `ownerID` smallint(5) unsigned NOT NULL,
  `type` varchar(30) NOT NULL,
  PRIMARY KEY (`eircode`),
  KEY `ownerID` (`ownerID`),
  CONSTRAINT `properties_ibfk_1` FOREIGN KEY (`ownerID`) REFERENCES `owners` (`ownerID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `properties`
--

LOCK TABLES `properties` WRITE;
/*!40000 ALTER TABLE `properties` DISABLE KEYS */;
INSERT INTO `properties` VALUES ('V92AAAA','Tralee','5 Sea View','Sea front property, near the town',1255.45,6,2,1,'N','N','Y','A',7,'Semi Detatched'),('V92CCCC','Tralee','12 park view ','Town House with view of park',850.50,5,2,0,'Y','Y','Y','A',4,'Semi Detatched'),('V92FFFF','Tralee','45 windmill lane','Terraced House near the city',600.00,2,1,2,'N','Y','N','A',6,'Semi Detatched'),('V93FFFF','Kilarney','3 park lane','apartment on the way to the park',900.00,3,1,0,'N','N','N','A',4,'Apartment');
/*!40000 ALTER TABLE `properties` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `rentals`
--

DROP TABLE IF EXISTS `rentals`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `rentals` (
  `rentID` smallint(7) unsigned NOT NULL AUTO_INCREMENT,
  `startDate` date NOT NULL,
  `endDate` date NOT NULL,
  `status` char(1) NOT NULL DEFAULT 'A',
  `eircode` char(7) NOT NULL,
  `tenantID` smallint(5) unsigned NOT NULL,
  `rentCost` decimal(10,2) NOT NULL CHECK (`rentCost` > 0),
  PRIMARY KEY (`rentID`),
  KEY `fk_rental_tenant` (`tenantID`),
  KEY `fk_rental_prop` (`eircode`),
  CONSTRAINT `fk_rental_prop` FOREIGN KEY (`eircode`) REFERENCES `properties` (`eircode`),
  CONSTRAINT `fk_rental_tenant` FOREIGN KEY (`tenantID`) REFERENCES `tenants` (`tenantID`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `rentals`
--

LOCK TABLES `rentals` WRITE;
/*!40000 ALTER TABLE `rentals` DISABLE KEYS */;
INSERT INTO `rentals` VALUES (1,'2023-06-20','2023-07-30','A','V93FFFF',1,1200.00),(2,'2023-06-20','2023-06-30','A','V92AAAA',2,418.48);
/*!40000 ALTER TABLE `rentals` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tenants`
--

DROP TABLE IF EXISTS `tenants`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `tenants` (
  `tenantID` smallint(5) unsigned NOT NULL AUTO_INCREMENT,
  `firstName` char(30) NOT NULL,
  `lastName` char(40) NOT NULL,
  `phone` varchar(15) NOT NULL,
  `email` varchar(50) NOT NULL,
  `status` char(1) NOT NULL DEFAULT 'A',
  PRIMARY KEY (`tenantID`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tenants`
--

LOCK TABLES `tenants` WRITE;
/*!40000 ALTER TABLE `tenants` DISABLE KEYS */;
INSERT INTO `tenants` VALUES (1,'Adam','O\'Tested','08777777777','adam@test.com','A'),(2,'John','Tested','089999999','john@testing.com','A');
/*!40000 ALTER TABLE `tenants` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2023-04-05 23:44:37
