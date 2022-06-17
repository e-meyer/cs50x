#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>

int main(){

    int letter_counter = 0, word_counter = 0, sentence_counter = 0;

    string str = get_string("Text: ");

    for(int i=0; i<strlen(str);i++){

        if(isalpha(str[i]))
            letter_counter++;
        else if(str[i] == ' ')
            word_counter++;
        else if(str[i] == '.' || str[i] == '!' || str[i] == '?')
            sentence_counter++;
    }

    word_counter++;

    double l = (double)letter_counter / word_counter * 100;
    double s = (double)sentence_counter / word_counter * 100;

    double index = 0.0588 * l - 0.296 * s - 15.8;

    if(index > 16)
        printf("Grade 16+\n");
        else if(index < 1)
            printf("Before Grade 1\n");
            else
                printf("Grade %.f\n", index);
}
