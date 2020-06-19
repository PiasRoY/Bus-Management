#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include "Bus.Functions.h"

int main()
{

    while(1) {
        //OPENING FILES
        FILE *MainBusSchedule = fopen("MainBusSchedule.txt", "r");
        FILE *MainBookedSeats = fopen("MainBookedSeats.txt", "r");
        FILE *MainAvailable = fopen("MainAvailable.txt", "r");
        FILE *ScheduleFile, *Info, *BookedSeats, *Available;
        //ScheduleFile
        char D[200];
        strcpy(D, DATE());
        strcat(D, "C1.Regular Bus Schedule.txt");
        if((ScheduleFile = fopen(D, "r")) == NULL) {
            char str[200];
            ScheduleFile = fopen(D, "a+");
            while(!feof(MainBusSchedule)) {
                fgets(str, 200, MainBusSchedule);
                fprintf(ScheduleFile, str);
                //fputs(str, ScheduleFile);
            }
            fclose(ScheduleFile), ScheduleFile = fopen(D, "a+");
        }
        else fclose(ScheduleFile), ScheduleFile = fopen(D, "a+"); //1

        //TicketOwnerFile
        strcpy(D, DATE());
        strcat(D, "C2.Ticket Owner's Basic Informations.txt");
        Info = fopen(D, "a+");                                    //2

        //BookedSeatsFile
        strcpy(D, DATE());
        strcat(D, "C3.Booked Seats.txt");
        if((BookedSeats = fopen(D, "r")) == NULL) {
            char str[200];
            BookedSeats = fopen(D, "a+");
            while(!feof(MainBookedSeats)) {
                fgets(str, 200, MainBookedSeats);
                fputs(str, BookedSeats);
            }
            fclose(BookedSeats), BookedSeats = fopen(D, "a+");
        }
        else fclose(BookedSeats), BookedSeats = fopen(D, "a+");   //3

        //AvailabilityFile
        strcpy(D, DATE());
        strcat(D, "C4.Availability.txt");
        if((Available = fopen(D, "r")) == NULL) {
            char str[200];
            Available = fopen(D, "a+");
            while(!feof(MainAvailable)) {
                fgets(str, 200, MainAvailable);
                fputs(str, Available);
            }
            fclose(Available), Available = fopen(D, "a+");
        }
        else fclose(Available), Available = fopen(D, "a+");                 //4

        //WorkingStart
        system("cls");
        //MAIN FUNCTION
        system("COLOR 3F");
        Display(ScheduleFile, Info, BookedSeats, Available);
        //CLOSING FILES
        fclose(ScheduleFile);
        fclose(Info);
        fclose(BookedSeats);
        fclose(Available);
    }

    return 0;
}

