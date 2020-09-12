-- phpMyAdmin SQL Dump
-- version 4.8.3
-- https://www.phpmyadmin.net/
--
-- Hôte : 127.0.0.1
-- Généré le :  lun. 06 mai 2019 à 01:24
-- Version du serveur :  10.1.36-MariaDB
-- Version de PHP :  7.2.11

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `boutique`
--

-- --------------------------------------------------------

--
-- Structure de la table `categories`
--

CREATE TABLE `categories` (
  `idCategorie` int(11) NOT NULL,
  `nomCategorie` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `categories`
--

INSERT INTO `categories` (`idCategorie`, `nomCategorie`) VALUES
(1, 'Adidas'),
(2, 'Fila'),
(3, 'Nike'),
(4, 'Jordan');

-- --------------------------------------------------------

--
-- Structure de la table `produits`
--

CREATE TABLE `produits` (
  `idProduit` int(11) NOT NULL,
  `nomProduit` varchar(255) NOT NULL,
  `descriptionProduit` text NOT NULL,
  `prix` int(11) NOT NULL,
  `imageProduit` varchar(255) NOT NULL,
  `idCategorie` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `produits`
--

INSERT INTO `produits` (`idProduit`, `nomProduit`, `descriptionProduit`, `prix`, `imageProduit`, `idCategorie`) VALUES
(1, 'Nike Tanjun', 'Baptisée d\'après le terme japonais signifiant « simplicité », la chaussure Nike Tanjun pour Femme présente un design élégant et moderne pour un look chic au quotidien.', 42250, 'Produits/nike1.jpg', 3),
(2, 'Nike Epic React Phantom - Homme Chaussures', '- Couleur : Black-Black-White\r\n- Documentation : Flyknit\r\n- Code produit : 314206017304', 97500, 'Produits/nike2.png', 3),
(3, 'Nike KD 12 - Homme Chaussures', 'Couleur : Black-Metallic Silver-White\r\nDocumentation : Maille/synthétique\r\nCode produit : 314100134304', 97500, 'Produits/nike3.png', 3),
(4, 'Jordan Executive - Homme Chaussures', 'Couleur : White-Red-Black\r\nDocumentation : Textile, Cuir, Synthétique\r\nCode produit : 314100112904', 65000, 'Produits/jordan1.png', 4),
(5, 'FILA\r\nbaskets montantes classiques', 'Baskets montantes classiques Fila avec contrefort contrastant, fermeture à lacer sur le devant, étiquette logo et semelle crantée en caoutchouc. Couleur : blanc', 176000, 'Produits/fila1.jpg', 2),
(6, 'FILA\r\nbaskets V94M', 'Baskets V94M Fila avec bout rond et fermeture à lacer sur le devant. Couleur : orange.', 78650, 'Produits/fila2.jpg', 2),
(7, 'FILA\r\nbaskets montantes F-13', 'Baskets montantes F-13 Fila avec bout rond, perforations décoratives, fermeture à lacer sur le devant, a touch strap fastening, patch logo sur la languette, hauteur cheville et semelle plate en caoutchouc. Couleur : rouge.', 63500, 'Produits/fila3.jpg', 2),
(8, 'FILA\r\nbaskets à logo', 'Baskets à logo en cuirs Fila. Couleur : noir.', 78650, 'Produits/fila4.jpg', 2),
(9, 'Tennis Fila Lightstep Comfort Feminin', 'Le Light Step Comfort Tennis pour femmes est un modèle léger et confortable qui séduit par son style. Son cuir en tissu avec matière synthétique pour structurer la chaussure et le tissu, ce qui permet la respiration correcte de la peau. La semelle EVA est légère et robuste, s\'adapte à la forme de la foulée pour assurer le confort.', 116935, 'Produits/fila5.jpg', 2),
(10, 'Adidas Nmd_r1 Primeknit\r\nSneaker Basses Femme', 'Dessus: Synthétique\r\nDoublure: Textile\r\nSemelle intérieure: Textile\r\nMatériau de semelle: Caoutchouc\r\nType de talons: Plat\r\nLargeur de la chaussure: Normal\r\nFermeture: Lacets', 69650, 'Produits/adidas1.jpg', 1),
(11, 'Adidas NMD R1 Basket Mode Homme', 'Dessus: Synthétique\r\nDoublure: Synthétique\r\nSemelle intérieure: Synthétique\r\nMatériau de semelle: Synthétique\r\nType de talons: Plat\r\nHauteur de la tige : 3 pouces\r\nLargeur de la chaussure: Normal\r\nSemelle: neutral\r\nFermeture: Lacets', 54600, 'Produits/adidas2.png', 1),
(12, 'adidas NMD_r1 W, Chaussures de Gymnastique Femme', 'Dessus: Autres Cuir\r\nDoublure: Synthétique\r\nSemelle intérieure: Synthétique\r\nMatériau de semelle: Caoutchouc\r\nType de talons: Sans talon\r\nLargeur de la chaussure: Normal\r\nFermeture: Lacets', 57135, 'Produits/adidas3.png', 1),
(13, 'adidas NMD_R1 W Chaussures Femme Bordeaux', 'Boost est l\'amorti le plus réactif\r\nÉléments EVA préformés sur la semelle intermédiaire\r\nDesign classique à 3 bandes\r\nLes baskets NMD_R1 pour femmes d\'Adidas offrent beaucoup de confort pour les circuits de découverte urbains.', 52325, 'Produits/adidas4.jpg', 1),
(14, 'adidas ZX Flux, Baskets Homme', 'Dessus: Synthétique\r\nDoublure: Textile\r\nSemelle intérieure: Synthétique\r\nMatériau de semelle: Caoutchouc\r\nSemelle intérieure amovible: false\r\nType de talons: Plat\r\nHauteur de talons: 2 centimètres\r\nLargeur de la chaussure: Regular\r\nFoulée: Neutral\r\nType de surface: Road\r\nSemelle: Flat\r\nFermeture: Lacets', 38610, 'Produits/adidas5.jpg', 1),
(15, 'adidas Swift Run, Chaussures de Fitness Homme', 'Dessus: Synthétique\r\nDoublure: Synthétique\r\nSemelle intérieure: Synthétique\r\nMatériau de semelle: Synthétique\r\nType de talons: Plat\r\nHauteur de talons: 2 centimètres\r\nLargeur de la chaussure: Normal\r\nType de surface: Road\r\nFermeture: Lacets', 36650, 'Produits/adidas6.jpg', 1),
(16, 'Fila Chaussure Sport Montante 95 pour Hommes, en Cuir Blanc ', 'Dessus: Autres Cuir\r\nFermeture: Lacets', 65000, 'Produits/fila6.jpg', 2),
(17, 'Nike NIKEAO2649-301\r\nHomme Jordan DNA LX Cargo Kaki/Voile Ao2649-301 Homme', 'Dessus: Synthétique\r\nFermeture: Lacets', 51350, 'Produits/jordan2.jpg', 4),
(18, 'Jordan Eclipse Lea Homme Chaussures Noir Jordan', 'Dessus: Synthétique\r\nDoublure: Textile,Cuir naturel\r\nMatériau de semelle: Synthétique\r\nFermeture: Lacets\r\n', 59500, 'Produits/jordan3.jpg', 4),
(19, 'Nike Air Jordan Future, Chaussures de Basketball Homme', 'Dessus: Autres Cuir\r\nDoublure: Synthétique\r\nMatériau de semelle: Caoutchouc\r\nType de talons: Plat\r\nLargeur de la chaussure: Normal\r\nFermeture: Lacets', 55250, 'Produits/jordan4.jpg', 4),
(20, 'NIKE Air Jordan Eclipse Chukka Messieurs Light-Bone Chaussures Homme Sneaker Baskets', 'Dessus: Synthétique\r\nDoublure: Textile\r\nSemelle intérieure: Synthétique\r\nMatériau de semelle: Synthétique\r\nType de talons: Plat\r\nLargeur de la chaussure: Regular\r\nFermeture: Lacets', 51935, 'Produits/jordan5.jpg', 4),
(21, 'AIR Jordan 11 Retro Low GS', 'AIR Jordan 11 Retro Low GS \'Snakeskin\' - CD6847-102', 211300, 'Produits/jordan6.jpg', 4),
(22, 'Nike AIR Max DIA Se White/DK Turquoise-Blue Force-White', 'Couleur: White/Dk Turquoise-blue\r\nDessus: N/A\r\nDoublure: N/A', 84500, 'Produits/nike4.jpg', 3),
(23, 'Nike Downshifter 9, Chaussures d\'Athlétisme Homme', 'Dessus: Synthétique\r\nDoublure: Synthétique\r\nSemelle intérieure: Synthétique\r\nMatériau de semelle: Synthétique\r\nFermeture: Lacets', 29800, 'Produits/nike5.jpg', 3),
(24, 'Nike Chaussure de Running React Element 55 - CD1503-001', 'Couleur: Gris\r\nDessus: Synthétique\r\nMatériau de semelle: Synthétique\r\nType de talons: Plat\r\nLargeur de la chaussure: Normal', 72400, 'Produits/nike6.jpg', 3);

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `categories`
--
ALTER TABLE `categories`
  ADD PRIMARY KEY (`idCategorie`);

--
-- Index pour la table `produits`
--
ALTER TABLE `produits`
  ADD PRIMARY KEY (`idProduit`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `categories`
--
ALTER TABLE `categories`
  MODIFY `idCategorie` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT pour la table `produits`
--
ALTER TABLE `produits`
  MODIFY `idProduit` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=25;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
