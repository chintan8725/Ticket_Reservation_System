
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>
#include "myheader.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
void login();
void headMessage()
{
    system("clear");
    printf("\n");
    printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############              Ticket Booking System                ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
}


int main()
{
    int t;
    headMessage();
    login();

    do
    {
        int stat;
        headMessage();
        printf("\n1> Bus reservation\n2> Flight booking\n0> exit\n");
        printf("Please, Enter your choice..!\n");
        scanf("%d",&t);
        if(fork()==0){
        switch(t)
        {
        case 1:
            bus_reservation();
            break;

        case 2:
            flight_reservation();
            break;
        default:
            printf("Please, Enter valid option..\n");
        }
        }
        wait(&stat);
        if(WCOREDUMP(stat)) printf("Error");
    }
    while(t != 0);
    system("clear");
    printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("   THANK YOU FOR USING TICKET RESERVATION SYSTEM " "%c",1);
    printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    getchar();

    return 0;
}
struct login
{
    char username[20];
    char password[20];
    char fname[20];
    char lname[20];
};
void registration()
{
    FILE *log;
    log=fopen("login.txt","w+");
    struct login l;
    char username[20],password[20];
    char fname[20];
    char lname[20];

    printf("\nEnter first name:\n");
    scanf("%s",fname);
    printf("\nEnter last name:\n");
    scanf("%s",lname);
    printf("Thank you.\nNow please choose a username and password as credentials for system login.\n");
    printf("\nEnter Username:\n");
    scanf("%s",username);
    printf("\nEnter Password:\n");
    scanf("%s",password);
    strcpy(l.username,username);
    strcpy(l.password,password);
    strcpy(l.fname,fname);
    strcpy(l.lname,lname);

    fwrite(&l,sizeof(l),1,log);
    fclose(log);

    printf("\nRegistration Successful!\n");
    getchar();

    login();
}
void login()
{
    int option;

    printf("Press '1' to Register\nPress '2' to Login\n\n");
    scanf("%d",&option);

    if(option == 1)
    {
        system("clear");
        registration();
    }


    int a=0,i=0;
    char uname[20],c=' ';
    char pword[20],code[10];
    FILE *log;
    log=fopen("login.txt","rb+");
    struct login l;
    pword[i]='\0';
    fread(&l,sizeof(l),1,log);
    fclose(log);
    do
    {

        printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
        printf("\t    TICKET RESERVATION");
        printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
        printf("   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd  LOGIN FORM  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd  ");
        printf("\n\n   ENTER USERNAME: ");
        scanf("%s", uname);
        printf(" \n   ENTER PASSWORD: ");
        scanf("%s", pword);
        i=0;


        if(strcmp(uname,l.username)==0 && strcmp(pword,l.password)==0)

        {
            printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
            printf("  \n\n   WELCOME %s %s !!!!",l.fname,l.lname);
            break;
        }
        else if(strcmp(uname,l.username)==0)
        {

            printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
            printf("  \n\n  Wrong password !!!!");
            getchar();//holds the screen
            system("clear");
        }
        else
        {
            printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
            printf("\n\n   LOGIN IS UNSUCESSFUL...PLEASE TRY AGAIN...");
            a++;

            getchar();//holds the screen
            system("clear");
        }


    }
    while(a<=3);
    if (a>3)
    {
        printf("\nSorry you have entered the wrong username and password for four times!!!,please exit");

        getchar();
        exit(0);
    }

}
