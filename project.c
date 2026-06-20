#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#define ENTER  13
#define BSKSPC 8
#define TAB    9


//--------------------------------------------------STRUCTURES USED----------------------------------------------
struct account{
    char first_name[50];
    char last_name[50];
    char username[50];
    char phone[20];
    char gender;
    char dob[10];
    char password[20];

};
//---------------------------------------------------flight module-----------------------------------------------
struct flight{
    int srno;
    char airline[20];
    char flightno[20];
    char source[30];
    char destination[30];
    float price;
    char time[10];
    int seat;
};
//-------------------------------------------------booking structure----------------------------------------------
struct booking{
    char firstname[50];
    char lastname[50];
    char gender[10];
    int age;
};


//------------------------------------------------IMPORTANT FUNCTIONS----------------------------------------------
void takepassword(char pass[]);
void welcomescreen();
void title();
int  menu();
void signup();
void login();
void search();
void booking();
void print_ticket(struct booking b, struct flight f);
void searchtime();
void searchprice();
void searchseat();
void search_ticket();
void cancel_booking();

/* UI helper functions */
void print_line(char ch);
void print_banner(const char title[]);
void print_section(const char title[]);
void print_flight_table_header();
void pause_and_clear();


//------------------------------------------------flight search-----------------------------------------------

/*======================================================================
                         TERMINAL UI HELPERS
======================================================================*/
void print_line(char ch)
{
    int i;
    for (i = 0; i < 78; i++) {
        printf("%c", ch);
    }
    printf("\n");
}

void print_banner(const char title[])
{
    int width = 78;
    int len = strlen(title);
    int left = (width - len) / 2;
    int i;

    printf("\n");
    print_line('=');
    for (i = 0; i < left; i++) {
        printf(" ");
    }
    printf("%s\n", title);
    print_line('=');
    printf("\n");
}

void print_section(const char title[])
{
    int width = 78;
    int len = strlen(title);
    int left = (width - len) / 2;
    int i;

    printf("\n");
    print_line('-');
    for (i = 0; i < left; i++) {
        printf(" ");
    }
    printf("%s\n", title);
    print_line('-');
}

void print_flight_table_header()
{
    printf("+-----+------------+----------+------------+------------+------------+----------+-------+\n");
    printf("| ID  | Airline    | Flight   | Source     | Destination| Price      | Time     | Seats |\n");
    printf("+-----+------------+----------+------------+------------+------------+----------+-------+\n");
}

void pause_and_clear()
{
    printf("\nPress any key to continue...");
    getch();
    system("cls");
}

void searchtime()
{
    print_banner("SEARCH FLIGHTS - SORT BY TIME");

    struct flight f, list[100];
    int count = 0, i, j;

    FILE *fp = fopen("flights.txt", "r");
    char source[20], dest[20];

    printf("Enter Source      : ");
    gets(source);
    printf("Enter Destination : ");
    gets(dest);

    while (fscanf(fp, "%d %s %s %s %s %f %s %d",
                  &f.srno, f.airline, f.flightno, f.source,
                  f.destination, &f.price, f.time, &f.seat) != EOF) {
        if (stricmp(source, f.source) == 0 && stricmp(dest, f.destination) == 0) {
            list[count++] = f;
        }
    }

    fclose(fp);

    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (strcmp(list[i].time, list[j].time) > 0) {
                struct flight temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }

    system("cls");
    print_banner("AVAILABLE FLIGHTS - TIME SORTED");
    print_flight_table_header();

    for (i = 0; i < count; i++) {
        printf("| %-3d | %-10s | %-8s | %-10s | %-10s | %10.2f | %-8s | %-5d |\n",
               list[i].srno, list[i].airline, list[i].flightno,
               list[i].source, list[i].destination,
               list[i].price, list[i].time, list[i].seat);
    }

    printf("+-----+------------+----------+------------+------------+------------+----------+-------+\n");
    pause_and_clear();
}

