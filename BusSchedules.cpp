#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include "Bus.Functions.h"

void BUSSCHEDULES(FILE *schedule, FILE *Info, FILE *BookedSeats, FILE *Available) {
    //INITIAL WORK
    printf("\t\tTODAY'S BUS SCHEDULE - 2017\n");
    printf("\t----------------------------------------------\n\n");
    //MAIN WORK
    char str[200];
    char ch;
    int i = 1;
    while(!feof(schedule)) {
        if(i == 28) printf("\n");
        fgets(str, 200, schedule),
        printf("\t%s", str);
        i++;
    }
    printf("\n\n\tDO YOU WANT TO BOOK TICKETS NOW?(Y/N) : ");
    getchar();
    scanf("%c", &ch);
    printf("\n\n");
    if(ch == 'Y' || ch == 'y') {
        system("cls");
        fclose(schedule);
        char D[200];
        strcpy(D, DATE());
        strcat(D, "C1.Regular Bus Schedule.txt");
        schedule = fopen(D, "a+");
        BUSBOOKING(schedule, Info, BookedSeats, Available);
    }
    printf("\n\n");
}
