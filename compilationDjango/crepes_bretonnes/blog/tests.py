from django.test import TestCase
from datetime import datetime,timedelta
from .models import Articles,Categorie

# Create your tests here.

class ArticleTests(TestCase):

	def test_est_recent_avec_futur_article(self):


		"""

		Verifie si la  methode est_recent d'un article ne renvoie pas
		True si l'article a sa date de publication dans le futur ."""


		futur_article=Articles(date=datetime.now() +timedelta(days=20))
		# il n'y a pas besion de remplir tous les champs ,ni de sauvegarder 
		self.assertEqual(futur_article.est_recent(),False)
		


	class UnTest(TestCase):


		@classmethod # <-

		def setUpTestData(cls):
			Categorie.objects.create(titre="Par defaut")

		def setUp(self):
			self.une_variable="Salut !"


		def test_verification(self):
			self.assertEqual(self.une_variable,"Salut !")
			self.assertTrue(
				Categorie.objects.filter(titre="Par defaut").exists()
			)