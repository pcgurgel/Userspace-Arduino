#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
 FILE *outfile;
 char *outname = "myoutputfile.txt";
 outfile = fopen(outname, "w");
 if (!outfile) {
  printf("There was a problem opening %s for writing\n", outname);
 }
 else {
 /* write to the file, or whatever */
   fprintf(outfile,"Hello BeagleBoard !\n");
 }
 fclose(outfile);
    }
