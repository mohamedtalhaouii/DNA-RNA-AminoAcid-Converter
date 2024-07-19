#include <stdio.h>
#include <string.h>

// Function to convert DNA to RNA
void dnaToRna(char *dna, char *rna) {
    int i;
    for (i = 0; dna[i] != '\0'; i++) {
        if (dna[i] == 'T') {
            rna[i] = 'U';
        } else {
            rna[i] = dna[i];
        }
    }
    rna[i] = '\0'; // Null-terminate the RNA string
}

// Function to count nucleotides in the DNA sequence
void countNucleotides(char *dna) {
    int countA = 0, countT = 0, countC = 0, countG = 0;

    for (int i = 0; dna[i] != '\0'; i++) {
        switch (dna[i]) {
            case 'A':
                countA++;
                break;
            case 'T':
                countT++;
                break;
            case 'C':
                countC++;
                break;
            case 'G':
                countG++;
                break;
        }
    }

    printf("Nucleotide counts:\n");
    printf("A: %d\n", countA);
    printf("T: %d\n", countT);
    printf("C: %d\n", countC);
    printf("G: %d\n", countG);
}

// Function to calculate GC content in the DNA sequence
void calculateGcContent(char *dna) {
    int countG = 0, countC = 0, length = 0;

    for (int i = 0; dna[i] != '\0'; i++) {
        if (dna[i] == 'G') {
            countG++;
        } else if (dna[i] == 'C') {
            countC++;
        }
        length++;
    }

    double gcContent = ((double)(countG + countC) / length) * 100;

    printf("GC content: %.2f%%\n", gcContent);
}

// Function to convert RNA to amino acids with their full names
void rnaToAminoAcids(char *rna, char *aminoAcids) {
    char *codonTable[64] = {
        "Phenylalanine", "Phenylalanine", "Leucine", "Leucine", "Serine", "Serine", "Serine", "Serine",
        "Tyrosine", "Tyrosine", "Stop", "Stop", "Cysteine", "Cysteine", "Stop", "Tryptophan",
        "Leucine", "Leucine", "Leucine", "Leucine", "Proline", "Proline", "Proline", "Proline",
        "Histidine", "Histidine", "Glutamine", "Glutamine", "Arginine", "Arginine", "Arginine", "Arginine",
        "Isoleucine", "Isoleucine", "Isoleucine", "Methionine", "Threonine", "Threonine", "Threonine", "Threonine",
        "Asparagine", "Asparagine", "Lysine", "Lysine", "Serine", "Serine", "Arginine", "Arginine",
        "Valine", "Valine", "Valine", "Valine", "Alanine", "Alanine", "Alanine", "Alanine",
        "Aspartic Acid", "Aspartic Acid", "Glutamic Acid", "Glutamic Acid", "Glycine", "Glycine", "Glycine", "Glycine"
    };
    char bases[] = "UCAG";
    int i, j = 0;

    for (i = 0; rna[i] != '\0' && rna[i+1] != '\0' && rna[i+2] != '\0'; i += 3) {
        int index = (strchr(bases, rna[i]) - bases) * 16 + 
                    (strchr(bases, rna[i+1]) - bases) * 4 + 
                    (strchr(bases, rna[i+2]) - bases);
        j += sprintf(&aminoAcids[j], "%s ", codonTable[index]);
    }
    aminoAcids[j-1] = '\0'; // Null-terminate the amino acid string
}

int main() {
    char dna[100], rna[100], aminoAcids[300];

    printf("Enter a DNA sequence: ");
    scanf("%s", dna);

    dnaToRna(dna, rna);
    printf("RNA sequence: %s\n", rna);

    countNucleotides(dna);
    calculateGcContent(dna);
    rnaToAminoAcids(rna, aminoAcids);
    printf("Amino acid sequence: %s\n", aminoAcids);

    return 0;
}
