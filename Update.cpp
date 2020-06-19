#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include "Bus.Functions.h"

void Update(FILE *Info)
{
    //FILE
    FILE *temp;
    char D[100], N[100], R[100], ch;
    strcpy(D, DATE());
    strcat(D, "C2.Ticket Owner's Basic Informations.txt");
    fclose(Info);
    Info = fopen(D, "a+");
    //INITIAL WORK
    printf("\t\tWELCOME TO OUR CUSTOMER-PROFILE UPDATE CATAGORY\n");
    printf("\t\t-----------------------------------------------\n\n");
    printf("\t\tYOU CAN CHANGE YOUR BASIC INFORMATION FROM HERE.\n");
    printf("\t---------------------------------------------------------------\n\n");
    //MAIN WORK
    int TF = 0;
    char S[50] = "User ID    : ", UID[20], str[200];
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
        if(!TF) printf("\n\n\tNO SUCH CUSTOMER IS REGISTERED WITH THIS USER-ID.\n\n");
        //UPDATING
        if(TF) {
            while(1) {
                fclose(Info);
                Info = fopen(D, "a+");
                printf("\tWHAT YOU WANT TO CHANGE?\n");
                printf("\t\t1) NAME\n\t\t2) PERMANENT ADDRESS\n\t\t3) PRESENT ADDRESS\n\t\t4) PHONE NUMBER\n\t\t5) ALTERNATIVE PHONE NUMBER\n\t\t6) E-MAIL\n\n");
                printf("\tENTER (1/2/3/4/5/6) : ");
                getchar();
                scanf("%c", &ch);
                if(ch == '1') printf("\tENTER YOUR NEW NAME : ");
                else if(ch == '2') printf("\tENTER YOUR NEW PERMANENT ADDRESS : ");
                else if(ch == '3') printf("\tENTER YOUR NEW PRESENT ADDRESS : ");
                else if(ch == '4') printf("\tENTER YOUR NEW PHONE NUMBER : ");
                else if(ch == '5') printf("\tENTER YOUR NEW ALTERNATIVE PHONE NUMBER : ");
                else if(ch == '6') printf("\tENTER YOUR NEW E-MAIL : ");
                else printf("\n\n\tINVALID INPUT."), getchar(), getchar(), system("cls"), Update(Info);
                getchar();
                gets(N);
                printf("\n\n");
                int i = 1;
                temp = fopen("temp.txt", "w");
                system("cls");
                while(!feof(Info)) {
                    fgets(str, 200, Info);
                    fputs(str, temp);
                    if(strcmp(S, str) == 0) {
                        while(1) {
                            fgets(str, 200, Info);
                            if(i == (ch-'0')+5) {
                                if(ch == '1') strcpy(R, "NAME       : "), strcat(R, N);
                                else if(ch == '2') strcpy(R, "PERMANENT ADDRESS : "), strcat(R, N);
                                else if(ch == '3') strcpy(R, "PRESENT ADDRESS   : "), strcat(R, N);
                                else if(ch == '4') strcpy(R, "PHONE NUMBER      : "), strcat(R, N);
                                else if(ch == '5') strcpy(R, "ALTERNATIVE NUMBER: "), strcat(R, N);
                                else if(ch == '6') strcpy(R, "E-MAIL            : "), strcat(R, N);
                                strcpy(str, R);
                                strcat(str, "\n");
                            }
                            fputs(str, temp);
                            if(strcmp(str, "END\n") == 0) break;
                            printf("\t%s", str);
                            i++;
                        }
                    }
                }
                fclose(temp);
                fclose(Info);
                remove(D);
                rename("temp.txt", D);

                printf("\n\n\tDO WANT TO CHANGE ANYTHING ELSE?(Y/N) : ");
                scanf("%c", &ch);
                if(ch == 'N' || ch == 'n') break;
            }
        }

        //MENU
        printf("\n\n\tPRESS 'M' TO GO BACK TO MENU\n\n");
        printf("\tPRESS 'E' TO EXIT\n\t");
        getchar();
        scanf("%c", &ch);
        system("cls");
        if(ch == 'E' || ch == 'e') printf("\tTHANK YOU FOR USING OUR ONLINE SERVICE.\n\n"), exit(0);

}
