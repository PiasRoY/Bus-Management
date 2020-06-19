#include <stdio.h>
#include <cstdlib>
#include "Bus.Functions.h"

void SEATS(FILE *schedule, FILE *Available)
{
    //INITIAL WORK
    printf("\n\n\t\t\tWELCOME TO SEAT AVAILABILITY CATAGORY\n");
    printf("\t\t----------------------------------------------------\n\n");

    //MAIN WORK STARTS HERE
    int RouteCode;
    RouteCode = RNtoRC(schedule);

    if(RouteCode != -1) AVAILABLESEATS(Available, RouteCode);
    else printf("\n\n\tYOU HAVE ENTERED INVALID BUS-ROUTE OR BUS-TIME.\n\n");
    //MENU
    char ch;
    printf("\n\n\tPRESS 'M' TO GO BACK TO MENU\n\n");
    printf("\tPRESS 'E' TO EXIT\n\t");
    getchar();
    scanf("%c", &ch);
    system("cls");
    if(ch == 'E' || ch == 'e') printf("\tTHANK YOU FOR USING OUR ONLINE SERVICE.\n\n"), exit(0);
}
