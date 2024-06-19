#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

void redColor() {
    printf("\033[1;31m");
}

void greenColor() {
    printf("\033[1;32m");
}

void resetColor() {
    printf("\033[0m");
}

void blueColor() {
    printf("\033[1;34m");
}

void splashScreen() {
    char *message = "WELCOME TO ONLINE BUS RESERVATION SYSTEM";
    int length = strlen(message);
    int i,j,k;

    system("cls");
    for (i = 0; i < 1; i++) {
        blueColor();
        printf("\n\n\n\n\n\n\t\t\t");
        for ( j = 0; j < length; j++) {
            printf("%c", message[j]);
            fflush(stdout);
            usleep(50000); 
        }
        resetColor();
        printf("\n\n\t\t\tLoading");
        for ( k = 0; k < 3; k++) {
            printf(".");
            fflush(stdout);
            usleep(500000); 
        }
        system("cls");
    }
}

int isUserExists(const char* userName) {
    char fileUserName[20];
    FILE *file = fopen("userNameList.txt", "r");
    if (file == NULL) return 502;

    while (fscanf(file, "%s", fileUserName) != EOF) {
        if (strcmp(fileUserName, userName) == 0) {
            fclose(file);
            return 200;
        }
    }
    fclose(file);
    return 402;
}

void login() {
	system("cls");
    FILE *file = fopen("userSection.txt", "w");
    char userName[20], password[10];
    blueColor();
    printf("\n\n=========================================================================================\n");
    printf("\n\t\t\tWELCOME TO ONLINE BUS RESERVATION");
    printf("\n\n=========================================================================================\n\n");
    resetColor();
    printf("\n\nENTER USERNAME: ");
    scanf("%s", userName);
    printf("\n\nENTER PASSWORD: ");
    scanf("%s", password);
    if (isUserExists(userName) == 200 && strcmp(password, "1234") == 0) {
        fprintf(file, "login");
        fclose(file);
        greenColor();
        printf("\nLOGGED IN SUCCESSFULLY...\n");
        resetColor();
        splashScreen();
        home();
    } else {
        redColor();
        printf("\nINVALID DETAILS TRY AGAIN...\n");
        resetColor();
        printf("PRESS 'ENTER' KEY TO TRY AGAIN ");
        getch();
        system("cls");
        login();
    }
}

void signUp() {
    char userName[20];
    FILE *fp = fopen("userNameList.txt", "a");

    blueColor();
    printf("\n\n=========================================================================================\n");
    printf("\n\t\t\tLET'S GO TO YOUR DESTINATION");
    printf("\n\n=========================================================================================\n\n");
    resetColor();
    while (1) {
        printf("\n\nENTER USERNAME: ");
        scanf("%s", userName);
        if (isUserExists(userName) != 200) {
            fprintf(fp, "\n%s", userName);
            fclose(fp);
            system("cls");
            greenColor();
            printf("\n\n=========================================================================================\n");
            printf("\n\t\t\tCONGRATULATIONS");
            printf("\n\n=========================================================================================\n\n");
            resetColor();
            printf("\nYOUR ACCOUNT HAS BEEN CREATED...\n");
            printf("\nTHANK YOU FOR CREATING ACCOUNT...\n");
            printf("\nYOUR PASSWORD IS 1234 \n\n");
            printf("\n\t\t\tPRESS 'ENTER' KEY TO CONTINUE \n");
            getch();
            system("cls");
            login();
            break;
        } else {
            system("cls");
            redColor();
            printf("\nACCOUNT ALREADY EXISTS, TRY WITH A DIFFERENT USERNAME...\n");
            resetColor();
        }
    }
}

void mainMenu() {
	
    int userChoice;
    main:
    system("cls");
    blueColor();
    printf("\n\n=========================================================================================\n");
    printf("\n\t\t\tONLINE BUS RESERVATION");
    printf("\n\n=========================================================================================\n\n");
    resetColor();
    printf(" \n1- SIGN UP\n");
    printf(" \n2- LOGIN\n");
    printf(" \n3- EXIT\n");
    printf("\nENTER YOUR CHOICE: ");
    scanf("%d", &userChoice);

    if(userChoice == 1){
	system("cls");
            signUp();
            return;
    }
    if(userChoice == 2){
	        system("cls");
            login();
            return;
    }
    if(userChoice == 3){
	        exit(0);
    }
    goto  main;
//    switch (userChoice) {
//        case 1:
//        	system("cls");
//            signUp();
//            break;
//        case 2:
//        	system("cls");
//            login();
//            break;
//        case 3:
//            exit(0);
//        default:
//            redColor();
//            printf("\nINVALID CHOICE!\n");
//            resetColor();
//           break;
//    }
}



