#include <stdio.h>
#include <stdlib.h>

#include "parser.h"


//Déclaration des procédures locales
static char* removeWhiteSpaces(char *string);
static int isEndOfCmd(char c);
static int isEndOfArgs(char c);

int getCmdAndArgs(char *iString, char *oCmd, char *oArgs)
{
    //On supprime les espaces de début de commande
    iString = removeWhiteSpaces(iString);
    
    return 0;
}

/*!
 * \fn      getCommand
 * \brief   Retourne un pointeur sur le premier caractère de la commande
 */
char* getCommand(char *string)
{
    //On supprime les espaces de début de commande
    string = removeWhiteSpaces(string);
    
    while (!isEndOfCmd(*string))
    {
        string++;
    }
    return string;
}

/*!
 * \fn      getArgs
 * \brief   Retourne un pointeur sur le premier caractère du permier argument
 */
char* getArgs(char *string)
{
    //On supprime les espaces de début de commande
    string = removeWhiteSpaces(string);
    
    while (!isEndOfArgs(*string))
    {
        string++;
    }
    return string;
}


/*!
 * \fn      removeWhiteSpaces
 * \brief   Utilitaire pour supprimer les espaces/tabulations et fin de lignes
 */
static char* removeWhiteSpaces(char *string)
{
    while ((*string == ' ') || (*string == '\t') || (*string == '\n') || (*string == '\r'))
    {
        string ++;
    }
    
    return string;
}


/*!
 * \fn      isEndOfCmd
 * \brief   Permet de déterminer une fin de commande (commande avec ou sans argument)
 */
static int isEndOfCmd(char c)
{
    switch (c)
    {
        case ' ':
        case '|':
        case '&':
        case ';':
        case '>':
        case '<':   
        case '\n':
        case '\r':
        case '\t':
        case EOF:   return 1;
        
        default:    return 0;
    }
    return 0;
}

/*!
 * \fn      isEndOfArgs
 * \brief   Permet de déterminer une fin d'arguments
 */
static int isEndOfArgs(char c)
{
    switch (c)
    {
        case '|':
        case '&':
        case ';':
        case '>':
        case '<':   
        case '\n':
        case '\r':
        case EOF:   return 1;
        
        default:    return 0;
    }
    return 0;
}
