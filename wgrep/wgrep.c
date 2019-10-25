/*header files  start*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>


int main(int argc, char *argv[]) {
    //define some variable to store lines read
    size_t line_size=80;
    char *buf = NULL;  

    //argc == 1, just exit
    if (argc == 1) {
        fprintf(stdout, "wgrep: searchterm [file ...]\n");
        exit(1);
     }

     //argc == 2, there is search term, search from stdin
    else if (argc == 2) {
        //empty string as search term, return NO lines
        if (strcmp(argv[1],"") == 0) return (0);
        //search from stdin
        while (getline(&buf, &line_size, stdin) >=0) {
            if (strcmp(buf,"\n")==0) break;
            if (strstr(buf,argv[1]))
               printf("%s", buf);
        }
        free(buf);
        buf=NULL;
        return (0);
    }

    //argc >=3 there is search term and also input files
    else {
         //empty string as search term, return NO lines
        if (strcmp(argv[1],"") == 0) return (0);

        //now open each file to search
        int i = 2;//start from argv[2] as file path
        while ( i < argc ) {
            FILE *in_fp = fopen(argv[i],"r");
            if (in_fp == NULL) {
                fprintf(stdout, "wgrep: cannot open file\n");
                exit(1);
            }

            //search from file
            while (getline(&buf, &line_size, in_fp) >=0) {
                if (strstr(buf,argv[1]))
                    printf("%s", buf);
            }
            free(buf);
            buf=NULL;
            i++;
        }
        return (0);
    }   
}