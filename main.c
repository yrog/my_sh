#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#include "parser.h"

#define MAX_SIZE    512

int main(int argc, char* argv[])
{
    char lineInput[MAX_SIZE];
    int index = 0;
    char oneCmd[MAX_SIZE];  //Une commande en 0 et la liste des arguments ensuite
    char allCmd[MAX_SIZE];  //Une commande + arguments par indice
    
    printf("Le prompt>");
    
    if (!fgets(lineInput, MAX_SIZE, stdin)) 
        return 0;
    
    cmd = getCmd(lineInput);
    
    
    printf("%s\n", lineInput);

    return 0;
}

 
