#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include "Bus.Functions.h"


void TICKETCANCELLATION(FILE *Info, FILE *BookedSeats, FILE *Available)
{
    //INITIAL WORK
    printf("\t\tWELCOME TO OUR TICKETCANCELLATION CATAGORY\n");
    printf("\t-----------------------------------------------------------\n\n");
    //MAIN WORK
    FILE *temp1 = fopen("temp1.txt", "w"), *temp2;
    FILE *Delete;

    //MAIN WORK STARTS HERE
    int TF = 0, i = 0;
    char S[50] = "User ID    : ", UID[20], str[200], RC[200], SN[100], SP[100], D[200], ch;
    printf("\tEnter Your UserID : ");
    scanf("%s", UID);
    strcat(S, UID);
    strcat(S, "\n");
    while(!feof(Info)) {
        fgets(str, 200, Info);
        //printf("Debug = %s %s %d\n", S, str, strcmp(S, str));
        if(strcmp(S, str) == 0) {
            TF = 1;
            while(1) {
                fgets(str, 200, Info);
                if(strcmp(str, "END\n") == 0) goto END;
                printf("\t%s", str);
            }
        }
    }
    END :
    ch = 'N';
    if(TF) {
        //OPTIONS
        printf("\n\n\tTICKETCANCELLATION WILL BE COST 10 PERCENT OF THE PRICE OF THE TICKET.\n");
        printf("\n\tDO YOU WANT TO PROCEED?(Y/N) : ");
        getchar();
        scanf("%c", &ch);
    }
    else printf("\n\n\tNO SUCH CUSTOMER IS REGISTERED WITH THIS USER-ID.\n\n");
    if(ch == 'Y' || ch == 'y')
    {
        //REOPOENING FILE
        strcpy(D, DATE());
        strcat(D, "C2.Ticket Owner's Basic Informations.txt");
        fclose(Info);
        Info = fopen(D, "a+");
        //BACKTOWORK
        while(!feof(Info)) {
            fgets(str, 200, Info);
            if(strcmp(S, str) == 0) {
                strcpy(D, DATE());
                strcat(D, "C5.Deleted Profile.txt");
                Delete = fopen(D, "a+");
                fputs(str, Delete);
                while(1) {
                    fgets(str, 200, Info);
                    fputs(str, Delete);
                    if(i == 0) strcpy(RC, str);
                    else if(i == 2) strcpy(SN, str);
                    else if(i == 3) strcpy(SP, str);
                    if(strcmp(str, "END\n") == 0) break;
                    i++;
                }
            }
            else fputs(str, temp1);
        }

        fclose(Info);
        fclose(temp1);
        fclose(Delete);

        strcpy(D, DATE());
        strcat(D, "C2.Ticket Owner's Basic Informations.txt");
        remove(D);
        rename("temp1.txt", D);
        //INFO EDITED!!
        //DELETE CREATED!!
        //BOOKEDSEATS & AVAILABILITY EDITING
        if(TF) {
            temp1 = fopen("temp1.txt", "w");
            temp2 = fopen("temp2.txt", "w");
            //Convert RouteCode(int to char)
            char no[3];
            if(RC[14] >= '0' && RC[14] <= '9') {
                no[0] = RC[13], no[1] = RC[14], no[2] = '\0';
            }
            else no[0] = RC[13], no[1] = '\0';
            char str[25] = "ROUTE NO. ";
            strcat(str, no), strcat(str, " :\n");
            char line[200]; int n = 0, i, j;
            while(!feof(BookedSeats)) {
                fgets(line, 200, BookedSeats);
                if(strcmp(str, line) == 0) {
                    fputs(line, temp1);
                    fscanf(BookedSeats, "%d", &n);
                    fprintf(temp1, "%d", n-(SN[13]-'0'));
                    for(i = 0; i < n; i++) {
                        fscanf(BookedSeats, "%s", line);
                        if(strstr(SP, line) != NULL) continue;
                        fprintf(temp1, " %s", line);
                    }
                }
                else fputs(line, temp1);
            }

            //Updating BookedSeats Completed
            //Now Updating Availability File..
            n = SN[13]-'0';
            struct string_id {
                char s[3];
            } S[n];
            for(i = 0, j = 14; i < n; i++, j+=3) {
                S[i].s[0] = SP[j], S[i].s[1] = SP[j+1], S[i].s[2] = '\0';
                //printf("\ti = %d, %s\n", i, S[i].s);
            }

            while(!feof(Available))
            {
                fgets(line, 200, Available);
                if(strcmp(str, line) == 0) {
                    fputs(line, temp2);
                    while(1) {
                        fgets(line, 200, Available);
                        //printf("\n%s\n", line);
                        if(strcmp(line, "END\n") == 0) { fputs("END\n", temp2); break; }
                        for(j = 0; j < n; j++) {
                            if(strstr(line, S[j].s) != NULL) {
                                for(i = 0; i < strlen(line); i++) {
                                    if(line[i] == S[j].s[0] && line[i+1] == S[j].s[1]) {
                                        line[i+2] = ' ';
                                        line[i+3] = ' ';
                                        line[i+4] = ' ';
                                        line[i+5] = ' ';
                                        line[i+6] = ' ';
                                        line[i+7] = ' ';
                                        line[i+8] = ' ';
                                        line[i+9] = ' ';
                                    }
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

        printf("\n\tTICKET HAS BEEN SUCCESSFULLY CANCELLED.\n\n");
    }

    //MENU
    printf("\n\n\tPRESS 'M' TO GO BACK TO MENU\n\n");
    printf("\tPRESS 'E' TO EXIT\n\t");
    getchar();
    scanf("%c", &ch);
    system("cls");
    if(ch == 'E' || ch == 'e') printf("\tTHANK YOU FOR USING OUR ONLINE SERVICE.\n\n"), exit(0);
}

