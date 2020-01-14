#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "babies.h"

int main ( int argc, char *argv[] ) {

   FILE *f1;
   int i = 0;
   int boolean;
   int done;
   int done2;
   int check;
   struct pNames popular;
   char maleSNumber[20];
   char femaleSNumber[20];
   char input[20];
   char fileStart[20];
   char fileEnd[20] = "Names.txt";
   int year;
   char string[100];
   int rank = 0;
   char search[20];
   
   done = 0;

   while (done == 0) {

      check = 0;
      while (check == 0){

         check = 1;
         printf("What decade do you want to look at? [1880 to 2010]: ");
         fgets(input, 20, stdin);

         strcpy(fileStart, input);
         fileStart[4] = '\0';
         if (!(atoi(fileStart) == 1880 || atoi(fileStart) == 1890 || atoi(fileStart) == 1900 || atoi(fileStart) == 1910 || atoi(fileStart) == 1920 || atoi(fileStart) == 1930 || atoi(fileStart) == 1940 || atoi(fileStart) == 1950 || atoi(fileStart) == 1960 || atoi(fileStart) == 1970 || atoi(fileStart) == 1980 || atoi(fileStart) == 1990 || atoi(fileStart) == 2000 || atoi(fileStart) == 2010)) {

            printf("Acceptable decades are 1880, 1890, 1900, 1910, 1920, 1930, 1940, 1950, 1960, 1970, 1980, 1990, 2000, or 2010. No other numbers are acceptable.\n");
            check = 0;
         }
      }

      year = atoi(fileStart);

      strcat(fileStart, fileEnd);

      i = 0;
      if ( (f1 = fopen(fileStart, "r")) != NULL ) {
         while ( fgets(string, 100, f1) != NULL ) {
            sscanf (string, "%d %s %s %s %s", &popular.rank[i], popular.maleName[i], maleSNumber, popular.femaleName[i], femaleSNumber);

            removeCommas ( maleSNumber );
            removeCommas ( femaleSNumber );
            popular.maleNumber[i] = atoi ( maleSNumber );
            popular.femaleNumber[i] = atoi ( femaleSNumber );
            i++;
         }
      } else {
         printf ( "Cannot open %s\n", fileStart );
         return ( -2 );
      }


      done2 = 0;

      while (done2 == 0) {

         check = 0;
         while (check == 0){
            check = 1;

            printf("Would you like to see a rank, search for a name, or see the top 10? [rank, search, top]: ");
            fgets(input, 20, stdin);

            for (i = 0; i < 8; i++) {
               if (input[i] < 97 || input[i] > 122) {
                  input[i] = '\0';
               }
            }

            if (!(strcmp(input,"rank") == 0 || strcmp(input,"search") == 0 || strcmp(input,"top") == 0)) {
               printf("Please type in rank, search, or top exactly as requested.\n");
               check = 0;
            }
         }


         if (strcmp(input, "rank") == 0){

            check = 0;
            while (check == 0){
               check = 1;
               printf("What rank do you wish to see? [1-200]: ");
               fgets(input, 20, stdin);
      
               for (i = 0; i < 2; i++) {
                  if (input[i] < 48 || input[i] > 57) {
                     input[i] = '\0';
                  }
               }

               rank = atoi(input);
               if (rank < 1 || rank > 200){
                  printf("Only numbers between 1 and 200 are acceptable.\n");
                  check = 0;
               }
            }

            check = 0;
            while (check == 0) {
               check = 1;

               printf("Whould you like to see the male (0), female (1), or both (2) name(s)? [0-2]: ");
               fgets(input, 20, stdin);
      
               for (i = 0; i < 2; i++) {
                  if (input[i] < 48 || input[i] > 57) {
                     input[i] = '\0';
                  }
               }

               if (atoi(input) < 0 || atoi(input) > 2) {
                  printf("Only the numbers 0, 1, or 2 are acceptable.\n");
                  check = 0;
               }
            }


            i = rank - 1;
      
            if (atoi(input) == 0) {
               printf("Rank %d: Male: %s (%d)\n", rank, popular.maleName[i], popular.maleNumber[i]);
            }

            if (atoi(input) == 1) {
               printf("Rank %d: Female: %s (%d)\n", rank, popular.femaleName[i], popular.femaleNumber[i]);
            }

            if (atoi(input) == 2) {
               printf("Rank %d: Male: %s (%d) and Female: %s (%d)\n", rank, popular.maleName[i], popular.maleNumber[i], popular.femaleName[i], popular.femaleNumber[i]);
            }
         }

   

         if (strcmp(input, "search") == 0 ) {
    
            printf("What name do you want to search for? [case sensitive]: ");
            fgets(input, 20, stdin);
      
            for (i = 1; i < 20; i++) {
               if (input[i] < 97 || input[i] > 122) {
                  input[i] = '\0';
               }
            }

            strcpy(search, input);


            check = 0;
            while (check == 0) {
               check = 1;
               printf("Do you wish to search male (0), female (1), or both (2) name(s)? [0-2]: ");
               fgets(input, 20, stdin);
      
               for (i = 0; i < 2; i++) {
                  if (input[i] < 48 || input[i] > 57) {
                     input[i] = '\0';
                  }
               }

               if (atoi(input) < 0 || atoi(input) > 2) {
                  printf("Only the numbers 0, 1, or 2 are acceptable.\n");
                  check = 0;
               }
            }


            if (atoi(input) == 0) {
               boolean = 0;

               for (i = 0; i < 200; i++) {
                  if (strcmp(search, popular.maleName[i]) == 0){
                     rank = i + 1;
                     printf("In %d, the male name %s is ranked %d with a count of %d.\n", year, popular.maleName[i], rank, popular.maleNumber[i]);
                     boolean = 1;
                     i = 200;
                  }
               }
     
               if (boolean == 0) {
                  printf("In %d, the male name %s is not ranked.\n", year, search);
               }
            }

            if (atoi(input) == 1) {
               boolean = 0;

               for (i = 0; i < 200; i++) {
                  if (strcmp(search, popular.femaleName[i]) == 0){
                     rank = i + 1;
                     printf("In %d, the female name %s is ranked %d with a count of %d.\n", year, popular.femaleName[i], rank, popular.femaleNumber[i]);
                     boolean = 1;
                     i = 200;
                  }
               }
     
               if (boolean == 0) {
                  printf("In %d, the female name %s is not ranked.\n", year, search);
               }
            } 

            if (atoi(input) == 2) {
               boolean = 0;

               for (i = 0; i < 200; i++) {
                  if (strcmp(search, popular.femaleName[i]) == 0){
                     rank = i + 1;
                     printf("In %d, the female name %s is ranked %d with a count of %d and ", year, popular.femaleName[i], rank, popular.femaleNumber[i]);
                     boolean = 1;
                     i = 200;
                  }
               }
     
               if (boolean == 0) {
                   printf("In %d, the female name %s is not ranked and ", year, search);
               }

               boolean = 0;

               for (i = 0; i < 200; i++) {
                  if (strcmp(search, popular.maleName[i]) == 0){
                     rank = i + 1;
                     printf("the male name %s is ranked %d with a count of %d.\n", popular.maleName[i], rank, popular.maleNumber[i]);
                     boolean = 1;
                  }
               }
     
               if (boolean == 0) {
                  printf("the male name %s is not ranked.\n", search);
               }         
            }

         }



         if (strcmp(input, "top") == 0) {
            for (i = 0; i < 10; i++){
               rank = i + 1;
               printf("%-5d%-15s%-12d%-15s%-12d\n", rank, popular.maleName[i], popular.maleNumber[i], popular.femaleName[i], popular.femaleNumber[i]);
            }
         }
   

         check = 0;
         while (check == 0) {
 
            check = 1;
            printf("Do you want to ask another question about %d? [Y or N]: ", year);
            fgets(input, 20, stdin);

            for (i = 0; i < 2; i++) {
               if (input[i] < 48) {
                  input[i] = '\0';
               }
            }

            if (!(strcmp(input, "N") == 0 || strcmp(input, "n") == 0 || strcmp(input, "Y") == 0 || strcmp(input, "y") == 0)) {
               printf("Only the single characters Y or N are acceptable.\n");
               check = 0;
            }
         }


         if (strcmp(input, "N") == 0 || strcmp(input, "n") == 0) {
            done2 = 1;

            check = 0;
            while (check == 0) {
               check = 1;

               printf("Would you like to select another year? [Y or N]: ");
               fgets(input, 20, stdin);

               for (i = 0; i < 2; i++) {
                  if (input[i] < 48) {
                     input[i] = '\0';
                  }
               }

               if (!(strcmp(input, "N") == 0 || strcmp(input, "n") == 0 || strcmp(input, "Y") == 0 || strcmp(input, "y") == 0)) {
                  printf("Only the single characters Y or N are acceptable.\n");
                  check = 0;
               }
            }


            if (strcmp(input, "N") == 0 || strcmp(input, "n") == 0) {
               printf("Thank you for using babyQuery.\n");
               done = 1;
            }
         }

      }
   }   

   return (0);

}
