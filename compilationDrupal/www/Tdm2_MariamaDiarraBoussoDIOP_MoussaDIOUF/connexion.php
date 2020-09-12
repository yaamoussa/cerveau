<?php
  function connexionDB(){
    $user = "root";
    $nomhote = "localhost";
    $password = "";
    $bd = "Boutique";
    $port = "";
    $connexion = mysqli_connect ($nomhote,$user,$password, $bd);
    if (!$connexion) {
      echo "impossible de se connecter";
      exit();
    }
 
    return $connexion;
  }
?>
