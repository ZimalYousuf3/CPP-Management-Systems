#include <iostream> 
#include <string>  // for strings
#include <iomanip> // for setprecision

using namespace std;

// Enum declaration
enum RoomType {
	SINGLE ,
    DOUBLE ,
	DELUXE ,
    SUITE
};

// Structure declaration
struct Date {
	int day, month, year ;
};

struct Guest {
	int guestID;
	string name;
	int age;
	RoomType roomType ;
	Date checkInDate ;
	Date checkOutDate ;
	double billAmount ;
};

// Structure Array Declaration
const int MAX_ROOMS = 100 ;
Guest guest[MAX_ROOMS] ;
int guestCount = 0 ;

// Function prototypes
void addGuest();
void displayAllGuests();
void findGuestsByRoomType(RoomType type);
string roomTypeToString (RoomType type) ;
int stayDuration(Date checkIn, Date checkOut);
void calculateBill(int guestID);
void generateHotelReport();

int main ()
{
	int choice ;
	do {
		cout << "========= HOTEL GUEST MANAGEMENT SYSTEM =========" << endl ;
		cout << " 1. Add new guest " << endl ;
		cout << " 2. Display all guests " << endl ;
		cout << " 3. Find guests by room type " << endl ;
		cout << " 4. Calculate guest bill " << endl ;
		cout << " 5. Generate hotel report " << endl ;
		cout << " 6. Exit " << endl ;
		cout << "=================================================" << endl ;
		cout << " Select your choice (1-6): ";
		cin >> choice ;
		cout << endl ;
		
		switch (choice)
		{
			case 1:
				{
					addGuest();
					break ;
				}
				
			case 2:
				{
					displayAllGuests();
					break ;
				}
				
			case 3:
				{
					int type ;
					cout << "----- Room Types -----" << endl ;
					cout << " 1. SINGLE " << endl ;
					cout << " 2. DOUBLE " << endl ;
					cout << " 3. DELUXE " << endl ;
					cout << " 4. SUITE " << endl ;
					cout << "----------------------" << endl ;
					cout << " Select your room type (1-4):" ;
					cin >> type ;
					if ( type >= 1 && type <= 4 )
					{
						findGuestsByRoomType(static_cast <RoomType> (type-1));
					}
					else
					{
						cout << " Invalid Choice! " << endl ;
					}
					break ;
				}
				
			case 4:
				{
					int guestID ;
					cout << " Enter guest ID: ";
					cin >> guestID ;
					
					calculateBill(guestID);
					break ;
				}
				
			case 5:
				{
					generateHotelReport();
					break ;
				}
				
			case 6:
				{
					cout << " Exiting...." << endl ;
					break ;
				}
				
			default:
			    {
			    	cout << " Invalid choice: Try Again!" << endl ;
				}				
		}
		
	} while (choice != 6) ;
	
	return 0 ;
}

// Function for adding new guest
void addGuest()
{
	Guest newGuest ;
	cout << " Enter your ID: " ;
	cin >> newGuest.guestID ;
	
	cin.ignore() ;
	cout << " Enter your Name: " ;
	getline (cin, newGuest.name) ;
	
	cout << " Enter your Age: " ;
	cin >> newGuest.age ;
	
	int roomType ;
	cout << "----- Room Types -----" << endl ;
	cout << " 1. SINGLE " << endl ;
    cout << " 2. DOUBLE " << endl ;
	cout << " 3. DELUXE " << endl ;
	cout << " 4. SUITE " << endl ;
	cout << "----------------------" << endl ;
	cout << " Select your room type (1-4): " ;
	cin >> roomType ;
	
	if ( roomType >= 1 && roomType <= 4 )
	{
		newGuest.roomType = static_cast <RoomType> (roomType-1);
	}
	else
	{
		cout << " Invalid Choice! " << endl ;
	}
	
	cout << " Enter your Check in date (DD MM YYYY) : " ;
	cin >> newGuest.checkInDate.day >> newGuest.checkInDate.month >> newGuest.checkInDate.year ;
	
	cout << " Enter your Check out date (DD MM YYYY) : " ;
	cin >> newGuest.checkOutDate.day >> newGuest.checkOutDate.month >> newGuest.checkOutDate.year ;
	
	newGuest.billAmount = 0.0 ;
	guest[guestCount] = newGuest ;
	guestCount++ ;
	
	cout << " New Guest Added!" << endl ;
	cout << endl ;
}