void searchprice()
{
    print_banner("SEARCH FLIGHTS - SORT BY PRICE");

    struct flight f, list[100];
    int count = 0, i, j;

    FILE *fp = fopen("flights.txt", "r");
    char source[20], dest[20];

    printf("Enter Source      : ");
    gets(source);
    printf("Enter Destination : ");
    gets(dest);

    while (fscanf(fp, "%d %s %s %s %s %f %s %d",
                  &f.srno, f.airline, f.flightno, f.source,
                  f.destination, &f.price, f.time, &f.seat) != EOF) {
        if (stricmp(source, f.source) == 0 && stricmp(dest, f.destination) == 0) {
            list[count++] = f;
        }
    }

    fclose(fp);

    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (list[i].price > list[j].price) {
                struct flight temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }

    system("cls");
    print_banner("AVAILABLE FLIGHTS - PRICE SORTED");
    print_flight_table_header();

    for (i = 0; i < count; i++) {
        printf("| %-3d | %-10s | %-8s | %-10s | %-10s | %10.2f | %-8s | %-5d |\n",
               list[i].srno, list[i].airline, list[i].flightno,
               list[i].source, list[i].destination,
               list[i].price, list[i].time, list[i].seat);
    }

    printf("+-----+------------+----------+------------+------------+------------+----------+-------+\n");
    pause_and_clear();
}

void searchseat()
{
    print_banner("SEARCH FLIGHTS - SORT BY SEATS");

    struct flight f, list[100];
    int count = 0, i, j;

    FILE *fp = fopen("flights.txt", "r");
    char source[20], dest[20];

    printf("Enter Source      : ");
    gets(source);
    printf("Enter Destination : ");
    gets(dest);

    while (fscanf(fp, "%d %s %s %s %s %f %s %d",
                  &f.srno, f.airline, f.flightno, f.source,
                  f.destination, &f.price, f.time, &f.seat) != EOF) {
        if (stricmp(source, f.source) == 0 && stricmp(dest, f.destination) == 0) {
            list[count++] = f;
        }
    }

    fclose(fp);

    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (list[i].seat < list[j].seat) {
                struct flight temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }

    system("cls");
    print_banner("AVAILABLE FLIGHTS - SEAT SORTED");
    print_flight_table_header();

    for (i = 0; i < count; i++) {
        printf("| %-3d | %-10s | %-8s | %-10s | %-10s | %10.2f | %-8s | %-5d |\n",
               list[i].srno, list[i].airline, list[i].flightno,
               list[i].source, list[i].destination,
               list[i].price, list[i].time, list[i].seat);
    }

    printf("+-----+------------+----------+------------+------------+------------+----------+-------+\n");
    pause_and_clear();
}

