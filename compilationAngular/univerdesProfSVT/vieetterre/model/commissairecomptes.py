#-*- coding: utf-8 -*-

from django.db import models

from commissairecomptessectoriel import CommissaireComptesSectoriel

class commissaireComptes(CommissaireComptesSectoriel):
    class Meta:
        verbose_name='commissaire'


