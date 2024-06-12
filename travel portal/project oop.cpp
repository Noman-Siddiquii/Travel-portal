#include<iostream>
#include<string>
using namespace std;
class Register{
	string password;
	string email;
	public:
		static int countUsers;
		string name;
		string contact;
	Register(){
		countUsers++;
	}
	void setName(){
		cout<<"Name:";
		getline(cin, name);
	}	
	void setContact(){
		cout<<"Phone number:";
		getline(cin, contact);
		if(contact.length() != 11){
			while(contact.length() != 11){
				cout<<"Wrong input\n";
				cout<<"Enter correct phone number:";
				getline(cin, contact);
			}
		}
	}
	void setEmail(){
		cout<<"Email:";
		getline(cin, email);
	}
	void setPassword(){
		cout<<"Password:";
		getline(cin, password);
	}
	string getName(){
		return name;
	}
	string getContact(){
		return contact;
	}
	string getEmail(){
		return email;
	}
	string getPassword(){
		return password;
	}
};
int Register::countUsers=0;

class Login{
	string emaill;
	string pass;
	int count;
	Register* ptr;
	public:
		Login(int c, Register* r){
			count=c;
			ptr=r;
		}
		void setEmail(){
			cout<<"Email:";
			getline(cin, emaill);
		}
		void setPass(){
			cout<<"Password:";
			getline(cin, pass);
		}
		void check(){
			int y=0;
			for(int i=0; i<count; i++){
				if(emaill.compare((ptr+i)->getEmail())==0){
					if(pass.compare((ptr+i)->getPassword())==0){
					    cout<<"Login successfully\n";
					    y++;
					}
					else{
						cout<<"Wrong password\n";
						while(pass.compare((ptr+i)->getPassword())!=0){
							cout<<"Enter correct password:";
							getline(cin, pass);
						}
						cout<<"Login successfully\n";
						y++;
					}	    
				}
			}
			if(y==0){
				cout<<"Account with given email doesn't exist\nKindly register first\n";
			}
		}
};

class Ticket
{
protected:
    string Departure_location, Arrival_location;
    string Departure_time, Arrival_time, TicketNumber;
    bool reserved = false;
    int EconomicPrice;
    int BussinessPrice;

public:
    Ticket() {}
    void setEconomicPrice(int p){
        EconomicPrice=p;
    }
    int getEconomicPrice(){
        return EconomicPrice;
    }
    void setBussinessPrice(int p){
        BussinessPrice=p;
    }
    int getBussinessPrice(){
        return BussinessPrice;
    }
    void setDeparturelocation(string Departure_location)
    {
        this->Departure_location = Departure_location;
    }
    void setDeparturetime(string Departure_time)
    {
        this->Departure_time = Departure_time;
    }
    string getDeparturelocation()
    {
        return Departure_location;
    }
    string getDeparturetime()
    {
        return Departure_time;
    }
    void setArrivalLocation(string Arrival_location)
    {
        this->Arrival_location = Arrival_location;
    }
    void setArrivaltime(string Arrival_time)
    {
        this->Arrival_time = Arrival_time;
    }
    string getArrivallocation()
    {
        return Arrival_location;
    }
    string getArrivaltime()
    {
        return Arrival_time;
    }
    void setTicketNumber(string TicketNumber)
    {
        this->TicketNumber = TicketNumber;
    }
    string getTicketNumber()
    {
        return TicketNumber;
    }
};

class Train : public Ticket
{
protected:
    int NumberofSeats;
    int NumberOfEconomySeats;
    int NumberOfBusinessSeats;
    Ticket *ecoTickets;
    Ticket *businessTickets;

public:
    Train() {}
    void TicketsInfo(int NumberofSeats, int NumberOfEconomySeats, int NumberOfBusinessSeats)
    {
        string departure, arrival, time_departure, time_arrival, seat;
        this->NumberofSeats = NumberofSeats;
        this->NumberOfEconomySeats=NumberOfEconomySeats;
        this->NumberOfBusinessSeats=NumberOfBusinessSeats;
        ecoTickets = new Ticket[NumberOfEconomySeats];
        businessTickets =  new Ticket[NumberOfBusinessSeats];
        cout << "Enter Departure Location: ";
        cin >> departure;
        cout << "Enter Arrival Location: ";
        cin >> arrival;
        cout << "Enter Departure Time: ";
        cin >> time_departure;
        cout << "Enter Arrival Time: ";
        cin >> time_arrival;
        for(int i=0;i<NumberOfEconomySeats;i++){
           ecoTickets[i].setArrivalLocation(arrival);
            ecoTickets[i].setDeparturetime(time_departure);
            ecoTickets[i].setDeparturelocation(departure);
            ecoTickets[i].setArrivaltime(time_arrival);
            seat = "T-#0" + to_string(i + 1);
            ecoTickets[i].setTicketNumber(seat); 
        }
        for(int i=0;i<NumberOfBusinessSeats;i++){
           businessTickets[i].setArrivalLocation(arrival);
            businessTickets[i].setDeparturetime(time_departure);
            businessTickets[i].setDeparturelocation(departure);
            businessTickets[i].setArrivaltime(time_arrival);
            seat = "T-#0" + to_string(i + 1 + NumberOfEconomySeats);
            businessTickets[i].setTicketNumber(seat); 
        }
        
    }
    void DisplayTickets()
    {
        cout << "\n    ECONOMY TICKETS    \n";
        for (int i = 0; i < NumberOfEconomySeats; i++)
        {
            cout << ecoTickets[i].getTicketNumber() << endl;
        }
        cout << "    BUSINESS CLASS TICKETS    \n";
        for (int i = 0; i < NumberOfBusinessSeats; i++)
        {
            cout << businessTickets[i].getTicketNumber() << endl;
        }
    }
    ~Train()
    {
        delete[] ecoTickets;
        delete[] businessTickets;
    }
};