//-------------------------------------------------BOOKING MODULE-----------------------------------------------
void booking(){
    struct flight f;
    print_banner("FLIGHT TICKET BOOKING");
    int n,nr,i;
    FILE *fp= fopen("flights.txt","r");
    char source[20], dest[20];
    printf("Enter source: ");
    gets(source);
    printf("Enter Destination: ");
    gets(dest);
    printf("\n%-5s %-10s %-10s %-12s %-12s %-10s %-10s %-10s\n","Sr_n0:","Airline","Flight_NO","Source","Destination","Price","Time","Available_seats");
    printf("-------------------------------------------------------------------------------------\n");
    while(fscanf(fp,"%d %s %s %s %s %f %s %d",&f.srno,f.airline,f.flightno,f.source,f.destination,&f.price,f.time,&f.seat)!=EOF){
        if(stricmp(source, f.source)==0&& stricmp(dest, f.destination)==0){
            printf("%-5d %-10s %-10s %-12s %-12s %-10.2f %-10s %-10d\n",f.srno,f.airline,f.flightno,f.source,f.destination,f.price,f.time,f.seat);
        } 
    }
    rewind(fp);
    FILE *p= fopen("booking.txt","a");
    printf("Enter Serial Number of Airline you want to book: ");
    scanf("%d",&n);
    getchar();
    char ch;
    printf("Confirm booking (Y/N): ");
    scanf("%c",&ch);
    if(ch=='Y'|| ch=='y'){
        while(fscanf(fp,"%d %s %s %s %s %f %s %d",&f.srno,f.airline,f.flightno,f.source,f.destination,&f.price,f.time,&f.seat)!=EOF){
            if(n==f.srno){
            printf("Number of seats you want to book: ");
            scanf("%d",&nr);
            getchar();
            struct booking book[nr];
            for(i=0; i<nr; i++){
                
                printf("----------Enter Details of %d Customer----------\n",i+1);
                printf("Enter first name: ");
                gets(book[i].firstname);
                printf("Enter Last name: ");
                gets(book[i].lastname);
                printf("Enter Gender (Male/Female): ");
                gets(book[i].gender);
                printf("Enter Age: ");
                scanf("%d",&book[i].age);
                getchar();
                fprintf(p,"%s %s %s %d %s %s %s %.2f %s\n",book[i].firstname,book[i].lastname,book[i].gender,book[i].age,f.flightno,f.source,f.destination,f.price,f.time);
                print_ticket(book[i],f);
            }
        } 
    }
    
}
else{
    print_banner("THANK YOU FOR VISITING");
}
fclose(p);
fclose(fp);
printf("press any key to continue.....");
getchar();
system("cls");
}
//---------------------------------------------TICKET PRINTING MODULE-------------------------------------------
void print_ticket(struct booking b, struct flight f)
{
    char passenger_name[120];
    strcpy(passenger_name, b.firstname);
    strcat(passenger_name, " ");
    strcat(passenger_name, b.lastname);

    print_banner("FLIGHT TICKET");
    printf("+----------------------------------------------------------------------+\n");
    printf("| Passenger Name : %-51s |\n", passenger_name);
    printf("| Gender         : %-51s |\n", b.gender);
    printf("| Age            : %-51d |\n", b.age);
    printf("+----------------------------------------------------------------------+\n");
    printf("| Flight No      : %-20s Time : %-23s |\n", f.flightno, f.time);
    printf("| From           : %-20s To   : %-23s |\n", f.source, f.destination);
    printf("| Ticket Price   : Rs. %-47.2f |\n", f.price);
    printf("+----------------------------------------------------------------------+\n");
    printf("|                 Thank you for booking with us!                       |\n");
    printf("+----------------------------------------------------------------------+\n");
}

//--------------------------------------------------WELCOMESCREEN-----------------------------------------------
void welcomescreen()
{
    system("cls");
    print_banner("FLIGHT TICKET BOOKING SYSTEM");
    printf("                 Welcome to your smart flight booking console\n");
    printf("                    Search | Book | View | Cancel Tickets\n\n");
    print_line('-');
    printf("                        Press any key to continue...");
    getch();
    system("cls");
}

//-----------------------------------------------TICKET SEARCHING MODULE----------------------------------------
void search_ticket(){

    print_banner("SEARCH YOUR BOOKING");
    FILE *fp = fopen("booking.txt","r");

    if(fp == NULL){
        printf("No bookings found!\n");
        return;
    }

    char fname[20];
    int found = 0;
    printf("Enter First Name to search: ");
    scanf("%s", fname);
    getchar();
    struct booking b;
    struct flight f;
    while(fscanf(fp,"%s %s %s %d %s %s %s %f %s",
          b.firstname, b.lastname, b.gender, &b.age,
          f.flightno, f.source, f.destination, &f.price, f.time) != EOF){
        if(stricmp(fname, b.firstname) == 0){
            found = 1;
            // print ticket
            print_ticket(b, f);
        }
    }
    if(!found){
        printf("No booking found with this name!\n");
    }
    printf("press any key to continue.....");
    getchar();
    system("cls");
    fclose(fp);
}
//------------------------------------------------CANCEL BOOKING------------------------------------------------
void cancel_booking(){
    FILE *fp = fopen("booking.txt","r");
    FILE *temp = fopen("temp.txt","w");
    if(fp == NULL){
        printf("No bookings found!\n");
        return;
    }
    char fname[20];
    int found = 0;
    printf("Enter First Name to cancel booking: ");
    scanf("%s", fname);
    struct booking b;
    struct flight f;
    while(fscanf(fp,"%s %s %s %d %s %s %s %f %s",
          b.firstname, b.lastname, b.gender, &b.age,
          f.flightno, f.source, f.destination, &f.price, f.time) != EOF){
        if(stricmp(fname, b.firstname) == 0){
            found = 1;
            printf("Booking Cancelled for %s %s\n", b.firstname, b.lastname);
            continue; // ❌ skip writing → deletes record
        }
        // keep other records
        fprintf(temp,"%s %s %s %d %s %s %s %.2f %s\n",
            b.firstname, b.lastname, b.gender, b.age,
            f.flightno, f.source, f.destination, f.price, f.time);
    }

    fclose(fp);
    fclose(temp);

    remove("booking.txt");
    rename("temp.txt","booking.txt");

    if(!found){
        printf("No booking found!\n");
    }
}
//----------------------------------------------TITLE SCREEN MODULE --------------------------------------------
void title()
{
    print_banner("FLIGHT TICKET BOOKING SYSTEM");
}

