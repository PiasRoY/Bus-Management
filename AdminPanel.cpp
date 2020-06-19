#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include "Bus.Functions.h"

void AdminPanel(FILE *schedule, FILE *Info, FILE *BookedSeats, FILE *Available)
{
    //INITIAL WORK
    printf("\n\n\t\t\tWELCOME TO ADMIN PANEL\n");
    printf("\t\t---------------------------------------\n\n");

    //MAIN WORK STARTS HERE
    char UID[100], PASS[100], ch;
    printf("\t\tLOGIN - \n\t\tUSERNAME : ");
    scanf("%s", UID);
    printf("\t\tPASSWORD : ");
    scanf("%s", PASS);
    if(strcmp(UID, "ROY") == 0 && strcmp(PASS, "123456") == 0) {
        while(1) {
            printf("\n\t\tSELECT ANY ABOVE OPTIONS - \n");
            printf("\n\t\t\t1. LIST OF PASSENGERS\n");
            printf("\t\t\t2. CANCELLED TICKETS\n");
            printf("\t\t\t3. EMERGENCY MODE\n\n");
            printf("\t\tENTER (1/2/3) : ");
            int option;
            scanf("%d", &option);
            system("cls");
            printf("\n\n\t\t\tWELCOME TO ADMIN PANEL\n");
            printf("\t\t---------------------------------------\n\n");
            //WORK START HERE..
            if(option == 1) AdminPanellist(schedule, Info);
            else if(option == 2) AdminPanelReadingFile();
            else if(option == 3) AdminPanelemergecy(schedule);
            else printf("\n\n\t\tINVALID INPUT."), getchar(), getchar(), system("cls"), AdminPanel(schedule, Info, BookedSeats, Available);
            //ENDS HERE..
            printf("\n\n\t\tWANT TO DO ANYTHING ELSE? (Y/N) : ");
            getchar();
            scanf("%c", &ch);
            if(ch == 'N' || ch == 'n') break;
            system("cls");
            printf("\n\n\t\t\tWELCOME TO ADMIN PANEL\n");
            printf("\t\t---------------------------------------\n\n");
        }
    }
    else printf("\n\n\t\tINCORRECT USERNAME OR PASSWORD.\n");

    //MENU
        printf("\n\n\tPRESS 'M' TO GO BACK TO MENU\n\n");
        printf("\tPRESS 'E' TO EXIT\n\t");
        getchar();
        scanf("%c", &ch);
        system("cls");
        if(ch == 'E' || ch == 'e') printf("\tTHANK YOU FOR USING OUR ONLINE SERVICE.\n\n"), exit(0);
}
