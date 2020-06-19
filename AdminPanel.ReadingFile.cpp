#include <stdio.h>
#include <string.h>
#include "Bus.Functions.h"

void AdminPanelReadingFile()
{
    FILE *Delete;
    char D[200];
    strcpy(D, DATE());
    strcat(D, "C5.Deleted Profile.txt");
    //fclose(Delete);
    if((Delete = fopen(D, "r")) == NULL) printf("\n\n\t\tTILL NOW NOBODY CANCALLED TICKET TODAY.\n\n");
    else {
        Delete = fopen(D, "r");
        char str[200];
        while(!feof(Delete)) {
            fgets(str, 200, Delete);
            if(strcmp(str, "END\n") == 0) {printf("\n\n"); continue;}
            printf("\t\t%s", str);
        }
    }
}
/*
ROY
123456
*/
