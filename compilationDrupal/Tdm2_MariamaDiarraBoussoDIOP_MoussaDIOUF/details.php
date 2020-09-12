<!doctype html>
<html lang="fr">
  <head>
    <meta charset = "utf-8">
    <title>Accueil</title>
    <link rel="stylesheet" href="bootstrap.css"/>
    <script type="text/javascript" src="Jquery2.js"></script>
    <script type="text/javascript" src="bootstrap.js"></script>
  </head>

  <body>
    <?php include("header.php"); ?>
    <hr>
    <?php
      echo $_GET["idProduit"];
      $requete = "SELECT * from produits where idProduit = ".$_GET["idProduit"];
      $result = mysqli_query($maBase,$requete);

      $nbLigne = mysqli_num_rows($result);
      $ligne = mysqli_fetch_array($result);
     ?>
    <!-- Page Content -->
    <div class="container">

      <!-- Portfolio Item Heading -->
      <h1 class="my-4"><?php echo $ligne["nomProduit"]; ?></h1>

      <!-- Portfolio Item Row -->
      <div class="row">

        <div class="col-md-8">
          <img class="img-fluid" src="<?php echo $ligne["imageProduit"]; ?>" alt="">
        </div>

        <div class="col-md-4">
          <h3 class="my-3">Description</h3>
          <p><?php echo $ligne["descriptionProduit"]; ?></p>
          <h3 class="my-3"><?php echo $ligne["prix"]; ?> CFA</h3>

        </div>

      </div>
      <!-- /.row -->

      <!-- Related Projects Row -->
      <h3 class="my-4">Nouveaux articles</h3>
      <div class="row">
        <?php
        $requete = "SELECT* from produits where idProduit <> ".$_GET["idProduit"]." limit 4";
        $result = mysqli_query($maBase,$requete);
        $nbLigne = mysqli_num_rows($result);


        while (($ligne = mysqli_fetch_array($result))) {   ?>
          <div class="col-md-3 col-sm-6 mb-4">
            <a href="details.php?idProduit= <?php echo $ligne["idProduit"]; ?>">
                  <img class="img-fluid" src="<?php echo $ligne["imageProduit"] ;?>" alt="">
                </a>
          </div>
        <?php }?>





        <div class="col-md-3 col-sm-6 mb-4">
          <a href="#">
                <img class="img-fluid" src="http://placehold.it/500x300" alt="">
              </a>
        </div>

        <div class="col-md-3 col-sm-6 mb-4">
          <a href="#">
                <img class="img-fluid" src="http://placehold.it/500x300" alt="">
              </a>
        </div>

        <div class="col-md-3 col-sm-6 mb-4">
          <a href="#">
                <img class="img-fluid" src="http://placehold.it/500x300" alt="">
              </a>
        </div>

      </div>
      <!-- /.row -->

    </div>
    <!-- /.container -->



    <footer>
      <div class="row mb-4 mt-5">
        <div class="text-center col-sm-4 col-4">
  				<a href=""><small>Contactez-nous</small></a>
  				<a href=""><small>Services</small></a>
  				<a href=""><small>Liens légaux</small></a>
  			</div>
  			<div class="text-center col-sm-4 col-4"><small>2018 L3 Info</small></div>
  			<div class="text-center col-sm-4 col-4">
  				<a href="http://www.facebook.com" target="_blank"><img src="articles/facebook.png" width="20" height="20"/></a>
  				<a href="http://www.twitter.com" target="_blank"><img src="articles/twitter.jpg" width="20" height="20"/></a>
  				<a href="http://www.instagram.com" target="_blank"><img src="articles/instagram.jpg" width="20" height="20"/></a>
  			</div>
      </div>
    </footer>
  </body>
</html>
