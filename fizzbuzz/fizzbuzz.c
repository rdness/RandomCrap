#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//***************************************************************************************
// Global Variable Declarations
//***************************************************************************************

struct Map {
    int mod;
    char* str;
};

const int STARTING_VALUE = 1;
const int ENDING_VALUE = 100;
const struct Map REPLACEMENTS[] = {
    {3, "fizz"},
    {5, "buzz"}
};

//***************************************************************************************
// Prototypes
//***************************************************************************************

void updateStr(char** curr, int i, int mod, const char* catStr);
int strlens(const char* str);
char* initStr(int strLen);

//***************************************************************************************
// Main Function
//***************************************************************************************

int main() {

    int i, j;
    int numReps = sizeof(REPLACEMENTS) / sizeof(REPLACEMENTS[0]);

    for(i = STARTING_VALUE; i <= ENDING_VALUE; i++) {
        char* output = NULL;
        
        for(j = 0; j < numReps; j++) {
            updateStr(  &output, 
                        i, 
                        REPLACEMENTS[j].mod, 
                        REPLACEMENTS[j].str);
        }
        
        if(output){
            printf("%s", output);
            free(output);
        } else {
            printf("%d", i);
        }

        printf("\n");
    }

    return 0;
}

//***************************************************************************************
// Definition
//***************************************************************************************

void updateStr(char** currPtr, int i, int mod, const char* catStr) {
    
    if(i % mod)
        return;

    char* curr = *currPtr;
    char* newStr = initStr(strlens(curr) + strlens(catStr) + 1);
    
    if(curr) {
        strcpy(newStr, curr);
        free(curr);
    }

    strcat(newStr, catStr);
    *currPtr = newStr;
}

int strlens(const char* str) {
    return ( str ? strlen(str) : 0 );
}

char* initStr(int strLen) {
    if(strLen > 0) {
        char* mem = (char*) malloc(sizeof(char) * strLen);
        mem[0] = '\0';
    
        return mem;
    }

    return NULL;
}
