
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "Russian");
    int summand1, summand2; 
    int X = 138;
    FILE* input_file;
    char const* const filePath = "C:\\Users\\sahau\\Desktop\\entrance.txt";
    input_file = fopen(filePath, "r");
    if (input_file == NULL)
    {
        // File not opened!
        // TODO: handle fopen retval
        return -1;
    }

    // loop of reading file with EOF handling
    while (!feof(input_file))
    {
        char readChar = fgetc(input_file);
        putc(readChar, stdout);
        //printf("%c", readChar);
    }
    char c;
    while ((c = fgetc(input_file)) != EOF)
    {
        // TODO: handle read character
    }

    fclose(input_file);

    return 0;
}
