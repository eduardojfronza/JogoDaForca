#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "forca.h"

// variaveis globais
char palavrasecreta[TAMANHO_PALAVRA];
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
    int erros = chuteserrado();

   printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros>=1 ? '(' : ' '), (erros >=1 ? '_' : ' '), (erros >=1 ? ')' : ' '));
    printf(" |      %c%c%c  \n", (erros>=3 ? '\\' : ' '), (erros >= 2 ? '|' : ' '), (erros >=3 ? '/' : ' '));
    printf(" |       %c     \n", (erros>=2 ? '|' : ' '));
    printf(" |      %c %c   \n", (erros>=4 ? '/' : ' '), (erros >= 4 ? '\\' : ' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");

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
    FILE *f;

    f = fopen("palavras.txt", "r");

    if (f == 0)
    {
        printf("Desculpe banco de dados nao disponivel \n");
        exit(1);
    }

    int qtddepalavras;
    fscanf(f, "%d", &qtddepalavras);

    srand(time(0));
    int randomico = rand() % qtddepalavras;

    for (int i = 0; i <= randomico; i++)
    {
        fscanf(f, "%s", palavrasecreta);
    }

    fclose(f);
}

int chuteserrado(){
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

    return erros;
}

int enforcou()
{
    return chuteserrado() >= 5;
}

int acertou()
{
    for (int i = 0; i < strlen(palavrasecreta); i++)
    {
        if (!jachutou(palavrasecreta[i]))
        {
            return 0;
        }
    }

    return 1;
}

void adicionapalavra()
{
    char quer;
    char novapalavra[TAMANHO_PALAVRA];

    printf("Voce deseja adicionar uma nova palavra no jogo? (S/N) \n");
    scanf(" %c", &quer);

    if (quer == 'S' | quer == 's')
    {
        printf("Qual a nova palavra?\n");
        scanf("%s", novapalavra);
    }

    FILE *f;
    // usamos r+ para ler e escrever no arquivo
    f = fopen("palavras.txt", "r+");
    if (f == 0)
    {
        printf("Desculpe banco de dados nao disponivel \n");
        exit(1);
    }

    int qtd;
    fscanf(f, "%d", &qtd);
    qtd++;

    fseek(f, 0, SEEK_SET);
    fprintf(f, "%d", qtd);

    fseek(f, 0, SEEK_END);
    fprintf(f, "\n%s", novapalavra);

    fclose(f);
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

    if(acertou()) {
        printf("Voce ganhou! \n");
        printf("   _____________\n");
        printf("  '._==_==_==_.'\n");
        printf("  .-\\:         /-.\n");
        printf(" | (|:.       |) |\n");
        printf("  '-|:.       |-' \n");
        printf("    \\::.      /\n");
        printf("     '::.    '\n");
        printf("       )   (\n");
        printf("     _.'   '._\n");
        
    } else {
        printf("Voce perdeu!\n");
        printf("A palavra secreta era **%s** \n\n", palavrasecreta);
        printf("███████████████████████████\n");
        printf("███████▀▀▀░░░░░░░▀▀▀███████\n");
        printf("████▀░░░░░░░░░░░░░░░░░▀████\n");
        printf("███│░░░░░░░░░░░░░░░░░░░│███\n");
        printf("██▌│░░░░░░░░░░░░░░░░░░░│▐██\n");
        printf("██░└┐░░░░░░░░░░░░░░░░░┌┘░██\n");
        printf("██░░└┐░░░░░░░░░░░░░░░┌┘░░██\n");
        printf("██░░┌┘▄▄▄▄▄░░░░░▄▄▄▄▄└┐░░██\n");
        printf("██▌░│██████▌░░░▐██████│░▐██\n");
        printf("███░│▐███▀▀░░▄░░▀▀███▌│░███\n");
        printf("██▀─┘░░░░░░░▐█▌░░░░░░░└─▀██\n");
        printf("██▄░░░▄▄▄▓░░▀█▀░░▓▄▄▄░░░▄██\n");
        printf("████▄─┘██▌░░░░░░░▐██└─▄████\n");
        printf("█████░░▐█─┬┬┬┬┬┬┬─█▌░░█████\n");
        printf("████▌░░░▀┬┼┼┼┼┼┼┼┬▀░░░▐████\n");
        printf("█████▄░░░└┴┴┴┴┴┴┴┘░░░▄█████\n");
        printf("███████▄░░░░░░░░░░░▄███████\n");
        printf("██████████▄▄▄▄▄▄▄██████████\n");
        printf("███████████████████████████\n");
    }
}