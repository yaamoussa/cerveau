#-*- coding: utf-8 -*-

from django.db import models

class Rapport(models.Model):
    class Meta:
        verbose_name='rapport'

    type = models.CharField(max_length=100)
    date = models.DateField(auto_now_add=True, auto_now=False,
	verbose_name="date du rapport")

    rediger = models.OneToOneField('CommissaireComptesSectoriel')
    rediger = models.OneToOneField('AdjointSGSectoriel')

