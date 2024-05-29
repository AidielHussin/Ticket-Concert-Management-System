#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Defining the Ticket struct
struct Ticket {
	
	char custID[5];
    char custName[50];
    char custPhoneNum[15];
    int custAge;
    char custAdd[100];
    char event[50];
	char date[50];
    char seat[50];
    
};

// Function prototypes
float calcPrice( struct Ticket[] , int  );
void calcTotalSales( struct Ticket[] , int  );
void countSection( struct Ticket[] , int );
void calcHighest( struct Ticket[]  , int );
void calcLowest( struct Ticket[]  , int );
void calcTotalSales( struct Ticket[], int );
void calcTotalAttendees( struct Ticket[], int );
void searchData( struct Ticket[], int, int );
int removeData ( struct Ticket[] ,int , int );

float calcPrice( struct Ticket t[] , int i )
{
	float total = 0;
	
        if( strcmp( t[i].event , "Aina Abdul Concert" ) == 0 ) 
        {
            if( strcmp( t[i].seat , "CAT 1 (VIP Pass)" ) == 0 )
                total = 300.00;
            else
			if( strcmp( t[i].seat , "CAT 2" ) == 0 )
                total = 250.00;
            else 
			if( strcmp( t[i].seat , "CAT 3" ) == 0 )
                total = 100.00;
        }
        else
		if( strcmp( t[i].event , "Siti Nurhaliza Concert" ) == 0 ) 
        {
            if( strcmp( t[i].seat , "CAT 1 (VIP Pass)" ) == 0 )
                total = 500.00;
            else 
			if( strcmp( t[i].seat , "CAT 2" ) == 0 )
                total = 350.00;
            else 
			if( strcmp( t[i].seat , "CAT 3" ) == 0 )
                total = 200.00;
        }
        else 
		if( strcmp( t[i].event , "Noraniza Idris Concert" ) == 0 ) 
        {
            if( strcmp( t[i].seat , "CAT 1 (VIP Pass)" ) == 0 )
                total = 150.00;
            else 
			if( strcmp( t[i].seat , "CAT 2" ) == 0 )
                total = 100.00;
            else 
			if( strcmp( t[i].seat , "CAT 3" ) == 0 )
                total = 50.00;
        }
        
	return total;
}

//count total attendee for each event 
void calcTotalAttendees( struct Ticket t[] , int numOfCustomers )
{	
	int totalAA = 0;
	int totalSN = 0;
	int totalNI = 0;
	int i;
	for( i = 0; i < numOfCustomers; i++){
		if( strcmp( t[i].event , "Aina Abdul Concert" ) == 0 ) 
			totalAA = totalAA + 1;
		else
		if( strcmp( t[i].event , "Siti Nurhaliza Concert" ) == 0 ) 
		    totalSN = totalSN + 1;
		else
		if( strcmp( t[i].event , "Noraniza Idris Concert" ) == 0 ) 
			totalNI = totalNI + 1;
	}
    
    int eventNum;  
    printf("\n");
    printf("\nTotal Attendees for Each Concert:");
    printf( "\n\tAina Abdul Concert : %d", totalAA );
	printf( "\n\tSiti Nurhaliza Concert : %d", totalSN );
	printf( "\n\tNoraniza Idris : %d",  totalNI );
        
}

//Count the total attendees for each section
void countSection( struct Ticket t[] , int size )
{
	int i;
	int catOne = 0;
	int catTwo = 0;
	int catThree = 0;
	
	for (i = 0; i < size; i++) 
	{
		if( strcmp( t[i].seat , "CAT 1 (VIP Pass)" ) == 0 )
                catOne = catOne + 1;
        else 
		if( strcmp( t[i].seat , "CAT 2" ) == 0 )  
                catTwo = catTwo + 1;
        else 
		if( strcmp( t[i].seat , "CAT 3" ) == 0 )
                catThree = catThree + 1;
    }
    
    printf("\nTotal customer that chose Cat One : %d", catOne);
    printf("\nTotal customer that chose Cat Two : %d", catTwo);
    printf("\nTotal customer that chose Cat Three : %d", catThree);
	
}

