/*JOGO DA VELHA

ALUNOS: VILTON EDSON FIGUEIRÔA DE MOURA, lUCAS NASCIMENTO*/

#include <stdio.h>
#include <stdlib.h>

/*Essa função tabuleiro irá imprimir as casas do tabuleiro do jogo da velha,
é uma matriz 3x3*/

void tabuleiro(char casas2[3][3]){

    system("cls || clear");
    printf(" %c | %c | %c \n", casas2 [0][0], casas2[0][1], casas2[0][2]);
    printf("--------------------\n");
    printf(" %c | %c | %c \n", casas2 [1][0], casas2[1][1], casas2[1][2]);
    printf("--------------------\n");
    printf(" %c | %c | %c \n", casas2 [2][0], casas2[2][1], casas2[2][2]);

}

/* essa função vai servir para checar as linhas e colunas se a casa ou coluna 0,1,2 forem iguais sendo X ou O
irá ter um ganhador*/
 int checarvitoria(char casa[3][3]) {
    int i;

    // checar linhas
    for(i = 0; i < 3; i++) {
        if(casa[i][0] == casa[i][1] && casa[i][1] == casa[i][2] && casa[i][0] != ' ')
            return 1;
    }

    // checar colunas
    for(i = 0; i < 3; i++) {
        if(casa[0][i] == casa[1][i] && casa[1][i] == casa[2][i] && casa[0][i] != ' ')
            return 1;
    }

    // checar diagonais
    if(casa[0][0] == casa[1][1] && casa[1][1] == casa[2][2] && casa[0][0] != ' ')
        return 1;
    if(casa[0][2] == casa[1][1] && casa[1][1] == casa[2][0] && casa[0][2] != ' ')
        return 1;

    return 0;
}

 /*Essa aqui e a MAIN principal, ela vai imprimir os numeros de 1 a 9 em cada espaço
 da matriz e depois vai num loop dos jogadores para inserirem o X ou O na linha e Coluna
 que desejarem*/

int main()

{

    char casa [3] [3] = { {'1', '2', '3'},

                          {'4', '5', '6'},

                          {'7', '8', '9'}, };

    char resposta;

    int num_jogadas, l, c, vez = 0, i, j;
/*eu fiz um dowhile externo que vai rodar todo o codigo do jogo*/
    do{
/*isso aqui é para contar o turno dos jogadores*/
    num_jogadas = 1;

        for(i=0;i<=2;i++){

            for(j=0;j<=2;j++){

                casa [i] [j] = ' ';

            }

        }
/*esse do while serve para chamar a funcao tabuleiro e depois pedir para o jogador a linha e coluna em 
que ele vai querer jogar */
        do{

        tabuleiro(casa);
        printf("Digite uma linha:");
        scanf("%i", &l);
        printf("Digite uma coluna:");
        scanf("%i", &c);

//aqui é para delimitar que a coluna e linha naos seja menor que 1 e maior que 3
        if(l < 1 || c < 1 || l > 3 || c > 3){

            printf("Linha ou Coluna não pode ser menor que 1\n");
            l = 0;
            c = 0;
//aqui eu fiz pra caso a casa que o jogador selecionar ja tiver com x ou o ele vai resetar
        }else if(casa [l-1] [c-1] != ' '){
            
            l = 0;
            c = 0;

        }
        else {

            if(vez % 2 == 0){
                casa [l-1] [c-1] = 'X';
            }
            else {
                casa [l-1] [c-1] = 'O';
            }
            
        }
            
        vez++;
        num_jogadas++;
        
        //o ? e o : eu pesquisei e vi que as pessoas usam como if e else porem
        // de uma maneira mais simplificada, eu nao sei se ta certo mas funcionou
        if(checarvitoria(casa)) {
            printf("O jogador que usa %c ganhou!\n", vez % 2 == 0 ? 'O' : 'X');
        }else if(num_jogadas > 9){
            printf("O jogogadores chegaram em um empate, recomece!\n");
        }
        }while(num_jogadas <= 9);
        
        printf("Você desejar jogar novamente? S/N\t");
        scanf("%s", &resposta);
    }while(resposta == 'S' || resposta == 's');
    
    return 0;
}

