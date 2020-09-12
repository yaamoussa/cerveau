#-*- coding: utf-8 -*-

from django.db import models

class Registre(models.Model):
    class Meta:
        verbose_name='registre'

    registrer = models.OneToOneField('SGSectoriel')

