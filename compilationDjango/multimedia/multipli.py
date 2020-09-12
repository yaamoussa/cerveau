"""module multipli contenant la fonction able"""
def table (nb,max=10):
	""" Fonction affichant la table de multiplication par nb de 1*nb jusqu'a max *nb """

	i=0
	while i<max :
		print(i+1,"*",nb ,"=",(i+1)*nb)
		i+=1
# test de la fonction table 
if __name__=="__main__":
	table(4)
	os.syatem("pause")



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
	 