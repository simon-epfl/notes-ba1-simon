

#include <iostream> 
#include <vector>
#include <array>

using namespace std;

typedef vector<int> Ligne;
typedef vector<Ligne> Matrice;

int somme_consecutifs_max (Ligne ligne) {
	int somme_actuelle (ligne[0]);
	int somme_maximum (ligne[0]);
	for (auto element : ligne){
		somme_actuelle = somme_actuelle + element;
		if (somme_actuelle > somme_maximum) {
			somme_maximum = somme_actuelle; 
			somme_actuelle = 0;
		}
	}
	return somme_maximum;
}
	
	
vector<size_t> lignes_max (Matrice entree){
	vector<size_t> matrice_retour (1,0);
	int somme_ligne_actuelle(0);
	int somme_ligne_max(0);
	for (size_t i(0); i < entree.size(); ++i) {
		somme_ligne_actuelle = somme_consecutifs_max(entree[i]);
		if (somme_ligne_max < somme_ligne_actuelle){
			somme_ligne_max = somme_ligne_actuelle;
			matrice_retour.clear();
		}
		if (somme_ligne_max == somme_ligne_actuelle){
			matrice_retour.push_back(i);
		}
	}
	return matrice_retour;
}
 
Matrice tranches_max(Matrice entree){
	Matrice resultat;
	for (auto numero_ligne : lignes_max(entree)){ 
		Ligne ligne = entree[numero_ligne];
		resultat.push_back(ligne);
	}
	return resultat; 
}
	
	


int main () {
    Matrice m = {{3,4,5},{0,0,1}};
    Matrice max = tranches_max(m);
    for (size_t i = 0; i < max.size(); i++)
    {
        for (size_t j = 0; j < max[i].size(); j++)
        {
            cout << max[i][j];
        }
    }
}
