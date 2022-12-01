#include <stdlib.h>
#include <stdio.h>
#include <time.h>


long getRandomNumber(long lower, long upper){

    //obter um número aleatório
    long number = (rand() % (upper - lower + 1)) + lower;
    return number;

}

int main(int agrc, char* argv[]){
    //initializes random number generator
    srand(time(0));

    FILE *text_file = fopen(argv[1], "r"); //argv[1] é o ficheiro que é passado na linha de comandos


    if (text_file == NULL){ //se não for passado nenhum ficheiro, dá erro

        printf("\nError: Cannot open this file");
        return 0;

    }

    long counter;

    fseek(text_file, 0, SEEK_END); // mete a posição do ficheiro da stream a apontar para o fim
    counter = ftell(text_file); // posição atual do ficheiro
    
    
    for (int i = 0; i < atoi(argv[2]); i++){ //atoi transforma uma string em int, argv[2]=n
        //inicio de cada linha
        printf(">");
        //procurar o inicio da porção de texto que quero dar print
        fseek(text_file, getRandomNumber(1, counter), SEEK_SET);

        for (int j = 0; j < atoi(argv[3]); j++){//argv[3] = m
            char letter = fgetc(text_file);//em cada iteração vou buscar a próxima letra
            if (letter < 32){ //ignoramos todas as instruções da tabela ascci com cujo numero seja menor que 32
                j--;
                continue;
            }
            else{
                printf("%c", letter);
            }
        }
        printf("<");
        printf("\n");
        rewind(text_file);//vou para o inicio do file
    }
    return 0;
}