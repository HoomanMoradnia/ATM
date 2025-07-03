#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#define true 1
#define false 0
#define Max 100
/********************************************/
void mainMenu();
/********************************************/
void employeeMenu();
void createAnAccount();
void editAnAccount();
void showTheRichestCustomer();
void showTotalBalanceOfAllAccount();
/*********************************************/
void customerMenu(int);
void accountBalance(int);
void cashTransfer(int);
void cashWithdrawal(int);
void resentAccountUpdates(int);
void changePassword();
/*********************************************/
void saveToFile();
int readFile(char [], char[]);
int checkPassword(char []);
void congratulatory();	
void fileInformation();
int findingAccount(char []);
void fileInformation();
void informationTransactionFile();
void saveTransactionToFile();
void fillRecents();
void updateRecents();
void clearOldUpdate(int);
/******************************************************************************************/
struct Account
{
	char firstName[10];
	char lastName[20];
	char phoneNumber[12];
	char nationalCode[13];
	char cardNumber[18];
	char password[6];	
	float balance;	
};

struct recents {
    char update[10][Max];
    int updateNum;
};
struct Account INFO[Max];
struct recents re[Max];
char recentData[5000];
int count=0;
int adminLogedIn=false;
int customerLogedIn=false;
/******************************************************************************************/


/*****************************************************************************************/
int main() 
{
	int z;
	int fileExist;
	fileInformation();
	for (z = 0; z < count; z++) {
        re[z].updateNum = 0;
    }
    fileExist = readFile("recentData.txt", recentData);
    if (fileExist) {
        fillRecents();
    }
	mainMenu();
	
}
/****************************************************************************************/

/***************************************************************************************/
void mainMenu() {
	system("cls");
	int options , exit;
	printf("\n\n\n\t\t\t\t----------------------\n");
	printf("\t\t\t\t|   welcome to ATM   |\n");
	printf("\t\t\t\t----------------------\n");
	printf("\n\n\n (1) Log in as an employee\n\n");
	printf(" (2) Log in as a customer\n\n");
	printf(" (3) Exit\n\n");
	scanf("%d", &options);
	
	switch(options) {
		case 1: employeeMenu(); break;
		case 2: customerMenu(0); break;
		case 3: printf(" Do you want exit the ATM?\t(1)yes\t(2)no\n");
		scanf("\n %d", &exit);
		if(exit == 1)
			return;
		else
			mainMenu();
		
		default: 
		printf("your number is wrong."); 
		getchar();
		getchar();
		mainMenu();
		
	}
}
/************************************************************************************/

/************************************************************************************/
void employeeMenu() {/*Log in as an employee*/ 
	char userName[6],password[5];
	system("cls");

	for(;;) {
		if (adminLogedIn) break;
		printf("\n user name : ");
		scanf("%s", userName);
		printf("\n\n password : ");
		scanf(" %s", password);
		
		if((strcmp(userName, "admin") == 0) && (strcmp(password, "1234") == 0)) {
			printf("\n\nuser name and password is correct.\n\n");
			adminLogedIn = true;
				break;
		}		
		else {
			printf("\n\nuser name or password is wrong.\ntry again.\n\n");
				continue;
		}
	}
	system("cls");
	int options;	
	printf("\n\n\n\t\t\t\t---------------------\n");
	printf("\t\t\t\t|   employee menu   |\n");
	printf("\t\t\t\t---------------------\n");
	printf("\n\n\n (1) Create an account\n\n");
	printf(" (2) Edit an account\n\n");
	printf(" (3) Show the richest customer\n\n");
	printf(" (4) Show total balance of all account\n\n");
	printf(" (5) Back to the main menu\n\n");
	scanf(" %d", &options);
	
	switch(options) {
		case 1: createAnAccount(); break;
		case 2: editAnAccount(); break; 
		case 3: showTheRichestCustomer(); break;
		case 4: showTotalBalanceOfAllAccount();break;
		case 5: adminLogedIn = false; mainMenu(); break;
		default : system("cls");
		printf(" your number is wrong.\n please click [ENTER] for try agian.");
		getchar();
		getchar();
		employeeMenu();
	}
}
/************************************************************************************/

