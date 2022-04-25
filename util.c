#include "globals.c"
#include "functions.c"

void prompt(){
    getcwd(CWD, sizeof(CWD));
    printf(RED BOLD "%s" UNBOLD RESET ":",PROMPT);
    printf(BLU BOLD "%s" UNBOLD RESET "<$",CWD);
    printf(GRN BOLD "OS J COMP $>" UNBOLD RESET);
}

void input(){
    scanf("%[^\n]%*c",INPUT);
}

int split ()
{
    char c = DELIMETER;
    int count = 1;
    int token_len = 1;
    int i = 0;
    char *p;
    char *t;

    p = INPUT;
    while (*p != '\0')
    {
        if (*p == c)
            count++;
        p++;
    }

    *&ARGS = (char**) malloc(sizeof(char*) * count);
    if (*&ARGS == NULL)
        exit(1);

    p = INPUT;
    while (*p != '\0')
    {
        if (*p == c)
        {
            (*&ARGS)[i] = (char*) malloc( sizeof(char) * token_len );
            if ((*&ARGS)[i] == NULL)
                exit(1);

            token_len = 0;
            i++;
        }
        p++;
        token_len++;
    }
    (*&ARGS)[i] = (char*) malloc( sizeof(char) * token_len );
    if ((*&ARGS)[i] == NULL)
        exit(1);

    i = 0;
    p = INPUT;
    t = ((*&ARGS)[i]);
    while (*p != '\0')
    {
        if (*p != c && *p != '\0')
        {
            *t = *p;
            t++;
        }
        else
        {
            *t = '\0';
            i++;
            t = ((*&ARGS)[i]);
        }
        p++;
    }

    return count;
}

void parse(){
    len = split();
    if(strcmp(ARGS[0],"echo")==0){print();}
    if(strcmp(ARGS[0],"clear")==0){printf(CLEAR);}
    if(strcmp(ARGS[0],"add")==0){add();}
    if(strcmp(ARGS[0],"sub")==0){sub();}
    if(strcmp(ARGS[0],"div")==0){divide();}
    if(strcmp(ARGS[0],"mul")==0){mul();}
    if(strcmp(ARGS[0],"touch")==0){newTxt();}
    if(strcmp(ARGS[0],"cat")==0){readTxt();}
    if(strcmp(ARGS[0],"cd")==0){changeDir();}
    if(strcmp(ARGS[0],"rm")==0){delete();}
    if(strcmp(ARGS[0],"copy")==0){copy();}
}


char* join_str() {
    char* str = NULL;             
    size_t total_length = 0;                     
    for (int i = 1; i < len; i++) total_length += strlen(ARGS[i]);
    str = (char*) malloc(total_length);  
    str[0] = '\0';                      
    for (int i = 1; i < len; i++) {
        strcat(str, ARGS[i]);
    }
    return str;
}