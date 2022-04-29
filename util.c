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
    else if(strcmp(ARGS[0],"clear")==0){printf(CLEAR);}
    else if(strcmp(ARGS[0],"add")==0){add();}
    else if(strcmp(ARGS[0],"sub")==0){sub();}
    else if(strcmp(ARGS[0],"div")==0){divide();}
    else if(strcmp(ARGS[0],"mul")==0){mul();}
    else if(strcmp(ARGS[0],"touch")==0){newTxt();}
    else if(strcmp(ARGS[0],"cat")==0){readTxt();}
    else if(strcmp(ARGS[0],"cd")==0){changeDir();}
    else if(strcmp(ARGS[0],"rm")==0){delete();}
    else if(strcmp(ARGS[0],"copy")==0){copy();}
    else if(strcmp(ARGS[0],"pwd")==0){pwd();}
    else if(strcmp(ARGS[0],"ls")==0){_ls(0,1);}
    else if(strcmp(ARGS[0],"date")==0){date();}
    else if(strcmp(ARGS[0],"cal")==0){calandar();}
    else if(strcmp(ARGS[0],"mkdir")==0){makedir();}
    else if(strcmp(ARGS[0],"rmdir")==0){removedir();}
    else if(strcmp(ARGS[0],"df")==0){diskspace();}
    else if(strcmp(ARGS[0],"ps")==0){processId();}
    else if(strcmp(ARGS[0],"kill")==0){pkill();}
    else{
        printf("please enter a valid command\n");
    }
}
