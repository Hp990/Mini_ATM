#include<stdio.h>
#include<time.h>

float balance = 25800.26;
int lp=0;

int arr2[10]; float amo[10];
int dd, mm, yy, hr, min;
 
int main()
{
	
    welcome();

    int pin;
    while(pin != 1234)
    {
        printf("Enter your 4 digit PIN: ");
        scanf("%d", &pin);
        if(pin == 1234)
            break;
        printf("Invalid PIN! Try Again\n");
    }
    printf("Success!!\n\n");

    printf("***** ATM Service *****\n");
    printf("1. Check Balance\n");
    printf("2. Cash Withdrawal\n");
    printf("3. Cash Deposit\n");
    printf("4. Money Transfer\n");
    printf("5. Mini Statement\n");
    printf("6. LogOut\n");
    printf("***********************\n\n");

    int choice;
    while(choice != 6)
    {

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

	switch(choice)
    {
    case 1:
        printf("\nYour current balance: %2.2f INR\n", balance);
        break;
    case 2:
        withdraw();
        break;
    case 3:
        deposit();
        break;
    case 4:
    	transfer();
    	break;
    case 5:
    	slip(); 
		//printout();
    	break;
    case 6:
        printf("\nYou are logged out Successfully!!\n"
               "Thank You, for choosing our service.\n\n");
        break;
    default:
        printf("\nError!!");
    }
    }
	getch();
    return 0;
}

int welcome()
{
    printf("\t\t\t\t\t***************************\n");
    printf("\t\t\t\t\t    Welcome to Your ATM\n");
    printf("\t\t\t\t\t***************************\n");
}

int withdraw()
{
    float amt;
    printf("\nEnter the amount to withdraw: ");
    scanf("%f", &amt);
    if(amt >= balance)
    {
        printf("Transaction Failed!!\n");
        printf("Your account balance is insufficient to make transaction !!\n");
    }
    else
    {
    	arr2[lp] = 11; amo[lp] = amt; lp++;
        printf("Amount withdrawal: %2.2f INR\n", amt);
        balance = balance - amt;
        printf("Current Balance:   %2.2f INR\n", balance);
        printf("Transaction is Completed!!\n");
    }
    return 0;

}

int transfer() 
{
	float amt;
	long int accNO;
	
	printf("Enter the Account Number of Account Holder\n");
	scanf("%ld", &accNO);
	
	int pin;
    while(pin != 1234)
    {
        printf("Enter your 4 digit PIN: ");
        scanf("%d", &pin);
        if(pin == 1234)
            break;
        printf("Invalid PIN! Try Again\n");
    }
    printf("Success!!\n");
    
    printf("\nEnter the amount to transfer: ");
    scanf("%f", &amt);
    
    if(amt >= balance)
    {
        printf("Transaction Failed!!\n");
        printf("Your account balance is insufficient to make transaction !!\n");
    }
    else
    {
    	arr2[lp] = 22; amo[lp] = amt; lp++;
        printf("Amount transfered: %2.2f INR\n", amt);
        balance = balance - amt;
        printf("Current Balance:   %2.2f INR\n", balance);
        printf("Amount is successfully transferred to Account Number %ld\n", accNO);
    }
    return 0;	
}

int deposit()
{
    float addAmt;
    printf("Enter the amount to add in your account: ");
    scanf("%f", &addAmt);
    balance += addAmt;
    printf("Amount Successfully added to your account!\n");
    printf("Current Balance: %2.2f INR\n", balance);
    arr2[lp] = 33; amo[lp] = addAmt; lp++;
    return 0;
}

void date_time() {
	time_t t = time(NULL);
  	struct tm tm = *localtime(&t);
  	dd = tm.tm_mday; mm = tm.tm_mon + 1; yy = tm.tm_year + 1900-2000;
  	hr = tm.tm_hour; min = tm.tm_min;
  	printf("  %d/%d/%d  \t%d:%d\tS10A001769001\n", dd, mm, yy, hr, min);
}

int slip()
{
	printf("\n\n\t  STATE BANK OF INDIA\n");
	printf("  ___________________________________\n\n");
	printf("  Phagwara (Branch)\n");
	printf("  DATE  \tTIME  \tTERM\n");
	date_time();
	printf("  CARD NUMBER\t7988XXXXXXXXXX325\n");
	printf("  TXN. NO  \t%d\n", 6362+lp);
	printf("  STATEMENT FOR\t000001545\n");
	
	int i;
	for(i=0; i<lp; i++) {
		if(arr2[i] == 11)
			printf("   %d/%d\t%.2f-ATM WDL\n", dd, mm, amo[i]);
		if(arr2[i] == 22)
			printf("   %d/%d\t%.2f-TRANSFER\n", dd, mm, amo[i]);
		if(arr2[i] == 33)
			printf("   %d/%d\t%.2f+CASH DEPOSIT\n", dd, mm, amo[i]);
	}
	
	printf("   AVAIL BAL\t%.2f+\n", balance);
	//printf("\n    Visit us at www.sbi.co.in\n");
	
	return 0;	
}

int printout() 
{	
// work is going on
	char chh;
	printf("Do you want a Slip [Y/N] : ");
	scanf("%c", &chh);
	
	FILE *fptr;
		
	if(chh == 'Y' || chh == 'y') {
	fptr = fopen("D:\\Slips\\emp.rec", "w");
	if(fptr == NULL) {
		printf("File does not exist");
		return;
	}
	fprintf(fptr, "\n\n\t  STATE BANK OF INDIA\n");
	fprintf(fptr, "  ___________________________________\n\n");
	fprintf(fptr, "  Phagwara (Branch)\n");
	fprintf(fptr, "  DATE  \tTIME  \tTERM\n");
	fprintf(fptr, "  %d/%d/%d  \t%d:%d\tS10A001769001\n", dd, mm, yy, hr, min);
	fprintf(fptr, "  CARD NUMBER\t7988XXXXXXXXXX325\n");
	fprintf(fptr, "  TXN. NO  \t%d\n", 6362+lp);
	fprintf(fptr, "  STATEMENT FOR\t000001545\n");
	
	int i;
	for(i=0; i<lp; i++) {
		if(arr2[i] == 11)
			fprintf(fptr, "   %d/%d\t%.2f-ATM WDL\n", dd, mm, amo[i]);
		if(arr2[i] == 22)
			fprintf(fptr, "   %d/%d\t%.2f-TRANSFER\n", dd, mm, amo[i]);
		if(arr2[i] == 33)
			fprintf(fptr, "   %d/%d\t%.2f+CASH DEPOSIT\n", dd, mm, amo[i]);
	}
	
	fprintf(fptr, "   AVAIL BAL\t%.2f+\n", balance);
	fclose(fptr);
		printf("Slip successfully saved to your computer.\n");
	}
	else{
		printf("\nOkay, Please continue our service !\n");
	}
	return 0;
}
