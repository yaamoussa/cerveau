#-*- coding: utf-8 -*-

from django.db import models

class Remplacement(models.Model):
    class Meta:
        verbose_name='remplacement'

    section1 = models.CharField(max_length=100)
    section2 = models.CharField(max_length=100)

    remplacer = models.OneToOneField('AdjointPresident')

