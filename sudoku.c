// Maria Clara Miranda de Sá 21.2.4187 turma 33
// Sudoku - trabalho prático
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcoes.h"
#include "implementacao.h"

#define TAM 9

// Função principal
int main(){
    int campo[TAM][TAM], original[TAM][TAM], opcao;
    char txt[20], nivel;

    printf("\nBem vindo ao Sudoku!\n");
    printf("\n0 - Sair do jogo\n1 - Gerar novo jogo\n2 - Carregar novo jogo\n3 - Resolver jogo\n\nDigite sua opção: ");
    scanf("%d", &opcao);

  switch(opcao){
    case 0:
      printf("\nAté mais!");
      break;
    case 1:
      printf("\nQual o nível de dificuldade? \nF - fácil\nD- difícil\nOpção escolhida: ");
      scanf("%c", &nivel); 
      imprimiMatriz(campo);
       break;
    case 2: 
      printf("Digite o nome do arquivo que contém o jogo: ");
      scanf("%s", txt);
      break;
    case 3:
      resolverSudoku(campo);
      break;
    
  }
    FILE *leitura = fopen(txt, "r");
    preencheMatriz(campo, leitura);
    fclose(leitura);

    copiaMatriz(campo, original);
    imprimiMatriz(campo);
    leDados(campo, original, txt);

    return 0;
}
// função para preencher matriz
void preencheMatriz(int campo[TAM][TAM], FILE *arquivo){
    int **matriz = (int **) malloc(TAM * sizeof(int *));
    for (int i = 0; i < TAM; i++) {
        matriz[i] = (int *) malloc(TAM * sizeof(int));
    }
    for (int i = 0; i < TAM; i++) {
      for (int j = 0; j < TAM; j++) {
            fscanf(arquivo, "%d", &matriz[i][j]);
            campo[i][j] = matriz[i][j];
        }
    }
    for (int i = 0; i < TAM; i++) {
      free(matriz[i]);
    }
    free(matriz);
}
void copiaMatriz(int campo[TAM][TAM], int original[TAM][TAM]){
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            original[i][j] = campo[i][j];
        }
    }
}
// função para imprimir matriz
void imprimiMatriz(int campo[TAM][TAM]){
    printf("\n\n -----------------------------------\n");
    for(int i = 0; i <= 8; i++){
        for(int j = 0; j <= 8; j++){
            if(j == 0)
                printf(" | ");
            if(campo[i][j] == 0){
                printf(" _ ");
            }
            else
                printf(" %d ", campo[i][j]);
            if((j + 1) % 3 == 0)
                printf(" | ");
        }
        printf("\n");
        if((i + 1) % 3 == 0){
            printf(" ---------------------------------\n");
        }
    }
}
// função para lê dados
void leDados(int campo[TAM][TAM], int original[TAM][TAM], char txt[]){
    char entrada[20];
    int coluna, linha, numero;

    // loop que lê os dados enquanto o usuário não digita "sair" ou "salvar" ou ganha
    do{
        scanf("%s", entrada);
        int seguranca = identificaEntrada(campo, entrada, &coluna, &linha, &numero, txt);
        // só passa se não for "sair" ou "salvar"
        if(seguranca > 0){
            int verificados = verificaDados(campo, original, coluna, linha, numero);
            if(seguranca != 0){
                if(verificados == 0){
                    campo[linha][coluna] = numero;
                    imprimiMatriz(campo);
                }
            }
        }
        vitoria(campo, &numero);
    }while(numero != 42);
}
int identificaEntrada(int campo[TAM][TAM], char entrada[], int *coluna, int *linha, int *numero, char txt[]){
    if((strcmp(entrada, "voltar")) == 0){
        
    if((strcmp(entrada, "salvar")) == 0){
        salvaJogo(campo, txt);
        return 0;
    }
    else{
        *linha = (entrada[0]) - 49;
        *coluna = (entrada[1]) - 49;
        *numero = (entrada[2]) - 48;
    }
    return 1;
}
// função para salvar jogo
void salvaJogo(int campo[TAM][TAM], char txt[]){
    FILE *arquivo = fopen(txt, "w+");
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            fprintf(arquivo, "%d", campo[i][j]);
        }
        fprintf(arquivo, "\n");
    }
    fclose(arquivo);
    printf("Jogo foi salvo em %s", txt);
}
int verificaDados(int campo[TAM][TAM], int original[TAM][TAM], int coluna, int linha, int numero){
    int vOriginal = verificaOriginal(original, linha, coluna);
    int vLinha = verificaLinha(campo, linha, numero);
    int vColuna = verificaColuna(campo, coluna, numero);
    int vBloco = verificaBloco(campo, linha, coluna, numero);

    if(vOriginal == 0 && vLinha == 0 && vColuna == 0 && vBloco == 0)
        return 0;
    else
        return 1;
}
int verificaOriginal(int original[TAM][TAM], int linha, int coluna){
        int numero;
        if(original[linha][coluna] != 0){
            printf("Erro! A célula %d, %d já possui o valor %d", linha, coluna, numero);
            return 1;
        }
        return 0;
}
// Função que verifica se as linhas do jogo não tem elementos repetidos
int verificaLinha(int campo[TAM][TAM], int linha, int numero){
    for(int i = 0; i < TAM; i++){
        if(campo[linha][i] == numero){
            printf("Erro! A linha %d já possui o valor %d na posição %d\n", (linha + 1), numero, (i + 1));
            return 1;
        }
    }
    return 0;
}
// Função que verifica se as colunas do jogo não tem elementos repetidos
int verificaColuna(int campo[TAM][TAM], int coluna, int numero){
    for(int i = 0; i < TAM; i++){
        if(campo[i][coluna] == numero){
            printf("Erro! A coluna %d já possui o valor %d na posição %d\n", (coluna + 1), numero, (i + 1));
            return 1;
        }
    }
    return 0;
}
// Função que verifica se os blocos (MATRIZ 3X3) do jogo não tem elementos 
//repetidos.
int verificaBloco(int campo [TAM][TAM], int linha, int coluna, int numero){
    int inicioBlocoL, inicioBlocoC, bloco;

    inicioBlocoL = (linha + (3 - (linha % 3))) - 3;
    inicioBlocoC = (coluna + (3 - (coluna % 3))) - 3;
    // achando o bloco
    switch(inicioBlocoC){
        case 0:
            bloco = 1;
            break;
        case 3: 
            bloco = 2;
            break;
        default:
            bloco = 3;
            break;
    }
    // cada linha são três blocos
    bloco += inicioBlocoL;
    // dois laços alinhados para percorrer o bloco
    for(int i = inicioBlocoL; i < (inicioBlocoL + 3); i++){
        for(int j = inicioBlocoC; j < (inicioBlocoC + 3); j++){
            if(campo[i][j] == numero){
                printf("Erro! O número %d já está no bloco %d\n", numero, bloco);
                return 1;
            }
        }
    }
    return 0;
}
// função que informa o usuário que ele ganhou
void vitoria(int campo[TAM][TAM], int *numero){
    int contador = 0;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if((campo[i][j] != 0)){
                contador++;
            }
        }
    }
    if(contador == 81){
        printf("Você venceu, parabéns!\n");
        *numero = 42;
    }
    else
       printf("Que pena, você não conseguiu...");
}
// função que resolve jogo de onde o usuário parou
void resolver(int campo[TAM][TAM]){
    int i, j;
    for (i = 0; i < 9; i++){
        for (j = 0; j < 9; j++){
            if (campo[i][j] == 1)
                campo[i][j] = rand() % 9 + 1;
        }
    }
}
void jogada(){
	printf("\nInforme o número, a linha, a coluna e a região que deseja inserir: ");
	scanf("%d %d %d %d", &numero, &linha, &coluna, &regiao);
}