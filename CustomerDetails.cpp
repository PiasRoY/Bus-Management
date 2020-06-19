#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include "Bus.Functions.h"

void CUSTOMERDETAILS(FILE *Info) {
    //INITIAL WORK
    printf("\t\tWELCOME TO OUR CUSTOMER-DETAILS CATAGORY\n");
    printf("\t--------------------------------------------------------\n\n");
    //MAIN WORK
    int TF = 0;
    //char S[50] = "User ID    : ", UID[20], str[200];
    //USE OF MALLOC
    char *S, *UID, *str;
    S = (char *)malloc(10*sizeof(char));
    UID = (char *)malloc(2*sizeof(char));
    str = (char *)malloc(20*sizeof(char));
    S = (char *)realloc(S, 100*sizeof(char));
    UID = (char *)realloc(UID, 20*sizeof(char));
    str = (char *)realloc(str, 200*sizeof(char));
    strcpy(S, "User ID    : ");

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
    free(S);
    free(UID);
    free(str);
    END :
        if(!TF) printf("\n\n\tNO SUCH CUSTOMER IS REGISTERED WITH THIS USER-ID.\n\n");
        //MENU
        printf("\n\n\tPRESS 'M' TO GO BACK TO MENU\n\n");
        printf("\tPRESS 'E' TO EXIT\n\t");
        char ch;
        getchar();
        scanf("%c", &ch);
        system("cls");
        if(ch == 'E' || ch == 'e') printf("\tTHANK YOU FOR USING OUR ONLINE SERVICE.\n\n"), exit(0);
}
