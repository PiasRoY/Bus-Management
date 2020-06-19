#include <stdio.h>
#include <string.h>
#include "Bus.Functions.h"

int RNtoRC(FILE * schedule)
{
    //INITIALWORK
    char D[200];
    strcpy(D, DATE());
    strcat(D, "C1.Regular Bus Schedule.txt");
    fclose(schedule);
    schedule = fopen(D, "a+");
    //MAINWORK
    char Start[100], End[100], Time[100], line[500];
    int l = 1;
    printf("\t\tENTER STARTING POINT : ");
    scanf("%s", Start);
    printf("\t\tENTER ENDING POINT   : ");
    scanf("%s", End);
    to_upper(Start), to_upper(End);
    strcat(Start, "-"), strcat(Start, End);
    printf("\t\tENTER TIME OF JOURNEY(ADD 'EXT' INFRONT FOR EXTRA BUSES): ");
    scanf("%s", Time);
    to_upper(Time);
    while(!feof(schedule)) {
        fgets(line, 500, schedule);
        if((strstr(line, Start) != NULL) && (strstr(line, Time) != NULL))
        {
            if((strstr(Time, "EXT") != NULL)) return 16+(l-27);
            return (((l-3)/3)*2)+(l%3==2?1:0);
        }
        l++;
    }

    return -1;
}
