#-*- coding: utf-8 -*-

from django.db import models

from membre import Membre


class AdjointSGSectoriel(Membre):
    class Meta:
        verbose_name='adjointSGsectoriel'

    gereradhesion = models.ForeignKey('Adhesion', on_delete=models.PROTECT)
    informer = models.OneToOneField('Note')

