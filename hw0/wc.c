/*
* implement man wc
*/

#include <stdio.h>

// helper function signature
FILE* openReadFile(const char *fileName);
void closeFile(FILE* fp);

// constant
const unsigned int MAX_STR = 256;

int main(int argc, char *argv[]) {
    if(argc > 2) {
        printf("Number of arguments are not correct");
    }

    char curChar;
    unsigned int chars = 0, words = 0, lines = 0;

    FILE* fp = NULL;
    char* fileName = NULL;
    if(argc == 1) {
        fp = stdin;
        fileName = "stdin";
    } else {
        fileName = argv[1];
        fp = openReadFile(fileName);
    }

    // open file for reading
    if(fp) {
        do{
            curChar = fgetc(fp);
            if(!feof(fp)){
                // printf("current char: %c", curChar);
                if(curChar == '\n') {
                    ++words;
                    ++lines;
                }

                if(curChar == ' ') {
                    ++words;
                }
                ++chars;
            }
        }while(!feof(fp));
        printf("%d %d %d %s\n",lines, words, chars, fileName);
    }

    closeFile(fp);
    return 0;
}

FILE* openReadFile(const char *fileName) {
    FILE* fp;
    fp = fopen(fileName, "r");
    return fp;
}

void closeFile(FILE* fp) {
    if(fp) {
        fclose(fp);
    }
}
