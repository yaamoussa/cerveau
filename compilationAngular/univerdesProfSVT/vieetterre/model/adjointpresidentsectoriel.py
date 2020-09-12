#-*- coding: utf-8 -*-

from django.db import models

from membre import Membre


class AdjointPresidentSectoriel(Membre):
    class Meta:
        verbose_name='adjoint'

    etat = models.CharField(max_length=100)

    gereradjoint = models.OneToOneField('PresidentSectoriel')
    gererrapport = models.OneToOneField('Rapport')

