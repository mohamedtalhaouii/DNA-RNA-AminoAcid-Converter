#include <stdio.h>
#include <string.h>

// Fonction pour convertir l'ADN en ARN
void adnEnArn(char *adn, char *arn) {
    int i;
    for (i = 0; adn[i] != '\0'; i++) {
        if (adn[i] == 'T') {
            arn[i] = 'U';
        } else {
            arn[i] = adn[i];
        }
    }
    arn[i] = '\0'; // Terminer la chaîne ARN
}

// Fonction pour compter les nucléotides dans la séquence ADN
void compterNucleotides(char *adn) {
    int compteA = 0, compteT = 0, compteC = 0, compteG = 0;

    for (int i = 0; adn[i] != '\0'; i++) {
        switch (adn[i]) {
            case 'A':
                compteA++;
                break;
            case 'T':
                compteT++;
                break;
            case 'C':
                compteC++;
                break;
            case 'G':
                compteG++;
                break;
        }
    }

    printf("Comptes des nucléotides:\n");
    printf("A: %d\n", compteA);
    printf("T: %d\n", compteT);
    printf("C: %d\n", compteC);
    printf("G: %d\n", compteG);
}

// Fonction pour calculer le contenu en GC dans la séquence ADN
void calculerContenuGc(char *adn) {
    int compteG = 0, compteC = 0, longueur = 0;

    for (int i = 0; adn[i] != '\0'; i++) {
        if (adn[i] == 'G') {
            compteG++;
        } else if (adn[i] == 'C') {
            compteC++;
        }
        longueur++;
    }

    double contenuGc = ((double)(compteG + compteC) / longueur) * 100;

    printf("Contenu en GC: %.2f%%\n", contenuGc);
}

// Fonction pour convertir l'ARN en acides aminés avec leurs noms complets
void arnEnAcidesAmines(char *arn, char *acidesAmines) {
    char *tableCodon[64] = {
        "Phénylalanine", "Phénylalanine", "Leucine", "Leucine", "Sérine", "Sérine", "Sérine", "Sérine",
        "Tyrosine", "Tyrosine", "Stop", "Stop", "Cystéine", "Cystéine", "Stop", "Tryptophane",
        "Leucine", "Leucine", "Leucine", "Leucine", "Proline", "Proline", "Proline", "Proline",
        "Histidine", "Histidine", "Glutamine", "Glutamine", "Arginine", "Arginine", "Arginine", "Arginine",
        "Isoleucine", "Isoleucine", "Isoleucine", "Méthionine", "Thréonine", "Thréonine", "Thréonine", "Thréonine",
        "Asparagine", "Asparagine", "Lysine", "Lysine", "Sérine", "Sérine", "Arginine", "Arginine",
        "Valine", "Valine", "Valine", "Valine", "Alanine", "Alanine", "Alanine", "Alanine",
        "Acide Aspartique", "Acide Aspartique", "Acide Glutamique", "Acide Glutamique", "Glycine", "Glycine", "Glycine", "Glycine"
    };
    char bases[] = "UCAG";
    int i, j = 0;

    for (i = 0; arn[i] != '\0' && arn[i+1] != '\0' && arn[i+2] != '\0'; i += 3) {
        int index = (strchr(bases, arn[i]) - bases) * 16 + 
                    (strchr(bases, arn[i+1]) - bases) * 4 + 
                    (strchr(bases, arn[i+2]) - bases);
        j += sprintf(&acidesAmines[j], "%s ", tableCodon[index]);
    }
    acidesAmines[j-1] = '\0'; // Terminer la chaîne des acides aminés
}

int main() {
    char adn[100], arn[100], acidesAmines[300];

    printf("Entrez une séquence ADN: ");
    scanf("%s", adn);

    adnEnArn(adn, arn);
    printf("Séquence ARN: %s\n", arn);

    compterNucleotides(adn);
    calculerContenuGc(adn);
    arnEnAcidesAmines(arn, acidesAmines);
    printf("Séquence d'acides aminés: %s\n", acidesAmines);

    return 0;
}
