
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
    <div id="carouselExampleControls" class="carousel slide mx-5 mb-5" data-ride="carousel">
      <div class="carousel-inner">
        <div class="carousel-item active">
          <img class="d-block w-100 img-responsive" src="Adidas.jpg" alt="First slide" height="730">
        </div>
        <div class="carousel-item">
          <img class="d-block w-100 img-responsive" src="Fila.jpg" alt="Second slide" height="730">
        </div>
        <div class="carousel-item">
          <img class="d-block w-100 img-responsive" src="Nike.jpg" alt="Third slide" height="730">
        </div>
      </div>
      <a class="carousel-control-prev" href="#carouselExampleControls" role="button" data-slide="prev">
        <span class="carousel-control-prev-icon" aria-hidden="true"></span>
        <span class="sr-only">Previous</span>
      </a>
      <a class="carousel-control-next" href="#carouselExampleControls" role="button" data-slide="next">
        <span class="carousel-control-next-icon" aria-hidden="true"></span>
        <span class="sr-only">Next</span>
      </a>
    </div>
    <hr>

    <!-- Page Content -->
    <div class="container">
      <?php
        //echo $_GET["idCategorie"];
        $requete = "SELECT nomCategorie from categories ";
        $result = mysqli_query($maBase,$requete);
        $nbLigne = mysqli_num_rows($result);
        $ligne = mysqli_fetch_array($result);
        $nomCategorie = $ligne["nomCategorie"];
        mysqli_close($maBase);
        $maBase = connexionDB();
        $requete = "SELECT * from produits  LIMIT 12" ;
        $result = mysqli_query($maBase,$requete);
       ?>
      <!-- Page Heading -->

      

      <div class="row">
        <?php while ( $ligne = mysqli_fetch_array($result)) {  ?>
          <div class="col-lg-4 col-sm-6 mb-4">
            <div class="card h-100">
              <a href="#"><img class="card-img-top" src="<?php echo $ligne["imageProduit"]; ?> " alt=""></a>
              <div class="card-body">
                <h4 style="text-align:center" class="card-title">
                  <a href="details.php?idProduit= <?php echo $ligne["idProduit"]; ?>"><?php echo $ligne[1]; ?></a>
                </h4>
                <h3 style="text-align:center" ><?php echo $ligne["prix"]; ?> fCFA</h3>
              </div>
            </div>
          </div>
       <?php }  ?>



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
