#include <stdio.h>
#include <string.h>

int main() {
   char palavrasecreta[20];

    sprintf(palavrasecreta,"Melancia");

    int acertou = 0;
    int enforcou = 0;

    do
    {
        char chute;
        scanf("%c", &chute);

        // Looping para percorrer todas as letras da palavra secreta
        for(int i = 0; i < strlen(palavrasecreta); i++) {
            // Verifica se a letra chutada tem na palavra secreta
            if(palavrasecreta[i] == chute) {
                printf(" A posição %d tem essa letra \n", i);
            }
        }


    } while (!acertou && !enforcou);
    
}   