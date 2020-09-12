#-*- coding: utf-8 -*-

from django.db import models

class Transfert(models.Model):
    class Meta:
        verbose_name='transfert'

    Codemembre = models.CharField(max_length=100)
    section1 = models.CharField(max_length=100)
    section2 = models.CharField(max_length=100)

    transferer = models.ManyToManyField('AdjointPresident')

