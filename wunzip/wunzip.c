/*header files  start*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

struct data {
    int length;
    char ch;
};

int main(int argc, char *argv[]) {
    //define some struct to hold data
    struct data myData;
    //int res;

    //argc == 1, just exit
    if (argc == 1) {
        fprintf(stdout, "wunzip: file1 [file2 ...]\n");
        exit(1);
     }

      //argc >1, at least one file
     else {
        //now open each file to search
        int i = 1;//start from argv[2] as file path
        while ( i < argc ) {
            FILE *in_fp = fopen(argv[i],"r");
            if (in_fp == NULL) {
                fprintf(stdout, "wzip: cannot open file\n");
                exit(1);
            }
            
            int pos = 0;
            while(!feof(in_fp)){
                fseek(in_fp, pos, SEEK_SET);
                size_t res = fread(&myData,sizeof(struct data),1,in_fp);
                for (int i = 0; i < myData.length; i++) printf("%c",myData.ch);
                pos += 5;
                //if(feof(in_fp)) break;
            }
            fclose(in_fp);
            i++;
        }
        return (0);
     }  
}