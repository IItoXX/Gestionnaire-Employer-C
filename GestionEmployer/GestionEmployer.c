#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

typedef struct Individu
{
    char nom[16];
    char prenom[16];
    int age;
    int salaire;
    int rib;
    int rtt;
} Individu;

void afficherListeContacts(Individu contacts[], int taille)
{
    int totalRTT = 0;
    int totalAge = 0;
    int totalSalaire = 0;

    printf("Liste de contacts :\n");
    for (int i = 0; i < taille; ++i) {
        printf("%d\t. Prenom -> %s\t    | Nom -> %s\t   | Age -> %d\t   | Salaire -> %d\t   | RIB -> %d\t   | RTT -> %d\t   | \n", i + 1, contacts[i].prenom, contacts[i].nom, contacts[i].age, contacts[i].salaire, contacts[i].rib, contacts[i].rtt);

        totalRTT += contacts[i].rtt;
        totalAge += contacts[i].age;
        totalSalaire += contacts[i].salaire;
    }

    if (taille > 0) {
        double moyenneAge = (double)totalAge / taille;
        double moyenneSalaire = (double)totalSalaire / taille;

        printf("Total des RTT : %d\t | Moyenne d'age : %d\t | Moyenne du salaire : %d Euro\t|\n", totalRTT, (int)moyenneAge, (int)moyenneSalaire);
    }
    else {
        printf("Aucun contact � afficher.\n");
    }

    printf("\n");
}


bool checkDuplicateRib(Individu contacts[], int taille, int newRib)
{
    for (int i = 0; i < taille; ++i) {
        if (contacts[i].rib == newRib) {
            return true;
        }
    }
    return false;
}


void generatePassword()
{
    srand(time(0));
    char pass[13];

    char data[] = "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0987654321"
        "~`!@#$%^&*()_+-={}|[]:>?<;.,";

    for (int i = 0; i < 12; i++)
    {
        pass[i] = data[rand() % 93];
    }
    pass[12] = '\0';

    printf("");
    printf("         --> [Mot De Passe ]: %s\n\n\n\n", pass);
}


void ajouterContact(Individu contacts[], int* taille)
{
    if (*taille < 50) {
        printf("Nouveau contact :\n");

        printf("Nom : ");
        scanf_s("%s", contacts[*taille].nom);

        printf("Prenom : ");
        scanf_s("%s", contacts[*taille].prenom);

        printf("Age : ");
        scanf_s("%d", &contacts[*taille].age);

        printf("Salaire : ");
        scanf_s("%d", &contacts[*taille].salaire);

        printf("RIB : ");
        scanf_s("%d", &contacts[*taille].rib);

        printf("RTT : ");
        scanf_s("%d", &contacts[*taille].rtt);

        int newRib;

        do {
            printf("RIB Existant (rentrer un nouveau) : ");
            scanf_s("%d", &newRib);

            if (checkDuplicateRib(contacts, *taille, newRib))
            {
                printf("Rib deja Existant\n");
            }
        } while (checkDuplicateRib(contacts, *taille, newRib));

        contacts[*taille].rib = newRib;

        (*taille)++;

    }
    else {
        printf("La liste d'employer est pleine, virez-en vite !\n");
    }
}

void supprimerContact(Individu contacts[], int* taille) {
    if (*taille > 0) {
        int indice;
        printf("Indiquez le numero du contact a virer (Nombre d'employer -> %d) : ", *taille);
        scanf_s("%d", &indice);

        if (indice >= 1 && indice <= *taille) {
            for (int i = indice - 1; i < *taille - 1; ++i)
            {
                contacts[i] = contacts[i + 1];
            }

            (*taille)--;
            printf("Contact Vire\n");
        }
        else {
            printf("Employer Invalide\n");
        }
    }
    else {
        printf("Liste d'employer vide\n");
    }
}

void modifierContact(Individu contacts[], int taille)
{
    if (taille > 0) {
        int indice;
        printf("Indiquez le numero du contact � modifier (Nombre d'employer -> %d) : ", taille);
        scanf_s("%d", &indice);

        if (indice >= 1 && indice <= taille) {
            printf("Nouvelles informations pour le contact %d :\n", indice);

            printf("Nom : ");
            scanf_s("%s", contacts[indice - 1].nom);

            printf("Prenom : ");
            scanf_s("%s", contacts[indice - 1].prenom);

            printf("Age : ");
            scanf_s("%d", &contacts[indice - 1].age);

            printf("Salaire : ");
            scanf_s("%d", &contacts[indice - 1].salaire);

            printf("RIB : ");
            scanf_s("%d", &contacts[indice - 1].rib);

            printf("RTT : ");
            scanf_s("%d", &contacts[indice - 1].rtt);

            printf("Contact Modifi�\n");
        }
        else {
            printf("Employer Invalide\n");
        }
    }
    else {
        printf("Liste d'employer vide\n");
    }
}

