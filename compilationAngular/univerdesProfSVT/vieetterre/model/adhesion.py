#-*- coding: utf-8 -*-

from django.db import models

class Adhesion(models.Model):
    class Meta:
        verbose_name='adhesion'

    effectif = models.CharField(max_length=100)


