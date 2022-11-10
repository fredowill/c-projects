/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
** WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
** FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
** OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
** OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.*/


/*1.	populates the titles array*/

char** getTitles(int numOfBooks);

/*2.	populates the favorites array*/
char*** getFavorites(int numOfFavBooks, char ***dPtr);

/*3. saves date to a file if the user wants*/
char* outputData(FILE *out, char* fileName, char **dPtr, char ***favPtr, int bookNum, int favNum);