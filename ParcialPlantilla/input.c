#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int indice = 0;

    printf("%s",message);
    scanf("%d",input);

    while( *input < lowLimit || *input >hiLimit)
    {
        printf("%s", eMessage);
        scanf("%d",input);
    }

    if(*input >lowLimit || *input <hiLimit){
        return indice;
    }
    else{
        indice = -1;
        return indice;
    }



}

int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit)
{
    int indice=0;

    printf("%s",message);
    scanf("%f",input);

    while( *input < lowLimit || *input >hiLimit)
    {
        printf("%s", eMessage);
        scanf("%f",input);
    }
    if(*input >lowLimit || *input <hiLimit){
        return indice;
    }

    else{
        indice = -1;
        return indice;
    }



}






int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit)
{
    int indice=0;

     printf("%s",message);
     fflush(stdin);
    scanf("%c",input);

    while( *input < lowLimit || *input >hiLimit)
    {
        printf("%s", eMessage);
        fflush(stdin);
        scanf("%c",input);
    }

   if(*input >lowLimit || *input <hiLimit){
        return indice;
    }
    else{
        indice = -1;
        return indice;
    }

}


int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int indice = 0;

    printf("%s",message);
    fflush(stdin);
    scanf("%[^\n]",input);

    while( strlen(input) < lowLimit || strlen(input) >hiLimit)
    {
        printf("%s", eMessage);
        fflush(stdin);
        scanf("%[^\n]",input);
    }
    if(*input >lowLimit || *input <hiLimit){
        return indice;
    }
    else{
        indice = -1;
        return indice;
    }



}