//Calculate the sum of all earnings from each event based on their name
void calcTotalSales( struct Ticket t[] , int size )
{
	int i;
	float sumAA = 0.00;
	float sumSN = 0.00;
	float sumNI = 0.00;
	
	for ( i = 0; i < size ; i++ )
	{
	if( strcmp( t[i].event , "Aina Abdul Concert" ) == 0 )    
            sumAA = sumAA + calcPrice( t , i );
    else 
	if( strcmp( t[i].event , "Siti Nurhaliza Concert" ) == 0  ) 
        sumSN = sumSN + calcPrice( t , i  );
    else 
	if( strcmp( t[i].event , "Noraniza Idris Concert" ) == 0 ) 
        sumNI = sumNI + calcPrice( t , i  );
	}
    
    printf("\nTotal Earnings for Each Concert: ");
    printf("\n\tAina Abdul's Concert : RM%.2f", sumAA);
    printf("\n\tSiti Nurhaliza's Concert : RM%.2f", sumSN);
    printf("\n\tNoraniza Idris's Concert : RM%.2f", sumNI);
}

//Determine the maximum sales and attendees gained by comparing each event thoroughly
void calcHighest( struct Ticket t[] , int size )
{
	int i;
	int countAA = 0;
	int countSN = 0;
	int countNI = 0;
	int highestAtt = 0;
	float highestSales = 0.00; 
	float sumAA = 0.00;
	float sumSN = 0.00;
	float sumNI = 0.00;	
	char SalesName[50];
	char AttName[50];
	
	for ( i = 0; i < size; i++ ) 
	{
		if( strcmp( t[i].event , "Aina Abdul Concert" ) == 0  ) 
            {
				sumAA = sumAA + calcPrice( t , i );
				countAA = countAA + 1;
			}
        else 
		if( strcmp( t[i].event , "Siti Nurhaliza Concert" ) == 0 )  
            {
				sumSN = sumSN + calcPrice( t , i );
				countSN = countSN + 1;
			}
        else 
		if( strcmp( t[i].event , "Noraniza Idris Concert" ) == 0 ) 
            {
				sumNI = sumNI + calcPrice( t , i );
				countNI = countNI + 1;
			}
    }
    
    if ( sumAA > highestSales )
        {
		  highestSales = sumAA;
		  strcpy( SalesName , "Aina Abdul's Concert");
    	}
    if ( sumSN > highestSales )
        {
		  highestSales = sumSN;
		  strcpy( SalesName,"Siti Nurhaliza's' Concert");
    	}
    if ( sumNI > highestSales )
        {
		  highestSales = sumNI;
		  strcpy( SalesName , "Noraniza Idris's' Concert");
    	}
         
    if ( countAA > highestAtt )
        {
         highestAtt = countAA;
         strcpy( AttName , "Aina Abdul's Concert" );
    	}
    if ( countSN > highestAtt )
        {
		  highestAtt = countSN;
		  strcpy( AttName , "Siti Nurhaliza's Concert" );
    	}
    if ( countNI > highestAtt )
        {
		  highestAtt = countNI;
		  strcpy( AttName , "Noraniza Idris's Concert" );
    	}
    
	printf("\nName of highest attended event : %s", AttName );     
    printf("\nTotal attendees for the highest event : %d", highestAtt);
    
    printf("\nName of highest sales gained from an event : %s", SalesName);     
    printf("\nTotal sales for the highest event : %.2f", highestSales);
    
}

