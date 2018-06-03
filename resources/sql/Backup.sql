-- MySQL dump 10.15  Distrib 10.0.34-MariaDB, for debian-linux-gnu (x86_64)
--
-- Host: 172.17.0.3    Database: test_cbanking
-- ------------------------------------------------------
-- Server version	5.7.12

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `Account`
--

DROP TABLE IF EXISTS `News`;

CREATE TABLE `News` (
  `id` BIGINT NOT NULL PRIMARY KEY AUTO_INCREMENT,
  `title` VARCHAR(127) NOT NULL,
  `date` VARCHAR(127) NOT NULL,
  `text` TEXT NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;


DROP TABLE IF EXISTS `Account`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Account` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT,
  `typeid` varchar(255) NOT NULL,
  `id_customer` bigint(20) NOT NULL,
  `id_employee` bigint(20) NOT NULL,
  `balance` double NOT NULL,
  `initialBalance` double NOT NULL,
  `creationDate` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Account`
--

LOCK TABLES `Account` WRITE;
/*!40000 ALTER TABLE `Account` DISABLE KEYS */;
/*!40000 ALTER TABLE `Account` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `BaseOperation`
--

DROP TABLE IF EXISTS `BaseOperation`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `BaseOperation` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT,
  `typeid` varchar(255) NOT NULL,
  `id_account` bigint(20) NOT NULL,
  `id_employee` bigint(20) NOT NULL,
  `date` varchar(255) NOT NULL,
  `montant` double NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `BaseOperation`
--

LOCK TABLES `BaseOperation` WRITE;
/*!40000 ALTER TABLE `BaseOperation` DISABLE KEYS */;
/*!40000 ALTER TABLE `BaseOperation` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `CurrentAccount`
--

DROP TABLE IF EXISTS `CurrentAccount`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `CurrentAccount` (
  `id` bigint(20) NOT NULL,
  `overdraft` double NOT NULL,
  PRIMARY KEY (`id`),
  CONSTRAINT `CurrentAccount_id_fk` FOREIGN KEY (`id`) REFERENCES `Account` (`id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `CurrentAccount`
--

LOCK TABLES `CurrentAccount` WRITE;
/*!40000 ALTER TABLE `CurrentAccount` DISABLE KEYS */;
/*!40000 ALTER TABLE `CurrentAccount` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Customer`
--

DROP TABLE IF EXISTS `Customer`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Customer` (
  `id` bigint(20) NOT NULL,
  PRIMARY KEY (`id`),
  CONSTRAINT `Customer_id_fk` FOREIGN KEY (`id`) REFERENCES `Person` (`id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Customer`
--

LOCK TABLES `Customer` WRITE;
/*!40000 ALTER TABLE `Customer` DISABLE KEYS */;
INSERT INTO `Customer` VALUES (9),(10),(11),(13),(14);
/*!40000 ALTER TABLE `Customer` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Employee`
--

DROP TABLE IF EXISTS `Employee`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Employee` (
  `id` bigint(20) NOT NULL,
  PRIMARY KEY (`id`),
  CONSTRAINT `Employee_id_fk` FOREIGN KEY (`id`) REFERENCES `Person` (`id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Employee`
--

LOCK TABLES `Employee` WRITE;
/*!40000 ALTER TABLE `Employee` DISABLE KEYS */;
INSERT INTO `Employee` VALUES (12);
/*!40000 ALTER TABLE `Employee` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Employee_subordinate`
--

DROP TABLE IF EXISTS `Employee_subordinate`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Employee_subordinate` (
  `object_id` bigint(20) NOT NULL,
  `index` bigint(20) unsigned NOT NULL,
  `value` bigint(20) DEFAULT NULL,
  KEY `object_id_i` (`object_id`),
  KEY `index_i` (`index`),
  CONSTRAINT `Employee_subordinate_object_id_fk` FOREIGN KEY (`object_id`) REFERENCES `Employee` (`id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Employee_subordinate`
--

LOCK TABLES `Employee_subordinate` WRITE;
/*!40000 ALTER TABLE `Employee_subordinate` DISABLE KEYS */;
/*!40000 ALTER TABLE `Employee_subordinate` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Group`
--

DROP TABLE IF EXISTS `Group`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Group` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Group`
--

LOCK TABLES `Group` WRITE;
/*!40000 ALTER TABLE `Group` DISABLE KEYS */;
/*!40000 ALTER TABLE `Group` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Group_members`
--

DROP TABLE IF EXISTS `Group_members`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Group_members` (
  `object_id` bigint(20) NOT NULL,
  `value` bigint(20) DEFAULT NULL,
  KEY `object_id_i` (`object_id`),
  CONSTRAINT `Group_members_object_id_fk` FOREIGN KEY (`object_id`) REFERENCES `Group` (`id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Group_members`
--

LOCK TABLES `Group_members` WRITE;
/*!40000 ALTER TABLE `Group_members` DISABLE KEYS */;
/*!40000 ALTER TABLE `Group_members` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Operation`
--

DROP TABLE IF EXISTS `Operation`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Operation` (
  `id` bigint(20) NOT NULL,
  `typeOperation` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  CONSTRAINT `Operation_id_fk` FOREIGN KEY (`id`) REFERENCES `BaseOperation` (`id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Operation`
--

LOCK TABLES `Operation` WRITE;
/*!40000 ALTER TABLE `Operation` DISABLE KEYS */;
/*!40000 ALTER TABLE `Operation` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Person`
--

DROP TABLE IF EXISTS `Person`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Person` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT,
  `typeid` varchar(255) NOT NULL,
  `name` varchar(255) NOT NULL,
  `surname` varchar(255) NOT NULL,
  `email` varchar(255) NOT NULL,
  `passwd` varchar(255) NOT NULL,
  `sexe` varchar(255) NOT NULL,
  `id_token` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `email_i` (`email`)
) ENGINE=InnoDB AUTO_INCREMENT=15 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Person`
--

LOCK TABLES `Person` WRITE;
/*!40000 ALTER TABLE `Person` DISABLE KEYS */;
INSERT INTO `Person` VALUES (9,'Entity::Customer','dalida','kodjo','dalida@gmail.com','C8E37EBBF525D680D2E0051D8FA2D6EC4DD358FBF81D87E26B3B4478A337F2D3','feminin',NULL),(10,'Entity::Customer','nabine','sabine','nabin@gmail.com','C8E37EBBF525D680D2E0051D8FA2D6EC4DD358FBF81D87E26B3B4478A337F2D3','feminin',NULL),(11,'Entity::Customer','thierrno','barry','thierrno@gmail.com','C8E37EBBF525D680D2E0051D8FA2D6EC4DD358FBF81D87E26B3B4478A337F2D3','masculin',NULL),(12,'Entity::Employee','root','root','root@root.com','6F8DC2A043C8D2C68D039FDB66AAFAEA7C9F8990F77C0C521E552B456F8BEDDA','masculin',3),(13,'Entity::Customer','bawara','titianne','titianne@gmail.com','C8E37EBBF525D680D2E0051D8FA2D6EC4DD358FBF81D87E26B3B4478A337F2D3','feminin',NULL),(14,'Entity::Customer','baba','samuelbaba@gmail.com','','732ADBBAFC12A2DC678A0A5B5EDE387708C3CF2383B83CF4805534CB9B12085F','',NULL);
/*!40000 ALTER TABLE `Person` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ReloadSession`
--

DROP TABLE IF EXISTS `ReloadSession`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ReloadSession` (
  `id` int(11) NOT NULL,
  `reloaded` tinyint(1) NOT NULL,
  PRIMARY KEY (`id`),
  CONSTRAINT `ReloadSession_id_fk` FOREIGN KEY (`id`) REFERENCES `Token` (`id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ReloadSession`
--

LOCK TABLES `ReloadSession` WRITE;
/*!40000 ALTER TABLE `ReloadSession` DISABLE KEYS */;
/*!40000 ALTER TABLE `ReloadSession` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `SavingsAccount`
--

DROP TABLE IF EXISTS `SavingsAccount`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `SavingsAccount` (
  `id` bigint(20) NOT NULL,
  `rate` double NOT NULL,
  PRIMARY KEY (`id`),
  CONSTRAINT `SavingsAccount_id_fk` FOREIGN KEY (`id`) REFERENCES `Account` (`id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `SavingsAccount`
--

LOCK TABLES `SavingsAccount` WRITE;
/*!40000 ALTER TABLE `SavingsAccount` DISABLE KEYS */;
/*!40000 ALTER TABLE `SavingsAccount` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Session`
--

DROP TABLE IF EXISTS `Session`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Session` (
  `id` int(11) NOT NULL,
  `begin` bigint(20) unsigned NOT NULL,
  `end` bigint(20) unsigned NOT NULL,
  PRIMARY KEY (`id`),
  CONSTRAINT `Session_id_fk` FOREIGN KEY (`id`) REFERENCES `Token` (`id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Session`
--

LOCK TABLES `Session` WRITE;
/*!40000 ALTER TABLE `Session` DISABLE KEYS */;
INSERT INTO `Session` VALUES (3,1526170122,3052340244);
/*!40000 ALTER TABLE `Session` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Token`
--

DROP TABLE IF EXISTS `Token`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Token` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `typeid` varchar(255) NOT NULL,
  `id_person` int(11) DEFAULT NULL,
  `token` varchar(255) NOT NULL,
  `appInstanceId` VARCHAR(511) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `token_i` (`token`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Token`
--

LOCK TABLES `Token` WRITE;
/*!40000 ALTER TABLE `Token` DISABLE KEYS */;
INSERT INTO `Token` VALUES (3,'Entity::Session',12,'EDFF32707D057B88546D0BDCCE676A007A2080599346D4138ABB7474E473743E', '');
/*!40000 ALTER TABLE `Token` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Virement`
--

DROP TABLE IF EXISTS `Virement`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Virement` (
  `id` bigint(20) NOT NULL,
  `id_account` bigint(20) DEFAULT NULL,
  PRIMARY KEY (`id`),
  CONSTRAINT `Virement_id_fk` FOREIGN KEY (`id`) REFERENCES `BaseOperation` (`id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Virement`
--

LOCK TABLES `Virement` WRITE;
/*!40000 ALTER TABLE `Virement` DISABLE KEYS */;
/*!40000 ALTER TABLE `Virement` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ci_sessions`
--

DROP TABLE IF EXISTS `ci_sessions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ci_sessions` (
  `id` varchar(128) NOT NULL,
  `ip_address` varchar(45) NOT NULL,
  `timestamp` int(10) unsigned NOT NULL DEFAULT '0',
  `data` blob NOT NULL,
  KEY `ci_sessions_timestamp` (`timestamp`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ci_sessions`
--

LOCK TABLES `ci_sessions` WRITE;
/*!40000 ALTER TABLE `ci_sessions` DISABLE KEYS */;
/*!40000 ALTER TABLE `ci_sessions` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2018-05-14 13:10:52
