#include <iostream>
#include <map>
/*
 * Pessoal, tenho um desafio legal para fazer.
Não é necessário nenhum conhecimento avançado.Mas, pode ser levemente complicado,
se a pessoa for iniciante,mas nada demais.

Seguinte:
Vcs tem uma quantidade infinita das seguintes moedas:

1, 2, 5, 10, 20.

Então, o programa de vcs deve receber um valor de entrada e o troco
deve ser o mínimo de uso de moedas possível.
Por exemplo, se a pessoa digitar 6
o troco será:

1 moeda de 5
1 moeda de 1

se for 26:

1 moeda de 20
1 moeda de 5
1 moeda de 1

se for 100:

5 moedas de 20.

Subi a resolução para o repositório.
Façam quando puderem!
 * */

inline std::map<int, int> lowest_combination(int *v, int size)
{
    int input, count = 0;
    std::map<int, int> result;

    std::cin >> input;
    // realiza a combinacao das moedas de modo a obter a menor possível
    for(int i = size - 1; i >= 0; i--){
        while(input > 0){
            if(input >= *v){
                count++;
                input -= *v;
                result[*v] = count;
            }else{
                break;
            }
        }
        *v--;
        count = 0;
    }
    return result;
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    int v[] = {1, 2, 5, 10, 20};
    int *p = &v[4];

    for(const auto& element: lowest_combination(p, 5)) {
        std::cout << element.first << ": " << element.second << '\n';
    }
    return 0;
}