# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models
from django.utils import timezone



class Categorie(models.Model):
	nom=models.CharField(max_length=30)

	def __str__(self):
		return self.nom



class Article(models.Model):
	titre=models.CharField(max_length=100)
	auteur=models.CharField(max_length=42)
	contenu=models.TextField(null=True)
	date=models.DateTimeField(default=timezone.now,verbose_name="Date de parution")



	Categorie=models.ForeignKey('Categorie',on_delete=models.CASCADE)



	class Meta:
		ordering=['date']

	def __str__(self):
		return self.titre

class Moteur (models.Model):
	nom=models.CharField(max_length=25)

	def __str__(self):
		return self.nom




class Voiture (models.Model):
	nom=models.CharField(max_length=25)
	moteur=models.OneToOneField(Moteur,on_delete=models.CASCADE)


	def __str__(self):

		return self.nom


# Create your models here.
class Produit(models.Model):
	nom=models.CharField(max_length=30)

	def __str__(self):
		return self.nom

class Vendeur(models.Model):
	nom=models.CharField(max_length=30)
	produit=models.ManyToManyField(Produit,through='Offre',related_name='+')
	produits_sans_prix=models.ManyToManyField(Produit,related_name="veudeur")


	def __str__(self):
		return self.nom



class Offre (models.Model):
	prix=models.IntegerField()
	produit=models.ForeignKey(Produit,on_delete=models.CASCADE)
	vendeur=models.ForeignKey(Vendeur,on_delete=models.CASCADE)

	def __str__(self):
		return "{0} vendu par {1} ".format(self.produit,self.vendeur)