void mainn(){
    title();
}
//-----------------------------------CREATING MENU FOR EASY COUSTMER INTERACTION--------------------------------
int menu()
{
    int c;

    printf("+----------------------------------------------------------------------+\n");
    printf("|                               MAIN MENU                              |\n");
    printf("+----------------------------------------------------------------------+\n");
    printf("|  [1] Search Flights                                                  |\n");
    printf("|  [2] Book Flight                                                     |\n");
    printf("|  [3] View Booking                                                    |\n");
    printf("|  [4] Cancel Booking                                                  |\n");
    printf("|  [5] Sort Flights                                                    |\n");
    printf("|  [6] Exit                                                            |\n");
    printf("+----------------------------------------------------------------------+\n");
    printf("Enter your choice: ");
    scanf("%d", &c);
    getchar();
    system("cls");

    return c;
}

//------------------------------------------------SIGN UP MODULE------------------------------------------------
void signup(){
    printf("\n");
    printf("\n");
    print_banner("CREATE NEW ACCOUNT");
    struct account u;
    char pass2[20];
    printf("Creating New Account\n");
    printf("Enter First Name: ");
    scanf("%s",&u.first_name);
    printf("Enter Last Name: ");
    scanf("%s",&u.last_name);
    printf("Enter Username: ");
    scanf("%s", &u.username);
    phone_try:
    printf("Enter Phone Number: ");
    scanf("%s",u.phone);
    int i=0,n;
    if(strlen(u.phone)!=10){
        printf("Phone number should be 10 Digits\n");
        goto phone_try;
    }
    printf("Enter Your Gender (M/F): ");
    scanf(" %c",&u.gender);
    printf("Enter Date of Birth (DD/MM/YYYY): ");
    scanf("%s",&u.dob);
    printf("Enter password: ");
    takepassword(u.password);
    printf("\n");
    conf_pass:
    printf("Confirm Password: ");
    takepassword(pass2);
    printf("\n");
    if(strcmp(u.password,pass2)){
        printf("Incorrect Password\n");
        goto conf_pass;
    }
    else{
        printf("ACCOUNT CREATED SUCESSFULLY\n"); 
        getch();
        FILE *fp= fopen("report.txt","a");
        fprintf(fp,"\n%s %s %s %s %c %s %s",u.first_name,u.last_name, u.username,u.phone,u.gender,u.dob,u.password);
        fclose(fp);
    }
    
    system("cls");
    login();
}
//-------------------------------------------------LOG IN MODULE-----------------------------------------------
void login(){
    getchar();
    print_banner("LOGIN MODULE");

    char uname[30], upass[30];
    struct account u;
    int found;

    username_try:   // label for username retry
    found = 0;

    printf("Enter username: ");
    gets(uname);

    FILE *fp = fopen("report.txt","r");

    while(fscanf(fp,"%s %s %s %s %c %s %s",
        u.first_name,u.last_name,u.username,
        u.phone,&u.gender,u.dob,u.password) != EOF)
    {
        if(strcmp(uname, u.username) == 0){
            found = 1;

            pass_try:   // label for password retry
            printf("Enter Password: ");
            takepassword(upass);
            printf("\n");

            if(strcmp(upass, u.password) == 0){
                printf("----LOG IN SUCCESSFUL----\n");
                printf("WELCOME %s\n", u.username);
                printf("First Name: %s\n", u.first_name);
                printf("Last Name: %s\n", u.last_name);
                printf("Username: %s\n", u.username);
                printf("Phone Number: %s\n", u.phone);
                printf("Gender: %c\n", u.gender);
                printf("Date of Birth: %s\n", u.dob);
            }
            else{
                printf("Incorrect Password\n");
                goto pass_try;   // retry password
            }
            break;
        }
    }

    fclose(fp);

    if(found == 0){
        printf("Username Not Found\n");
        goto username_try;   // retry username
    }

    printf("\nPress any key to continue...");
    getch();
    system("cls");
}
//----------------------------------------MODULE OF ENTERING PRIVACY PASSWORD--------------------------------------
void takepassword(char pass[]){
int i=0;
char ch;
while(1){
    ch= getch();
    if(ch== ENTER || ch== TAB){
        pass[i]= '\0';
        break;
    }
    else if(ch== BSKSPC){
        if(i>0){
            i--;
            printf("\b \b");
        }
    }
    else{
        pass[i++]= ch;
        printf("*");
    }
}
}
//----------------------------------------------FLIGHT SEARCH MODULE---------------------------------------------------
void search()
{
    print_banner("SEARCH FOR FLIGHTS");

    struct flight f;
    FILE *fp = fopen("flights.txt", "r");
    char source[20], dest[20];

    printf("Enter Source      : ");
    gets(source);
    printf("Enter Destination : ");
    gets(dest);

    system("cls");
    print_banner("AVAILABLE FLIGHTS");
    print_flight_table_header();

    while (fscanf(fp, "%d %s %s %s %s %f %s %d",
                  &f.srno, f.airline, f.flightno, f.source,
                  f.destination, &f.price, f.time, &f.seat) != EOF) {
        if (stricmp(source, f.source) == 0 && stricmp(dest, f.destination) == 0) {
            printf("| %-3d | %-10s | %-8s | %-10s | %-10s | %10.2f | %-8s | %-5d |\n",
                   f.srno, f.airline, f.flightno, f.source,
                   f.destination, f.price, f.time, f.seat);
        }
    }

    printf("+-----+------------+----------+------------+------------+------------+----------+-------+\n");
    fclose(fp);
    pause_and_clear();
}

