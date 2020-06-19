#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include "Bus.Functions.h"

void BUSBOOKING(FILE *ScheduleFile, FILE *Info, FILE *BookedSeats, FILE *Available) {
    //INITIAL WORK
    printf("\t\tWELCOME TO OUR BUS BOOKING CATAGORY\n");
    printf("\t------------------------------------------------\n\n");
    //MAIN WORK
    struct info INFORMATION;
    //RouteCode
    //printf("\tENTER THE ROUTE CODE : ");
    INFORMATION.routecode.RC = RNtoRC(ScheduleFile);
    if(INFORMATION.routecode.RC != -1) {
        //Seat
        printf("\tENTER NUMBER OF SEATS YOU WANT : ");
        scanf("%d", &INFORMATION.seat.NumeberOfSeats);
        //BookedFile
        char n[3];
        if(INFORMATION.routecode.RC < 10) n[0] = INFORMATION.routecode.RC+48, n[1] = '\0';
        else {
            int i = INFORMATION.routecode.RC%10;
            int j = INFORMATION.routecode.RC / 10;
            n[0] = j+48, n[1] = i+48, n[2] = '\0';
        }
        char str[25] = "ROUTE NO. ";
        strcat(str, n), strcat(str, " :\n");
        char thatline[200];
        while(!feof(BookedSeats)) {
            fgets(thatline, 200, BookedSeats);
            if(strcmp(str, thatline) == 0) {
                fgets(thatline, 200, BookedSeats);
                break;
            }
        }
        //BACKTOMAINWORK
        //REOPENING
        fclose(Available);
        char D[200];
        strcpy(D, DATE());
        strcat(D, "C4.Availability.txt");
        Available = fopen(D, "a+");

        AVAILABLESEATS(Available, INFORMATION.routecode.RC);
        char S[2]; int i;
        printf("\tENTER YOUR SEATPLAN : \n");
        strcpy(INFORMATION.seat.SeatPlans, "");
        for(i = 1; i <= INFORMATION.seat.NumeberOfSeats; i++) {
            printf("\t%d :", i);
            scanf("%s", S);
            to_upper(S);
            if(strstr(thatline, S) != NULL) {
                printf("\tSORRY SIR, YOUR PREFERABLE SEAT HAS BEEN BOOKED BY SOMEONE-ELSE\n");
                printf("\tENTER ANYOTHER AVAILABLE SEATS!\n");
                i--;
                continue;
            }
            fclose(BookedSeats);
            fclose(Available);
            strcpy(D, DATE());
            strcat(D, "C4.Availability.txt");
            Available   = fopen(D, "a+");
            strcpy(D, DATE());
            strcat(D, "C3.Booked Seats.txt");
            BookedSeats = fopen(D, "a+");

            InsertInBooked(BookedSeats, Available, INFORMATION.routecode.RC, S);
            strcat(INFORMATION.seat.SeatPlans, " ");
            strcat(INFORMATION.seat.SeatPlans, S);
        }
        //NAME
        printf("\tYour First Name(IN 20 CHARACTERS) : ");
        scanf("%s", INFORMATION.name.fname);
        printf("\tYour Last Name(IN 20 CHARACTERS)  : ");
        scanf("%s", INFORMATION.name.lname);
        //ADDRESS
        printf("\tYOUR PERMANENT ADDRESS(IN 50 CHARACTERS) : ");
        scanf("%s", INFORMATION.address.Peaddress);
        printf("\tYOUR PRESENT ADDRESS(IN 50 CHARACTERS)   : ");
        scanf("%s", INFORMATION.address.Praddress);
        //CONTACTS
        printf("\tYour Phone Number(WITH COUNTRY CODE)     : ");
        scanf("%lld", &INFORMATION.contacts.number);
        printf("\tAlternative Number(WITH COUNTRY CODE)    : ");
        scanf("%lld", &INFORMATION.contacts.Alnumber);
        printf("\tYour Email ID(IN 100 CHARACTERS)         : ");
        scanf("%s", INFORMATION.contacts.Email);

        printf("\n\tYOUR TICKET HAS BEEN BOOKED SUCCESSFULLY!!\n\n");

        system("cls");
        printf("\t************PLEASE PRINT IT FOR FUTHER USE**************\n");
        printf("\t\tROUTE CODE : %d\n"         , INFORMATION.routecode.RC);
        printf("\t\tTIME       : %s\n"         , INFORMATION.costntime.Time[INFORMATION.routecode.RC-1].time);
        printf("\t\tSEAT NO    : %d\n"         , INFORMATION.seat.NumeberOfSeats);
        printf("\t\tSEATPLAN   : %s\n"         , INFORMATION.seat.SeatPlans);
        printf("\t\tPRICE      : %d\n"         , INFORMATION.costntime.Cost[INFORMATION.routecode.RC-1]);
        printf("\t\tNAME       : %s "          , INFORMATION.name.fname);
        printf("%s\n"                          , INFORMATION.name.lname);
        printf("\t\tPERMANENT ADDRESS : %s\n"  , INFORMATION.address.Peaddress);
        printf("\t\tPRESENT ADDRESS   : %s\n"  , INFORMATION.address.Praddress);
        printf("\t\tPHONE NUMBER      : %lld\n", INFORMATION.contacts.number);
        printf("\t\tALTERNATIVE NUMBER: %lld\n", INFORMATION.contacts.Alnumber);
        printf("\t\tE-MAIL            : %s\n"  , INFORMATION.contacts.Email);
        printf("\t    YOUR FIRST NUMBER IS YOUR USERID : %lld\n"  , INFORMATION.contacts.number);
        printf("\t**************USE IT IN CUSTOMER DETAILS!!**************\n");

        printf("\t********************************************************\n");

        fprintf(Info, "User ID    : %lld\n"       , INFORMATION.contacts.number);
        fprintf(Info, "ROUTE CODE : %d\n"         , INFORMATION.routecode.RC);
        fprintf(Info, "TIME       : %s\n"         , INFORMATION.costntime.Time[INFORMATION.routecode.RC-1].time);
        fprintf(Info, "SEAT NO    : %d\n"         , INFORMATION.seat.NumeberOfSeats);
        fprintf(Info, "SEATPLAN   : %s\n"         , INFORMATION.seat.SeatPlans);
        fprintf(Info, "PRICE      : %d\n"         , INFORMATION.costntime.Cost[INFORMATION.routecode.RC-1]);
        fprintf(Info, "NAME       : %s "          , INFORMATION.name.fname);
        fprintf(Info, "%s\n"                      , INFORMATION.name.lname);
        fprintf(Info, "PERMANENT ADDRESS : %s\n"  , INFORMATION.address.Peaddress);
        fprintf(Info, "PRESENT ADDRESS   : %s\n"  , INFORMATION.address.Praddress);
        fprintf(Info, "PHONE NUMBER      : %lld\n", INFORMATION.contacts.number);
        fprintf(Info, "ALTERNATIVE NUMBER: %lld\n", INFORMATION.contacts.Alnumber);
        fprintf(Info, "E-MAIL            : %s\n"  , INFORMATION.contacts.Email);
        fprintf(Info, "END\n\n");
    }
    else printf("\n\n\tYOU HAVE ENTERED INVALID BUS-ROUTE OR BUS-TIME.\n\n");

    //MENU
    printf("\n\tPRESS 'M' TO GO BACK TO MENU\n");
    printf("\tPRESS 'E' TO EXIT\n\t");
    char ch;
    getchar();
    scanf("%c", &ch);
    if(ch == 'E' || ch == 'e') exit(0);
}
