#include <stdio.h>
#include <string.h>
#include <time.h>
#include "Bus.Functions.h"

char * DATE() {
    char str1[200], str2[50];
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    sprintf(str2, "%d", now->tm_year + 1900);
    strcpy(str1, str2);
    sprintf(str2, "%d", now->tm_mon + 1);
    strcat(str1, str2);
    sprintf(str2, "%d", now->tm_mday);
    strcat(str1, str2);
    strcat(str1, ".");

    return str1;
}
