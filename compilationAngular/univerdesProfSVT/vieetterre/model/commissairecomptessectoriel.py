#-*- coding: utf-8 -*-

from django.db import models

from membre import Membre


class CommissaireComptesSectoriel(Membre):
    class Meta:
        verbose_name='CommissaireCS'


