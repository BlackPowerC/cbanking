-- MySQL dump 10.15  Distrib 10.0.34-MariaDB, for debian-linux-gnu (x86_64)
--
-- Host: 172.17.0.2    Database: test_cbanking
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

DROP TABLE IF EXISTS `Account`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Account` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT,
  `typeid` varchar(255) NOT NULL,
  `id_customer` bigint(20) NOT NULL,
  `id_employee` bigint(20) NOT NULL,
  `balance` double NOT NULL,
  `initialBalance` DOUBLE NOT NULL,
  `creationDate` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Account`
--

LOCK TABLES `Account` WRITE;
/*!40000 ALTER TABLE `Account` DISABLE KEYS */;
INSERT INTO `Account` VALUES (1,'Entity::SavingsAccount',8,4,35905,35905,'16-04-2018 14:57:15');
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
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `BaseOperation`
--

LOCK TABLES `BaseOperation` WRITE;
/*!40000 ALTER TABLE `BaseOperation` DISABLE KEYS */;
INSERT INTO `BaseOperation` VALUES (1,'Entity::Operation',1,4,'16-04-2018 15:02:20',12),(2,'Entity::Operation',1,4,'16-04-2018 15:02:24',45),(3,'Entity::Operation',1,4,'16-04-2018 15:02:27',63),(4,'Entity::Operation',1,4,'16-04-2018 15:02:29',785);
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
INSERT INTO `Customer` VALUES (1),(3),(5),(6),(8);
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
INSERT INTO `Employee` VALUES (4);
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
INSERT INTO `Operation` VALUES (1,0),(2,0),(3,0),(4,0);
/*!40000 ALTER TABLE `Operation` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Person`
--

DROP TABLE IF EXISTS `Person`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Person` (
  `id` BIGINT NOT NULL PRIMARY KEY AUTO_INCREMENT,
  `typeid` VARCHAR(255) NOT NULL,
  `name` VARCHAR(255) NOT NULL,
  `surname` VARCHAR(255) NOT NULL,
  `email` VARCHAR(255) NOT NULL,
  `passwd` VARCHAR(255) NOT NULL,
  `sexe` VARCHAR(255) NOT NULL,
  `id_token` INT NULL,
  UNIQUE KEY `email_i` (`email`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Person`
--

LOCK TABLES `Person` WRITE;
/*!40000 ALTER TABLE `Person` DISABLE KEYS */;
INSERT INTO `Person` VALUES
(1,'Entity::Customer','dalida','kodjo','dalida@gmail.com','2071312255312623918418924184408021410912872143222851187212201312441693321110823320671208209609313324217625513124210135126236479918549189716512212916556501222493921862','feminin', NULL),
(3,'Entity::Customer','thierrno','barry','thierrno@gmail.com','2071312255312623918418924184408021410912872143222851187212201312441693321110823320671208209609313324217625513124210135126236479918549189716512212916556501222493921862','masculin', NULL),
(4,'Entity::Employee','root','root','root@root.com','972421352182013417157156195134211362021111302237481562462191841041061691642551672311641131991552471431591461324511811919232038342282288294451827487105252130184235223210169','masculin', 1),
(5,'Entity::Customer','bawara','titianne','titianne@gmail.com','2071312255312623918418924184408021410912872143222851187212201312441693321110823320671208209609313324217625513124210135126236479918549189716512212916556501222493921862','feminin', NULL),
(6,'Entity::Customer','baba','samuelbaba@gmail.com','','2071312255312623918418924184408021410912872143222851187212201312441693321110823320671208209609313324217625513124210135126236479918549189716512212916556501222493921862','masculin',NULL),
(8,'Entity::Customer','fatigba','jordy','fatigba@jordy.com','972421352182013417157156195134211362021111302237481562462191841041061691642551672311641131991552471431591461324511811919232038342282288294451827487105252130184235223210169', 'masculin' ,2);
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
INSERT INTO `SavingsAccount` VALUES (1,12);
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
INSERT INTO `Session` VALUES (1,1523890032,3047780064),(2,1523890194,3047780388);
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
  PRIMARY KEY (`id`),
  UNIQUE KEY `token_i` (`token`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Token`
--

LOCK TABLES `Token` WRITE;
/*!40000 ALTER TABLE `Token` DISABLE KEYS */;
INSERT INTO `Token` VALUES (1,'Entity::Session',4,'23321425024549421161211921618911418213413092729622315176208194194234106118104173101211616736141415951461566075101219662762140166180182112771166623369121591147657224'),(2,'Entity::Session',8,'175215240642331023412261278211920295236179205219151107109165116110131108792151446316718820311314821492721671494314322599489752383724012623910832406420616268971943022842');
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
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2018-04-19  0:11:54