/************************************************************************************/
void createAnAccount() {/*Create an account*/
		system("cls");
		printf("\n\n\n\t\t\t\t---------------------\n");
		printf("\t\t\t\t|  creat an account |\n");
		printf("\t\t\t\t---------------------\n");
		
		for(;;) {
			printf("\n\n\n first name : ");
			scanf("%s", INFO[count].firstName);
			/*if(INFO[count].firstName == isalpha(INFO[count].firstName))*/ {
				break;
			}
			/*else */{
				printf("\n your first name must be alphabet!");
					continue;	
			}
		}
		
		printf("\n last name : ");
		scanf("%s", INFO[count].lastName);
		
		for(;;) {
			printf("\n phone number must be 11 digits!\n phone number : ");
			scanf("%s", INFO[count].phoneNumber);
			if((INFO[count].phoneNumber[0]!='0') && (INFO[count].phoneNumber[1]!='9')) {
				printf("\n your number must beginning with 09!");
					continue;
			}
			else if(strlen(INFO[count].phoneNumber) != 11) {
				printf("\n your number must be 11 digits!");
					continue;
			}
			/*else if(INFO[count].phoneNumber != isdigit(INFO[count].phoneNumber)) {
				printf("\n your phone number must be digit!");
					continue;
			}*/
			else
				break;
		}
		
		for(;;)	{
			printf("\n national code must be 10 digits.\n national code:");
			scanf("%s", INFO[count].nationalCode);
			if(strlen(INFO[count].nationalCode) != 10) {
				printf("\n national code is invalid");
					continue;
			}
			else
				break;
		}
		
		for(;;)	{
			printf("\n card number must be 16 digits.\n card number:");
			scanf("%s", INFO[count].cardNumber);
			if(strlen(INFO[count].cardNumber) != 16) {
				printf("\n card number is invalid");
					continue;
			}
			else
				break;
		}
		
		for(;;) {
			printf("\n password must be 4 digits.\n password:");
			scanf("%s", INFO[count].password);
			if(checkPassword(INFO[count].password) == 0) {
				printf("\n password is invalid.");
					continue;
			}
			else 
				break;
		}
		
		for(;;) {
		printf("\n balance:");
		scanf("%f", &INFO[count].balance);
		if(INFO[count].balance < 0)	{
			printf("\n please enter the correct account balance.");
				continue;
		}
		else
			break;
		}
		
		re[count].updateNum = 0;
		system("cls");
		count++;
		saveToFile();
		congratulatory();
		employeeMenu();
}
int checkPassword(char password[]) {
	
	int i;
	if(strlen(password)!=4)
	return 0;
	for(i=0;i<4;i++) {
		if(!isdigit(password[i]))
		return 0;
	}
	return 1;
}


void congratulatory() {
	printf("\n\n\n********************** you made an account successfully ************************\n");
	printf("\n\n\n\t\t\t back to main menu -----> [ENTER]");
	getchar();
	getchar();
	system("cls");
	employeeMenu();
}
void saveToFile() {
	int i=0;
	FILE *ptf = fopen("account.txt", "w");
	if(ptf==NULL) {
		printf("Error");
	}
	else {
		for(i=0;i<count;i++) {
			fprintf(ptf,"%s  %s  %s  %s  %s  %s  %.2f\n",INFO[i].firstName,INFO[i].lastName,INFO[i].phoneNumber,INFO[i].nationalCode,INFO[i].cardNumber,INFO[i].password,INFO[i].balance);
		}
		fclose(ptf);
	}
}

/************************************************************************************/

/************************************************************************************/
void fileInformation() {
	FILE *ptf;
	ptf=fopen("account.txt","r");
	if(ptf==NULL) {
		/*printf("Error");
		exit(0);*/
		ptf=fopen("account.txt","r");
	}
	else {
		while(!feof(ptf)) {
			fscanf(ptf,"%s %s %s %s %s %s %f ",INFO[count].firstName,INFO[count].lastName,INFO[count].phoneNumber,INFO[count].nationalCode,INFO[count].cardNumber,INFO[count].password,&INFO[count].balance);
			count++;
		}
		fclose(ptf);
	}
}
/*************************************************************************************/

