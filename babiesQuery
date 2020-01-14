#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "babies.h"

int main ( int argc, char *argv[] ) {

   FILE *f1;
   int i = 0;
   int j = 0;
   int boolean;
   int boolean2;
   int done;
   int done2;
   int check;
   struct pNames popular1;
   struct pNames popular2;
   char maleSNumber1[20];
   char femaleSNumber1[20];
   char maleSNumber2[20];
   char femaleSNumber2[20];
   char input[20];
   char fileStart1[20];
   char fileStart2[20];
   char fileEnd[20] = "Names.txt";
   int year1;
   int year2;
   char string[100];
   int rank = 0;
   char search[20];
   char topM[200][20];
   char topF[200][20];
   
 
   for (i = 0; i < 200; i++) {
      strcpy(topM[i], "NO");
   }
   for (i = 0; i < 200; i++) {
      strcpy(topF[i], "NO");
   }


   done = 0;

   while (done == 0) {

      check = 0;
      while (check == 0){

         check = 1;
         printf("What 2 decades do you want to look at? [1880 to 2010]: ");
         fgets(input, 20, stdin);

         fileStart1[0] = input[0];
         fileStart1[1] = input[1];
         fileStart1[2] = input[2];
         fileStart1[3] = input[3];
         fileStart1[4] = '\0';
         if (!(atoi(fileStart1) == 1880 || atoi(fileStart1) == 1890 || atoi(fileStart1) == 1900 || atoi(fileStart1) == 1910 || atoi(fileStart1) == 1920 || atoi(fileStart1) == 1930 || atoi(fileStart1) == 1940 || atoi(fileStart1) == 1950 || atoi(fileStart1) == 1960 || atoi(fileStart1) == 1970 || atoi(fileStart1) == 1980 || atoi(fileStart1) == 1990 || atoi(fileStart1) == 2000 || atoi(fileStart1) == 2010)) {

            printf("Acceptable decades are 1880, 1890, 1900, 1910, 1920, 1930, 1940, 1950, 1960, 1970, 1980, 1990, 2000, or 2010. No other numbers are acceptable. You must enter 2 acceptable decades separated by at least one space.\n");
            check = 0;
         }

         int n = 0;

         for (i = 5; i < 20; i++) {
            if (input[i] > 47 && input[i] < 58){
               n = i;
               i = 20;
            }
         }

         fileStart2[0] = input[n];
         fileStart2[1] = input[n+1];
         fileStart2[2] = input[n+2];
         fileStart2[3] = input[n+3];
         fileStart2[4] = '\0';
         if ((!(atoi(fileStart2) == 1880 || atoi(fileStart2) == 1890 || atoi(fileStart2) == 1900 || atoi(fileStart2) == 1910 || atoi(fileStart2) == 1920 || atoi(fileStart2) == 1930 || atoi(fileStart2) == 1940 || atoi(fileStart2) == 1950 || atoi(fileStart2) == 1960 || atoi(fileStart2) == 1970 || atoi(fileStart2) == 1980 || atoi(fileStart2) == 1990 || atoi(fileStart2) == 2000 || atoi(fileStart2) == 2010) && check == 1) || (strcmp(fileStart1, fileStart2) == 0 && check == 1)) {

            printf("Acceptable decades are 1880, 1890, 1900, 1910, 1920, 1930, 1940, 1950, 1960, 1970, 1980, 1990, 2000, or 2010. No other numbers are acceptable. You must enter 2 acceptable decades separated by at least one space.\n");
            check = 0;
         }
      }

      year1 = atoi(fileStart1);
      year2 = atoi(fileStart2);

      strcat(fileStart1, fileEnd);
      strcat(fileStart2, fileEnd);

      i = 0;
      if ( (f1 = fopen(fileStart1, "r")) != NULL ) {
         while ( fgets(string, 100, f1) != NULL ) {
            sscanf (string, "%d %s %s %s %s", &popular1.rank[i], popular1.maleName[i], maleSNumber1, popular1.femaleName[i], femaleSNumber1);

            removeCommas ( maleSNumber1 );
            removeCommas ( femaleSNumber1 );
            popular1.maleNumber[i] = atoi ( maleSNumber1 );
            popular1.femaleNumber[i] = atoi ( femaleSNumber1 );
            i++;
         }
      } else {
         printf ( "Cannot open %s\n", fileStart1 );
         return ( -2 );
      }

      i = 0;
      if ( (f1 = fopen(fileStart2, "r")) != NULL ) {
         while ( fgets(string, 100, f1) != NULL ) {
            sscanf (string, "%d %s %s %s %s", &popular2.rank[i], popular2.maleName[i], maleSNumber2, popular2.femaleName[i], femaleSNumber2);

            removeCommas ( maleSNumber2 );
            removeCommas ( femaleSNumber2 );
            popular2.maleNumber[i] = atoi ( maleSNumber2 );
            popular2.femaleNumber[i] = atoi ( femaleSNumber2 );
            i++;
         }
      } else {
         printf ( "Cannot open %s\n", fileStart2 );
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
               printf("Rank %d: %d: Male: %s (%d)\n", rank, year1, popular1.maleName[i], popular1.maleNumber[i]);
               printf("         %d: Male: %s (%d)\n", year2, popular2.maleName[i], popular2.maleNumber[i]);
            }

            if (atoi(input) == 1) {
               printf("Rank %d: %d: Female: %s (%d)\n", rank, year1, popular1.femaleName[i], popular1.femaleNumber[i]);
               printf("         %d: Female: %s (%d)\n", year2, popular2.femaleName[i], popular2.femaleNumber[i]);
            }

            if (atoi(input) == 2) {
               printf("Rank %d: %d: Male: %s (%d) and Female: %s (%d)\n", rank, year1,  popular1.maleName[i], popular1.maleNumber[i], popular1.femaleName[i], popular1.femaleNumber[i]);
               printf("         %d: Male: %s (%d) and Female: %s (%d)\n", year2, popular2.maleName[i], popular2.maleNumber[i], popular2.femaleName[i], popular2.femaleNumber[i]);
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
               boolean2 = 0;

               for (i = 0; i < 200; i++) {
                  if (strcmp(search, popular1.maleName[i]) == 0){
                     rank = i + 1;
                     printf("In %d, the male name %s is ranked %d with a count of %d and\n", year1, popular1.maleName[i], rank, popular1.maleNumber[i]);
                     boolean = 1;
                     i = 200;
                  }
               }

     
               if (boolean == 0) {
                  printf("In %d, the male name %s is not ranked and\n", year1, search);
               }

               for (i = 0; i < 200; i++) {
                  if (strcmp(search, popular2.maleName[i]) == 0){
                     rank = i + 1;
                     printf("In %d, the male name %s is ranked %d with a count of %d.\n", year2, popular2.maleName[i], rank, popular2.maleNumber[i]);
                     boolean2 = 1;
                     i = 200;
                  }
               }

               if (boolean2 == 0) {
                  printf("In %d, the male name %s is not ranked.\n", year2, search);
               }
            }

            if (atoi(input) == 1) {
               boolean = 0;
               boolean = 0;

               for (i = 0; i < 200; i++) {
                  if (strcmp(search, popular1.femaleName[i]) == 0){
                     rank = i + 1;
                     printf("In %d, the female name %s is ranked %d with a count of %d and\n", year1, popular1.femaleName[i], rank, popular1.femaleNumber[i]);
                     boolean = 1;
                     i = 200;
                  }
               }
     
               if (boolean == 0) {
                  printf("In %d, the female name %s is not ranked and\n", year1, search);
               }

               for (i = 0; i < 200; i++) {
                  if (strcmp(search, popular2.femaleName[i]) == 0){
                     rank = i + 1;
                     printf("In %d, the female name %s is ranked %d with a count of %d.\n", year2, popular2.femaleName[i], rank, popular2.femaleNumber[i]);
                     boolean2 = 1;
                     i = 200;
                  }
               }

               if (boolean2 == 0) {
                  printf("In %d, the female name %s is not ranked.\n", year2, search);
               }
            } 

            if (atoi(input) == 2) {
               boolean = 0;
               boolean2 = 0;

               for (i = 0; i < 200; i++) {
                  if (strcmp(search, popular1.femaleName[i]) == 0){
                     rank = i + 1;
                     printf("In %d, the female name %s is ranked %d with a count of %d and ", year1, popular1.femaleName[i], rank, popular1.femaleNumber[i]);
                     boolean = 1;
                     i = 200;
                  }
               }
     
               if (boolean == 0) {
                   printf("In %d, the female name %s is not ranked and ", year1, search);
               }

               boolean = 0;

               for (i = 0; i < 200; i++) {
                  if (strcmp(search, popular1.maleName[i]) == 0){
                     rank = i + 1;
                     printf("the male name %s is ranked %d with a count of %d\n", popular1.maleName[i], rank, popular1.maleNumber[i]);
                     boolean = 1;
                  }
               }
     
               if (boolean == 0) {
                  printf("the male name %s is not ranked\n", search);
               }  

               for (i = 0; i < 200; i++) {
                  if (strcmp(search, popular2.femaleName[i]) == 0){
                     rank = i + 1;
                     printf("And in %d, the female name %s is ranked %d with a count of %d and ", year2, popular2.femaleName[i], rank, popular2.femaleNumber[i]);
                     boolean2 = 1;
                     i = 200;
                  }
               }
     
               if (boolean2 == 0) {
                   printf("And in %d, the female name %s is not ranked and ", year2, search);
               }    

               boolean2 = 0;

               for (i = 0; i < 200; i++) {
                  if (strcmp(search, popular2.maleName[i]) == 0){
                     rank = i + 1;
                     printf("the male name %s is ranked %d with a count of %d.\n", popular2.maleName[i], rank, popular2.maleNumber[i]);
                     boolean2 = 1;
                  }
               }
     
               if (boolean2 == 0) {
                  printf("the male name %s is not ranked.\n", search);
               }   
            }

         }



         if (strcmp(input, "top") == 0) {

            int k = 0;
            int g = 0;
            for (i = 0; i < 10; i++){
               for (j = 0; j < 10; j++){

                  if (strcmp(popular1.maleName[i], popular2.maleName[j]) == 0){
                     strcpy(topM[k], popular1.maleName[i]);
                     k++;
                  }
                  if (strcmp(popular1.femaleName[i], popular2.femaleName[j]) == 0){
                     strcpy(topF[g], popular1.femaleName[i]);
                     g++;
                  }
               }
            }

            k = 0;
            g = 0;

            printf("Male names that appear in both %d and %d Top Tens: ", year1, year2);

            while (strcmp(topM[k], "NO") != 0){
               if (strcmp(topM[k+1], "NO") != 0){
                  printf("%s, ", topM[k]);
               } else {
                  printf("%s\n", topM[k]);
               }
               k++;
            }

            printf("Female names that appear in both %d and %d Top Tens: ", year1, year2);

            while (strcmp(topF[g], "NO") != 0){
               if (strcmp(topF[g+1], "NO") != 0){
                  printf("%s, ", topF[g]);
               } else {
                  printf("%s\n", topF[g]);
               }
               g++;
            }
         }
   

         check = 0;
         while (check == 0) {
 
            check = 1;
            printf("Do you want to ask another question about %d and %d? [Y or N]: ", year1, year2);
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

               printf("Would you like to select other decades? [Y or N]: ");
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
               printf("Thank you for using babiesQuery.\n");
               done = 1;
            }
         }

      }
   }   

   return (0);

}
