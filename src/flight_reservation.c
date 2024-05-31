#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>
//void bus_registration(){
char *my_itoa1(int num, char *str)
{
    if(str == NULL)
    {
        return NULL;
    }
    sprintf(str, "%d", num);
    return str;
}
char cha1[10][130]= {"Dubai","London","Singapore","New-york","Tokyo"};
char cha[10][130]= {"Air India Airlines","Indigo Airlines","SpiceJet Airlines","Alliance Airlines","Star Airlies"};
char source1[20]="Mumbai";
char name1[73][100]= {'\0'};
char number1[73][2]= {'\0'};
int num11[73]= {0};
int trno1;
void flight();
void name_number1(int book_ticket,char numstr[100]);
void book_ticket();//for book_ticket the tickets
int read_name_number1(int trno1);//for reading the number from the file
void status1();//for printing the status by user input
void status1_1(int trno1);//for printing the status while book_ticket ticket
void ticket_download1();
void cancle1();

void flight_reservation()
{

    int num,i;
    do
    {
        system("clear");
        printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
        printf("\t    Flight RESERVATION");
        printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
        printf("   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd  MAIN MENU  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
        printf("   [1] View Flight List\n\n");
        printf("   [2] Book Tickets\n\n");
        printf("   [3] Cancel Booking\n\n");
        printf("   [4] Booked ticket status\n\n");
        printf("   [5] Download your Tickets\n\n");
        printf("   [6] Exit\n\n");
        printf("   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
        printf("   ENTER YOUR CHOICE: ");
        scanf("%d",&num);
        switch(num)
        {
        case 1:
            flight();//for list of flight
            break;
        case 2:
            book_ticket();//for booking the tickets
            break;
        case 3:
            cancle1();
            break;
        case 4:
            status1();
            break;
        case 5:
            ticket_download1();
            break;
        }
        getchar();
    }
    while(num != 6);
    system("clear");
    printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("   THANK YOU FOR USING THIS FLIGHT TICKET RESERVATION SYSTEM " "%c",1);
    printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    getchar();
    exit(0);
}

struct ticket
{
    char name[30];
    char num[3];
};

void flight()
{

    system("clear");
    printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t    FLIGHT RESERVATION");
    printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
    printf("   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd  FLIGHT-LIST  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd \n\n");
    printf("   [1]  =>  %s\n",cha[0]);
    printf("   SOURCE: %s",source1);
    printf("   DESTINATION: %s\n",cha1[0]);
    printf("   [2]  =>  %s\n",cha[1]);
    printf("   SOURCE: %s",source1);
    printf("   DESTINATION: %s\n",cha1[1]);
    printf("   [3]  =>  %s\n",cha[2]);
    printf("   SOURCE: %s",source1);
    printf("   DESTINATION: %s\n",cha1[2]);
    printf("   [4]  =>  %s\n",cha[3]);
    printf("   SOURCE: %s",source1);
    printf("   DESTINATION: %s\n",cha1[3]);
    printf("   [5]  =>  %s\n",cha[4]);
    printf("   SOURCE: %s",source1);
    printf("   DESTINATION: %s\n",cha1[4]);
    getchar();
}

void book_ticket()
{

    int i=0;
    char numstr[100];
    char uname[100];
    system("clear");
    printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t    FLIGHT RESERVATION");
    printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
    flight();//for seeing flight list
    printf("   ENTER THE FLIGHT NUMBER: ");
    scanf("%d",&trno1);
    system("clear");
    printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t    FlIGHT RESERVATION");
    printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
    printf("Your FLIGHT Number is %d **** %s",trno1,cha[trno1-1]);
    status1_1(trno1);
    FILE *f1, *fopen();//for reading the seats from the user.
    int seat1,booking=0;
    seat1=read_name_number1(trno1);//covert the string into number
    if(seat1 >= 72)
    {
        printf("There is no blank seat in this bus plz choose another bus ");
    }
    else
    {
        printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
        printf("\n   AVAILABLE SEATS: %d\n",(72-seat1));
        printf("\n   NUMBER OF TICKETS: ");
        scanf("%d",&booking);
        printf("\n");
        if(booking>72-seat1)
        {
            printf("\n   AVAILABLE SEATS: %d plz Try Another bus\n",(72-seat1));

        }
        else
        {
            my_itoa1(trno1,numstr);
            name_number1(booking,numstr);
            printf("   The Total booking amount is %d",5000*booking);
        }

    }
    getchar();
}


void name_number1(int booking,char numstr[100])
{
    char tempstr[100],tempstr1[12]="Airstatus";
    int number;
    FILE *a;
    int i=0,tem=0;
    strcat(numstr,".txt");
    strcat(tempstr1,numstr);
    a = fopen(tempstr1,"a");//for open the file to write the name in the file
    struct ticket b;
    for(i=0; i<booking; i++)//for entering the person name and seat number in the file
    {
        printf("   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd Enter the details for ticket no %d \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n",i+1);
        printf("   ENTER THE SEAT NUMBER: ");
        scanf("%d",&number);
        tem=0;
        for(int j=1; j<=72; j++)
        {
            if(num11[j]==0) break;
            if(num11[j]==number)
            {
                printf("\nSEAT AlREADY TAKEN PLZ CHOOSE ANOTHER SEAT\n ");

                tem=1;
                break;
            }
        }
        if(tem==1||number>108||number<1){ i--; continue;}
        printf("\n   ENTER THE PERSON NAME: ");
        scanf("%s",name1[number-1]);
        printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
        printf("\n");
        my_itoa1(number, tempstr);
        strcpy(b.name,name1[number-1]);
        strcpy(b.num,tempstr);
        fwrite(&b,sizeof(b),1,a);
    }
    fclose(a);

}

void *read_name1(void* arg)
{
    char *temp=arg;
    FILE *a1;
    a1 = fopen(temp,"r");
    struct ticket b1;
    int ii=1;
    while(fread(&b1,sizeof(b1),1,a1)==1)
    {
        strcpy(name1[ii],b1.name) ;
        ii++;
    }
    fclose(a1);
    pthread_exit(0);

}

int read_name_number1(int trno1) //for putting the numeric value in the array
{
    char tempstr[100],tempstr2[12]="Airstatus";
    FILE *a;
    char numstr[100];
    int i=1,j=0,k;
    my_itoa1(trno1,numstr);
    strcat(numstr,".txt");
    strcat(tempstr2,numstr);
    a = fopen(tempstr2,"a+");//for open the file to write the name in the file
    struct ticket b;
    pthread_t thread1;
    pthread_create(&thread1,NULL,read_name1,(void*)&tempstr2);
    while(fread(&b,sizeof(b),1,a)==1)
    {
        strcpy(number1[i],b.num) ;
        num11[i] = atoi(number1[i]);
        i++;
    }
    fclose(a);
    pthread_join(thread1,NULL);
    return i-1;
}



void status1()
{
    system("clear");
    printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t\t      FLIGHT RESERVATION");
    printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
    int i,trno1,index=0,j;
    printf("   ENTER THE FLIGHT NUMBER: ");
    scanf("%d",&trno1);
    j=read_name_number1(trno1);

    printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t\t   Flight No.%d: %s\n",trno1,cha[trno1-1]);
    printf("   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
    char tempname[73][10];
    for(i=0; i<73; i++)
    {
        strcpy(tempname[i],"Empty");
    }
    for(i=1; i<=j; i++)
    {
        strcpy(tempname[num11[i]],name1[i]);
        num11[i]=0;
    }

    for(i=0; i<12; i++)
    {
        printf("   ");
        for(j=0; j<6; j++)
        {
            if((index)%2==0)
            {
                printf("\t\t");
            }
            printf("%d.%s ",index+1,tempname[index+1]);
            index++;
        }
        printf("\n");
    }
    getchar();
}

void status1_1(int trno1)
{
    printf("Your Flight Number is %d **** %s",trno1,cha[trno1-1]);
    system("clear");
    printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t\t      FLIGHT RESERVATION");
    printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
    int i,index=0,j;
    j=read_name_number1(trno1);
    printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t\t   Flight No.%d: %s\n",trno1,cha[trno1-1]);
    printf("   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
    char tempname[73][10];
    for(i=0; i<73; i++)
    {
        strcpy(tempname[i],"Empty");
    }
    for(i=1; i<=j; i++)
    {
        strcpy(tempname[num11[i]],name1[i]);
        num11[i]=0;
    }

    for(i=0; i<12; i++)
    {
        printf("   ");
        for(j=0; j<6; j++)
        {
            if((index)%2==0)
            {
                printf("\t\t");
            }
            printf("%d.%s ",index+1,tempname[index+1]);
            index++;
        }
        printf("\n");
    }
}


void cancle1()
{
    int seat_no,i,j;
    char numstr[100],tempstr1[15]="Airstatus" ;
    printf("\n   ENTER THE FLIGHT NUMBER: ");
    scanf("%d",&trno1);
    my_itoa1(trno1,numstr);
    strcat(numstr,".txt");
    strcat(tempstr1,numstr);
    read_name_number1(trno1);
    status1_1(trno1);
    struct ticket b;
    printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("   ENTER THE SEAT NUMBER: ");
    scanf("%d",&seat_no);

    FILE *a,*ftemp;
    a = fopen(tempstr1,"r");
    ftemp = fopen("temp.txt", "wb");


    while(fread(&b,sizeof(b),1,a)==1)
    {
        if(seat_no!=atoi(b.num))
            fwrite(&b,sizeof(b),1,ftemp);
    }

    fclose(a);
    fclose(ftemp);
    remove(tempstr1);
    rename("temp.txt",tempstr1);



    printf("\n\n");
    printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("   Your 5000 Rupees has been Returned\n");
    printf("   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    getchar();
}
struct dwn
{
    char pname[20];
    int seat;
    int busno;
};
void *download1(void* arg)
{
    struct dwn *t=arg;
    printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t\t      TICKET INFORMATION");
    printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
    printf("\t\tFlight NAME: %s\n",cha[t->busno]);
    printf("\t\tSOURCE: %s\n",source1);
    printf("\t\tDESTINATION: %s",cha1[t->busno]);
    printf("\n");
    printf("\t\tNAME: %s\n",t->pname);
    printf("\t\tSEAT NUMBER: %d\n",t->seat);
    printf("\t\t\t\t\t 5000 Rupees\n");
    printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");


}
void ticket_download1()
{
    int seat_no,i=0;
    char print[30]="./tickets/airticket_";
    char numstr[100],tempstr1[15]="Airstatus";
    printf("\n   ENTER THE FLIGHT NUMBER: ");
    scanf("%d",&trno1);
    my_itoa1(trno1,numstr);
    strcat(numstr,".txt");
    strcat(tempstr1,numstr);
    read_name_number1(trno1);
    status1_1(trno1);
    printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("   ENTER THE SEAT NUMBER: ");
    scanf("%d",&seat_no);
    struct ticket b;
    struct dwn d;
    FILE *a;
    a = fopen(tempstr1,"r");
    pthread_t tid;
    while(fread(&b,sizeof(b),1,a))
    {
        i=0;
        if(seat_no==atoi(b.num))
        {
            d.busno=trno1-1;
            strcpy(d.pname,b.name);
            d.seat=seat_no;
            pthread_create(&tid,NULL,download1,(void*)&d); //for printing ticket
            //for downloading ticket
            FILE *d;
            strcat(print,b.name);
            strcat(print,b.num);
            strcat(print,".txt");
            d=fopen(print,"w+");
            fprintf(d,"********************\t Ticket Receipt \t********************\n");
            fprintf(d, "AirPlane Name: %s\t From %s to %s\n", cha[trno1-1],source1, cha1[trno1-1]);
            fprintf(d, "Name: %s\t\t seat no: %d\n", b.name, seat_no);
            fprintf(d, "Ammount paid 5000 rs.");
            fclose(d);
            fflush(stdin);
            i=1;
            break;
        }

    }
    printf("\n\t Ticket downloaded: %s",print);
    pthread_join(tid,NULL);
    if(i==0 )  printf("\n\t   NO TICKET INFORMATION");

    getchar();
    fclose(a);


}
