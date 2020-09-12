#-*- coding: utf-8 -*-

from django.db import models

from sgsectoriel import SGSectoriel

class AdjointSG(SGSectoriel):
    class Meta:
        verbose_name='adjointSG'

    gererjournal = models.OneToOneField('Journal')
    coordonner = models.ForeignKey('AdjointPresidentSectoriel', on_delete=models.PROTECT)

