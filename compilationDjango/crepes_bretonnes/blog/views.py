from datetime import datetime
from django.http import HttpResponse,Http404
from django.shortcuts import render,redirect,get_object_or_404,get_list_or_404
#rom blog.models import Articles,Contact,Categorie
from .forms import ArticleForm,NouveauContactForm
from django.views.generic  import ListView
from .models import Articles

def home(request):
    """ Exemple de page non valide au niveau HTML pour que l'exemple soit concis """
    return HttpResponse("""
        <h1>Bienvenue sur mon blog !</h1>
        <p>Les crêpes bretonnes ça tue des mouettes en plein vol !</p>
    """)



def view_article(request, id_article):
    """ 
    Vue qui affiche un article selon son identifiant (ou ID, ici un numéro)
    Son ID est le second paramètre de la fonction (pour rappel, le premier
    paramètre est TOUJOURS la requête de l'utilisateur)
    """

    #Si l'ID est superieur a 100 ,nous considerons que l'article n'existe paas
    if int(id_article) >100 :   
    	raise Http404
    return redirect('afficher_article',id_article=42)

def view_redirection(request):
	return HttpResponse("Vous avez ete redirige.")


def list_articles(request,year,month):
	"""Liste des articles d'un mois precis ."""

	return redirect("http://www.djangoproject.com")

def date_actuelle(request):
	return render (request,'blog/date.html',{'date':datetime.now()})


def addition(request,nombre1,nombre2):
	total=nombre1+nombre2
    

	#retourne nombre1,nombre2 et la somme des deux au tpl
	return render (request,'blog/addition.html',locals())

def mapage(request):

    return render(request,'mapage.html')



def accueil(request):
    articles = Articles.objects.all() # Nous sélectionnons tous nos articles
    return render(request, 'blog/accueil.html', {'derniers_articles': articles})



def lire(request,id,slug):
    """Afficher un article complet """
    article=get_object_or_404(Articles,id=id,slug=slug)

    return render(request,'blog/lire.html',{'article':article})   









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

def nouveau_contact(request):
    sauvegarde=False
    form=NouveauContactForm(request.POST or None,request.FILES)
    if form.is_valid():
        contact=Contact()
        contact.nom=forms.cleaned_data["nom"]
        contact.adresse=form.cleaned_data["adresse"]
        contact.photo=form.cleaned_data["photo"]
        contact.save()
        sauvegarde=True

    return render (request,'blog/contact.html',{'form':form,
    'sauvegarde':sauvegarde})    






def voir_contact(request):


    return render (
        request,'blog/voir_contact.html',
        {'contact': Contact.objects.all()})

def voir_categorie(request):
    categorie=Categorie.objects
    return render(request,'blog/categorie.html')


def archives(request):
    return render (request,'blog/archives.html')


class ListeArticles(ListView):
    model=Articles
    context_object_name="derniers_articles"
    template_name="blog/accueil.html"
    paginate_by=5