/*************************************************************************************/
void editAnAccount() {/*Edit an account*/
	char cardNumber1[Max];
	char newInformation[Max];
	int i, check;
	int option;
	system("cls");
	
	printf("************************* credibility *******************************");
	
	for(i = 0; i < 3; i++) {
		printf("\n\ncard number must be 16 digits.\nplease enter your card number:");
		scanf("%s", cardNumber1);
		for (check = 0; check < count; check++) {

			if(strcmp(cardNumber1, INFO[check].cardNumber) != 0) {
				printf(" your card number is wrong.\n\n pleas try agian.");
					continue;
			}
			else 
				break;
		}
		
		if(strcmp(cardNumber1, INFO[check].cardNumber) == 0) break;
	}
	if (i == 3) return;
	
	system("cls");
	for(;;) {
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~your current information~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		
		printf("(1) first name : %s\n", INFO[check].firstName);
		printf("(2) last name : %s\n", INFO[check].lastName);
		printf("(3) phone number : %s\n", INFO[check].phoneNumber);
		printf("(4) national code : %s\n", INFO[check].nationalCode);
		printf("(5) password : %s\n", INFO[check].password);
		printf("(6) Back to employee menu\n\n");
		printf("(choose one of the option for change it)");
		scanf("%d", &option);
		system("cls");
		
		if(option==1) {
			printf("New first name:");
			scanf("%s", newInformation);
			strcpy(INFO[count].firstName, newInformation);
				break;
		}
		
		if(option==2) {	
			printf("New last name:");
			scanf("%s", INFO[count].lastName);
			strcpy(INFO[count].lastName, newInformation);
				break;
		}
	
		if(option==3) {
			for(;;) {
				printf("New phone number:\nphone number must be 11 digits.");
				scanf("%s", newInformation);
				if((INFO[count].phoneNumber[0]!='0') && (INFO[count].phoneNumber[1]!='9')) {
					printf("your new phone number must beginning with 09.");
						continue;
				}
				else if(strlen(newInformation) != 11) {
					printf("your new phone number must be 11 digits.");
						continue;
				}
				else {
					strcpy(INFO[count].phoneNumber, newInformation);
						break;
				}	
			}
			break;
		}
		
		if(option==4) {
			for(;;) {
				printf("New national code:\nnational code must be 10 digits.");
				scanf("%s", newInformation);
				if(strlen(newInformation) != 10) {
					printf("New national code is invalid");
						continue;
				}
				else {
					strcpy(INFO[count].nationalCode, newInformation);
						break;	
				}
			}
			break;
		}
		
		if(option==5) {
			for(;;) {
				printf("New password:\npassword must be 4 digits.");
				scanf("%s", newInformation);
				if(checkPassword(newInformation) == 0) {
					printf("New password is invalid.");
						continue;
				}
				else {
					strcpy(INFO[count].password, newInformation);
						break;
				}	
			}
			break;
		}
		
		if(option==6) {
			employeeMenu();
			system("cls");
		}
		
		if(option!= 1 || 2 || 3 || 4 || 5 || 6) {
			printf("your option is wrong\nplease try agian.");
			getchar();
			system("cls");
			editAnAccount();
		}
	}
	saveToFile();
	system("cls");
}
/************************************************************************************/

/************************************************************************************/
void showTheRichestCustomer() {/*Show the richest customer*/ 
	system("cls");
	float max=0;
	int i , index;
	
	for(i=0;i<count;i++) {
		if(INFO[i].balance>max) {
			max=INFO[i].balance;
			index=i;
		}
	}
	
	printf("\n\n\n\t\t\t if you want, you can see the richest customer.\n\n\n\n\n");
	getchar();
	printf("\t\t\t first name : %s\n\t\t\t last name : %s\n\t\t\t phone number : %s\n\t\t\t national code : %s\n\t\t\t card number : %s\n\t\t\t password : %s\n\t\t\t balance : %f$",
	INFO[index].firstName,INFO[index].lastName,INFO[index].phoneNumber,INFO[index].nationalCode,INFO[index].cardNumber,INFO[index].password,INFO[index].balance);
	printf("\n\n\n\t\t\t back to employee menu -----> [ENTER]");
	getchar();
	system("cls");
	employeeMenu();
}
/************************************************************************************/

