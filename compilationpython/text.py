import re
chaine = " "
expression = r"^0221[0-9]{2}[0-9]([ . -]?[0-9] {2}) {3}$"
expression=re.compile(expression)
while re . search ( expression , chaine ) is None :
	chaine = input ( " Saisissez un num é ro de t é l é phone ( valide ) :")