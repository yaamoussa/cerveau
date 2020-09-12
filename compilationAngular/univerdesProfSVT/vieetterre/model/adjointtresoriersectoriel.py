#-*- coding: utf-8 -*-

from django.db import models

from membre import Membre

class AdjointTresorierSectoriel(Membre):
    class Meta:
        verbose_name='adjointTresorier'

    rediger = models.OneToOneField('Rapport')
    encaisser = models.OneToOneField('Cotisation')

