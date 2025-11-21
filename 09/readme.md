Choisir le bon conteneur pour chaque exo

Ex00 - Bitcoin Exchange

* std::map

--> On doit associer une date (clé) à un taux de conversion Bitcoin (valeur).
--> std::map stocke les éléments triés par clé ce qui permet :
 * Chercher facilement uen date précise
 * Obtenir la date immédiatement inférieur quand celle de l'input n'existe pas

Il n'y a pas de doublons de dates dans la base de données, ce qui correspond bien au comportement d'un map (clé unique)

L'ordre chronologique naturel des dates (YYYY-MM-DD) conservé automatiquement

Comment fonctionne std::map<Key, Value> conteneur associatif de la STL
On associe chaque clé à une valeur unique, comme un dictionnaire en Python

Exemple :
std::map<std::string, int> ages;
ages["Alice"] = 25;
ages["Bob"] = 33;

Alice et Bob = clés
24 et 33 = valeurs associées

-- Comment ça fonctionne --

La structure est comme un arbre binaire.
Les clés sont uniques.
Le conteneur garde les ekements tries automatiquement.
Lacces ets fait par clé et non par index.
