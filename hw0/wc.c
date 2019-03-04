/*
* implement man wc
*/

#include <stdio.h>

// struct for word counting
typedef struct wcresult {
    int chars;
    int words;
    int lines;
} wcresult_t;

// helper function signature
FILE* openReadFile(const char *fileName);
void closeFile(FILE *fp);
void wordCount(FILE *fp, wcresult_t *res);

// constant
const unsigned int MAX_STR = 256;

int main(int argc, char *argv[]) {
    if(argc > 2) {
        printf("Number of arguments are not correct");
    }

    wcresult_t result = {0,0,0};

    FILE* fp = NULL;
    char* fileName = NULL;
    if(argc == 1) {
        fp = stdin;
        fileName = "stdin";
    } else {
        fileName = argv[1];
        fp = openReadFile(fileName);
    }
    wordCount(fp, &result);
    printf("%d %d %d %s\n",result.lines, result.words, result.chars, fileName);
    closeFile(fp);
    return 0;
}

void wordCount(FILE *fp, wcresult_t *res) {
    char *wordStart = NULL;
    // open file for reading
    if(fp && res) {
        do{
            char curChar = fgetc(fp);
            if(!feof(fp)){
                if(curChar == '\n') {
                    if(wordStart) {
                        ++(res->words);
                    }
                    wordStart = NULL;
                    ++(res->lines);
                } else if(curChar == ' ') {
                    if(wordStart) {
                        ++(res->words);
                    }
                    wordStart = NULL;
                } else {
                    if(!wordStart) wordStart = &curChar;
                }
                ++(res->chars);
            }
        }while(!feof(fp));

        if(wordStart) ++(res->words);
    }
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
