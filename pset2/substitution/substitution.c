#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void cipher(string key, string text);
bool invalid_chars(string s);
bool has_duplicate(string s);

int main(int argc, string argv[])
{
    if(argv[1] == NULL || argc > 2)
    {
        printf("Usage: ./substitution key\n");                    // if no args || if more than 2 arg (command and key) || isn't a digit
        exit(1);                                              // exits the program
    }
    string str = argv[1];
    if(strlen(str) < 26)                                            // checks if the key is shorter than 26 letters
    {
        printf("Key must contain 26 characters.\n");
        exit(1);
    }else if(invalid_chars(str))                                    // calls function invalid_chars to see if key
    {                                                               // only contains letters (A-z)
        printf("Key must only contain valid characters. [A-z]\n");
        exit(1);
    }else if(has_duplicate(str))                                    // calls function has_duplicate to check if key
    {                                                               // has duplicated letters
        printf("Key must not contain duplicated letters.\n");
        exit(1);
    }
    else
    {
        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");
        cipher(str, plaintext);
        printf("\n");
        return 0;
    }
}

bool has_duplicate(string s)
{
    int length = strlen(s);
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (s[i] == s[j]) {
                return true;
            }
        }
    }
    return false;
}

bool invalid_chars(string s)
{
    int length = strlen(s);
    for(int i = 0; i < length; i++){
        if(!isalpha(s[i]))
            return true;
    }
    return false;
}

void cipher(string key, string text)
{
    char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                       'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    //
    // # key:        'YTNSHKVEFXRBAUQZCLWDMIPGJO'
    // # plaintext:  'HELLO'
    // # ciphertext: 'EHBBQ'
    //
    // # H = 8th letter of array(?)
    // # 8th letter of array given = E
    //

    for (int i = 0, length_plain = strlen(text); i < length_plain; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if(isalpha(text[i]))                                         // checks if its char in plaintext is alphabetical
            {
                if(tolower(text[i]) == tolower(alphabet[j]))
                {                                                       // compares both in lower case to be easier
                    if(islower(text[i]))                                // if the char in text is in lower case
                    {
                        text[i] = tolower(key[j]);                      // then we keep it as it is, getting j index
                        break;                                          // of key and putting it into index i of text (plaintext)
                    }
                    text[i] = toupper(key[j]);                          // this is if the char is in uppercase, so just to
                    break;                                              // make sure it stays in uppercase, we use uppercase
                }                                                       // function in the key to just then store it in text[i]
            }
        }
        printf("%c", text[i]);                                          // prints out every char of the cipher text
    }

}