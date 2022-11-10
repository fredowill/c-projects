/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
** WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
** FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
** OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
** OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab3.h"
int main()
{
    int numOfBooks, fav, save = 0;
    int i, k, l = 0;
  /*  char *booksPtr = malloc(61 * sizeof(char)); */
    char **doublePtr;
    char ***favoritePtr = &doublePtr;
    char *fileName;
    FILE *out;

    printf("Enter a number of book titles:");
    scanf("%i", &numOfBooks);
    getchar();
    printf("Enter %i books seperated by a new line: \n", numOfBooks);

    doublePtr = getTitles(numOfBooks); 

    printf("\nOf those 9 books, how many do you plan to put on your favorites list? ");
    scanf("%i", &fav);

    favoritePtr = getFavorites(fav, &doublePtr);

    printf("\nDo you want to save them (1=yes, 2=no): ");
    scanf("%i", &save);
    getchar();  

    if (save == 1) {
        fileName = malloc(256 * sizeof(char));
        printf("\nWhat file name do you want to use? ");
        scanf("%s", fileName); 
        getchar();
        out = fopen(fileName, "w");
        fileName = outputData(out, fileName, doublePtr, favoritePtr, numOfBooks, fav);
        fclose(out);
        printf("Your booklist and favorites have been saved to the file %s.", fileName);
    }
    for(i =0; i<numOfBooks; i++){
        free(*(doublePtr + i));
        *(doublePtr + i) = NULL;
    }
    free(doublePtr);
    doublePtr = NULL;
    free(favoritePtr);
    favoritePtr=NULL;
    free(fileName);
    fileName=NULL;
    
#ifdef PROMPT
    /* allocate the size of the double pointere and bookpointer*/
    doublePtr = (char **)malloc(numOfBooks * sizeof(char *));
    for (i = 0; i < numOfBooks; i++)
    {
        *(doublePtr + i) = malloc(61 * sizeof(char));
    }

    /*scanf-ing*/
    for (i = 0; i < numOfBooks; i++)
    {
        scanf("%[^\n]", *(doublePtr + i));
        getchar();
    }
    /*check*/
    for (i = 0; i < numOfBooks; i++)
    {
        printf("\n%i. %s ", i + 1, *(doublePtr + i));
    }

    /*get favroite nums and which ones on the list*/
    printf("\nEnter num of favorite books:");
    scanf("%i", &fav);

    favoritePtr = malloc(fav * sizeof(char **));
    printf("Enter indexies of favorite books:");
    for (i = 0; i < fav; i++)
    {
        scanf(" %d", &k);
        *(favoritePtr + i) = (doublePtr + (k - 1));
    }
    /*check*/
    for (i = 0; i < fav; i++)
    {
        printf("\n%i. %s ", i + 1, **(favoritePtr + i));
    }

    printf("\nDo you want to save them (1=yes, 2=no): ");
    scanf("%i", &save);
    getchar();

    if (save == 1)
    {
        printf("\nWhat file name do you want to use? ");
        scanf("%s", fileName);
        out = fopen(fileName, "w");
    }

#endif
}

/* function to populate the list of books */
char** getTitles(int numOfBooks)
{
    int i;
    char **dPtr;
    /*check to see if memory allocated correctly?*/
    dPtr = (char **)malloc(numOfBooks * sizeof(char *));
    for (i = 0; i < numOfBooks; i++)
    {
        *(dPtr + i) = malloc(61 * sizeof(char));
        
    }

    /*Scan in all the books listed by the user*/
        for (i = 0; i < numOfBooks; i++)
    {
        scanf("%[^\n]", *(dPtr + i));
        getchar();
    }

        /*Print out all the books the user input in order*/
        printf("You've entered: ");
    for (i = 0; i < numOfBooks; i++)
    {
        printf("\n%i. %s ", i + 1, *(dPtr + i));
    }
    return dPtr;
}

/* function to populate the list of books */
char*** getFavorites(int numOfFavBooks, char ***dPtr){
    int i,k;
    char *** tPtr;

    tPtr = malloc(numOfFavBooks * sizeof(char **));

    printf("Enter the number next to each book title you want on your favorites list: ");
    for (i = 0; i < numOfFavBooks; i++)
    {
        scanf(" %d", &k);
        *(tPtr + i) = (*dPtr + (k - 1));
    }
    printf("The books on your favorites list are:");
    for (i = 0; i < numOfFavBooks; i++)
    {
        printf("\n%i. %s ", i + 1, **(tPtr + i));
    }    
    return tPtr;
}
/*function to output data to a file by choice*/
char* outputData (FILE *out, char* fileName, char **dPtr, char ***favPtr, int booknNum, int favNum){
    int i;
    /*print out books I've read*/
    fprintf(out,"Books I've Read: \n");
    for ( i = 0; i <booknNum; i++) {
        fprintf(out,"%s\n", *(dPtr + i));
    }

    fprintf(out, "\nMy favoites are: \n"); 
    for(i = 0; i<favNum;i++) {
        fprintf(out, "%s\n",**(favPtr+i));
    }

    return fileName;
}
