#include <stdio.h>


/*
 * SUDOKU
 *
 *  - Jogo desenvolvido pelo matemático euler
 *
 * Regras:
 *
 *  - Não deve haver repetições nas linhas
 *  - Não deve haver repetições nas colunas
 *  - Não deve haver repetições nos quadrantes 3x3
 *
 * */


int main()
{

    // variaveis
    int check_line[9],           // array para verificar repetições em linhas
        check_column[9],
        block[3][3],             // bloco 3x3 da matriz para analisar repeticoes neste bloco
        comparator,              // variavel que compara se um valor já esta no array
        input,                   // limite de entradas
        index = 0,               // index para percorrer array
        aux_column = 0,          // coluna auxiliar para percorrer o bloco
        aux_line = 0,            // linha auxiliar para percorrer o bloco
        aux_array[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0},  // array que verifica repetições no bloco
        initial_limit = 0,
        final_limit = 9,
        ok = 1;                  // variavel que diz se atende ou não as regras


     // quantidade de matrizes a serem lidas
     scanf("%d", &input);

     int board[9 * input][9 * input];  // declaração do tabuleiro (matriz 9x9) * quantidade de entradas

     // alimentação da matriz conforme entrada
     for(int line = 0; line < 9 * input; line++){
         for(int column = 0; column < 9; column++){
             scanf("%d", &board[line][column]);
         }
     }

     int checkLine = 0, x = 0;


     // verificações para analisar se satisfaz as regras do sudoku
    for(int data = 0; data < input; data++){
        // verifica se existe repetição de linhas
        if(ok){
            for (int i = x; i < x + 9; i++) {
                for (int j = 0; j < 9; j++) {
                    check_line[j] = board[i][j];
                }
                for (int t = 0; t < 9; t++) {
                    int value = check_line[t];
                    for (int p = 0; p < 9; p++) {
                        if (value == check_line[p] && p != t) {
                            ok = 0;
                            //printf("OK ");
                            break;
                        }
                    }
                }
                if (ok == 0) {
                    break;
                }
            }
        }


        // verifica se há duplicadas nas colunas
        //printf("\nX %d ", x);
        if(ok){
            for (int i = 0; i < 9; i++) {
                int indice = 0;
                for (int j = x; j < x + 9; j++) {
                    check_column[indice] = board[j][i];
                    indice++;
                }
                for (int t = 0; t < 9; t++) {
                    comparator = check_column[t];
                    for(int value = 0; value < 9; value++){
                        if(comparator == check_column[value] && value != t){
                            ok = 0;
                            break;
                        }
                    }
                if (ok == 0) {
                    break;
                }
            }
            }
        }

        index = 0;
        /*
         * verifica se há repetição no quadrante (3x3),
         * para ficar mais visivel, preferi criar uma matriz (3x3)
         * e analisá-la como bloco
         * */
        for (int lines = x; lines < x + 9; lines += 3) {
            if (ok == 0) break;
            aux_line = lines;
            for (int column = 0; column < 9; column++) {
                if (ok == 0) break;
                for (int n = 0; n < 3; n++) {
                    block[n][aux_column] = board[aux_line][column];
                    aux_line++;
                }
                aux_column++;
                aux_line = lines;
                if (aux_column > 2) {
                    aux_column = 0;
                    for (int line_block = 0; line_block < 3; line_block++) {
                        if (ok == 0) break;
                        for (int column_block = 0; column_block < 3; column_block++) {
                            aux_array[index] = block[line_block][column_block];
                            index++;
                        }
                    }

                    index = 0;
                    for (int i = 0; i < 9; i++) {
                        if (ok == 0) break;
                        for (int j = 0; j < 9; j++) {
                            if (aux_array[i] == aux_array[j] && i != j) {
                                ok = 0;
                                //printf("OK3 ");
                                break;
                            }
                        }
                    }
                }
            }
        }

        //resultado
        if(ok){
            printf("CORRETO\n");
        }else {
            ok = 1;
            printf("INCORRETO\n");
        }
        x += 9;
    }

    return 0;
}