int main()
{

    int taille = 44;
    Individu contacts[50] = {
        {"Dupont", "Alice", 35, 2800, 4567,3},
{"Martin", "Louis", 42, 2300, 8912, 7},
{"Dubois", "Sophie", 27, 1500, 2345, 2},
{"Lefevre", "Pierre", 55, 3100, 6789, 5},
{"Moreau", "Emma", 31, 2000, 1234, 8},
{"Girard", "Mathieu", 48, 2800, 5678, 1},
{"Leroux", "Julie", 22, 1800, 7890, 4},
{"Fournier", "Antoine", 39, 3200, 3456, 6},
{"Caron", "Elise", 26, 2500, 9012, 0},
{"Rousseau", "Gabriel", 43, 2900, 6789, 9},
{"Lemoine", "Charlotte", 34, 2000, 1234, 2},
{"Picard", "Alexandre", 29, 1700, 5678, 7},
{"Garnier", "Camille", 53, 3300, 2345, 1},
{"Chevalier", "Lucie", 24, 1400, 4567, 8},
{"Meyer", "Theo", 45, 3000, 7890, 4},
{"Huet", "Manon", 38, 2600, 3456, 6},
{"Lucas", "Arthur", 21, 1900, 8912, 3},
{"Fontaine", "Laura", 58, 3400, 9012, 5},
{"Riviere", "Hugo", 33, 2400, 6789, 0},
{"Guerin", "Hector", 49, 3100, 1234, 9},
{"Leclerc", "Nathan", 30, 2200, 4567, 2},
{"Renard", "Amandine", 25, 1600, 7890, 7},
{"Roux", "Noah", 47, 3000, 2345, 1},
{"Gauthier", "Basilou", 32, 2100, 5678, 4},
{"Perrin", "Mathis", 56, 3300, 9012, 8},
{"Colin", "Emma", 28, 1800, 3456, 6},
{"Fabre", "Louis", 41, 2600, 6789, 3},
{"Brun", "Chlo�", 23, 1500, 1234, 9},
{"Blanc", "Antoine", 54, 3200, 8912, 0},
{"Marchand", "Juliette", 37, 2300, 4567, 5},
{"Morin", "Gabriel", 20, 1400, 7890, 2},
{"Leconte", "Alice", 44, 2900, 5678, 1},
{"Guillot", "Hugo", 31, 2000, 2345, 7},
{"Bertrand", "Charlotte", 26, 1700, 9012, 4},
{"Dumont", "Alexandre", 52, 3100, 3456, 8},
{"Benoit", "Chiela", 35, 2400, 5678, 3},
{"David", "Thomas", 27, 1600, 8912, 6},
{"Berger", "Amandine", 46, 2800, 1234, 0},
{"Fischer", "Lucie", 33, 2200, 4567, 9},
{"Goncalves", "Theo", 21, 1500, 6789, 5},
{"Lejeune", "Manon", 50, 3200, 9012, 1},
{"Lefort", "Basilou", 29, 1900, 3456, 8},
{"Deschamps", "Arthur", 38, 2600, 5678, 2},
{"Pierre", "Saminou", 24, 1700, 1234, 7},
{"Leblanc", "Chloe", 55, 3300, 7890, 6},
{"Lopez", "Nathan", 30, 2000, 4567, 4},
{"Henry", "Chiena", 43, 2900, 8912, 9},
{"Roussel", "Lucas", 22, 1600, 2345, 0},
{"Bouvier", "Camille", 51, 3000, 5678, 5},
{"Leroy", "Theo", 34, 2100, 9012, 1},
    };


    int choix;
    do {
        system("color 3");
        printf("Menu :\n");
        printf("                1. Afficher liste de contacts\n");
        printf("                2. Ajouter un contact\n");
        printf("                3. Supprimer un contact\n");
        printf("                4. Modifier un contact\n");
        printf("                5. Generer un Mot de Passe Aleatoire\n");
        printf("                    6. Quitter\n");
        printf("Choix : ");
        scanf_s("%d", &choix);

        switch (choix) {
        case 1:
            afficherListeContacts(contacts, taille);
            break;
        case 2:
            ajouterContact(contacts, &taille);
            break;
        case 3:
            supprimerContact(contacts, &taille);
            break;
        case 4:
            modifierContact(contacts, taille);
            break;
        case 5:
            generatePassword();
            break;
        case 6:
            printf("Au revoir!\n");
            break;
        default:
            printf("\033[1;Choix invalide.Veuillez choisir une option valide.\033[0m\n");
        }
    } while (choix != 6);

    return 0;
}