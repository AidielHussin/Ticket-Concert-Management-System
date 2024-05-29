/***==================================================
Main Application of Ticket Concert Management System 
==================================================***/
import java.util.*;                                                               
import java.time.LocalDateTime;                    
import java.time.format.DateTimeFormatter;  
       
public class TicketApps
{
    public static void main(String args[])
    {
        //Array declaration
        Ticket []t = new Ticket[5];
        
        //Menu List
        System.out.println("Welcome to Ticket Concert Management System!");             
        System.out.println("\n\t----------------------------------------");
        System.out.printf("\t\t\tTicket List");                                         
        System.out.println("\n\t----------------------------------------");
        
        System.out.printf("\n\tConcert 1:");                                          
        System.out.printf("\n\tTicket ID: AA001");
        System.out.printf("\n\tEvent Name: Aina Abdul Concert");
        System.out.printf("\n\tEvent Date Available:");
        System.out.printf("\n\t\t[1] 24/01/2024 (Wednesday) - 8pm");
        System.out.printf("\n\t\t[2] 28/02/2024 (Wednesday) - 8pm");
        System.out.printf("\n\tSeat Section:");
        System.out.printf("\n\t\t[1] CAT 1 (VIP Pass) - RM 300.00");
        System.out.printf("\n\t\t[2] CAT 2 - RM 250.00");
        System.out.printf("\n\t\t[3] CAT 3 - RM 100.00");
        
        System.out.printf("\n\n\tConcert 2:");                                         
        System.out.printf("\n\tTicket ID: SN001");
        System.out.printf("\n\tEvent Name: Siti Nurhaliza Concert");
        System.out.printf("\n\tEvent Date Available:");
        System.out.printf("\n\t\t[1] 28/09/2024 (Saturday) - 8pm");
        System.out.printf("\n\t\t[2] 26/10/2024 (Saturday) - 8pm");
        System.out.printf("\n\tSeat Section:");
        System.out.printf("\n\t\t[1] CAT 1 (VIP Pass) - RM 500.00");
        System.out.printf("\n\t\t[2] CAT 2 - RM 350.00");
        System.out.printf("\n\t\t[3] CAT 3 - RM 200.00");
        
        System.out.printf("\n\n\tConcert 3:");                                        
        System.out.printf("\n\tTicket ID: NI001");
        System.out.printf("\n\tEvent Name: Noraniza Idris Concert");
        System.out.printf("\n\tEvent Date Available:");
        System.out.printf("\n\t\t[1]17/05/2024 (Friday) - 8pm");
        System.out.printf("\n\t\t[2]14/06/2024 (Friday) - 8pm");
        System.out.printf("\n\tSeat Section:");
        System.out.printf("\n\t\t[1] CAT 1 (VIP Pass) - RM 150.00");
        System.out.printf("\n\t\t[2] CAT 2 - RM 100.00");
        System.out.printf("\n\t\t[3] CAT 3 - RM 50.00\n\n");
        
        //Input from console 
        Scanner input = new Scanner(System.in); 
        Scanner inputNum = new Scanner(System.in);
        Scanner inputText = new Scanner(System.in);  
        for(int i=0; i<t.length; i++)
        {
            System.out.println("\nCustomer " + (i+1) + " ");
            System.out.println("Customer ID: ");
            String ID = inputText.nextLine();
            System.out.println("Customer Name: ");
            String name = inputText.nextLine();
            System.out.println("Customer Phone Number: ");
            String phone = inputText.nextLine();
            System.out.println("Customer Age: ");
            int age = inputNum.nextInt();
            System.out.println("Customer State/City ( Address ): ");
            String address = inputText.nextLine();
            
            System.out.println("\nTicket Order " + (i+1) + " :");
            System.out.println("Choose your preferent Ticket by Entering Concert Code [1 - AA001|2 - SN001|3 - NI001]: ");
            char ticketID = input.next().charAt(0);
            System.out.println("Enter Event Date you Prefer [1|2]: ");
            char date = input.next().charAt(0);
            System.out.println("Enter Seat Section you Prefer [1|2|3]: ");
            char seat = input.next().charAt(0);
            
            t[i] = new Ticket(ticketID, date, seat, ID, name, phone, age, address);
        }
        
        //Calculate the sum of all earnings from each event based on ticket ID.
        double sumAA = 0, sumSN = 0, sumNI = 0;
        for(int i=0; i<t.length; i++)
        {
            if(t[i].getTicketID() == '1')
                sumAA += t[i].calcPrice();
            else if(t[i].getTicketID() == '2')
                sumSN += t[i].calcPrice();
            else if(t[i].getTicketID() == '3')
                sumNI += t[i].calcPrice();
        }
        System.out.println("\nTotal Earnings for Each Concert: ");
        System.out.println("\tAina Abdul's Concert: RM " + sumAA);
        System.out.println("\tSiti Nurhaliza's Concert: RM " + sumSN);
        System.out.println("\tNoraniza Idris's Concert: RM " + sumNI);
        
        //Count the total attendees for each section. 
        int countAA = 0, countSN = 0, countNI = 0;
        for(int i=0; i<t.length; i++)
        {
            if(t[i].getTicketID() == '1')
                countAA++;
            else if(t[i].getTicketID() == '2')
                countSN++;
            else if(t[i].getTicketID() == '3')
                countNI++;
        }
        System.out.println("\nTotal Attendees for Each Concert: ");
        System.out.println("\tAina Abdul's Concert: " + countAA);
        System.out.println("\tSiti Nurhaliza's Concert: " + countSN);
        System.out.println("\tNoraniza Idris's Concert: " + countNI);
        
        //Determine the maximum sales and attendees gained by comparing each event thoroughly .
        int countMax = 0;
        double maxSales = 0;
        String maxSalesEvent = "", maxCountEvent = "";
        for(int i=0; i<t.length; i++) 
        {
            if(sumAA > maxSales)
            {
                maxSales = sumAA;
                maxSalesEvent = "Aina Abdul's Concert";
            }
            
            if(sumSN > maxSales)
            {
                maxSales = sumSN;
                maxSalesEvent = "Siti Nurhaliza's Concert";
            }
            
            if(sumNI > maxSales)
            {
                maxSales = sumNI;
                maxSalesEvent = "Noraniza Idris's Concert";
            }
            
            
            if(countAA > countMax)
            {
                countMax = countAA;
                maxCountEvent = "Aina Abdul's Concert";
            }
            
            if(countSN > countMax)
            {
                countMax = countSN;
                maxCountEvent = "Siti Nurhaliza's Concert";
            }
            
            if(countNI > countMax)
            {
                countMax = countNI;
                maxCountEvent = "Noraniza Idris's Concert";
            }
        }
        System.out.println("\nName of highest attended event: " +maxCountEvent);
        System.out.println("Total attendees for the highest event: " +countMax);
        System.out.println("Name of highest sales gained from an event: " +maxSalesEvent);
        System.out.println("Total sales for highest sales event: RM " +maxSales);
        
        //Determine the minimum sales and attendees gained by comparing each event thoroughly. 
        int countMin = 99999;
        double minSales = 999999.99;
        String minSalesEvent = "", minCountEvent = "";
        for(int i=0; i<t.length; i++) 
        {
            if(sumAA < minSales)
            {
                minSales = sumAA;
                minSalesEvent = "Aina Abdul's Concert";
            }
            
            if(sumSN < minSales)
            {
                minSales = sumSN;
                minSalesEvent = "Siti Nurhaliza's Concert";
            }
            
            if(sumNI < minSales)
            {
                minSales = sumNI;
                minSalesEvent = "Noraniza Idris's Concert";
            }
            
            
            if(countAA < countMin)
            {
                countMax = countAA;
                minCountEvent = "Aina Abdul's Concert";
            }
            
            if(countSN < countMax)
            {
                countMin = countSN;
                minCountEvent = "Siti Nurhaliza's Concert";
            }
            
            if(countNI < countMin)
            {
                countMin = countNI;
                minCountEvent = "Noraniza Idris's Concert";
            }
        }
        System.out.println("\nName of lowest attended event: " +minCountEvent);
        System.out.println("Total attendees for the lowest event: " +countMin);
        System.out.println("Name of lowest sales gained from an event: " +minSalesEvent);
        System.out.println("Total sales for lowest sales event: RM " +minSales);
        
        //Search the data of any customer by using their customer ID for reference and update phone number purpose. 
        System.out.println("\nUPDATE PHONE NUMBER");
        Scanner inLine = new Scanner(System.in);
        System.out.println("Enter [Y] to continue update phone number or [N] to skip this process: ");
        String answer = inLine.nextLine();
        while(answer.equalsIgnoreCase("Y"))
        {  
            System.out.println("\nEnter customer ID to update phone number: ");
            String searchID = inputText.nextLine();
            
            int foundIndex = -1;
            //Search for customer by customer ID
            for(int i=0; i<t.length; i++)
            {
                if(t[i].getCustID().equalsIgnoreCase(searchID)) 
                {
                    foundIndex = i;
                    break; 
                }
            }
            
            //Update phone number if customer is found
            if (foundIndex != -1) 
            {
                System.out.println("Customer found!\n\nEnter the new phone number to update: ");
                String newPhoneNum = inputText.nextLine();
                
                //Update the new phone number for customer
                t[foundIndex].setCustPhoneNum(newPhoneNum);
                
                System.out.println("\nPhone number has been updated.");
                System.out.println("\nUPDATED DETAILS" + t[foundIndex].toStringCustomer());
            }
            else 
            {
                System.out.println("Customer ID doesn't match or not found. Try again!");
            }
            System.out.println("\nEnter [Y] to continue update phone number or [N] to skip this process: ");
            answer = inLine.nextLine();
        }
        
        //Remove data
        System.out.println("\nREMOVE CUSTOMER ORDER");
        System.out.println("Enter [Y] to continue or [N] to skip this process: ");
        String remove = inLine.nextLine();
        while(remove.equalsIgnoreCase("Y"))
        {
            System.out.println("Enter Customer ID that want to remove: ");
            String searchIDRemove = inputText.nextLine();
            
            int foundIndex = -1;
            //Search for customer by customerID
            for(int i=0; i<t.length; i++)
            {
                if(t[i].getCustID().contains(searchIDRemove)) 
                {
                    foundIndex = i;
                    break; 
                }
            }
          
            //Remove customer if customerID is found
            if (foundIndex != -1) 
            {
                System.out.println("Customer found!\nDeleting... \n");
                
                //Remove customer
                t[foundIndex] = new Ticket();
                t[foundIndex] = null;
                
                System.out.println("Customer data for "+searchIDRemove+ " is successfully delete.");
            }
            else 
            {
                System.out.println("ID are not in the data. Please enter a valid ID");
            }
            System.out.println("\nEnter [Y] to continue or [N] to skip this process: ");
            remove = inLine.nextLine();
        }
        
        //Display all Tickets orders after update
        System.out.println("\n\nCustomer's Ticket Information: ");
        int p = 0;
        for(int i=0; i<t.length; i++)
        {
            if(t[i] != null){
                System.out.println("\n===== Customer " + (p+1) + " ======");
                System.out.println(t[i].toStringTicket() + "\n" + t[i].toStringCustomer());
                p++;
            }
        }
        System.out.println("\n\nThank You for Using Our System!");
    }
}