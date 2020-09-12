#-*- coding: utf-8 -*-

from django.db import models

class Retraites(models.Model):
    class Meta:
        verbose_name='retraite'

    Codemembre = models.CharField(max_length=100)
    date = models.DateField(auto_now_add=True, auto_now=False,
	verbose_name="date du rapport")


