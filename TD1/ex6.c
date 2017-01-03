#include <stdio.h>
#include <limits.h>

int main(void){
    int wMin = INT_MAX;
    int wMax = INT_MIN;
    int wRead = 1;

    while(wRead != 0){
        printf("Saisir un entier positif : ");
        scanf("%d", &wRead);
        while(wRead < 0){
            printf("Ce nombre est négatif. Saisir un entier positif : ");
            scanf("%d", &wRead);
        }
        if(wRead > 0){
            if (wRead > wMax){
                wMax = wRead;
            }
            if (wRead < wMin){
                wMin = wRead;
            }
        }
    }

    printf("Le nombre minimum est %d\nLe nombre maximum est %d\n", wMin, wMax);
    return 0;
}
