#include <stdio.h>

int main(void){

    char wChar;

    printf("Quel caractère ?");
    scanf("%c", &wChar);

    switch(wChar){
        case '@' :
        case '.' :
            printf("Caractère qui peut se trouver dans une adresse mail\n");
            break;

        case '/' :
            printf("Caractère qui peut se trouver dans une adresse http\n");
            break;

        case '<' :
        case '>' :
        case '=' :
            printf("Caractère de comparaison\n");
            break;

        case 'A' :
        case 'B' :
        case 'C' :
        case 'D' :
        case 'E' :
        case 'F' :
        case 'G' :
        case 'H' :
        case 'I' :
        case 'J' :
        case 'K' :
        case 'L' :
        case 'M' :
        case 'N' :
        case 'O' :
        case 'P' :
        case 'Q' :
        case 'R' :
        case 'S' :
        case 'T' :
        case 'U' :
        case 'V' :
        case 'W' :
        case 'X' :
        case 'Y' :
        case 'Z' :
            printf("Lettre majuscule\n");
            break;

        case '0' :
        case '1' :
        case '2' :
        case '3' :
        case '4' :
        case '5' :
        case '6' :
        case '7' :
        case '8' :
        case '9' :
            printf("Chiffre\n");
            break;

        default:
            printf("Autre caractère\n");
    }

    return 0;
}
