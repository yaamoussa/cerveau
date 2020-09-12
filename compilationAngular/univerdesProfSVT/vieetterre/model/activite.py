#-*- coding: utf-8 -*-

from django.db import models

class Activite(models.Model):
    class Meta:
        verbose_name='activite'

    type = models.CharField(max_length=100)
    date = models.DateField(auto_now_add=True, auto_now=False,
	verbose_name="Date de l'evenement")
    lieu = models.CharField(max_length=100)

    gereractivite = models.ForeignKey('AdjointPresidentSectoriel', on_delete=models.PROTECT)

