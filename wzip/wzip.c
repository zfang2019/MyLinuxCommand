/*header files  start*/
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <string.h>

struct data {
    int length;
    char ch;
};

int main(int argc, char *argv[]) {
    //define some variable to store lines read
    char *line;
    size_t line_size = 10;
    struct data myData;

    //argc == 1, just exit
    if (argc == 1) {
        fprintf(stdout, "wzip: file1 [file2 ...]\n");
        exit(1);
     }

     //argc >1, at least one file
     else {
        //now open each file to search
        int i = 1;//start from argv[2] as file path
        while ( i < argc ) {
            //check duplicate files
            bool duplicate_file = false;
            if (i >= 2 )  {
                struct stat buf1, buf2;
                for (int j=1; j < i; j++) {
                    lstat(argv[i], &buf1);
                    lstat(argv[j], &buf2);
                    if ((int) buf1.st_ino == (int) buf2.st_ino  ) duplicate_file = true; 
                }
            }

            if (!duplicate_file) {
                //open file for compress
                FILE *in_fp = fopen(argv[i],"r");
                if (in_fp == NULL) {
                    fprintf(stdout, "wzip: cannot open file\n");
                    exit(1);
                }
                // fprintf(stdout, "Process %s file now.\n",argv[i]);
                line = malloc(line_size*sizeof(char));
                while ((getline(&line,&line_size,in_fp)) >= 0 ) {
                    int len = strlen(line);
                    int prev = 0;
                    int count = 0;
                    for (int i = 1; i < len; i++) {
                        if(line[prev] == line[i]) i++;
                        else {
                            count = i - prev;
                            myData.length = count;
                            myData.ch = line[prev];
                            fwrite(&myData,5, 1, stdout);
                            prev = i;
                         }
                    }
                    count = len - prev;
                    myData.length = count;
                    myData.ch = line[prev];
                    fwrite(&myData,5, 1, stdout);
                }
                free(line);
                line=NULL;
                fclose(in_fp);
            }

            i++;
        }
        return (0);
     }

}