//------------------------------------------------MAIN FUNCTION-------------------------------------------------------
int main(){
    welcomescreen();
    int q=1,o,l;
    while(q){
    mainn();
        switch(menu()){
            case 1:
            search();
            break;
            case 2:
            print_section("ACCOUNT ACCESS");
            printf(" [1] Create New Account\n");
            printf(" [2] Login Existing Account\n");
            printf("Enter your choice: ");
            scanf("%d",&l);
            switch(l){
            case 1:
            signup();
            booking();
            break;
            case 2:
            login();
            booking();
            break;
            default:
            printf("Invalid option\n");
            break;
        
        }
            break;
            case 3:
            search_ticket();
            break;
            case 4:
            cancel_booking();
            break;
            case 5:
            print_section("SORT FLIGHTS BY");
            printf(" [1] Departure Time\n");
            printf(" [2] Ticket Price\n");
            printf(" [3] Available Seats\n");
            printf("Enter your choice: ");
            scanf("%d",&o);
            getchar();
            switch(o){
                case 1:
                searchtime();
                break;
                case 2:
                searchprice();
                break;
                case 3:
                searchseat();
                break;
                default:
                printf("Invalid option\n");
                break;
            }
            case 6:
            q=0;
            break;
            default:
            printf("Invalid option\n");
            break;
        }
    }
    return 0;
}