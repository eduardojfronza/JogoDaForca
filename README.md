# JogoDaForca

# Jogo da forca

estrutura básica do projeto, onde farei um jogo da forca na linguagem C. Nesse arquivo tem todos os passos que trilhei para chegar no resultado final do jogo.

```c
#include <stdio.h>

int main {
    
}
```

- **Conhecendo os arrays**
    
    para declarar apenas uma string usamos o char:
    
    ```c
    char letra = 'a';
    printf("%c", letra)
    
    ```
    
    para resolvermos isso usamos uma array:
    
    ```c
    #include <stdio.h>
    
    int main() {
       char palavrasecreta[20];
    
        palavrasecreta[0] = 'M';
        palavrasecreta[1] = 'e';
        palavrasecreta[2] = 'l';
        palavrasecreta[3] = 'a';
        palavrasecreta[4] = 'n';
        palavrasecreta[5] = 'c';
        palavrasecreta[6] = 'i';
        palavrasecreta[7] = 'a';
    
        printf("%c %c %c %c %c %c %c %c %c", palavrasecreta[0], palavrasecreta[1], palavrasecreta[2], palavrasecreta[3], palavrasecreta[4], palavrasecreta[5], palavrasecreta[6], palavrasecreta[7], palavrasecreta[8]);
    }
    ```
    
    podemos melhorar isso da seguinte forma:
    
    ```c
    #include <stdio.h>
    
    int main() {
       char palavrasecreta[20];
    
        sprintf(palavrasecreta,"Melancia");
    		
    		// Note que usamos o %s para poder printar
        printf("%s", palavrasecreta);
    }
    ```
    
- L**oop do-while**
    
    a estrutura basica é:
    
    ```c
    
        int acertou = 0;
        int enforcou = 0;
    
        do
        {
            
        } while (acertou == 0 && enforcou == 0);
    ```
    
- **Percorrendo o array**
    
    para percorrer toda array podemos usar um looping:
    
    ```c
    #include <string.h>
    
    // strlen é para contar o numero de caracteres que tem na palavra secreta
    for(int i = 0; i < strlen(palavrasecreta); i++) {
                // Verifica se a letra chutada tem na palavra secreta
                if(palavrasecreta[i] == chute) {
                    printf(" A posição %d tem essa letra \n", i);
                }
            }
    ```
    
- **Laços encadeados**
    
    vamos fazer a forca funcionar de vez:
    
    ```c
    #include <stdio.h>
    #include <string.h>
    
    int main()
    {
        char palavrasecreta[20];
    
        sprintf(palavrasecreta, "Melancia");
    
        int acertou = 0;
        int enforcou = 0;
    
        char chutes[26];
        int tentativas = 0;
    
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
    
            char chute;
            scanf(" %c", &chute);
    
            chutes[tentativas] = chute;
            tentativas++;
    
        } while (!acertou && !enforcou);
    }
    ```
    
    output:
    
    ```c
    _ _ _ _ _ _ _ _ 
    M
    M _ _ _ _ _ _ _ 
    e
    M e _ _ _ _ _ _ 
    l
    M e l _ _ _ _ _ 
    a
    M e l a _ _ _ a 
    n
    M e l a n _ _ a 
    c
    M e l a n c _ a 
    i
    M e l a n c i a
    ```
    
- **Entendendo as funções**
    
    para criar uma função podemos fazer dessa maneira:
    
    ```c
    void abertura() {
        printf("/****************/\n");
        printf("/ Jogo de Forca */\n");
        printf("/****************/\n\n");
    }
    
    //Para chamar a função
    abertura()
    ```
    
- **Quebrando nosso código em funções**
    
    vamos começar a transformas algumas coisas em função, vamos começar pelo chute:
    
    ```c
    void chuta() {
            char chute;
            scanf(" %c", &chute);
    
            chutes[tentativas] = chute;
            tentativas++;
    }
    ```
    
    dessa forma não vai funcionar, precisamos passar parâmetros para  função, da seguinte forma:
    
    ```c
    void chuta(char chutes[26], int tentativas) {
            char chute;
            scanf(" %c", &chute);
    
            chutes[tentativas] = chute;
    
    }
    
    chuta(chutes, tentativas);
    tentativas++;
    ```
    
