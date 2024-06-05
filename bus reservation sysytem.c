#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

void redColor() {
    printf("\033[1;31m");
}

void resetColor() {
    printf("\033[0m");
}

int isUserExists(const char* userName){
		char fileUserName[20];
	    FILE *file = fopen("userNameList.txt", "r");
	if(file == NULL) return 502;
		// Database is not access able right Msg.
		
	while(fscanf(file , "%s",fileUserName ) != EOF){
		if (strcmp(fileUserName, userName) == 0) {
            fclose(file);
            return 200; 
        }
	}
	fclose(file);
	return 402;
}


void login(){
	char userName[20] , password[10], inputUsername[20];
	int isvalid = 0 ;
	
	redColor();
    printf("\n\n=========================================================================================\n");
    printf("\n\t\t\tWELCOME TO ONLINE BUS RESERVATION");
    printf("\n\n=========================================================================================\n\n");
    resetColor();
    printf("\n\nENTER USERNAME: ");
    scanf("%s",&userName);
    printf("\n\nENTER PASSOWRD: ");
    scanf("%s",&password);
    if(isUserExists(userName)== 200 && strcmp(password, "1234") == 0){
    	printf("\nLOGGED IN SUCCESSFULLY...\n");
    	return;
	}else{
		redColor();
        printf("\nNVALID DETAILS TRY AGAIN...\n");
        resetColor();
        login();

	}
}
    

void signUp(){
char userName[20] ;
FILE *fp = fopen("userNameList.txt", "a");

	redColor();
    printf("\n\n=========================================================================================\n");
    printf("\n\t\t\LETS GO TO YOUR DESTINATION");
    printf("\n\n=========================================================================================\n\n");
    resetColor();
    while(1){
    printf("\n\nENTER USERNAME: ");
    scanf("%s",&userName);
    if(isUserExists(userName)!= 200){
    fprintf(fp, "\n%s", userName);
    fclose(fp);
    system("cls");
        redColor();
    printf("\n\n=========================================================================================\n");
    printf("\n\t\t\Congrulation");
    printf("\n\n=========================================================================================\n\n");
    resetColor();
    	printf("\nYOUR ACCOUNT HAS BEEN CREATED...\n");
    	printf("\nTHANK YOU FOR CREATING ACCOUNT...\n");
    	printf("\nYOUR PASSWORD IS 1234 \n\n");
    	
        printf("\n\t\t\PRESS 'ENTER' KEY TO LOGIN \n");
        getch();
    	login();
    	break;
	}else{
		redColor();
        printf("\nACCOUNT ALREADY EXITS TRY WITH DIFFRENT USER NAME...\n");
        resetColor();

	}	
	
		}
}

void mainMenu() {
    int userChoice , initial = 0 ;
// need to add check for fitst time welcome screen
    redColor();
    printf("\n\n=========================================================================================\n");
    printf("\n\t\t\tWELCOME TO ONLINE BUS RESERVATION SYSTEM");
    printf("\n\n=========================================================================================\n\n");
    resetColor();
	
    
    printf(" \n1- SIGN UP\n");
    printf(" \n2- LOGIN\n");
    printf(" \n3- EXIT\n");
    printf("\nENTER YOUR CHOICE: ");
    scanf("%d", &userChoice);

    switch (userChoice) {
        case 1:
            signUp();
            break;
        case 2:
            login();
            break;
        case 3:
            exit(0);
        default:
            redColor();
            printf("\nINVALID CHOICE!\n");
            resetColor();
            mainMenu();
    }
    
}
void main(){
	mainMenu();

    int choice;
    char c;
    int x;
    int custID;
    int randNum;
    srand(time(0));
    randNum = rand();
    
    
    
     do {
        system("cls");
        printf("\n\n=========================================================================================\n");
        printf("\n\t\t\t\tHOME SCREEN\n");
        printf("\n\n=========================================================================================\n\n");
        printf(" \n1- TICKET RESERVATION");
        printf(" \n2- BUS STATUS");
        printf(" \n3- TICKET CANCELLATION");
        printf(" \n4- USER INFORMATION");
        printf(" \n5- EXIT");
        printf("\n\n=========================================================================================\n\n");
        printf("\nENTER YOUR CHOICE :");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                system("cls");
                
                break;
            case 2:
                system("cls");
//                status();
                break;
            case 3:
                system("cls");
//                cancel(randNum);
                break;
            case 4:

break;
            case 5:
                exit(0);
                break;
            default:
                redColor();
                printf("\nINVALID CHOICE!\n");
                resetColor();
                break;
        }
    } while (choice != 5);
}

