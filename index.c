#include <stdio.h>
#include <string.h>

void abertura() {
    printf("/****************/\n");
    printf("/ Jogo de Forca */\n");
    printf("/****************/\n\n");
}

void chuta(char chutes[26], int* tentativas) {
        char chute;
        scanf(" %c", &chute);

        chutes[(*tentativas)] = chute;
        (*tentativas)++;
}

int main()
{
    char palavrasecreta[20];

    sprintf(palavrasecreta, "Melancia");

    int acertou = 0;
    int enforcou = 0;

    char chutes[26];
    int tentativas = 0;

    abertura();

    do
    {
        // Looping para percorrer todas as letras da palavra secreta
        for (int i = 0; i < strlen(palavrasecreta); i++)
        {
            int achou = 0;
            // Lopping para verificar se o chute da letra tem na palavra secreta
            for (int j = 0; j < tentativas; j++)
            {
                if (chutes[j] == palavrasecreta[i])
                {
                    // se o chute(letra) tiver na palavra secreta o achou vai ser verdadeiro
                    achou = 1;
                    break;
                }
            }
            if (achou)
            {
                // se achou a letra printa a letra na posição que ela está na palavra secreta
                printf("%c ", palavrasecreta[i]);
            }
            else
            {
                printf("_ ");
            }
        }

        printf("\n");

        chuta(chutes, &tentativas);

    } while (!acertou && !enforcou);
}