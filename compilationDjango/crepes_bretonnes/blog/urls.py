from django.urls import path,re_path
from django.conf.urls import url
from django.views.generic import ListView,TemplateView


from . import views
from .models import Articles ,Categorie


urlpatterns = [
# Via la fonction as_view, comme vu tout à l'heure
    url(r'^$', views.ListeArticles.as_view(), name="blog_liste"),
    # Et nous avons toujours nos autres pages...
    url(r'^article/(?P<id>\d+)$', views.lire),
    url(r'^(?P<page>\d+)$', views.archives),
    url(r'^categorie/(?P<slug>.+)$', views.voir_categorie),



    ]