//Determine the lowest sales and attendees gained by comparing each event thoroughly
void calcLowest( struct Ticket t[] , int size )
{
	int i;
	int countAA = 0;
	int countSN = 0;
	int countNI = 0;
	int lowestAtt = 999;
	float lowestSales = 999999.00; 
	float sumAA = 0.00;
	float sumSN = 0.00;
	float sumNI = 0.00;
	char SalesName[50];
	char AttName[50];
	
	for (i = 0; i < size; i++ ) 
	{
		if( strcmp( t[i].event , "Aina Abdul Concert" ) == 0 ) 
            {
				sumAA = sumAA + calcPrice( t , i );
				countAA = countAA + 1;
			}
        else 
		if( strcmp( t[i].event , "Siti Nurhaliza Concert" ) == 0 ) 
            {
				sumSN = sumSN + calcPrice( t , i );
				countSN = countSN + 1;
			}
        else 
		if( strcmp( t[i].event , "Noraniza Idris Concert" ) == 0 ) 
			{
				sumNI = sumNI + calcPrice( t , i );
				countNI = countNI + 1;
			}
    }
    
    if ( sumAA < lowestSales )
        {
		  lowestSales = sumAA;
		  strcpy( SalesName , "Aina Abdul's Concert");
    	}
    if ( sumSN < lowestSales )
        {
		  lowestSales = sumSN;
		  strcpy( SalesName , "Siti Nurhaliza's Concert");
    	}
    if ( sumNI < lowestSales )
        {
		  lowestSales = sumNI;
		  strcpy( SalesName , "Noraniza Idris's Concert");
    	}
         
    if ( countAA < lowestAtt )
        {
         lowestAtt = countAA;
         strcpy( AttName , "Aina Abdul's Concert" );
    	}
    if ( countSN < lowestAtt )
        {
		  lowestAtt = countSN;
		  strcpy( AttName , "Siti Nurhaliza's Concert" );
    	}
    if ( countNI < lowestAtt )
        {
		  lowestAtt = countNI;
		  strcpy( AttName , "Noraniza Idris's Concert");
    	}
    
	printf("\nName of lowest attended event : %s", AttName);     
    printf("\nTotal attendees for the lowest event : %d", lowestAtt);
    
    printf("\nName of lowest sales gained from an event : %s", SalesName);     
    printf("\nTotal sales for the lowest event : %.2f", lowestSales);
    
}


void updateData(struct Ticket t[], int i, int size){
	printf("\n");
    char enterID[100];
    char enterName[100];
    int index = 0;
    printf("Enter customer ID to update phone number:\n");
    scanf("%s", enterID);
    

    int found = 0;
    for (i = 0; i < size; i++) {
        if ( strcmp(t[i].custID, enterID) == 0 ) 
		{
			index = i;
            char newPhone[50];
            printf("Customer found!\n\nEnter the new phone number to update:\n");
            scanf("%s", newPhone);
            strcpy(t[i].custPhoneNum, newPhone);
            found = 1;
            break;
        }
    }

    if (found) 
	{
        printf("\nPhone number has been updated.\n");
        printf("\nUPDATED DETAILS \n");
        printf("Customer ID: %s\n", t[index].custID);
        printf("Customer Name: %s\n", t[index].custName);
        printf("Phone Number: %s\n", t[index].custPhoneNum);
        printf("Age: %d\n", t[index].custAge);
        printf("Address: %s\n", t[index].custAdd);
        printf("\n");
    } else {
        printf("Customer ID doesn't match or not found. Try again!\n");;
    }
	
}

int removeData(struct Ticket t[], int i , int size){
    char findID[5];
    printf("Enter Customer ID that want to remove:\n");
    scanf("%s", findID);
    
    int found = 0;
    for(i = 0; i < size; i++){
        if( strcmp(t[i].custID, findID ) == 0){
            found = 1;
            int s;
            for(s = i; s < size-1; s++){
                strcpy(t[s].custID, t[s+1].custID);
                strcpy(t[s].custName, t[s+1].custName);
                t[s].custAge = t[s+1].custAge;
                strcpy(t[s].custAdd, t[s+1].custAdd);
                strcpy(t[s].custPhoneNum, t[s+1].custPhoneNum);
                strcpy( t[s].event , t[s+1].event );
                strcpy(t[s].date, t[s+1].date);
                strcpy( t[s].seat , t[s+1].seat );
            }
         	size= size-1;
        }
    }
    
    if( !found ){
		 printf("ID are not in the data. Please enter a valid ID. \n");
	}else {
		printf("Customer found!\nDeleting... \n");
		printf("\nCustomer data for %s is successfully delete.\n", findID);
	}
	
	return size;

}

