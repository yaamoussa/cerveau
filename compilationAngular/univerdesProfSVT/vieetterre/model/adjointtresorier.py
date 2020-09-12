#-*- coding: utf-8 -*-

from django.db import models

from tresoriersectoriel import TresorierSectoriel

class AdjointTresorier(TresorierSectoriel):
    class Meta:
        verbose_name='adjointT'

    coordonner = models.ForeignKey('AdjointPresidentSectoriel', on_delete=models.PROTECT)
    gerersubvention = models.ForeignKey('Subvention', on_delete=models.PROTECT)
    gererdoc = models.ForeignKey('Documentfinance', on_delete=models.PROTECT)