// Function for displaying all guests
void displayAllGuests()
{
	cout << " --------------------------------------------------------------------- " << endl ;
	cout << setw(5) << "ID" << setw(15) << "Name" << setw(15) << "Age" 
	     << setw(15) << "Room Type" << setw(15) << "Bill" << endl ;
	cout << " --------------------------------------------------------------------- " << endl ;
	
	for (int i = 0 ; i < guestCount ; i++)
	{
		cout << setw(5) << guest[i].guestID << setw(15) << guest[i].name << setw(15) << guest[i].age 
	         << setw(15) << roomTypeToString (guest[i].roomType) << setw(15) << guest[i].billAmount << endl ;
	}
	cout << " ---------------------------------------------------------------------- " << endl ;
	cout << endl ;     
}

// Function for finding patients by Room type
void findGuestsByRoomType(RoomType type)
{
	cout << " Guests with room type " << roomTypeToString (type) << ":-" << endl;
	cout << " ------------------------------------------------------------------ " << endl ;
	cout << setw(5) << "ID" << setw(15) << "Name" << setw(15) << "Age" 
	     << setw(15) << "Room Type" << setw(15) << "Bill" << endl ;
	cout << " ------------------------------------------------------------------ " << endl ;
	
	bool found = false ;
	for (int i = 0 ; i < guestCount ; i++)
	{
		if (guest[i].roomType == type)
		{
			found = true ;
			cout << setw(5) << guest[i].guestID << setw(15) << guest[i].name << setw(15) << guest[i].age 
	        << setw(15) << roomTypeToString (guest[i].roomType) << setw(15) << guest[i].billAmount << endl ;
		}
	}
	cout << " ------------------------------------------------------------------- " << endl ;
	
	if (!found)
	{
		cout << " No guest found! " << endl ;
	}
	
	cout << endl ; 
}

// Function for calculating stay duration
int stayDuration(Date checkIn, Date checkOut)
{
	int days = (checkOut.year - checkIn.year) * 365 +
	            (checkOut.month - checkIn.month) * 30 +
	            (checkOut.day - checkIn.day) ;
	return (days > 0) ? days : 0 ;
}

// Function for calculation of bill
void calculateBill(int guestID)
{
	int stayDays = 0 ;
	double bill = 0.0 ;
	for (int i = 0 ; i < guestCount ; i++) 
	{
		if (guest[i].guestID == guestID)
		{
			stayDays = stayDuration(guest[i].checkInDate, guest[i].checkOutDate) ;
			
			if (guest[i].roomType == SINGLE)
			{
				bill = stayDays * 3000 ;
			}
			else if (guest[i].roomType == DOUBLE)
			{
				bill = stayDays * 5000 ;
			}
			else if (guest[i].roomType == DELUXE)
			{
				bill = stayDays * 7000 ;
			}
			else 
			{
				bill = stayDays * 10000 ;
			}
			guest[i].billAmount = bill ;
		}	
	}
	    cout << " -------- Bill -------- " << endl ;
		cout << " Stay Duration: " << stayDays << " days "<< endl ;
		cout << " Total Bill: Rs. " << fixed << setprecision(2) << bill << endl ;
		cout << endl ;
}

// Function for generating Report
void generateHotelReport()
{
	double hotel_revenue = 0.0 ;
	int highBillCount = 0 ;
	for (int i = 0 ; i < guestCount ; i++) 
	{
		hotel_revenue += guest[i].billAmount ;
		if (guest[i].billAmount > 50000)
		{
			highBillCount++ ;
		}
	}

	cout << " ------------- Hotel Report ------------- " << endl;
	cout << " Total No. of Guests: " << guestCount << endl ;
	cout << " Total Hotel Revenue: Rs." << fixed << setprecision(2) << hotel_revenue << endl ;
	cout << " Guests with bills above Rs.50,000 : " << highBillCount << endl ;
	
	if (highBillCount > 0)
	{
		cout << " ---------------------------------------------------- " << endl ;
	    cout << setw(5) << "ID" << setw(15) << "Name" << setw(15) << "Bill" << endl ;
	    cout << " ---------------------------------------------------- " << endl ;
		
		for (int i = 0 ; i < guestCount ; i++) 
		{
			if (guest[i].billAmount > 50000)
			{
				cout << setw(5) << guest[i].guestID << setw(15) << guest[i].name << setw(15) << guest[i].billAmount << endl ;
			}
		}
	}
	    cout << " ---------------------------------------------------------------------- " << endl ;
}

// Function for string conversion
string roomTypeToString (RoomType type)
{
	switch (type)
	{
		case SINGLE : return " Single" ;
		case DOUBLE : return " Double" ;
		case DELUXE : return " Deluxe" ;
		case SUITE : return " Suite" ;
		default: return "UNKNOWN" ;
	}
}
