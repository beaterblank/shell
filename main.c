#include "util.c"

int main(){
    printf(CLEAR);
    while (1)
    {
        prompt();
        input();
        parse();
    }
}
