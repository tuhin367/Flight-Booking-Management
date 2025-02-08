#include<stdio.h>
#include<string.h>

typedef struct {
    int flyNumber;
    char flyOrigin[100];
    char flyDestination[100];
    char flyTime[100];
    int totalSeats;
    int availableSeats;

}Flight;


typedef struct {
    char passName[30];
    char passPhone[20];
    char passportNum[30];
    int seatbook;
    char flihtType[20];

    int flightNumber;
    char flightOrigin[100];
    char flightDestination[100];
    char flightTime[100];


}Booking;


Flight flights[100];
Booking booking[500];
int flightsindex=0;
int bookIndex =0;



void AddFlights();
void DisplayFlights();
void RemoveFlight();
void BookingFlight();
void ReservationsList();
void ReservationsFile();
int FlightSearch(int target);


int main(){

int select;

while(1){
printf("\n                                          **********Flight Management System**********                           \n");
 printf("Select one\n");
 printf("1. Flight Add \n");
 printf("2. Flight Remove\n");
 printf("3. Flight Display Flight\n");
 printf("4. Flight Booking\n");
 printf("5. Flight Reservation List\n");
 printf("6. Flight ReservationsFile Save\n");
 printf("7. Exit\n");
 scanf("%d",&select);

switch (select){
case 1: AddFlights();
    break;

case 2: RemoveFlight();
    break;

case 3: DisplayFlights();
    break;
case 4: BookingFlight();
    break;

case 5: ReservationsList();
    break;
case 6: ReservationsFile();
    break;

}
if (select == 7){
    printf("Program End\n");
    break;
}
};


}




void AddFlights(){
    if(flightsindex < 100){

    printf("Flight Number : ");
    scanf("%d",&flights[flightsindex].flyNumber);

    printf("Flight Origin: ");
    scanf(" %[^\n]",flights[flightsindex].flyOrigin);

    printf("Flight Destination: ");
    scanf(" %[^\n]",flights[flightsindex].flyDestination);

    printf("Flight Time : ");
    scanf(" %[^\n]",flights[flightsindex].flyTime);

    printf("Flight Total seats : ");
    scanf("%d",&flights[flightsindex].totalSeats);

    int availseats;
    printf("Flight Available Seats :");
    scanf("%d",&availseats);

    if(flights[flightsindex].totalSeats >= availseats){
        flights[flightsindex].availableSeats = availseats;
    }else{
    printf("Available seats wrong entry\n");
        flights[flightsindex].availableSeats = flights[flightsindex].totalSeats;
    }

    printf("\n");

    flightsindex++;   //updating array size
    printf("Flight Details Added\n");

    }
    else{
        printf("Flights data full\n");
    }


}




void RemoveFlight( ){

int target;
printf("Enter the flight number to remove: ");
scanf("%d", &target);
int found = FlightSearch(target);

if(found!=-1){
    int m =0;                           // new index number
       for (int x=0; x<flightsindex-1; x++){
           if(x==found){
            continue;                   //skip the data
           }
           else{
            flights[m++] =flights[x];     //updating index
           }
       }
        flightsindex--;
        printf("Flight Data removed\n\n");
}

else{
    printf("NO Data available \n\n");
}
}


void DisplayFlights() {
    if (flightsindex != 0) {
        printf("------------------------------------------------------------------------------------------------------------------\n");
        printf("%-15s |%-20s |%-20s |%-15s |%-15s |%-15s\n",
               "Flight Number", "Origin", "Destination", "Time", "Total Seats", "Available Seats");

        printf("------------------------------------------------------------------------------------------------------------------\n");

        for (int i = 0; i < flightsindex; i++) {
            printf("%-15d |%-20s |%-20s |%-15s |%-15d |%-15d\n",
                   flights[i].flyNumber,flights[i].flyOrigin,flights[i].flyDestination,
                   flights[i].flyTime,flights[i].totalSeats,flights[i].availableSeats);
        }
        printf("------------------------------------------------------------------------------------------------------------------\n");
        printf("\n");
    } else {
        printf("No flight data found.\n\n");
    }

}


