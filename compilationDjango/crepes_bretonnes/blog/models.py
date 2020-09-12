# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models
from django.utils import timezone
from datetime import datetime
from django.contrib.auth.models import User

class Categorie(models.Model):
	nom=models.CharField(max_length=30)

	def __str__(self):
		return self.nom



class Articles(models.Model):
	titre=models.CharField(max_length=100)
	slug=models.SlugField(max_length=100)
	auteur=models.CharField(max_length=42)
	contenu=models.TextField(null=True)
	date = models.DateTimeField(auto_now_add=True, auto_now=False,
	verbose_name="Date de parution")


	categorie=models.ForeignKey('Categorie',on_delete=models.CASCADE)



	class Meta:
		ordering=['date']
		verbose_name="article"

	def  est_recent(self):
		""" Retourne True l'article a ete publie dans les  	30 jours derniers jours"""

		return (datetime.now()-self.date).days <30 and self.date<datetime.now()

		
	def __str__(self):
		return self.titre

class Contact(models.Model):
	nom=models.CharField(max_length=225)
	adresse=models.TextField()
	photo=models.ImageField(upload_to ="photos/")


	def __str__(self):
		return self.nom



class Profil(models.Model):
	user= models.OneToOneField(User,on_delete=models.CASCADE)
	site_web=models.URLField(blank=True)
	avatar=models.ImageField(null=True,blank=True,upload_to="avatars/")
	signature=models.TextField(blank=True)
	inscrit_newsletter=models.BooleanField(default=False)



	def __str__(self):
		return "Profil de {1}".format(self.user.username)


class Eleve(models.Model):

	nom=models.CharField(max_length=31)
	moyenne=models.IntegerField(default=10)



	def __str__(self):

		return "Eleve {0} ({1}/20 de moyenne)".format(self.nom,self.moyenne)
		