from django import forms
from .models import Articles,Contact



class ArticleForm(forms.ModelForm):
	class Meta :
		model=Articles
		fields='__all__'



class NouveauContactForm(forms.Form):
	nom=forms.CharField()
	adresse=forms.CharField(widget=forms.Textarea)
	photo=forms.ImageField()


class ConnexionForm(forms.Form):
	username=forms.CharField(label="Nom d'utilisateur",max_length=30)
	password=forms.CharField(label="Mot de passe",widget=forms.PasswordInput)
	
required=False