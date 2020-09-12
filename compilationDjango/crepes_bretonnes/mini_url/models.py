from django.db import models
import random 
import string
# Create your models here.


class MiniURL (models.Model):
	url=models.URLField(verbose_name="URL a reduire",unique=True)
	code = models.CharField(max_length=6, unique=True)
	date = models.DateTimeField(auto_now_add=True,verbose_name="Date d'enregistrement")
	pseudo=models.CharField(max_length=255,blank=True,null=True)
	nb_acces=models.IntegerField(default=0,verbose_name="Nombre d'acces a l'URL")


	def __str__ (self):
		return "[{0}] {1}".format(self.code,self.url)


	def save(self,*args,**kwargs):


		if self.pk is None :
			self.generer(6)


			super(MiniURL,self).save(*args,**kwargs)


	def generer (self,nb_caracteres):
		caracteres=string.ascii_letters + string.digits
		aleatoire=[random.choice(caracteres) for _  in range(nb_caracteres)]


		self.code=''.join(aleatoire)



		class Meta:

			verbose_name="MiniURL"
			verbose_name_plural="MinisURL"
