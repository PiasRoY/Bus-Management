#include <stdio.h>
#include <string.h>
#include "Bus.Functions.h"

void InsertInBooked(FILE *BookedSeats, FILE *Available, int RouteCode, char S[]) {
    FILE *temp1 = fopen("temp1.txt", "w");
    FILE *temp2 = fopen("temp2.txt", "w");
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
    char line[200]; int n, i;
    while(!feof(BookedSeats)) {
        fgets(line, 200, BookedSeats);
        if(strcmp(str, line) == 0) {
            fputs(line, temp1);
            fscanf(BookedSeats, "%d", &n);
            fprintf(temp1, "%d", n+1);
            for(i = 0; i < n; i++) {
                fscanf(BookedSeats, "%s", line);
                fprintf(temp1, " %s", line);
            }
            fprintf(temp1, " %s", S);
        }
        else fputs(line, temp1);
    }

    //Updating BookedSeats Completed
    //Now Updating Availability File..
    while(!feof(Available))
    {
        fgets(line, 200, Available);
        if(strcmp(str, line) == 0) {
            fputs(line, temp2);
            while(1) {
                fgets(line, 200, Available);
                //printf("\n%s\n", line);
                if(strcmp(line, "END\n") == 0) { fputs("END\n", temp2); break; }
                if(strstr(line, S) != NULL) {
                    for(i = 0; i < strlen(line); i++) {
                        if(line[i] == S[0] && line[i+1] == S[1]) {
                            line[i+2] = '(';
                            line[i+3] = 'B';
                            line[i+4] = 'O';
                            line[i+5] = 'O';
                            line[i+6] = 'K';
                            line[i+7] = 'E';
                            line[i+8] = 'D';
                            line[i+9] = ')';
                        }
                    }
                }
                fputs(line, temp2);
            }
        }
        else fputs(line, temp2);
    }
    fclose(BookedSeats);
    fclose(temp1);
    fclose(Available);
    fclose(temp2);

    char D[200];
    strcpy(D, DATE());
    strcat(D, "C3.Booked Seats.txt");
    remove(D);
    rename("temp1.txt", D);

    strcpy(D, DATE());
    strcat(D, "C4.Availability.txt");
    remove(D);
    rename("temp2.txt", D);
}


