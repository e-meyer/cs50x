#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string str);
void rotate(char c, int key);

int main(int argc, string argv[])
{
    string str = argv[1];
    if(argv[1] == NULL || argc > 2 || !only_digits(str)){
        printf("Usage: ./caesar key\n");                    // if no args || if more than 2 arg (command and key) || isn't a digit
        exit(1);                                            // exits the program
    }else
    {
        int num = atoi(str);
        string text = get_string("plain text: ");
        printf("ciphertext: ");
        int size = strlen(text);
        for (int i = 0; i < size; i++){
            rotate(text[i], num);                           // for the size of the string given, iterate
        }
        printf("\n");                                       // newline at the end

    }
}

void rotate(char c, int key)
{
    if(isalpha(c))
    {
        int num = key % 26;
        if(isupper(c))
        {
            // c >= 65 && c <= 90
            // get ASCii of actual char + value of key and check if the result is > 90
            //      if so, start over the uppercase alphabet
            if((c + num) > 90)
            {
                c += num;
                c -= 26;
            }
            else if((c + num) < 65) // same logic happens here, but this condition is for negative numbers
            {
                c += num;
                c += 26;
            }
            else
            {
                c += num;
            }
            printf("%c", c);
        }else
        {
            // c >= 97 && c <= 122
            // get ASCii of actual char + value of key and check if the result is > 122
            //      if so, start over the lowercase alphabet
            if((c + num) > 122)
            {
                c += num;
                c -= 26;
            }
            else if((c+num) < 97)  // same logic happens here, but this condition is for negative numbers
            {
                c += num;
                c += 26;
            }
            else
            {
                c += num;
            }
            printf("%c", c);
        }
    }else
    {
        printf("%c", c);
    }
}

bool only_digits(string str){
    int length = strlen(str);
    for (int i=0;i<length;i++){
        if(!isdigit(str[i]))
        {
            if(str[i] == '-'){
                continue;               //checks if str includes - because thats not a digit and negative numbers may be an entry
            }
            return false;
        }
    }
    return true;

}
