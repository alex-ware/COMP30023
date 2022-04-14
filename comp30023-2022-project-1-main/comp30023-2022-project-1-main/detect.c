#include "detect.h"

int main(int argc, char *argv[]) {
    //invoke(argc, argv);    
    //printf("bruh\n");
    task_1(get_path(argc, argv));  
    
    return 0;
}

int invoke(int argc, char *argv[]) {
    //int i = 0;

    //for (i = 0; i < argc; i++) {
    //    printf("%s\n", argv[i]);
    //}
    return 0;
}

char* get_path(int argc, char *argv[]) {
    int path_length = 0;

    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "-f") == 0) {
            //makeprintf("found\n");
            path_length = strlen(argv[i+1]);
            char *file_path = (char *)malloc(sizeof(char)*path_length);
            strcpy(file_path, argv[i+1]);
            return file_path;
        }
    }
    return "0";
}

int task_1(char* file_path) {
    char c;
    int unique = 0, lines = 0;
    int processes = 0, conts = 0, not_unique = 0, files = 0;
    FILE *fp = fopen(file_path,"r");
    c = fgetc(fp);

    char *token;
    const char s[2] = " ";
    
    char *file_conts = (char *)malloc(sizeof(char)*(conts+1));
    
    while (c != EOF) { 
        if (conts >= 1) {
            file_conts = (char *)realloc(file_conts, sizeof(char)*(conts+1)); 
        }
        if (c == '\n') {
            lines++;
            c = ' ';
        }
        file_conts[conts] = c;


        /*if (isdigit(c)!=0) {
            if (conts % 3 == 1 || conts % 3 == 2) {
                file_conts[conts] = c;                
                for(int i = 0; i < conts-1; i++) {
                    if (file_conts[i] ==  c) {
                        not_unique = 1;
                    }
                }
                if (not_unique == 0) {
                    files++;
                }
            }
            conts++;
           
        }
        if (c == '\n') {
            processes++;
        }*/
        conts++;
        c = getc(fp);        
    }
    file_conts[conts-1] = '\n';

    int *file_ints = (int *)malloc(sizeof(int)*(lines*3));
    token = strtok(file_conts, s);

    int i = 0;
    while (token != NULL) {
        file_ints[i] = atoi(token);
        //printf("%s token\n", token);
        //printf("%d\n", file_ints[i]);
        token = strtok(NULL,s);
        i++;
    }

    int *unique_files = (int *)malloc(sizeof(int)*(lines*2));

    for (int i = 0; i < lines*2; i++) {
        unique_files[i] = EMPTY;
    }

    for (int i = 0; i < lines * 3; i++) {
        if (i%3 != 0) {
            for (int j = 0; j < lines * 2; j++) {
                if (file_ints[i] == unique_files[j]) {
                    not_unique ++;
                }
            }
            if (not_unique == 0) {
                unique_files[unique] = file_ints[i];
                unique++;
            }
        }
        not_unique = 0;        
    }

    /*for (int i = 0; i<lines*2; i++) {
        printf("%d ", unique_files[i]);
    }*/


    /*for (int i = 0; i < lines*3; i++) {
        //printf("%d\n", i);
        for (int j = 0; j < (lines*3)-1; j++) {
            if(((i%3 != 0 && j%3 != 0) && file_ints[j] == file_ints[i]) && i != j) {
                not_unique = 1;
            }
        }
        if (not_unique == 1 && i%3 != 0) {
            //printf("%d , not unique\n", file_ints[i]);
        }
        if (not_unique == 0 && i%3 != 0) {
            //printf("%d , unique\n", file_ints[i]);  
            files ++;
        }
        not_unique = 0;
    }*/



    //for(int i=0; i<conts; i++) {
    //    printf("%c ", file_conts[i]);
    //}
    //printf("\n");
    

    files = unique;
    printf("Processes %d\nFiles  %d\n", lines, files);
    free(file_conts);
    free(file_ints);
    free(unique_files);
    fclose(fp);
    return 0;   
}

