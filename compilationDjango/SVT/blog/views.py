# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.http import HttpResponse,Http404
from django.shortcuts import render
from blog.models import Article 
# Create your views here.



def accueil (request):
	"""Afficher tous les article de notre blog"""

	articles=Article.objects.all() # NOus selectionnes tous nos articles

	return render (request,'blog/accueil',{'derniers_article':articles})


def lire(request,id):

	"""Afficher un article complet"""

	pass # Le code de cette fonction est donnne un peu plus loin 

		