void displaySeatStatus(int busNumber) {
    int fileBusNumber, fileSeatNumber ,i;
    int busSeats[33] = {0};

    FILE *file = fopen("busSeatList.txt", "r");

    while (fscanf(file, "%d %d", &fileBusNumber, &fileSeatNumber) != EOF) {
        if (fileBusNumber == busNumber) {
            busSeats[fileSeatNumber] = 1;
        }
    }
    fclose(file);

    for (i = 1; i <= 32; i++) {
        if(busSeats[i]){
            redColor();
            printf("Seat %02d: BOOKED\n", i);
            resetColor();
        } else {
            greenColor();
            printf("Seat %02d: EMPTY\n", i);
            resetColor();
        }
    }
}

void busLists() {
    blueColor();
    printf("-----------------------------------------------------------------------------------------");
    printf("\nBus.No\tName\t\t\tDestinations  \t\tCharges  \t\tTime\n");
    printf("-----------------------------------------------------------------------------------------");
    resetColor();
    printf("\n1\tDaewoo Express       \tKarachi to Lahore     \tRs.2500   \t\t07:00  AM");
    printf("\n2\tFaisal Movers        \tLahore to Islamabad   \tRs.1500   \t\t01:30  PM");
    printf("\n3\tBilal Travels        \tIslamabad to Peshawar \tRs.800    \t\t03:50  PM");
    printf("\n4\tSkyways              \tPeshawar to Quetta    \tRs.3500   \t\t01:00  AM");
    printf("\n5\tNiazi Express        \tQuetta to Multan      \tRs.2000   \t\t12:05  AM");
    printf("\n6\tKainat Travels       \tMultan to Sialkot     \tRs.1200   \t\t09:30  AM");
    printf("\n7\tNew Khan Roadrunners \tSialkot to Faisalabad \tRs.1000   \t\t11:00  PM");
    printf("\n8\tKohistan Express     \tFaisalabad to Sukkur  \tRs.2200   \t\t08:15  AM");
    printf("\n9\tWaraich Express      \tSukkur to Hyderabad   \tRs.1800   \t\t04:00  PM");
    printf("\n");
    printf("\n   PRESS 'ENTER' KEY TO CONTINUE ");
    getch();
}

void status() {
    int busNum;
    busLists();
busInput:
    printf("\n\nENTER YOUR BUS NUMBER : ");
    scanf("%d", &busNum);
    if (busNum <= 0 || busNum >= 10) {
        redColor();
        printf("\n  PLEASE ENTER CORRECT BUS NUMBER !!\n");
        resetColor();
        goto busInput;
    }
    printf("\n");
    displaySeatStatus(busNum);
}

int isSeatExists(int busNumber, int seatNumber) {
    int fileBusNumber, fileSeatNumber;
    FILE *file = fopen("busSeatList.txt", "r");
    if (file == NULL) return 502;

    while (fscanf(file, "%d %d", &fileBusNumber, &fileSeatNumber) != EOF) {
        if (fileBusNumber == busNumber && fileSeatNumber == seatNumber) {
            fclose(file);
            return 402;
        }
    }
    fclose(file);
    return 200;
}

void bookSeat(int busNumber, int seatNumber) {
    if (isSeatExists(busNumber, seatNumber) == 402) {
        printf("\n   SEAT NO ALREADY BOOKED.\n\n");
    } else {
        FILE *file = fopen("busSeatList.txt", "a");
        if (file != NULL) {
            fprintf(file, "%d %d\n", busNumber, seatNumber);
            fclose(file);
            printf("\n   SEAT BOOKED SUCCESSFULLY.\n\n");
        } else {
            printf("\n   ERROR: Could not open file for writing.\n\n");
        }
    }
}