int FlightSearch(int target){

int idx= -1;

for (int i =0 ;i<flightsindex; i++){
    if(flights[i].flyNumber == target){
        idx = i;
        break;
    }
    }

    return idx ;
}

void BookingFlight(){

int select;
int target;
printf("Enter the flight number to Booking Flight: ");
scanf("%d", &target);
int found = FlightSearch(target);

if(found!=-1){
        printf("Select one\n");
        printf("1. Economy Class\n");
        printf("2. Business class\n");
        printf("3. First class\n");
        scanf("%d",&select);

        if (select == 1) {
                strcpy(booking[bookIndex].flihtType, "Economy Class");
            } else if (select == 2) {
                strcpy(booking[bookIndex].flihtType, "Business Class");
            } else if (select == 3) {
                strcpy(booking[bookIndex].flihtType, "First Class");
            } else {
                printf("Invalid selection.\n");
                return;
            }
   int ticket;
   printf("How many ticket do you want");
   scanf("%d",&ticket);

 if(flights[found].availableSeats >= ticket){

    printf("Enter Name : ");
    scanf(" %[^\n]",booking[bookIndex].passName);

    printf("Enter Phone Number : ");
    scanf(" %[^\n]",&booking[bookIndex].passPhone);

    printf("Enter Passport number : ");
    scanf(" %[^\n]",booking[bookIndex].passportNum);


    booking[bookIndex].seatbook = ticket;
    booking[bookIndex].flightNumber = flights[found].flyNumber;
    strcpy(booking[bookIndex].flightOrigin, flights[found].flyOrigin);
    strcpy(booking[bookIndex].flightDestination, flights[found].flyDestination);
    strcpy(booking[bookIndex].flightTime, flights[found].flyTime);

    printf("successfully ticket Booked\n");
    flights[found].availableSeats = flights[found].availableSeats - ticket;
    bookIndex++;
 }
}else{
    printf("Flight doesen't exist\n");
    return ;
}

}


void ReservationsList() {
    int target;
    printf("Enter flight number to view reservations: ");
    scanf("%d", &target);

    int reservationFound = 0;
    printf("------------------------------------------------------------------------------------------------------------------\n");
    printf("%-20s |%-20s |%-15s |%-20s |%-10s|\n",
           "Class","Passenger Name", "Phone Number", "Passport Number", "Seats Booked");

    printf("------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < bookIndex; i++) {
        if (booking[i].flightNumber == target) {
            printf("%-20s |%-20s |%-15s |%-20s |%-15d|\n",booking[i].flihtType,booking[i].passName,booking[i].passPhone,booking[i].passportNum,booking[i].seatbook);
            reservationFound = 1;
        }
    }
    printf("------------------------------------------------------------------------------------------------------------------\n");
    if (reservationFound!=1) {
        printf("No reservations found for this flight.\n");
    }
    printf("\n");

}





void ReservationsFile() {
    int target;
    printf("Enter flight number to view reservations: ");
    scanf("%d", &target);

    char filename[50];
    sprintf(filename,"Reservation_%d.txt",target);

    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error: Could not open file for writing.\n");
        return;
    }

    int reservationFound = 0;
    fprintf(file, "                                            %d Number Flight Details ",target);
    fprintf(file, "\n------------------------------------------------------------------------------------------------------------------\n");
    fprintf(file, "%-20s |%-20s |%-15s |%-20s |%-15s|\n","Class","Passenger Name", "Phone Number", "Passport Number", "Seats Booked");
    fprintf(file, "------------------------------------------------------------------------------------------------------------------\n");


    for (int i = 0; i < bookIndex; i++) {
        if (booking[i].flightNumber == target) {
            fprintf(file, "%-20s |%-20s |%-15s |%-20s |%-15d|\n",
                    booking[i].flihtType,booking[i].passName, booking[i].passPhone, booking[i].passportNum, booking[i].seatbook);

            reservationFound = 1;
        }
    }

    if (reservationFound!=1) {
        fprintf(file, "No reservations found for this flight.\n");
        printf("No reservations found for this flight.\n");
    }

    fprintf(file, "------------------------------------------------------------------------------------------------------------------\n");
    fclose(file);

    printf("\nReservation details saved to %s.\n\n",filename);
}
