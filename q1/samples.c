#include <stdlib.h>
#include <stdio.h>
#include <time.h>


long getRandomNumber(long lower, long upper, long m){

    long number = (rand() % (upper - lower + 1)) + lower;
    if (number > (upper - m)){
        return upper - m - 2;
    }
    else{
        return number;
    }

}

int main(int agrc, char* argv[]){

    srand(time(0));

    FILE *text_file = fopen(argv[1], "r");


    if (text_file == NULL){

        printf("\nError: Cannot open this file");
        return 0;

    }

    long counter;

    fseek(text_file, 0, SEEK_END); // shifted to end of file

    counter = ftell(text_file); // current position of text_file
    

    for (int i = 0; i < atoi(argv[2]); i++){
        printf(">");

        fseek(text_file, getRandomNumber(1, counter, atoi(argv[3])), SEEK_SET);

        for (int j = 0; j < atoi(argv[3]); j++){
            char letter = fgetc(text_file);
            if (letter < 32){
                j--;
                continue;
            }
            else{
                printf("%c", letter);
            }
        }
        printf("<");
        printf("\n");
    }
    return 0;
}