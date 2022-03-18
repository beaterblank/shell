#include "globals.c"

void prompt(){
    getcwd(CWD, sizeof(CWD));
    printf(RED BOLD "%s" UNBOLD RESET ":",PROMPT);
    printf(BLU BOLD "%s" UNBOLD RESET ":",CWD);
}

char* splitNext(char* str,char delimeter){
    char* token = strtok(str,delimeter);
    str = strtok(NULL,delimeter);
    return token;
}


void input(){
    scanf("%[^\n]%*c",INPUT);
}

void parse(){
    char* item = splitNext();
}