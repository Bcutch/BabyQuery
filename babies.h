/*  Defines */
#define MAXLENGTH 20
#define ROWS 200

/* Struct definitions */
struct pNames {
   int  year;
   int  rank[ROWS];
   char maleName[ROWS][MAXLENGTH];   
   int  maleNumber[ROWS];
   char femaleName[ROWS][MAXLENGTH];   
   int  femaleNumber[ROWS];
};

/* Function definitions */
int removeCommas ( char * );
