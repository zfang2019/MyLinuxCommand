/*header files  start*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>


int main(int argc, char *argv[]) {
   /*
    define some common variables 
   */
    //size_t line_size = 256;
    //size_t file_size = 2;
    //int    line_count = 0;
    //char **buffer = (char**)malloc(file_size*sizeof(char*));
    //char buf[256];

    
    //argc = 1, just exit
    if (argc == 1) {
        return (0);
     }
 
     //argc > 2, open one or more files
    else  {
        int i = 1;
        while (i < argc) {
         size_t line_size = 256;
         char buf[256];

         FILE  *in_fp = fopen(argv[i], "r");
         if (in_fp == NULL) {
            //fprintf(stderr,"reverse: cannot open file '/no/such/file.txt'\n");
            printf("wcat: cannot open file\n");
            exit(1);
         }
         
         while (fgets(buf, line_size, in_fp) )  {
           printf("%s", buf);
         }
         fclose(in_fp);
         i++;
       }
       return (0);
    }
}