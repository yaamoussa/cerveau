from django.shortcuts import render
from django.contrib.auth import authenticate, login
# Create your views here.
from django.urls  import reverse
from django.contrib.auth import logout
from django.contrib.auth.decorators import login_required

def contact(request):
    # Construire le formulaire ,soit avec les donnes posteees,
    #soit vide l'utilisateur accede pour la premiere fois 
    # a la page 
    # form=ArticleForm(request.POST or None)
    form=ArticleForm(request.POST)
    if form.is_valid():
        form.save()
    #Nous verifions que les donnnes envoyees sont valides 
    #Cette methode renvoie False s'il n'y a pas de donnees
    #dans le formulaire ou qu'il contient des errreurs.
   
     #Quoiqu'il arrive ,on affiche la page du formulaire .
    return render(request,'blog/contact.html',locals())
