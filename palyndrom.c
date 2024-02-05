#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char * reverse(char * word){


    int length = strlen(word);
    char* rev = malloc(length+1);

    for(int i = length-1; i>=0 ;i--){

        rev[i]=word[length-i-1];
    }
    rev[length] = '\0';

    //printf("%s", rev);


    return rev;
}

int is_palindrom(char *word){

    char *word2 = reverse(word);
    int value = strcmp(word,word2);
    if(value == 0)
        printf("strings are same %s\n",word);
    else
        printf("strings are not same %s %s\n",word, word2);

    return 0;
}


int main() {

    char *filename = "../text.txt";
    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Error: could not open file %s", filename);
        return 1;
    }


        const unsigned MAX_LENGTH = 256;
        char buffer[MAX_LENGTH];

        while (fgets(buffer, MAX_LENGTH, fp)) {
            buffer[strcspn(buffer, "\n")] = 0;  // Remove the newline character
            is_palindrom(buffer);
            printf("%s", buffer);
        }

        // close the file
        fclose(fp);

        return 0;

}
