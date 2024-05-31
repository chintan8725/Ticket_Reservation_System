#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>
char *my_itoa(int num, char *str)
{
    if(str == NULL)
    {
        return NULL;
    }
    sprintf(str, "%d", num);
    return str;
}
//void bus_registration(){
struct ticket
{
    char name[30];
    char num[3];
};
char ch1[10][130]= {"Surat","Rajkot","Vadodara","Junagadh","Bhuj"};
char ch[10][130]= {"SOMNATH EXPRESS","REAL TRAVELS","EAGLE TRAVELS","SHYAM TRAVELS","RAMNATH TRAVELS"};
char source[20]="Ahmedabad";
char name[33][100]= {'\0'};
char number[33][2]= {'\0'};
int num1[33]= {0};
int trno;
void bus();
void name_number(int booking,char numstr[100]);
void booking();//for booking the tickets
int read_name_number(int trno);//for reading the number from the file
void status();//for printing the status by user input
void status_1(int trno);//for printing the status while booking ticket
void ticket_download();
void cancle();

void bus_reservation()
{

    int num,i;
    do
    {
        system("clear");
        printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
        printf("\t    BUS RESERVATION");
        printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
        printf("   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd  MAIN MENU  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
        printf("   [1] View Bus List\n\n");
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
            bus();//for list of bus
            break;
        case 2:
            booking();//for booking the tickets
            break;
        case 3:
            cancle();
            break;
        case 4:
            status();
            getchar();
            break;
        case 5:
            ticket_download();
            break;
        }
        getchar();
    }
    while(num != 6);
    system("clear");
    printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("   THANK YOU FOR USING THIS BUS TICKET RESERVATION SYSTEM " "%c",1);
    printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    getchar();
    exit(0);
}


void bus()
{

    system("clear");
    printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t    BUS RESERVATION");
    printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
    printf("   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd  BUS-LIST  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd \n\n");
    printf("   [1]  =>  %s\n",ch[0]);
    printf("   SOURCE: %s",source);
    printf("   DESTINATION: %s\n",ch1[0]);
    printf("   [2]  =>  %s\n",ch[1]);
    printf("   SOURCE: %s",source);
    printf("   DESTINATION: %s\n",ch1[1]);
    printf("   [3]  =>  %s\n",ch[2]);
    printf("   SOURCE: %s",source);
    printf("   DESTINATION: %s\n",ch1[2]);
    printf("   [4]  =>  %s\n",ch[3]);
    printf("   SOURCE: %s",source);
    printf("   DESTINATION: %s\n",ch1[3]);
    printf("   [5]  =>  %s\n",ch[4]);
    printf("   SOURCE: %s",source);
    printf("   DESTINATION: %s\n",ch1[4]);
    getchar();
}

void booking()
{

    int i=0;
    char numstr[100];
    char uname[100];
    system("clear");
    printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t    BUS RESERVATION");
    printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
    bus();//for seeing bus least
    printf("   ENTER THE BUS NUMBER: ");
    scanf("%d",&trno);
    system("clear");
    printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t    BUS RESERVATION");
    printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
    status_1(trno);

    int seat1,booking=0;
    seat1=read_name_number(trno);
    if(seat1 >= 32)
    {
        printf("\nThere is no blank seat in this bus plz choose another bus \n");
    }
    else
    {
        printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
        printf("\n   AVAILABLE SEATS: %d\n",(32-seat1));
        printf("\n   NUMBER OF TICKETS: ");
        scanf("%d",&booking);
        printf("\n");
        if(booking>32-seat1)
        {
            printf("\n   AVAILABLE SEATS: %d  PLZ TRY ANOTHER BUS\n",(32-seat1));

        }
        else
        {
            my_itoa(trno,numstr);
            name_number(booking,numstr);
            printf("   The Total booking amount is %d rupees",200*booking);
        }
    }
    getchar();
}


void name_number(int booking,char numstr[100])
{
    char tempstr[100],tempstr1[12]="status";
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
        for(int j=1; j<33; j++)
        {
            if(num1[j]==0) break;
            if(num1[j]==number)
            {
                printf("\nSEAT AlREADY TAKEN PLZ CHOOSE ANOTHER SEAT\n ");
                tem=1;
                break;
            }
        }
         if(tem==1||number>32||number<1) {i--; continue;}

        printf("\n   ENTER THE PERSON NAME: ");
        scanf("%s",name[number-1]);
        printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
        printf("\n");
        my_itoa(number, tempstr);
        strcpy(b.name,name[number-1]);
        strcpy(b.num,tempstr);
        fwrite(&b,sizeof(b),1,a);
    }
    fclose(a);

}
void *read_name(void* arg)
{
    char *temp=arg;
    FILE *a1;
    a1 = fopen(temp,"r");
    struct ticket b1;
    int ii=1;
    while(fread(&b1,sizeof(b1),1,a1)==1)
    {
        strcpy(name[ii],b1.name) ;
        ii++;
    }
    fclose(a1);
    pthread_exit(0);

}

