#-*- coding: utf-8 -*-

from django.db import models

class Cotisation(models.Model):
    class Meta:
        verbose_name='cotisation'

    part = models.IntegerField()
    sommeTotal = models.IntegerField()
    debut = models.DateField(auto_now_add=True, auto_now=False,
	verbose_name="Demarrage ")
    fin = models.DateField(auto_now_add=True, auto_now=False,
	verbose_name="fin")