/************************************************************************************/
void showTotalBalanceOfAllAccount() {/*show total balance of all account*/
	system("cls");
	int i;
	float sum=0;
	float sumAccount=0;

	for(i=0;i<count;i++) {
		sum = INFO[i].balance + sumAccount;
		sumAccount = sum ;
			continue;
	}
	printf("\n************************ now you can see total balance ************************\n\n\n\n");
	printf("\t\t\t\t%f$",sumAccount);
	printf("\n\n\n\t\t\t back to employee menu -----> [ENTER]");
	getchar();
	getchar();
	system("cls");
	employeeMenu();
}

/************************************************************************************/

/************************************************************************************/
void customerMenu(int check) {/*customer menu*/
	system("cls");
	char cardNumber1[Max];
	char password[Max];
	int i;
	int option;
	
	printf("\n******************************* credibility ***********************************");
	
	for(i = 0; i < 3; i++) {
		if(customerLogedIn) break;

		for(;;) {
			printf("\n\n card number must be 16 digits.\n please enter your card number :");
			scanf("%s", cardNumber1);
			
			if(strlen(cardNumber1) != 16) {
				printf("\n card number is invalid");
					continue;
			}
			else {
				/*customerLogedIn=true;*/
					break;
			}
				
		}
		
		for (check = 0; check < count; check++) {
			if(strcmp(cardNumber1, INFO[check].cardNumber) != 0) {
				/*printf("\nyour card number is wrong.");
				getchar();*/
				system("cls");
				continue;
			}
			else 
				break;
		}
		if(strcmp(cardNumber1, INFO[check].cardNumber) == 0) 
			break;
	}
	if (i == 3) return;
	
	

	
	for(i = 0; i < 3; i++) {
		if(customerLogedIn) break;

		for(;;) {
			printf("\n\n please enter your password :");
			scanf("%s", password);
			
			if(strlen(password) != 4) {
				printf("\n password is invalid");
					continue;
			}
			else {
				/*customerLogedIn=true;*/
					break;
			}
				
		}
		
		for (check = 0; check < count; check++) {
			if(strcmp(password, INFO[check].password) != 0) {
				/*printf("\nyour password is wrong.");
				getchar();*/
				system("cls");
				continue;
			}
			else 
				break;
		}
		if(strcmp(password, INFO[check].password) == 0) 
			break;
	}
	if (i == 3) return;
	
	
	system("cls");
	
	printf("\n\n\n\t\t\t------------------------------\n");
	printf("\t\t\t|   welcome to customer menu |\n");
	printf("\t\t\t------------------------------\n");
	
	printf("************************* your card namber is true *****************************\n\n\t\t\t\t   welcome\n\n");
	printf(" (1) account balance\n");
	printf(" (2) cash transfer\n");
	printf(" (3) cash withdrawal\n");
	printf(" (4) recent account updates\n");
	printf(" (5) change password\n");
	printf(" (6) Back to the main menu\n");
	scanf("%d", &option);
			
		switch(option) {
			case 1: accountBalance(check);break;
			case 2: cashTransfer(check);break;
			case 3: cashWithdrawal(check);break;
			case 4: resentAccountUpdates(check);break;
			case 5: changePassword();break;
			case 6: customerLogedIn = false; mainMenu();break;
			default : printf(" your number is wrong.\n please try agian.");
			getchar();
			getchar(); 
			customerMenu(0);
		}
}
/************************************************************************************/

/************************************************************************************/
void accountBalance(int check) {
	system("cls");
	printf("\n\n\n\t\t\t\t------------------------\n");
	printf("\t\t\t\t|   account balance    |\n");
	printf("\t\t\t\t------------------------\n");
	
	printf("\n\n\t\t\tyour account balance : %f$", INFO[check].balance);
	printf("\n\n\n\t\t\t back to customer menu -----> [ENTER]");
	getchar();
	getchar();
	system("cls");
	customerMenu(check);
	
}


