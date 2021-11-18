#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
    
int main(void){
    DIR * dir;
    struct dirent * de;
    printf("Current directory/\n");
    if ((dir = opendir(".")) == NULL){
        fprintf(stderr, "Forbidden, niht permission!\n");
    }
    else{
        while ( de = readdir(dir) ) 
        printf("%s\n", de->d_name);
    }
    printf("\n\nMain directory/\n");
    if ((dir = opendir("/")) == NULL){
        fprintf(stderr, "Forbidden, niht permission!\n");
    }
    else{
        while ( de = readdir(dir) ) 
        printf("%s\n", de->d_name);
    }
    
    
    closedir(dir);
    return 0;
}