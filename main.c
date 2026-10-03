#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

int main(int argc, char *argv[]){
    if( argc != 2){
        printf("Invalid command!");
        return 1;
    }
    if(access(argv[1],F_OK) != 0){
        printf("invalid file path, pls ensure the file is in this folder!\n");
        return 1;
    }
    FILE *file = fopen(argv[1],"rb");
    if(file == NULL){
        printf("Error opening the file!");
        return 1;
    }
    unsigned char buffer[16];
    size_t bytesread;
    size_t offset = 0;

    while ((bytesread = fread(buffer, 1, sizeof(buffer), file)) > 0){  // to look like 000000x0
        printf("%08zx : ",offset);
    
    for(size_t i = 0; i < bytesread;i++){
        printf("%02X ",buffer[i]);
    }
    for(size_t i = bytesread; i < 16;i++){
        printf("   ");
    }
    printf("  | ");
    for(size_t i = 0 ; i < bytesread ; i++){
        if(isprint(buffer[i])){
        printf("%c",buffer[i]);
        } else {
            printf(".");
        }
    }
    printf("\n");
    offset += bytesread;
    }
    fclose(file);
    return 0;
}