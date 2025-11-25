Comment fontionne lalgo

Pourquoi le nombre de comparaison est important :
On distingue la difference entre la vitesse reel et la complexite theorique (le nombre doperations)
C'est pas le plus rapide en temps reel mais il permet deconomiser les ressources de calcule car
il evite de comparer quand cest pas necessaire
L'exercice veut nous faire comprendre un algo qui minimise le nombre de fois ou on rearde les donnees


3 phases de l'algorithme :

Pairing et local sort : Regrouper les elements par parires et on trie chaque paire (le plus grand element devient le gagnant et le petit le perdant)
Recursif sort : On prend tous les "gagnants" (les plus grands de chaque paire) et on les trie recursivement pour creer la main chain.
Insertion : On insere les perdants ( et leventuel element impair laisse de cote) dans la main chain en utilisant le Binary Search

Etape 1 : Appairage (pairing)

si le nb delement est impait on met limpair de cote
On forme des pairs avec le reste
Dans chaque pair le plus grand est gagant et lautre perdant

3, 5, 9, 7, 4

impair donc 4 de cote

3-5 pair --> 5 gagnant
7-4 pair --> 7 gagnant

Etape 2
