/***==================================================
Definition of Ticket Class
==================================================***/

public class Ticket
{
    private char ticketID;
    private char eventDate;
    private char seatSection;
    private String custID;                
    private String custName;             
    private String custPhoneNum;            
    private int custAge;                  
    private String custAddress; 
    
    //Default Constructor
    public Ticket()        
    {
        this.ticketID = 'n';
        this.eventDate = 'n';
        this.seatSection = 'n';
        this.custID = "";                      
        this.custName = "";                  
        this.custPhoneNum = "";         
        this.custAge = 0;                    
        this.custAddress = ""; 
    }
    
    //Normal Constructor
    public Ticket(char ticketID, char eventDate, char seatSection, String custID, String custName, String custPhoneNum, int custAge, String custAddress)        
    {
        this.ticketID = ticketID;
        this.eventDate = eventDate;
        this.seatSection = seatSection;
        this.custID = custID;                      
        this.custName = custName;                  
        this.custPhoneNum = custPhoneNum;         
        this.custAge = custAge;                    
        this.custAddress = custAddress; 
    }
    
    public void setDefaultTicket()        
    {
        this.ticketID = 'n';
        this.eventDate = 'n';
        this.seatSection = 'n';
        this.custID = "";                      
        this.custName = "";                  
        this.custPhoneNum = "";         
        this.custAge = 0;                    
        this.custAddress = ""; 
    }
    //Setter Method
    public void setTicket(char ticketID, char eventDate, char seatSection, String custID, String custName, String custPhoneNum, int custAge, String custAddress)        
    {
        this.ticketID = ticketID;
        this.eventDate = eventDate;
        this.seatSection = seatSection;
        this.custID = custID;                      
        this.custName = custName;                  
        this.custPhoneNum = custPhoneNum;         
        this.custAge = custAge;                    
        this.custAddress = custAddress;
    }
    
    public void setTicketID(char ticketID){this.ticketID = ticketID; }
    public void setEventDate(char eventDate){this.eventDate = eventDate; }
    public void setSeatSection(char seatSection){this.seatSection = seatSection; }
    public void setCustID(String custID){this.custID = custID; } 
    public void setCustName(String custName){this.custName = custName; }                
    public void setCustPhoneNum(String custPhoneNum){this.custPhoneNum = custPhoneNum; }  
    public void setCustAge(int custAge){this.custAge = custAge; } 
    public void setCustAddress(String custAddress){this.custAddress = custAddress; }  
    
    //Getter Method
    public char getTicketID(){return ticketID; }
    public char getEventDate(){return eventDate; }
    public char getSeatSection(){return seatSection; }
    public String getCustID(){return custID; }  
    public String getCustName(){return custName; }          
    public String getCustPhoneNum(){return custPhoneNum; }
    public int getCustAge(){return custAge; }        
    public String getCustAddress(){return custAddress; }  
    
    //Printer
    public String toString()
    {
        String str = "\nEvent Name: " + eventName(ticketID) +
                     "\nEvent Date: " + date(ticketID, eventDate) +
                     "\nSeat Section: " + seatSection(ticketID, seatSection) +
                     "\nPrice: RM " + calcPrice() +
                     "\nCustomer ID: " + custID +
                     "\nCustomer Name: " + custName +  
                     "\nPhone Number: " + custPhoneNum +  
                     "\nAge: " + custAge +
                     "\nAddress: " + custAddress;
        return str;
    }
    
    public String toStringTicket()
    {
        String textTicket = "\nEvent Name: " + eventName(ticketID) +
                            "\nEvent Date: " + date(ticketID, eventDate) +
                            "\nSeat Section: " + seatSection(ticketID, seatSection) +
                            "\nPrice: RM " + calcPrice();
        return textTicket;
    }
    
    public String toStringCustomer()
    {
        String textCust = "\nCustomer ID: " + custID +
                          "\nCustomer Name: " + custName +  
                          "\nPhone Number: " + custPhoneNum +  
                          "\nAge: " + custAge +
                          "\nAddress: " + custAddress;
        return textCust;
    }
    
    //Processor
    public double calcPrice()
    {
        double price = 0;
        if(ticketID == '1')
        {
            if(seatSection == '1')
                price = 300.00;
            else if(seatSection == '2')
                price = 250.00;
            else if(seatSection == '3')
                price = 100.00;
        }
        else if(ticketID == '2')
        {
            if(seatSection == '1')
                price = 500.00;
            else if(seatSection == '2')
                price = 350.00;
            else if(seatSection == '3')
                price = 200.00;
        }
        else if(ticketID == '3')
        {
            if(seatSection == '1')
                price = 150.00;
            else if(seatSection == '2')
                price = 100.00;
            else if(seatSection == '3')
                price = 50.00;
        }
        return price;
    }
    
    public String eventName(char ticketID)
    {
        String name = "default";
        if(ticketID == '1')
            name = "Aina Abdul's Concert";
        else if(ticketID == '2')
            name = "Siti Nurhaliza's Concert";
        else if(ticketID == '3')
            name = "Noraniza Idris's Concert";
        return name;
    }
    
    public String date(char ticketID, char eventDate)
    {
        String dateEvent = "default";
        if(ticketID == '1')
        {
            if(eventDate == '1')
                dateEvent = "24/01/2024 (Wednesday) - 8pm";
            else if(eventDate == '2')
                dateEvent = "28/02/2024 (Wednesday) - 8pm";  
        }
        else if(ticketID == '2')
        {
            if(eventDate == '1')
                dateEvent = "28/09/2024 (Saturday) - 8pm";
            else if(eventDate == '2')
                dateEvent = "26/10/2024 (Saturday) - 8pm";  
        }
        else if(ticketID == '3')
        {
            if(eventDate == '1')
                dateEvent = "17/05/2024 (Friday) - 8pm";
            else if(eventDate == '2')
                dateEvent = "14/06/2024 (Friday) - 8pm";  
        }
        return dateEvent;
    }
    
    public String seatSection(char ticketID, char seatSection)
    {
        String seat = "default";
        if(ticketID == '1')
        {
            if(seatSection == '1')
                seat = "CAT 1 - (VIP Pass)";
            else if(seatSection == '2')
                seat = "CAT 2"; 
            else if(seatSection == '3')
                seat = "CAT 3 ";
        }
        else if(ticketID == '2')
        {
            if(seatSection == '1')
                seat = "CAT 1 - (VIP Pass)";
            else if(seatSection == '2')
                seat = "CAT 2"; 
            else if(seatSection == '3')
                seat = "CAT 3";  
        }
        else if(ticketID == '3')
        {
            if(seatSection == '1')
                seat = "CAT 1 - (VIP Pass)";
            else if(seatSection == '2')
                seat = "CAT 2"; 
            else if(seatSection == '3')
                seat = "CAT 3";  
        }
        return seat;
    }
    
    public String nameTicketID(char ticketID)
    {
        String nameID = "default";
        if(ticketID == '1')
            nameID = "AA001";
        else if(ticketID == '2')
            nameID = "SN001";
        else if(ticketID == '3')
            nameID = "NI001";
        return nameID;
    }
}