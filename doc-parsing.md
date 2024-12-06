pour l'instant:
 1. on recup la ligne
 2. on l'ajoute a l'historique de readline
 3. et ensuite on parse

todo:
 1. arbre binare pour parsing


 creer cmdli -> envoyer directement 

etape 1:
	- tester cas erreur
		1. mauvais ordre
		2. token syntax error
		3. token non existant
		4. parentheses ordre

variable d'environement sont traitee a la volee. pas a l'avance
c'est un split et des arguments
char \*str[0] = commande
char \*str[1] = argument1
char \*str[2] = argument2

apres une redirection: checker si le nombre d'argument de la variable d'env est 1. si c'est pas 1 -> [shell]: [variable]: ambiguous redirect
ex:
   export TEST="cat -e *ke* && <" && ls | grep srcs && $TEST

tableau de structure pour savoir si c'est la variable est expendable ou pas
ex:
    ls && export TEST_CHIANT="dfgsd:sdf:dgf:dg:sdf" && echo "truc" > $TEST_CHIANT


toutes les env variables sont evaluee au moment de l'utilisation

single quote: interprete pas les variables / asterisques

take care of CDPATH variable -> should be added if updated
