#-*- coding: utf-8 -*-

from django.db import models

class Journal(models.Model):
    class Meta:
        verbose_name='journal'

    DatePub = models.DateField(auto_now_add=True, auto_now=False,
	verbose_name="date de publication")
    DateEcrit = models.DateField(auto_now_add=True, auto_now=False,
	verbose_name="date d'ecriture")

    publier = models.ForeignKey('AdjointTresorierSectoriel', on_delete=models.PROTECT)
    publier = models.ForeignKey('CommissaireComptesSectoriel', on_delete=models.PROTECT)

