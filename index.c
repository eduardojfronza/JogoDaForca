#include <stdio.h>
#include <string.h>

char palavrasecreta[20];
char chutes[26];
int tentativas = 0;

void abertura()
{
    printf("/****************/\n");
    printf("/ Jogo de Forca */\n");
    printf("/****************/\n\n");
}

void chuta()
{
    char chute;
    scanf(" %c", &chute);

    chutes[tentativas] = chute;
    tentativas++;
}

int jachutou(char letra)
{
    int achou = 0;

    // Lopping para verificar se o chute da letra tem na palavra secreta
    for (int j = 0; j < tentativas; j++)
    {
        if (chutes[j] == letra)
        {
            // se o chute(letra) tiver na palavra secreta o achou vai ser verdadeiro
            achou = 1;
            break;
        }
    }
    return achou;
}

void desenhaforca()
{
    // Looping para percorrer todas as letras da palavra secreta
    for (int i = 0; i < strlen(palavrasecreta); i++)
    {
        int achou = jachutou(palavrasecreta[i]);

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
}

void escolhepalavra()
{
    sprintf(palavrasecreta, "Melancia");
}

int main()
{
    int acertou = 0;
    int enforcou = 0;

    escolhepalavra();
    abertura();

    do
    {
        desenhaforca();
        chuta();

    } while (!acertou && !enforcou);
}