#-*- coding: utf-8 -*-

from django.db import models

from adjointpresident import AdjointPresident

class Presient(AdjointPresident):
    class Meta:
        verbose_name='president'