class TicketInfo : virtual public Train
{
public:
    virtual void TicketsInfo(int NumberofSeats, int NumberOfEconomySeats, int NumberOfBusinessSeats)
    {
        Train::TicketsInfo(NumberofSeats,NumberOfEconomySeats, NumberOfBusinessSeats);
    }
};

class Bus : virtual public TicketInfo
{
public:
    Bus() {}
    ~Bus()
    {
        delete[] ecoTickets;
        delete[] businessTickets;
    }
};

class Flight : virtual public TicketInfo
{
public:
    Flight() {}
    ~Flight()
    {
        delete[] ecoTickets;
        delete[] businessTickets;
    }
};
class Payment:public Train{
protected:
    string cardNumber;
    string cardHolderName;
    string cvvCode;
    
    

public:
	Payment(){
	}

    void setCardNumber(string cardNumber){
        this->cardNumber = cardNumber;
    }

    string getCardNumber(){
        return cardNumber;
    }
    void setCardHolderName(string cardHolderName){
        this->cardHolderName = cardHolderName;
    }
    string getCardHolderName(){
        return cardHolderName;
    }

    void setCvvCode(string cvvCode){
        this->cvvCode = cvvCode;
    }

    string getCvvCode(){
        return cvvCode;
    }
    void PaymentProcess(){
    int choice;
    cout<<"Do you want to make Payment through Cash or Card?"<<endl;
    cout<<"Enter 1 For Cash"<<endl;
    cout<<"Enter 2 For Card"<<endl;
    cin>>choice;
    cin.ignore(); 
    if(choice==1)
    {
        cout<<"Visit Our nearest office to pay and get tickets"<<endl;
    }
    else if(choice==2)
    {
        cout<<"Enter your Card Number(e.g 1234567890123456):";
        getline(cin,cardNumber);

        if(cardNumber.length()==16)
        {
            for (int i = 0; i < cardNumber.length(); i++) {
               char c = cardNumber[i];
              if (c < '0' || c > '9') {
                cout << "Invalid input: Please enter only numbers.\n";
                break;
            }
            }
        }

        cout<<"Enter Card Holder Name:";
        getline(cin,cardHolderName);

        cout<<"Enter CVV code:";
        getline(cin,cvvCode);

        if(cvvCode.length()==3)
        {
            for (int i = 0; i < cvvCode.length(); i++) {
               char c = cvvCode[i];
              if (c < '0' || c > '9') {
                cout << "Invalid input: Please enter only numbers.\n";
                break;
            }
            }
        }
    }
}

	    void displayPayment(){
	    	double total=0;
	    	cout<<"Payment SuccessFull!"<<endl;
	    	cout<<"Card Holder Name:"<<cardHolderName<<endl;
	    	cout<<"Card Number:"<<cardNumber<<endl;
	    	cout << "\n    ECONOMY TICKETS    \n";
        for (int i = 0; i < NumberOfEconomySeats; i++)
        {
            cout << ecoTickets[i].getTicketNumber() <<" Price:"<<getEconomicPrice() <<endl;
            total=total+getEconomicPrice();
        }
        cout << "    BUSINESS CLASS TICKETS    \n";
        for (int i = 0; i < NumberOfBusinessSeats; i++)
        {
            cout << businessTickets[i].getTicketNumber() <<" Price:"<<getBussinessPrice() <<endl;
            total=total+getBussinessPrice();
        }
        cout<<"Total:"<<total<<endl;
		}
         
		
    	
    	
	
    
};
int main()
{
// 	Register* r=new Register;
// 	cout<<"    REGISTER    \n";
// 	r[0].setName();
// 	r[0].setContact();
// 	r[0].setEmail();
// 	r[0].setPassword();
//	r[1].setName();
//	r[1].setContact();
//	r[1].setEmail();
//	r[1].setPassword();
// 	cout<<"    LOGIN    \n";
// 	Login l(1, r);
// 	l.setEmail();
// 	l.setPass();
// 	l.check();
    //Bus b;
    //b.TicketsInfo(5, 3, 2);
    //b.DisplayTickets();
    Payment p;
    p.setEconomicPrice(2000);
    p.setBussinessPrice(5000);
    
    p.TicketsInfo(5,3,2);
    p.PaymentProcess();
    p.displayPayment();
    
    
    return 0;
}