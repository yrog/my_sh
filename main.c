#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#include "parser.h"

#define MAX_SIZE    512

int main(int argc, char* argv[])
{
    char lineInput[MAX_SIZE];
    
    char cmd[MAX_SIZE];
    char args[MAX_SIZE];
    
    memset(cmd, '\0', sizeof(cmd));
    memset(args, '\0', sizeof(args));
    
    
    printf("Le prompt>");
    
    //On récupère le texte tapé dans le prompt
    if (!fgets(lineInput, MAX_SIZE, stdin)) 
        return 0;
    
    getCmdAndArgs(lineInput, cmd, args);
    
    printf("La commande est: %s\n", cmd);
    printf("Les arguments sont: %s\n", args);
    
    
    //Tant qu'il y a des commandes
        //On cherche à extraire la commande et les arguments associés
        //On cherche à connaitre l'enchainement des fonctions (pipe, ...)
    //Fin tant que
    
    //Pour chaque commande, on l'exécute et on récupère le résultat.
        //Selon l'enchainement de fonction on passe le résultat précédant à la commande qui suit.
    
    
    if (execve(cmd, args, NULL) == -1)
    {
        printf("execve returned %i\n", errno);
    }
    
    printf("%s\n", lineInput);

    return 0;
}

 
