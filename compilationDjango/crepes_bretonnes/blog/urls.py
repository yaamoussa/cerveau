from django.urls import path,re_path
from django.conf.urls import url
from django.views.generic import ListView,TemplateView
from blog.views import ListeArticles

from blog import views
from .models import Articles ,Categorie


urlpatterns = [
# Via la fonction as_view, comme vu tout à l'heure
    url(r'^accueil$', views.ListeArticles.as_view(), name="blog_liste"),
    # Et nous avons toujours nos autres pages...
	url(r'^article/(?P<pk>\d+)$', views.lireArticle.as_view(), name='blog_lire'),    url(r'^accueil(?P<page>\d+)$', views.archives),
    url(r'^categorie/(?P<slug>.+)$', views.voir_categorie),
    url(r'^categorie/(\d+)$', views.ListeArticles.as_view(), name='blog_categorie'),

    ]