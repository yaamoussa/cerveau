#-*- coding: utf-8 -*-

from django.db import models

from AdjointSGSectoriel import AdjointSGSectoriel
from AdjointSG import AdjointSG

class SG(AdjointSGSectoriel, AdjointSG):
    class Meta:
        verbose_name='sg'

    pass
