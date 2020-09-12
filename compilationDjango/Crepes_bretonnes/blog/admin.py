from django.contrib import admin
from .models import Categorie,Articles
from django.utils.text import Truncator 
#from blog.models import Categorie,Articles
# Register your models here.
class ArticleAdmin(admin.ModelAdmin):

	#COnfiguration de la liste d'articles
	list_display=('titre','categorie','auteur','date','slug')
	list_filter=('auteur','categorie')
	date_hierarchy='date'
	ordering=('date',)
	search_fields=('titre','contenu')
	prepopulated_fields = {'slug': ('titre', ), }
	#Configuration du formulaire d'edition 
	fieldsets=(
		#Fieldset 1: meta-info (titre,auteur....)
		('General',{
		'classes':['collapse',],
		'fields':('titre','auteur','categorie','slug')

		}),
	#Fieldset 2 : contenu de l'article 
	('Contenu de l\'article',{
		'description':'Le formulaire accepte les balises HTML. Utilisez -les a bon escient !',
		'fields':('contenu',)

		}),
	)
	def apercu_contenu(self,articles):
		""" 
		Retourne les 40 premiers caracteres du contenu de l'article ,
		suivi de points de suspension si le texte  est plus long.
		On pourrait le coder nous meme,mais Django fournit deja la
		fonction qui le fait pour nous !
		"""

		text=article.contenu[0:40]
		if len(article,contenu)>40 :
			return '% ...'% text 
		else :
			return text
		
	# En tete de notre colonne 
	apercu_contenu.short_description='Aperçu du contenu'

admin.site.register(Categorie)
admin.site.register(Articles,ArticleAdmin)
