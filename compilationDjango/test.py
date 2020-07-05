#!/usr/bin/python3.6
# -*-coding:Utf-8 -*

"""import os # On importe le module os
print("Bonjour le monde !")
os.system("pause")"""
"""bissextile=False
"""

"""annee=input("Saisissez une annee:")

try :
	annee=int(annee)
	if annee <=0 :
		raise ValueError ("l'annee saisie est negative ou nulle.")
	#assert annee > 0
except:
	print ("Erreur lorsque de la conversion de l'annee.")
except ValueError:
	print("Vous n'avez pas saisi un nombre.")

if annee % 400==0:
    bissextile=True
elif annee %100==0:
	bissextile=False

elif annee % 4:
	bissextile=True
else :
      bissextile=False

if bissextile :
         	 print("L' annee saisie est bissextile.")
else:

         	 print("l'annee saisie n'est pas bissextile.")


"""
"""try:
	resultat=numerateur /denominateur
except NameError:
	print("La variable numeraeur ou denominateur n'a pas ete definie.")


except TypeError :
	print("La variable numeraeur ou denominateur possede un type incompatble avec la division.")
except ZeroDivisionError:
	print("La variable denominateur est egale a 0.")

"""


ma_liste=['a','b','c','e','f','h','g']

for i,elt in enumerate (ma_liste):
	print("A l'indice {} se trouve {}.".format(i,elt))

for elt in enumerate(ma_liste):
	print(elt)

def decompaser (entier,devise_par):
	p_e=entier//divise_par
	reste=entier % divise_par
	return p_e,reste


def afficher_flottant(flottant):
	"""Fonction prenant en parametre un flottant et renvoyant 
	une chaine de caratere representant la troncature de ce nombre.
	La partie flottant doit avoir une longueur maximun de 3 caracteres.


	De plus ,on va remplacer le point decimal par la virgule"""

	if type(flottant) is not float :
		raise TypeError ("Le parametre attendu doit etre un flottant")
		flottant =str(flottant)

		partie_entiere,partie_flottant=flottant.split(".")


		#La partie entiere n'est pas a modifier 
		#Seule la partie flottant doit etre tronquee

		return ",".join([partie_entiere,partie_flottant[:3]])



v=afficher_flottant

print(afficher_flottant(3.9999))