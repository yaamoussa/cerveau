from django.shortcuts import render,redirect,get_object_or_404
from django.views.generic import ListView
from mini_url.models import MiniURL
from mini_url.forms import MiniURLForm
from django.views.generic import CreateView,UpdateView,DeleteView
from django.urls import reverse_lazy

import random
import string

# Create your views here.

def liste(request):

	"""Affichage des redirections """

	minis=MiniURL.objects.order_by('-nb_acces')


	return render (request,'mini_url/liste.html',locals())




def nouveau (request):

	"""Ajout d'une redirection """

	if request.method=="POST":

		form=MiniURLForm(request.POST)

		if form.is_valid():
			form.save()

			return redirect(liste)

	else :

		form =MiniURLForm()	


	return render (request,'mini_url/nouveau.html',{'form':form})



def redirection (request,code):

	""" Redirection vers l'URL enregistrement """

	mini=get_object_or_404(MiniURL,code=code)
	mini.nb_acces +=1
	mini.save()

	return redirect(mini.url,permanent=True)



def generer(nb_caracteres):

	caracteres = string.ascii_letters + string.digits

	aleatoire = [random.choice(caracteres) for _ in range(nb_caracteres)]

	return ''.join(aleatoire)




class MiniUrlList(ListView):


	model=MiniURL

	context_object_name='listmini'



class URLCreate(CreateView):

	model=MiniURL
	template_name='mini_url/nouveau.html'
	form_class=MiniURLForm
	success_url=reverse_lazy(liste)



class URLUpdate(UpdateView):


	model=MiniURL
	template_name='mini_url/nouveau.html'

	form_class=MiniURLForm
	success_url=reverse_lazy(liste)


	def get_object(self,queryset=None):

		code=self.kwargs.get('code',None)
		return get_object_or_404(MiniURL,code=code)

	def form_valid(self,form):

		self.object=form.save()

		#Envoi d'un message a l'utilisateur
		messages.success(self.request, "Votre profil a été mis à jour avec succès.")
		return HttpResponseRedirect(self.get_success_url)




class URLDelete(DeleteView):

	model=MiniURL
	context_object_name="mini_url"
	template_name='mini_url/supprimer.html'
	success_url=reverse_lazy(liste)


	def get_object(self,queryset=None):
		code=self.kwargs.get('code',None)
		return get_object_or_404(MiniURL,code=code)