int main(){
	int size = 5;
	struct Ticket t[ size ];
	
	printf("Welcome to Ticket Concert Management System!\n");             
    printf("\n\t----------------------------------------");
    printf("\n\t\t\tTicket List");                                         
    printf("\n\t----------------------------------------");
        
    printf("\n\n\tConcert 1:");                                          
    printf("\n\tTicket ID: AA001");
    printf("\n\tEvent Name: Aina Abdul Concert");
    printf("\n\tEvent Date Available:");
    printf("\n\t\t[1] 24/01/2024 (Wednesday) - 8pm");
    printf("\n\t\t[2] 28/02/2024 (Wednesday) - 8pm");
    printf("\n\tSeat Section:");
    printf("\n\t\t[1] CAT 1 (VIP Pass) - RM 300.00");
    printf("\n\t\t[2] CAT 2 - RM 250.00");
    printf("\n\t\t[3] CAT 3 - RM 100.00");
        
    printf("\n\n\tConcert 2:");                                         
    printf("\n\tTicket ID: SN001");
    printf("\n\tEvent Name: Siti Nurhaliza Concert");
    printf("\n\tEvent Date Available:");
    printf("\n\t\t[1] 28/09/2024 (Saturday) - 8pm");
    printf("\n\t\t[2] 26/10/2024 (Saturday) - 8pm");
    printf("\n\tSeat Section:");
    printf("\n\t\t[1] CAT 1 (VIP Pass) - RM 500.00");
    printf("\n\t\t[2] CAT 2 - RM 350.00");
    printf("\n\t\t[3] CAT 3 - RM 200.00");
        
    printf("\n\n\tConcert 3:");                                        
    printf("\n\tTicket ID: NI001");
    printf("\n\tEvent Name: Noraniza Idris Concert");
    printf("\n\tEvent Date Available:");
    printf("\n\t\t[1] 17/05/2024 (Friday) - 8pm");
    printf("\n\t\t[2] 14/06/2024 (Friday) - 8pm");
    printf("\n\tSeat Section:");
    printf("\n\t\t[1] CAT 1 (VIP Pass) - RM 150.00");
    printf("\n\t\t[2] CAT 2 - RM 100.00");
    printf("\n\t\t[3] CAT 3 - RM 50.00\n\n");
    
	printf("\n");
	int i;
	for( i = 0 ; i < size ; i++ )
	{
	
	printf("\nCustomer %d ", i+1);
	printf("\nCustomer ID:\n");
	scanf("%s", &t[i].custID);
	printf("Customer Name:\n");
	scanf("%s", &t[i].custName);
	printf("Customer Phone Number:\n");
	scanf("%s", &t[i].custPhoneNum);
	printf("Customer Age:\n");
	scanf("%d", &t[i].custAge);
	printf("Customer State/City ( Address ):\n");
	scanf("%s", &t[i].custAdd);

	printf("\nTicket Order %d :", i+1);
	printf("\nChoose your preferent Ticket by Entering Concert Code [ 1 - AA001 | 2 - SN001 | 3 - NI001]:\n");
	scanf("%s", &t[i].event);
	
	if( strcmp( t[i].event , "1" ) == 0 ) 
	{
	strcpy( t[i].event , "Aina Abdul Concert" );
	printf("Enter Event Date you prefer [1|2]:\n");
	scanf("%s", &t[i].date);
		if( strcmp( t[i].date , "1" ) == 0 ) 
			strcpy(t[i].date,"24/01/2024 (Wednesday) - 8pm");
		
		else
			strcpy(t[i].date, "28/02/2024 (Wednesday) - 8pm");
		
	}
	else
	if( strcmp( t[i].event , "2" ) == 0 )
	{
	strcpy( t[i].event , "Siti Nurhaliza Concert" );
	printf("Enter Event Date you prefer [1|2]:\n");
	scanf("%s", &t[i].date);
		if( strcmp( t[i].date , "1" ) == 0 )
			strcpy( t[i].date, "28/01/2024 (Saturday) - 8pm");
		
		else
			strcpy( t[i].date, "26/01/2024 (Saturday) - 8pm");
		
	}
	else
	if( strcmp( t[i].event , "3" ) == 0 ){
	strcpy( t[i].event , "Noraniza Idris Concert" );
	printf("Enter Event Date you prefer [1|2]:\n");
	scanf( "%s", &t[i].date);
		if( strcmp( t[i].date , "1" ) == 0 )
			strcpy(t[i].date , "17/01/2024 (Friday) - 8pm");
		
		else
			strcpy(t[i].date, "14/02/2024 (Friday) - 8pm");
		
	}
		
	printf("Enter Seat Section you Prefer [1|2|3]:\n");
	scanf("%s", &t[i].seat );
	if( strcmp( t[i].seat , "1" ) == 0 )
        strcpy( t[i].seat,"CAT 1 (VIP Pass)");
    else 
	if( strcmp( t[i].seat , "2" ) == 0 )
        strcpy( t[i].seat,"CAT 2");
    else 
	if( strcmp( t[i].seat , "3" ) == 0 )
        strcpy( t[i].seat,"CAT 3");
	
	printf("\n");
  	}
    
    calcTotalSales( t , size );
    
    printf("\n");
    calcTotalAttendees( t , size );	
    printf("\n");
    
    
    printf("\n");
    calcHighest( t  , size );
    
    printf("\n");
    calcLowest( t , size );	
    printf("\n");
    
	char updateChoice;
	printf("\nUPDATE PHONE NUMBER");
	printf("\nEnter [Y] to continue update phone number or [N] to skip this process:\n");
	scanf(" %c", &updateChoice );
	
	while( ( updateChoice == 'Y' ) || (updateChoice == 'y' ) )
	{	
		updateData(t , i ,size);	
		printf("\nEnter [Y] to continue update phone number or [N] to skip this process:\n");
		scanf(" %c", &updateChoice );
	}
	
	char removeChoice;
	printf("\nREMOVE CUSTOMER ORDER");
	printf("\nEnter [Y] to continue or [N] to skip this process:\n");
	scanf(" %c", &removeChoice );
	while( ( removeChoice== 'Y' ) || ( removeChoice== 'y' ) )
	{
	 	size = removeData(t ,i,size);
	 	
		printf("\nEnter [Y] to continue or [N] to skip this process:\n");
		scanf(" %c", &removeChoice );
	}
	printf("\n");
	printf("\n\nCustomer's Ticket Information:\n ");
  int j;
  for (j = 0; j < size; j++) {
  		
  		printf("\n===== Customer Data %d =====\n", j+1);
  		printf("\nEvent Name: %s\n",t[j].event );
        printf("Event Date: %s\n",t[j].date);
        printf("Seat Section: %s\n",t[j].seat);
        printf("Price: %.2f\n",calcPrice( t , j ) );
        
        printf("\nCustomer ID: %s\n", t[j].custID);
        printf("Customer Name: %s\n", t[j].custName);
        printf("Phone Number: %s\n", t[j].custPhoneNum);
        printf("Age: %d\n", t[j].custAge);
        printf("Address: %s\n", t[j].custAdd);
        printf("\n");
    }
    printf("\n\nThank You for Using Our System!");
	
  	return 0;
}