void cancelSeat(int busNumber, int seatNumber) {
    int fileBusNumber, fileSeatNumber;
    int seatFound = 0;

    FILE *file = fopen("busSeatList.txt", "r");
    FILE *tempFile = fopen("tempBusSeatList.txt", "w");

    if (file == NULL || tempFile == NULL) {
        if (file != NULL) fclose(file);
        if (tempFile != NULL) fclose(tempFile);
        printf("\n   ERROR: Could not open file.\n\n");
        return;
    }

    while (fscanf(file, "%d %d", &fileBusNumber, &fileSeatNumber) != EOF) {
        if (fileBusNumber == busNumber && fileSeatNumber == seatNumber) {
            seatFound = 1;
        } else {
            fprintf(tempFile, "%d %d\n", fileBusNumber, fileSeatNumber);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (seatFound) {
        remove("busSeatList.txt");
        rename("tempBusSeatList.txt", "busSeatList.txt");
        greenColor();
        printf("\n   SEAT CANCELLATION SUCCESSFUL.\n\n");
        resetColor();
        
    } else {
        remove("tempBusSeatList.txt");
        redColor();
        printf("\n   SEAT NOT FOUND.\n\n");
        resetColor();
    }
    printf("PRESS 'ENTER' KEY TO CONTINUE ");
    getch();
}

void home() {
    int choice;
    char busSeat[33][9];
    do {
        system("cls");
        blueColor();
        printf("\n\n=========================================================================================\n");
        printf("\n\t\t\t\tHOME SCREEN\n");
        printf("\n\n=========================================================================================\n\n");
        resetColor();
        printf(" \n1- TICKET RESERVATION");
        printf(" \n2- BUS STATUS");
        printf(" \n3- TICKET CANCELLATION");
        printf(" \n5- LOGOUT");
        blueColor();
        printf("\n\n=========================================================================================\n\n");
		resetColor();
        printf("\nENTER YOUR CHOICE :");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                system("cls");
                blueColor();
                printf("\n\n=========================================================================================\n");
                printf("\n\t\t\t\tTICKET RESERVATION\n");
                printf("\n\n=========================================================================================\n\n");
                resetColor();
                busLists();
                int CustId, choice, seats;
                busChoice:
                printf("\n\nCHOOSE YOUR BUS  : ");
                scanf("%d", &choice);
                if (choice <= 0 || choice > 9) {
                    redColor();
                    printf("\nENTER VALID BUS NUMBER !! \n");
                    resetColor();
                    getch();
                    goto busChoice;
                }
                printf("\n");
                displaySeatStatus(choice);
                int seatNumber, i ;
                printf("\n\nNO. OF SEATS YOU NEED TO BOOK : ");
                scanf("%d", &seats);
                if(seats>5){
                redColor();
                printf("\n   YOU CAN ONLY BOOK MAX 5 SEATS\n\n");
                resetColor();
                getch();
                goto busChoice;
				}
                printf("\n\n==================================================================================\n\n");
                for (i = 1; i <= seats; i++) {
                    seat:
                    printf("   ENTER THE SEAT NUMBER: ");
                    scanf("%d", &seatNumber);
                    if (seatNumber <= 0 || seatNumber > 32) {
                        redColor();
                        printf("\n   ENTER VALID SEAT NUMBER!!\n\n");
                        resetColor();
                        goto seat;
                    }
                    bookSeat(choice, seatNumber);
                    CustId = choice * 1000 + seatNumber;
                    busSeat[choice][seatNumber] = 1;
                    greenColor();
                    printf("\n SEAT NO. %d HAS BEEN BOOKED SUCCESSFULLY",seatNumber);
                    resetColor();
                    printf("\n\n==================================================================================\n\n");
                }
                redColor();
                printf("\nPLEASE NOTE DOWN YOUR BUS AND SEAT NUMBER FOR CANCEL BOOKING TICKETS!!\n");
                resetColor();
                printf("PRESS 'ENTER' KEY TO CONTINUE ");
                getch();
                home();
                break;
            case 2:
                system("cls");
                blueColor();
                printf("\n\n=========================================================================================\n");
                printf("\n\t\t\t\tBUS STATUS\n");
                printf("\n\n=========================================================================================\n\n");
                resetColor();
                status();
                printf("PRESS 'ENTER' KEY TO CONTINUE ");
                getch();
                break;
            case 3:
                system("cls");
                blueColor();
                printf("\n\n=========================================================================================\n");
                printf("\n\t\t\t\tTICKET CANCELLATION\n");
                printf("\n\n=========================================================================================\n\n");
                resetColor();
                int seatNum, busNum;
                printf("\n\nENTER YOUR BUS NUMBER : ");
                scanf("%d", &busNum);
                printf("\n\nENTER YOUR SEAT NUMBER : ");
                scanf("%d", &seatNum);
                cancelSeat(busNum, seatNum);
                break;
            case 5:
                {
                    FILE *file = fopen("userSection.txt", "w");
                    fprintf(file, "logout");
                    fclose(file);
                    system("cls");
                    mainMenu();
                }
                break;
            default:
                redColor();
                printf("\nINVALID CHOICE!\n");
                resetColor();
                break;
        }
    } while (choice != 5);
}

void isFoldersExist() {
    FILE *userSection = fopen("userSection.txt", "r");
    FILE *userNameList = fopen("userNameList.txt", "r");
    FILE *userDetails = fopen("userDetails.txt", "r");
    FILE *busSeatList = fopen("busSeatList.txt", "r");
    if (userSection == NULL) {
        userSection = fopen("userSection.txt", "w");
    }
    if (userNameList == NULL) {
        userNameList = fopen("userNameList.txt", "w");
    }
    if (userDetails == NULL) {
        userDetails = fopen("userDetails.txt", "w");
    }
    if (busSeatList == NULL) {
        busSeatList = fopen("busSeatList.txt", "w");
    }
    fclose(userSection);
    fclose(userNameList);
    fclose(userDetails);
    fclose(busSeatList);
}

int main() {
    isFoldersExist();
    FILE *file = fopen("userSection.txt", "r");
    char isLogin[100];
    fscanf(file, "%s", isLogin);
    fclose(file);
    if (strcmp(isLogin, "login") == 0) {
        home();
    } else {
        mainMenu();
    }
    return 0;
}