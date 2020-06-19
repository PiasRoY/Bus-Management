#include <stdio.h>
#include <string.h>
#include "Bus.Functions.h"

void AdminPanellist(FILE *schedule, FILE *Info)
{
    fclose(Info);
    char D[200];
    strcpy(D, DATE());
    strcat(D, "C2.Ticket Owner's Basic Informations.txt");
    Info = fopen(D, "r");
    //AFTER FILE OPENING
    char RC[100] = "ROUTE CODE : ", R[200];
    int iR, TF = 0;
    iR = RNtoRC(schedule);
    if(iR != -1) {
        sprintf(R, "%d", iR);
        strcat(RC, R), strcat(RC, "\n");
        printf("\n\n\t\t%s\n\n", RC);
        while(!feof(Info))
        {
            fgets(R, 200, Info);
            if(strcmp(R, RC) == 0) {
                TF = 1;
                while(1) {
                    fgets(R, 200, Info);
                    if(strcmp(R, "END\n") == 0) {printf("\n\n"); break;}
                    printf("\t\t%s", R);
                }
            }
        }
        if(!TF) printf("\t\tNOBODY BOARDING IN THIS BUS.");
    }
    else printf("\n\n\tYOU HAVE ENTERED INVALID BUS-ROUTE OR BUS-TIME.\n\n");
}
