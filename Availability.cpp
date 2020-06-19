#include <stdio.h>
#include <string.h>
#include "Bus.Functions.h"

void AVAILABLESEATS(FILE *Available, int RouteCode)
{
    //Convert RouteCode(int to char)
    char no[3];
    if(RouteCode < 10) no[0] = RouteCode+48, no[1] = '\0';
    else {
        int i = RouteCode%10;
        int j = RouteCode / 10;
        no[0] = j+48, no[1] = i+48, no[2] = '\0';
    }
    char str[25] = "ROUTE NO. ";
    strcat(str, no), strcat(str, " :\n");
    char line[200];
    while(!feof(Available)) {
        fgets(line, 200, Available);
        if(strcmp(str, line) == 0) {
            printf("\n\n%s\n", line);
            while(1) {
                fgets(line, 200, Available);
                if(strcmp(line, "END\n") == 0) goto END;
                puts(line);
            }
        }
    }
    END :
    printf("\n\n");
}
