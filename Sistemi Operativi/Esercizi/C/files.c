//
//  files.c
//  C
//
//  Created by Kevin Della schiava on 13/11/18.
//  Copyright © 2018 Esercizi. All rights reserved.
//

#include "files.h"

//Argument counter: quanti argomenti ci sono
//Argument value: quali argomenti ci sono
int cat(int argc, char **filenames){
    
    if(argc < 2){
        fprintf(stderr, "Fornire il nome di almeno un file \n");
        return 1;
    }
    
    //Il primo argomento è sempre il nome del file 😱
    //[cat] [-f] [file] [file]
    
    //Per ogni file partendo dal secondo
    for (int file_index = 1; file_index < argc; file_index++) {
        fprintf(stdout, "%s \n", filenames[file_index]);
        
        FILE *opened_file = fopen(filenames[file_index], "r");
        if(opened_file < 0){
            return -1;
        }
        char carachter;
        while ((carachter = fgetc(opened_file), carachter != EOF)) {
            fputc(carachter, stdout);
        }
        fclose(opened_file);
    }
    
    return 0;
}

int diff(int argc, char **filenames){
    
    FILE *cmp_from = fopen(filenames[1], "r");
    FILE *cmp_to = fopen(filenames[2], "r");
    
    int line = 0;
    
    char from = fgetc(cmp_from);
    char to = fgetc(cmp_to);
    while (from != EOF && to != EOF) {
        if(from != to){
            printf("Diff on line %d \n", line);
            return 0;
        }
        
        if((from == to) && from == '\n') line++;
        
        from = fgetc(cmp_from);
        to = fgetc(cmp_to);
    }

    printf("No diffs");
    return 0;
}