int read_name_number(int trno)//for putting the numeric value in the array
{

    char tempstr[100],tempstr2[12]="status";
    FILE *a;
    char numstr[100];
    int i=1,j=0,k;
    my_itoa(trno,numstr);
    strcat(numstr,".txt");
    strcat(tempstr2,numstr);
    a = fopen(tempstr2,"a+");//for open the file to write the name in the file

    struct ticket b;
    pthread_t thread1,thread2;
    pthread_create(&thread1,NULL,read_name,(void*)&tempstr2);
    while(fread(&b,sizeof(b),1,a)==1)
    {
        strcpy(number[i],b.num) ;
        num1[i] = atoi(number[i]);
        i++;
    }
    fclose(a);
    pthread_join(thread1,NULL);

    return i-1;
}


void status()
{
    system("clear");
    printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t\t      BUS RESERVATION");
    printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
    int i,trno,index=0,j;
    printf("   ENTER THE BUS NUMBER: ");
    scanf("%d",&trno);
    j=read_name_number(trno);
    printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t\t   Bus No.%d: %s\n",trno,ch[trno-1]);
    printf("   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");

    char tempname[33][10];
    for(i=0; i<33; i++)
    {
        strcpy(tempname[i],"Empty");
    }
     for(i=1; i<=j; i++)
    {
        strcpy(tempname[num1[i]],name[i]);

        num1[i]=0;
    }
    for(i=0; i<8; i++)
    {
        printf("   ");
        for(j=0; j<4; j++)
        {
            printf("%d.%s\t",index+1,tempname[index+1]);
            index++;
        }
        printf("\n");
    }
}

void status_1(int trno)
{
    system("clear");
    printf("Your Bus Number is %d ********** %s",trno,ch[trno-1]);

    printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t\t      BUS RESERVATION");
    printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
    int i,index=0,j;
    j=read_name_number(trno);
    char tempname[33][10];
    for(i=0; i<33; i++)
    {
        strcpy(tempname[i],"Empty");
    }
     for(i=1; i<=j; i++)
    {
        strcpy(tempname[num1[i]],name[i]);

        num1[i]=0;
    }
    for(i=0; i<8; i++)
    {
        printf("   ");
        for(j=0; j<4; j++)
        {
            printf("%d.%s\t",index+1,tempname[index+1]);
            index++;
        }
        printf("\n");
    }
}


void cancle()
{
    int seat_no;
    char numstr[100],tempstr1[15]="status" ;
    printf("\n   ENTER THE BUS NUMBER: ");
    scanf("%d",&trno);
    my_itoa(trno,numstr);
    strcat(numstr,".txt");
    strcat(tempstr1,numstr);
    read_name_number(trno);
    status_1(trno);
    struct ticket b;
    printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("   ENTER THE SEAT NUMBER: ");
    scanf("%d",&seat_no);

    FILE *a,*ftemp;
    a = fopen(tempstr1,"a+");
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
    printf("   Your 200 rupees has been Returned\n");
    printf("   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    getchar();
}
struct dwn
{
    char pname[20];
    int seat;
    int busno;
};
void *download(void* arg)
{
    struct dwn *t=arg;
    printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t\t      TICKET INFORMATION");
    printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
    printf("\t\tBUS NAME: %s\n",ch[t->busno]);
    printf("\t\tSOURCE: Ahmedabad\n");
    printf("\t\tDESTINATION: %s",ch1[t->busno]);
    printf("\n");
    printf("\t\tNAME: %s\n",t->pname);
    printf("\t\tSEAT NUMBER: %d\n",t->seat);
    printf("\t\t\t\t\t 200 Rupees\n");
    printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");


}
void ticket_download()
{
    int seat_no,i=0;
    char print[30]="./tickets/ticket_";
    char numstr[100],tempstr1[15]="status";
    printf("\n   ENTER THE BUS NUMBER: ");
    scanf("%d",&trno);
    my_itoa(trno,numstr);
    strcat(numstr,".txt");
    strcat(tempstr1,numstr);
    read_name_number(trno);
    status_1(trno);
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
            d.busno=trno-1;
            strcpy(d.pname,b.name);
            d.seat=seat_no;
            pthread_create(&tid,NULL,download,(void*)&d); //for printing ticket
            //for downloading ticket
            FILE *d;

            strcat(print,b.name);
            strcat(print,b.num);
            strcat(print,".txt");
            d=fopen(print,"w+");
            fprintf(d,"********************\t Ticket Receipt \t********************\n");
            fprintf(d, "Bus Name: %s\t From Ahmdabad to %s\n", ch[trno-1], ch1[trno-1]);
            fprintf(d, "Name: %s\t\t seat no: %d\n", b.name, seat_no);
            fprintf(d, "Ammount paid 200 rs.");
            fclose(d);
            i=1;
            break;
        }

    }
     printf("\n\t Ticket downloaded: %s",print);
    if(i==0 )  printf("\n\t   NO TICKET INFORMATION");
    pthread_join(tid,NULL);
    getchar();
    fclose(a);


}



