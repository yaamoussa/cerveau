#-*- coding: utf-8 -*-

from django.db import models

from AdjointTresorier import AdjointTresorier

class Tresorier(AdjointTresorier):
    class Meta:
        verbose_name='tresorier'

    pass
