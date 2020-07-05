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
required=False