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
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `owners`
--

LOCK TABLES `owners` WRITE;
/*!40000 ALTER TABLE `owners` DISABLE KEYS */;
INSERT INTO `owners` VALUES (1,'Adam','O\'Mahony','555555555','adamtest@gmail.com','v92cccc','A');
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
INSERT INTO `properties` VALUES ('v92ffff','Causeway','The Cottage Slievebwee','testing',500.20,10,10,10,'Y','Y','N','A',1,'Semi Detatched');
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
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `rentals`
--

LOCK TABLES `rentals` WRITE;
/*!40000 ALTER TABLE `rentals` DISABLE KEYS */;
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
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tenants`
--

LOCK TABLES `tenants` WRITE;
/*!40000 ALTER TABLE `tenants` DISABLE KEYS */;
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

-- Dump completed on 2023-03-31 19:56:56
