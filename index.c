#include <stdio.h>
#include <string.h>
#include <forca.h>


// variaveis globais
char palavrasecreta[20];
char chutes[26];
int chutedados = 0;

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

    chutes[chutedados] = chute;
    chutedados++;
}

int jachutou(char letra)
{
    int achou = 0;

    // Lopping para verificar se o chute da letra tem na palavra secreta
    for (int j = 0; j < chutedados; j++)
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

int enforcou()
{
    int erros = 0;

    for (int i = 0; i < chutedados; i++)
    {
        int existe = 0;

        // Para percorrer o toda a palavra secreta
        for (int j = 0; j < strlen(palavrasecreta); j++)
        {
            if (chutes[i] == palavrasecreta[j])
            {
                existe = 1;
                break;
            }
        }

        if (!existe)
            erros++;
    }

    return erros >= 5;
}

int acertou() {
    for(int i = 0; i < strlen(palavrasecreta); i++) {
        if(!jachutou(palavrasecreta[i])) {
            return 0;
        }
    }

    return 1;
}


int main()
{
    escolhepalavra();
    abertura();

    do
    {
        desenhaforca();
        chuta();

    } while (!acertou() && !enforcou());
}