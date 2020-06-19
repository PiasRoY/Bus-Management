#include <stdio.h>
#include <string.h>
#include "Bus.Functions.h"

void to_upper(char *str) {
    int i = 0;
    while(str[i] != '\0') {
        if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] = 'A'+(str[i]-'a');
        }
        i++;
    }
}
