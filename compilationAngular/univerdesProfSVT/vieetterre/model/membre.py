#-*- coding: utf-8 -*-

from django.db import models


class Membre(models.Model):
    class Meta:
        verbose_name='membre'

    nom = models.CharField(max_length=100)
    prenom = models.CharField(max_length=100)
    Codemembre = models.CharField(max_length=100)
    proftype =models.CharField(max_length=100)
    section = models.CharField(max_length=100)
    etablissement = models.CharField(max_length=100)
    datead = models.DateField(auto_now_add=True, auto_now=False,
    verbose_name="date d'adhesion")

    signaleRetraite = models.OneToOneField('Retraites',on_delete=models.CASCADE)
    lire = models.OneToOneField('comminuquee',on_delete=models.CASCADE)
    se_faire = models.OneToOneField('Transfert',on_delete=models.CASCADE)
    demander = models.OneToOneField('Adhesion',on_delete=models.CASCADE)

