#include <stdio.h>
#include <stdlib.h>

#include "parser.h"


//Déclaration des procédures locales
static char* removeWhiteSpaces(char *string);
static int isEndOfCmd(char c);
static int isEndOfArgs(char c);
//static int isAlphaNumChar(char c);

/*!
 * \fn      getCmdAndArgs
 * \brief   Retourne le pointeur sur la commande et la liste des arguments
 */
int getCmdAndArgs(char *iString, char *oCmd, char *oArgs)
{
    int stringIndex = 0;
    int cmdIndex = 0;
    int argIndex = 0;
    
    char *string = iString;
    
    //On supprime les espaces de début de commande
    string = removeWhiteSpaces(&string[stringIndex]);
    
    while (isEndOfCmd(string[stringIndex]) == 0)
    {
        oCmd[cmdIndex] = string[stringIndex];
        stringIndex++;
        cmdIndex++;
    }
    oCmd[cmdIndex] = '\0';

#ifdef _DEBUG
    printf("Commande: %s\n", oCmd);
#endif
    
    //On supprime les espaces entre la fin de la commande et le début des arguments
    string = removeWhiteSpaces(&string[stringIndex]);
    stringIndex = 0;
    
    while (isEndOfArgs(string[stringIndex]) == 0)
    {
        oArgs[argIndex] = string[stringIndex];
        stringIndex++;
        argIndex++;
    }
    oArgs[argIndex] = '\0';
    
#ifdef _DEBUG
    printf("Arguments: %s\n", oCmd);
#endif
    
    
    return 0;
}

/*!
 * \fn      getStringSize
 * \brief   Retourne la taille de la string (terminée par \0) passée en paramètre
 */
int getStringSize(char *iString)
{
    int index = 0;
    
    while (iString[index] != '\0')
        index ++;
    
    return index;
}


/*!
 * \fn      removeWhiteSpaces
 * \brief   Utilitaire pour supprimer les espaces/tabulations et fin de lignes
 */
static char* removeWhiteSpaces(char *string)
{
    char *pString = string;
    while ((*pString == ' ') || (*pString == '\t') || (*pString == '\n') || (*pString == '\r'))
    {
        pString ++;
    }
    
    return pString;
}


/*!
 * \fn      isEndOfCmd
 * \brief   Permet de déterminer une fin de commande (commande avec ou sans argument)
 */
static int isEndOfCmd(char c)
{
#ifdef _DEBUG
    printf ("isEndOfCmd(%c)\n", c);
#endif
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
#ifdef _DEBUG
    printf ("isEndOfArgs(%c)\n", c);
#endif
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

/*!
 * \fn      isAlphaNumChar
 * \brief   Détermine si le caractère passé en paramètre est un caractère alphanumérique
 */
/*static int isAlphaNumChar(char c)
{
    if (((c >= 'a') && (c <= 'Z')) || ((c >= '0') && (c <= '9')))
        return 1;
    
    return 0;
}*/
