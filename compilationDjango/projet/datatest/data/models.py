from django.db import models



class Customer(models.Model):


	name=models.CharField(max_length=40)
	age=models.IntegerField()
	city=models.CharField(max_length=40)


	class Meta:
		verbose_name="customer"
		ordering=['age']

# Create your models here.
