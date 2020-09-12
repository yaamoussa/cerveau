#-*- coding: utf-8 -*-

from django.db import models

from presidentsectoriel import PresidentSectoriel

class AdjointPresident(PresidentSectoriel):
    class Meta:
        verbose_name='adjoint'

    etat = models.CharField(max_length=100)

    gereradjoint = models.OneToOneField('Presient')