void cashTransfer(int index) {
	system("cls");
	printf("\n\n\n\t\t\t\t---------------------\n");
	printf("\t\t\t\t|   cash transfer   |\n");
	printf("\t\t\t\t---------------------\n");
	int i , size , option;
	int receiverIndex=-1;
	int length;
	float money , sum=0 , cut=0;
	char cardDestination[Max];
	
	printf(" enter your card number destination : ");
	scanf("%s", cardDestination);
	printf(" \nenter your amount cash transfer : \n\n");
	scanf("%f", &money);
	
	for(i=0;i<count;i++) {
		if(strcmp(INFO[i].cardNumber, cardDestination) != 0) {
			continue;
		}
		else {
			size = i;
			receiverIndex = i;
			printf("  (1) first name : %s\n", INFO[i].firstName);
			printf("  (2) last name : %s\n", INFO[i].lastName);
			printf("  (3) phone number : %s\n\n", INFO[i].phoneNumber);
			printf("\n\n  Do you want to perform this operation?\t 1)yes\t 2)no\n");
			scanf("%d", &option);
		
			if(option == 1) {
				break;
			}
			if(option == 2) {
				customerMenu(index);	
			}	
		}
	}
	if (receiverIndex < 0) {
		printf(" Wrong Card Number.");
		getchar();
		exit(0);
		cashTransfer(index);
	}
	if(INFO[index].balance < money) {
		printf(" your balance is not enough.");
		getchar();
		cashTransfer(index);
	}
	printf("\n\n\n\t\t\t\t DONE");
	
	cut = INFO[index].balance - money;
	sum = INFO[size].balance + money;
	INFO[index].balance = cut;
	INFO[size].balance = sum;
	
	char tmp[Max];
    gcvt((float) money, 10, tmp);
    length = strlen(tmp);
    if (tmp[length-1] == '.') {
        tmp[length-1] = '\0';
    }

    if (re[index].updateNum == 10) {
        clearOldUpdate(index);
    }
    i = re[index].updateNum;
    strcpy(re[index].update[i], "You Transfered $");
    strcat(re[index].update[i], tmp);
    strcat(re[index].update[i], " To ");
    strcat(re[index].update[i], INFO[receiverIndex].firstName);
    strcat(re[index].update[i], " ");
    strcat(re[index].update[i], INFO[receiverIndex].lastName);
    strcat(re[index].update[i], "(");
    strcat(re[index].update[i], cardDestination);
    strcat(re[index].update[i], ")");
    re[index].updateNum++;


    if (re[receiverIndex].updateNum == 10) {
        clearOldUpdate(receiverIndex);
    }
    i = re[receiverIndex].updateNum;
    strcpy(re[receiverIndex].update[i], "You Got $");
    strcat(re[receiverIndex].update[i], tmp);
    strcat(re[receiverIndex].update[i], " From ");
    strcat(re[receiverIndex].update[i], INFO[index].firstName);
    strcat(re[receiverIndex].update[i], " ");
    strcat(re[receiverIndex].update[i], INFO[index].lastName);
    strcat(re[receiverIndex].update[i], "(");
    strcat(re[receiverIndex].update[i], INFO[index].cardNumber);
    strcat(re[receiverIndex].update[i], ")");
    re[receiverIndex].updateNum++;

    saveToFile();
    updateRecents();

    printf("\n\n  Transfer Completed Successfully!");
    printf("\n\n  Your Account Balance Now : $%f", INFO[index].balance);
    printf("\n\n\n\t\t\t back to Customer menu -----> [ENTER]");
    getchar();
	
	
	/*saveTransactionToFile();*/
	customerMenu(index);
}


void cashWithdrawal(int check) {
	system("cls");
	printf("\n\n\n\t\t\t\t-----------------------\n");
	printf("\t\t\t\t|   cash withdrawal   |\n");
	printf("\t\t\t\t-----------------------\n");
	float cut , money;
	char tmp[Max];
	int length;
	int i;
	
	for(;;) {
		printf(" request money : ");
		scanf("%f", &money);
		if(INFO[check].balance < money) {
			printf(" your balance is not enough.\n\n try agian.");
			cashWithdrawal(check);
		}	
		else
			break;
	}	

			printf("\n\n  Don't Forget Your Money!");
    printf("\n\n  Your Account Balance Now : $%f", INFO[check].balance);
    printf("\n\n\n\t\t\t back to Customer menu -----> [ENTER]");
	getchar();
	getchar();
	system("cls");
	
	cut = INFO[check].balance - money;
	INFO[check].balance = cut;
	
	gcvt((float) money, 10, tmp);
    length = strlen(tmp);
    if (tmp[length-1] == '.') {
        tmp[length-1] = '\0';
    }
	
	if (re[check].updateNum == 10) {
        clearOldUpdate(check);
    }
    i = re[check].updateNum;
    strcpy(re[check].update[i], "You Got $");
    strcat(re[check].update[i], tmp);
    strcat(re[check].update[i], " Out Of Your Account");
    re[check].updateNum++;

    saveToFile();
    updateRecents();
	customerMenu(check);
}


