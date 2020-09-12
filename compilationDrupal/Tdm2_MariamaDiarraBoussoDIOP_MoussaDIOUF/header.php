<?php include("connexion.php"); ?>
<header>
  <div class="fixed-top">
      <nav class="navbar navbar-expand-lg navbar-light bg-light row">
        <a class="navbar-brand col-md-8 col-6" href="#">
          <img src="logo 1.png" width="36" height="36" alt="logo" title="logo">
        </a>
        <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarNavDropdown" aria-controls="navbarNavDropdown" aria-expanded="false" aria-label="Toggle navigation">
          <span class="navbar-toggler-icon"></span>
        </button>
        <div class="collapse navbar-collapse col-md-4 col-6" id="navbarNavDropdown">
          <div class="row ">
            <ul class="navbar-nav">
              <li class="nav-item active">
                <a class="nav-link" href="index.php">Nouveautés <span class="sr-only">(current)</span></a>
              </li>
              <li class="nav-item active">
                <a class="nav-link" href="#">Vêtements</a>
              </li>
              <li class="nav-item active dropdown">
                <a class="nav-link dropdown-toggle" href="#" id="navbarDropdownMenuLink" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
                  Marques
                </a>
                <div class="dropdown-menu" aria-labelledby="navbarDropdownMenuLink">
                  <?php
                    $maBase = connexionDB();
                    $requete = "SELECT * from categories";
                    $result = mysqli_query($maBase,$requete);
                    $nbLigne = mysqli_num_rows($result);
                    while ($ligne = mysqli_fetch_array($result)) {


                  ?>
                    <a class="dropdown-item" href="liste.php?idCategorie=<?php echo $ligne["idCategorie"]; ?>"> <?php echo $ligne["nomCategorie"]; ?></a>

                  <?php
                    }
                   ?>
                </div>
              </li>
              <li class="nav-item active">
                <a class="nav-link" href="formulaire.html">Mon espace</a>
              </li>
              <li class="nav-item active">
                <a class="nav-link" href="#">Mon panier</a>
              </li>
            </ul>
          </div>
        </div>
      </nav>
    </div>
</header>