- **Entendendo os ponteiros**
    
    para podermos entender os ponteiros vamos criar um novo código:
    
    ```c
    #include <stdio.h>
    
    void calcula(int c) {
        printf("calcula %d\n", c);
        c++;
        printf("%d\n", c);
    }
    
    int main() {
        int c = 10;
    
        printf("main %d\n", c);
    
        calcula(c);
        printf("main %d\n", c);
    }
    ```
    
    no output vai dar assim:
    
    ```c
    main 10
    calcula 10
    11
    main 10
    ```
    
    por que o valor **c da função calcula** apenas copia o valor que foi passado para ele, ou seja, cria uma nova variável. Precisamos apontar que ele é a mesma da função main, para podermos fazer isso **vamos fazer com que o espaço de memoria seja o mesmo para as duas**:
    
    para isso vamos usar o **********&********** que serve para pegar o endereço de memoria de uma variável. Ou seja, precisamos passar para o função calcula o endereço da variável c, fazendo dessa maneira:
    
    ```c
        calcula(&c);
    ```
    
    agora, precisamos adptar a função:
    
    ```c
    // para acessar o valor, colocamos o * na frente do int
    
    void calcula(int* c) {
    // se usarmos o c++ ele vai mudar o endereço da variavel, por exemplo:
    // e o valor era 0001 ele vai se tornar 0002
    
    //para acessar o valor do conteudo colocamos em (*)
        (*c)++;
    }
    ```
    
    no fim a função de exemplo vai ficar assim:
    
    ```c
    #include <stdio.h>
    
    void calcula(int* c) {
        printf("Calcula %d %d\n", (*c), c);
        (*c)++;
        printf("Calcuala %d %d\n", (*c), c);
    
    }
    
    int main() {
        int c = 10;
    
        printf("main %d\n", &c);
    
        calcula(&c);
        printf("main %d\n", &c);
    }
    ```
    
    output
    
    ```c
    main -75667788
    Calcula 10 -75667788
    Calcuala 11 -75667788
    main -75667788
    ```
    
- **Melhorando a função chuta()**
    
    agora que sabemos usar ponteiro vamos atualizar o codigo:
    
    ```c
    // Guardamos o valor que estamos recebendo
    void chuta(char chutes[26], int* tentativas) {
            char chute;
            scanf(" %c", &chute);
    				// Pegamos somente o valor guardado no endereço da memoria
            chutes[(*tentativas)] = chute;
            (*tentativas)++;
    }
    
    // Passamos somente o valor guardado no endereço da memoria, atraves do &
    chuta(chutes, &tentativas);
    ```
    
    mas perceba que não passamos o chutes como ponteiro. Isso acontece por que um **array ja é um ponteiro por natureza.**
    
- **Funções com retorno**
    
    agora vamos transformar a função de encontrar a letra na palavra secreta, para isso fazemos:
    
    ```c
    void jachutou(char letra, char chutes[26], int tentativas) {
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
    }
    
    jachutou(palavrasecreta[i], chutes, tentativas);
    ```
    
    nosso código main vai ficar assim:
    
    ```c
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
                jachutou(palavrasecreta[i], chutes, tentativas);
                
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
    ```
    
    mas perceba que precisamos do retorno da função, o resultado se achou ou não a letra. Para isso fazemos assim:
    
    ```c
    // Para a função retornar algo, mudamos o void para oque queremos que ele retorne
    // nesse caso queremos um inteiro
    int jachutou(char letra, char chutes[26], int tentativas)
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
    
    		// acrescentamos oque ele retornará com o return
        return achou;
    }
    ```
    
    no main criamos um int chamado **int achou** que vai armazenar a função.
    
- **Extraindo mais funções**
    
    extraindo mais funções nosso código fica assim:
    
    ```c
    #include <stdio.h>
    #include <string.h>
    
    void abertura()
    {
        printf("/****************/\n");
        printf("/ Jogo de Forca */\n");
        printf("/****************/\n\n");
    }
    
    void chuta(char chutes[26], int *tentativas)
    {
        char chute;
        scanf(" %c", &chute);
    
        chutes[(*tentativas)] = chute;
        (*tentativas)++;
    }
    
    int jachutou(char letra, char chutes[26], int tentativas)
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
    
    void desenhaforca(char palavrasecreta[20], char chutes[], int tentativas)
    {
        // Looping para percorrer todas as letras da palavra secreta
        for (int i = 0; i < strlen(palavrasecreta); i++)
        {
            int achou = jachutou(palavrasecreta[i], chutes, tentativas);
    
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
    
    void escolhepalavra(char palavrasecreta[20])
    {
        sprintf(palavrasecreta, "Melancia");
    }
    
    int main()
    {
        char palavrasecreta[20];
    
        int acertou = 0;
        int enforcou = 0;
    
        char chutes[26];
        int tentativas = 0;
    
        escolhepalavra(palavrasecreta);
        abertura();
    
        do
        {
            desenhaforca(palavrasecreta, chutes, tentativas);
            chuta(chutes, &tentativas);
    
        } while (!acertou && !enforcou);
    }
    ```
    