void resentAccountUpdates(int check) {
	
    int numOfUpdate;
    int i;
    

    numOfUpdate = re[check].updateNum;
    if (numOfUpdate == 0) {
        printf("\n\n\n\t\t\tNo Recent Activities!");
        printf("\n\n\n\t\t\t back to customer menu -----> [ENTER]");
        getchar();
        getchar();
    	customerMenu(check);
    }

    for (i = 0; i < numOfUpdate; i++) {
        printf("\n\n\t%d) %s", i+1, re[check].update[i]);
    }
    printf("\n\n\n\t\t\t back to customer menu -----> [ENTER]");
    getchar();
    getchar();
    customerMenu(check);

}


void changePassword(int check) {
	char password[Max];
	char newPassword[Max];
	int option;
	
	for(;;) {
		printf("\n enter your password :");
		scanf(" %s", password);
		for (check = 0; check < count; check++) {
			if(strcmp(INFO[check].password, password) != 0) {
				printf("\n password is invalid.");
		 		printf("\n\n Do you want back to customer menu?\t 1)yes\t 2)no\n");	
				scanf("%d", &option);
		
				if(option == 1) {
					customerMenu(check);
				}
				else
					continue;
			
				}
			}
			break;
		}
	
	for(;;) {
		printf("\n enter your new password :");
		scanf(" %s", newPassword);
		if(checkPassword(newPassword) == 0)	{
			printf("\n new password is invalid.");
				continue;
		}
		else 
			break;
	}
	/*INFO[check].password = newPassword;*/
		printf("\n\n\n\t\t\t back to customer menu -----> [ENTER]");
    	getchar();
    	
		customerMenu(check);
		
}



void fillRecents() {
    int length;
    int i, index;
    int fileIndex;
    int upIndex;
    char c;

    fileIndex = 0;

    length = strlen(recentData);
    if (length == 0) {
        return;
    }
    for (index = 0; index < count && fileIndex < length; index++) {
        upIndex = 0;
        for (i = 0; fileIndex < length; i++) {
            c = recentData[fileIndex];
            fileIndex++;
            if (c == '\n') break;
            if (c == '|') {
                upIndex++;
                re[index].updateNum++;
                i = -1;
                continue;
            }
            re[index].update[upIndex][i] = c;
        }
    }
}


void updateRecents() {
    FILE *file = fopen("recentData.txt", "w");
    int i, index;
    int results;

    for (index = 0; index < count; index++) {

        for (i = 0; i < re[index].updateNum; i++) {
            results = fputs(re[index].update[i], file);
            results = fputs("|", file);
            if (results == EOF) {
            	
            }
        }
        results = fputs("\n", file);
        if (results == EOF) {
        	
        }
    }
    fclose(file);
}


void clearOldUpdate(int index) {
    char tempStr[Max];
    int length;
    int i;
    for (i = 1; i < 10; i++) {
        length = strlen(re[index].update[i]);
        strcpy(re[index].update[i-1], re[index].update[i]);
        re[index].update[i-1][length] = '\0';
    }
    re[index].update[9][1] = '\0';
    re[index].updateNum--;
}


int readFile(char fileName[Max], char data[5000]) {
    FILE *file = fopen(fileName, "r");
    int n = 0;
    int c;

    if (file == NULL) {
        return false;
    }

    while ((c = fgetc(file)) != EOF) {
        data[n++] = (char) c;
    }

    /* don't forget to terminate with the null character */
    data[n] = '\0';
    fclose(file);
    return true;
}



/*void informationTransactionFile()	{
	/*FILE *ptf;
	ptf = fopen("Transaction.txt","r");
	if(ptf==NULL) {
		/*printf("Error");
	
