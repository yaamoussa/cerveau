from django.test import TestCase
from django.urls import reverse
from mini_url.models import MiniURL
from mini_url.views import generer 

def creer_url():

	mini=MiniURL(url="http://foo.bar",code=generer(6),pseudo="Maxime")
	mini.save()
	return mini 

class MiniURLTests(TestCase):

	def test_liste(self):
		"""Verifie si une URL sauvegarde est bien affiche """
		mini=creer_url()

		reponse=self.client.get(reverse('mini_url.views.liste'))


		self.assertEqual(reponse.status_code,200)
		self.assertContains(reponse,mini_url)
		self.assertQuerysetEqual(reponse.context['minis'],[repr(mini)])



	def test_nouveau_redirection (self):

		"""Verifie la redirection d'un ajout d'URL """

		data={
			'url':'http://www.djangoproject.com',
			'pseudo':'Jean Dupont',
		}


		reponse=self.client.post(reverse('mini_url.views.nouveau').data)
		self.assertEqual(reponse.status_code,302)
		self.assertRedirects(reponse,reverse('mini_url.views.liste'))

# Create your tests here.
