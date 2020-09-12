#-*- coding: utf-8 -*-

from django.db import models

class comminuquee(models.Model):
    class Meta:
        verbose_name='comminuque'

    sujet = models.CharField(max_length=100)
    Date = models.DateField(auto_now_add=True, auto_now=False,
	verbose_name="Date de la comminuquee")


