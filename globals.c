#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define PROMPT_MAX 10

#define RED    "\x1B[31m"
#define GRN    "\x1B[32m"
#define YEL    "\x1B[33m"
#define BLU    "\x1B[34m"
#define MAG    "\x1B[35m"
#define CYN    "\x1B[36m"
#define WHT    "\x1B[37m"
#define RESET  "\x1B[0m"
#define BOLD   "\033[1m"
#define UNBOLD "\033[0m"

char PROMPT[PROMPT_MAX] = "gmteja";
char CWD[PATH_MAX];
char INPUT[20];
int COMMAND=0;