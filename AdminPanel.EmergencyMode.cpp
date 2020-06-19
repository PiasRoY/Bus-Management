#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include "Bus.Functions.h"

void AdminPanelemergecy(FILE *schedule)
{
    //FILE REOPENNIG
    char D[200];
    strcpy(D, DATE());
    strcat(D, "C1.Regular Bus Schedule.txt");
    fclose(schedule);
    schedule = fopen(D, "a+");
    //MAIN WORK
    printf("\t\tEMERGENCY MODE : \n\n");
    int n;
    printf("\t\t\tHOW MANY BUSES YOU WANT TO ADD? : ");
    scanf("%d", &n);
    while(n--) {
        char strt[100], eend[100], Time[100], Cost[100];
        printf("\n\t\tSTARTING POINT : ");
        scanf("%s", strt);
        printf("\t\tENDING POINT   : ");
        scanf("%s", eend);
        printf("\t\tTIME OF JOURNEY: ");
        scanf("%s", Time);
        printf("\t\tPRICE OF TICKET: ");
        scanf("%s", Cost);
        to_upper(strt), to_upper(eend), to_upper(Time);
        fprintf(schedule, "\nEXTRA BUS : ");
        fprintf(schedule, "%s-%s(NON-AC)	 EXT%s	   %s", strt, eend, Time, Cost);
    }

    printf("\n\n\t\tEXTRA BUS HAS BEEN SUCCESSFULLY ADDED IN THAT ROUTE.\n");
}
