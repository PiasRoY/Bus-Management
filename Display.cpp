#include <stdio.h>
#include <string.h>
#include <time.h>
#include <cstdlib>
#include "Bus.Functions.h"

void Display(FILE *ScheduleFile, FILE *Info, FILE *BookedSeats, FILE *Available) {
    printf("\t*****WELCOME TO THE TRAVELER BUS RESERVATION SYSTEM - @2017*****\n");
    time_t t;
    time(&t);
    printf("\n\t       Today's date and time : %s\n",ctime(&t));

    printf("\t\t*************MENU*************\n");
    printf("\t\t------------------------------\n\n");
    printf("\t\t\tA. BUS SCHEDULES.\n");
    printf("\t\t\tB. BUS BOOKING.\n");
    printf("\t\t\tC. SEAT AVAILABILITY.\n");
    printf("\t\t\tD. CUSTOMER DETAILS.\n");
    printf("\t\t\tE. TICKET CANCELLATION.\n");
    printf("\t\t\tF. PROFILE UPDATE.\n");
    printf("\t\t\tG. ADMIN PANEL.\n");
    printf("\t\t\t0. EXIT.\n\n");
    printf("\t\tWHAT YOU WANT TO DO?(ENTER A/B/C/D/E/F/G) : ");

    //INPUT
    char ch;
    scanf("%c", &ch);
    system("cls");
    if     (ch == 'A' || ch == 'a') BUSSCHEDULES(ScheduleFile, Info, BookedSeats, Available);
    else if(ch == 'B' || ch == 'b') BUSBOOKING(ScheduleFile, Info, BookedSeats, Available);
    else if(ch == 'C' || ch == 'c') SEATS(ScheduleFile, Available);
    else if(ch == 'D' || ch == 'd') CUSTOMERDETAILS(Info);
    else if(ch == 'E' || ch == 'e') TICKETCANCELLATION(Info, BookedSeats, Available);
    else if(ch == 'F' || ch == 'f') Update(Info);
    else if(ch == 'G' || ch == 'g') AdminPanel(ScheduleFile, Info, BookedSeats, Available);
    else if(ch == '0') printf("\tTHANK YOU FOR USING OUR ONLINE SERVICE.\n\n"), exit(0);
}
