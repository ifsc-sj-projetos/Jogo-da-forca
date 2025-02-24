//Jogo completo
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void forca(int estado) { //funcao que implementa a forca
    if(estado == 8){
        printf("\n -----------------");
        printf("\n |               |");
        printf("\n |");
        printf("\n |");
        printf("\n |");
        printf("\n |");
        printf("\n |");
        printf("\n -");
    } else if (estado == 7){
        printf("\n -----------------");
        printf("\n |               |");
        printf("\n |               0");
        printf("\n |");
        printf("\n |");
        printf("\n |");
        printf("\n |");
        printf("\n -");  
    } else if (estado == 6){
        printf("\n -----------------");
        printf("\n |               |");
        printf("\n |               0");
        printf("\n |               |");
        printf("\n |");
        printf("\n |");
        printf("\n |");
        printf("\n -"); 
    } else if (estado == 5){
        printf("\n -----------------");
        printf("\n |               |");
        printf("\n |               0");
        printf("\n |              /|");
        printf("\n |");
        printf("\n |");
        printf("\n |");
        printf("\n -"); 
    } else if (estado == 4){
        printf("\n -----------------");
        printf("\n |               |");
        printf("\n |               0");
        printf("\n |              /|\\");
        printf("\n |");
        printf("\n |");
        printf("\n |");
        printf("\n -"); 
    } else if (estado == 3){
        printf("\n -----------------");
        printf("\n |               |");
        printf("\n |               0");
        printf("\n |              /|\\");
        printf("\n |               |");
        printf("\n |");
        printf("\n |");
        printf("\n -"); 
    } else if (estado == 2){
        printf("\n -----------------");
        printf("\n |               |");
        printf("\n |               0");
        printf("\n |              /|\\");
        printf("\n |               |");
        printf("\n |              / ");
        printf("\n |");
        printf("\n -"); 
    } else if (estado == 1){
        printf("\n -----------------");
        printf("\n |               |");
        printf("\n |               0");
        printf("\n |              /|\\");
        printf("\n |               |");
        printf("\n |              / \\");
        printf("\n |");
        printf("\n -"); 
    } else if (estado == 0){
        printf("\n -----------------");
        printf("\n |               |");
        printf("\n |              /0\\");
        printf("\n |              /|\\");
        printf("\n |               |");
        printf("\n |              / \\");
        printf("\n |");
        printf("\n -"); 
    }
}

int main() {
    char rodada1[20]; // String para armazenar a palavra
    char dica[40]; // string para armazenar a dica
    char letra; // string que armazena uma letra
    int tamanho; // variavel que armazenará o tamanho da da string
    int   tentativas = 8; // contador de tentativas
    char letras_erradas[9] = {'\0'}; // string para armazenar as letras erradas
    int posi_letra_errada = 0; // variável que armazena a posição da string
    int jogar_novamente = 1; // variavel para verificar se o jogador quer jogar novamente

    while (jogar_novamente) { // looping criado para o usuario sempre jogar novamente se quiser
        system("clear"); // limpa a tela do terminal
        // Solicita a palavra e a dica do usuário
        printf("Digite a palavra a ser adivinhada: ");
        scanf("%s", rodada1);
        getchar(); // Para capturar a tecla ENTER após a digitação da palavra

        printf("Digite uma dica para a palavra: ");
        fgets(dica, 100, stdin); /* f fgets:  funcao que  lê a entrada de dados, incluindo espaços. 
        O stdin indica que os dados devem ser lidos do teclado do usuário */

        system("clear"); 
        
        tamanho = strlen(rodada1); // funcao que retorna tamanho da palavra
        
        // Cria a resposta com as letras ocultas
        char resposta[tamanho + 1]; /* +1 no tamanho da string, garante espaço para o caractere nulo que indica o final da string. */
        for (int i = 0; i < tamanho; i++) {
            resposta[i] = '_';
        }
        resposta[tamanho] = '\0';

        printf("\nDica: %s", dica); // Exibe a dica para o jogador
        printf("Resposta: %s\n", resposta); // Mostra as letras ocultas inicialmente

        tentativas = 8; // Reseta o número de tentativas
        posi_letra_errada = 0; // Reseta o contador de letras erradas
        letras_erradas[0] = '\0'; // Limpa as letras erradas

        while (tentativas > 0) { 
            printf("Digite uma letra: ");
            scanf(" %c", &letra);

            int encontrou = 0; // variavel para saber se a letra foi encontrada
            for (int i = 0; i < tamanho; i++) { // percorre cada posicao palavra 
                if (rodada1[i] == letra) { // se a rodada for igual em valor a letra
                    resposta[i] = letra; // atribui o valor da letra a resposta
                    encontrou = 1;
                }   
            }

            if (!encontrou) { // se não encontrou, decresce o contador de tentativas
                letras_erradas[posi_letra_errada++] = letra; // quando a letra estiver errada a string letras_erradas obtém o valor da variável letra
                printf("Essa letra não faz parte da palavra, você tem %d tentativas restantes\n", --tentativas);
                printf("Letras erradas: %s\n", letras_erradas);
                forca(tentativas);  
            }

            printf("Resposta: %s\n", resposta); // Exibe a resposta após cada tentativa

            // Verifica se o usuário ganhou o jogo
            int ganhou = 1;
            for (int i = 0; i < tamanho; i++) { //percorre todas as letras.
                if (resposta[i] == '_') { // Se a letra da palavra ainda estiver oculta, ganhou obtém valor 0
                    ganhou = 0;
                    break; // 
                }
            }

            if (ganhou) { // se ganhou igual a 1, ou seja, verdadeiro
                printf("Parabéns! Você ganhou o jogo!\n");
                break;  // Sai do loop de tentativas
            }
        }

        if (tentativas == 0) { // se tentativas for igual em comparação a 0
            printf("Você perdeu o jogo! A resposta era %s\n", rodada1);
        }

        // Pergunta se o jogador quer jogar novamente
        printf("\nDeseja jogar novamente? (1 - Sim, 0 - Não): ");
        scanf("%d", &jogar_novamente); // captura a resposta do jogar em valor numerico

        if (jogar_novamente == 0) { //compara o valor 
            printf("Obrigado por jogar!\n");
        }
    }

    return 0;
}