- **Variáveis globais**
    
    para tornar um variavel global basta colcocar fora das funções
    
    ```c
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
    ```
    
- **Finalizando o jogo após erros seguidos**
    
    ```c
    int enforcou() {
        int erros = 0;
    
        for(int i = 0; i < chutedados; i++) {
            int existe = 0;
    
            // Para percorrer o toda a palavra secreta
            for (int j = 0; j < strlen(palavrasecreta); j++) {
                if (chutes[i] == palavrasecreta[j] )
                {
                    existe = 1;
                    break;
                }
            }
    
            if (!existe) erros++; 
        }
    
        return erros >= 5;
    }
    ```
    
    o codigo final vai ficar assim:
    
    ```c
    #include <stdio.h>
    #include <string.h>
    
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
    
    int enforcou() {
        int erros = 0;
    
        for(int i = 0; i < chutedados; i++) {
            int existe = 0;
    
            // Para percorrer o toda a palavra secreta
            for (int j = 0; j < strlen(palavrasecreta); j++) {
                if (chutes[i] == palavrasecreta[j] )
                {
                    existe = 1;
                    break;
                }
            }
    
            if (!existe) erros++; 
        }
    
        return erros >= 5;
    }
    int main()
    {
        int acertou = 0;
    
        escolhepalavra();
        abertura();
    
        do
        {
            desenhaforca();
            chuta();
    
        } while (!acertou && !enforcou());
    }
    ```
    
- **Verificando se o usuário ganhou o jogo**
    
    para verificar se ganhou fazemos o seguinte looping:
    
    ```c
    int acertou() {
        for(int i = 0; i < strlen(palavrasecreta); i++) {
            if(!jachutou(palavrasecreta[i])) {
                return 0;
            }
        }
    
        return 1;
    }
    ```
    
    e adaptamos o while para:
    
    ```c
    while (!acertou() && !enforcou());
    ```
    
- **Header files**
    
    A linguagem C tem um problema que lê as funções de cima para baixa, ou seja, se criarmos uma função no fim do código e chamarmos no começo ela não irá funcionar. Para resolver isso vamos fazer igual as variáveis globais, chamá-las em um outro arquivo com o final ****.h****
    
    ```c
    // lista de funções que aparecerão no arquivo
    int enforcou();
    void abertura();
    void chuta();
    int jachutou(char letra);
    int acertou();
    void desenhaforca();
    void escolhepalavra();
    ```
    
    **no index.c,** importamos com o nome que demos para o arquivo
    
    ```c
    #include <forca.h>
    ```
    
- **Lendo arquivos**
    
    vamos deixar a palavra secreta aleatória. Primeiro precisamos criar um arquivo ********************.txt,******************** e colocar as palavras que queremos, mas antes das palavras colocar o numero de palavras que vai ter. Depois no **index.c:**
    ```c
    //incluir as libs
	#include <time.h>
	#include <stdlib.h>
	
	void escolhepalavra()
	{
		FILE* f;
		// a função fopone serve para abrir arquivos
		// o primeiro parametro passamos o arquivo
		// o segundo como queremos abri-lo
		// nesse caso so queremos ler, entao o r (read)
	    f = fopen("palavras.txt", "r");
			// caso o arquivo esteja comrrompido ou dê algum problema
			if(f == 0) {
	        printf("Desculpe banco de dados nao disponivel /n");
	        exit(1);
	    }
	
			int qtddepalavras;
			// fscanf serve para ler arquivos
			// primeiro parametro é o arquivo que vai ler
			// o segundo para ler
			// e o terceiro para pegar o que está armazenado no ponteiro
	    fscanf(f, "%d", &qtddepalavras);
	
			// para gerar um numero aleatorio
	    srand(time(0));
	    int randomico = rand() % qtddepalavras;
	
	    for(int i = 0; i <= randomico; i++) {
					// para ler e armazenar a palavra aleatoria
	        fscanf(f, "%s", palavrasecreta);
	    }
	
			//para fechar o arquivo
			fclose(f)
	}
    ```
