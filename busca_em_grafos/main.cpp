#include <iostream>
#include <stdio.h>

/*
 * Agora, eu tenho outro desafio
Policia e ladrão.
Basicamente, envolve conceito de busca em grafos,
se não souberem o que é isso, pensem em matriz.
O jogo consiste no seguinte:

Se os policiais chegarem a ultima posição de uma matriz
5x5, eles vencem.

exemplo:
entrada:

0 0 0 0 1
1 1 0 0 1
0 1 0 0 0
0 0 1 1 1
1 1 0 0 0

Os ladrões vencem pq os policiais não conseguem chegar
a ultima posição (as paredes são os números 1)

Já em:
0 0 0 0 1
1 1 0 0 1
0 1 0 0 0
0 0 0 1 0
1 1 0 0 0

os policiais vencem

tentem fazer ai.
 * */

int main()
{
    std::ios_base::sync_with_stdio(false);
    int matriz[5][5];
    int input;
    bool coops = false;

    std::cin >> input;

    for(int i = 0; i < input; i++)
    {
        // alimenta a matriz (cria o grafo)
        for(int line = 0; line < 5; line++){
            for(int column = 0; column < 5; column++) {
                scanf("%d", &matriz[line][column]);
            }
        }

        // analisa se há barreiras
        // se nao existir 0 abaixo, então não há passagem
        for(int line = 0; line < 4; line++){
            for(int column = 0; column < 5; column++) {
                if(matriz[line][column] == 0 && matriz[line + 1][column] == 0){
                    coops = true;
                    break;
                }else{
                    coops = false;
                }
            }
        }
        if(coops)
        {
            std::cout << "COOPS" << '\n';
        }else{
            std::cout << "ROOBERS" << '\n';
        }
    }

    return 0;
}
