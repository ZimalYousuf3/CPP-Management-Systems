#include <iostream>
#include <iomanip>
#include <string>
using namespace std ;

// Structure & Enum Declaration
enum BloodGroup { A_POSITIVE, A_NEGATIVE, B_POSITIVE, B_NEGATIVE,
 O_POSITIVE, O_NEGATIVE, AB_POSITIVE, AB_NEGATIVE };
 
struct Date { 
 int day ;
 int month ;
 int year ; 
}; 

struct Patient {
	int patientID ; 
	string name ;
	int age ;
	BloodGroup bloodGroup ;
	Date admissionDate ;
	Date dischargeDate ;
	double billAmount ; 
};

// Array of Structure
const int MAX_PATIENTS = 100 ;
Patient patient [MAX_PATIENTS] ;
int patientCount = 0 ;

// Function prototypes
void addPatient () ;
void displayAllPatients () ;
string bloodGroupToString (BloodGroup bg) ;
void findPatientsByBloodGroup(BloodGroup bg) ;
void calculateBill(int patientID) ;
int stayDuration (Date admit, Date discharge) ;
void generateHospitalReport() ;

int main ()
{
	int choice ;
	do{
		cout << " ======= Hospital Patient Management System ======= " << endl ;
		cout << " 1. Add new patient detail. " << endl ;
		cout << " 2. Display all patients details. " << endl ;
		cout << " 3. Find patient by blood group. " << endl ;
		cout << " 4. Calculate Bill. " <<endl ;
		cout << " 5. Generate Hospital Report. " << endl ;
		cout << " 6. Exit " << endl ;
		cout << " ================================================== " << endl ;
		cout << endl;
		cout << " Enter your choice: " ;
		cin >> choice ;
		
		switch (choice)
		{
			case 1:
				{
					addPatient () ;
					break ;
				}
			
			case 2:
			    {
			    	displayAllPatients () ;
			    	break ;
				}
				
			case 3:
			    {
			    	int bgChoice;
			    	cout << " ----- Blood Groups ----- " << endl ;
			    	cout << " 1. A_POSITIVE " << endl ;
			    	cout << " 2. A_NEGATIVE " << endl ;
			    	cout << " 3. B_POSITIVE " << endl ;
			    	cout << " 4. B_NEGATIVE " << endl ;
			    	cout << " 5. O_POSITIVE " << endl ;
			    	cout << " 6. O_NEGATIVE " << endl ;
			    	cout << " 7. AB_POSITIVE " << endl ;
			    	cout << " 8. AB_NEGATIVE " << endl ;
			    	cout << " ------------------------ " << endl ;
			    	cout << " Select blood group (1-8) : ";
			    	cin >> bgChoice ;
			    	
			    	if ( bgChoice >=1 && bgChoice <=8 )
			    	findPatientsByBloodGroup( static_cast <BloodGroup> (bgChoice-1) ) ;
			    	else cout << " Invalid Choice! " << endl ;
			    	
			    	break ;
				}	
				
			case 4:
			    {
			    	int patientID ;
			    	cout << " Enter patient ID: ";
			    	cin >> patientID ;
			    	calculateBill(patientID) ;
			    	break ;
				}
				
			case 5:
			    {
			        generateHospitalReport() ;	
			        break ;
				}
				
			case 6:
			    {
			    	cout << " Exiting! " << endl ;
			    	break ;
				}	
				
			default:
			cout << " Invalid Choice! Choose between 1-6";				
		}
		 
		
	} while (choice != 6) ;
	return 0 ;
}

 // Function for adding details of new patient 
void addPatient ()
{
	if (patientCount > MAX_PATIENTS) 
	{
		cout << " No more space left in the hospital. " << endl ;
		return ;
	}
	
	Patient newPatient ;
	cout << " Enter patient ID: " ;
	cin >> newPatient.patientID ;
	cout << " Enter patient name: ";
	cin.ignore();
	getline ( cin,newPatient.name ) ;
	cout << " Enter patient age: ";
	cin >> newPatient.age ;
	int bg ;
	cout << " ----- Blood Groups ----- " << endl ;
	cout << " 1. A_POSITIVE " << endl ;
	cout << " 2. A_NEGATIVE " << endl ;
	cout << " 3. B_POSITIVE " << endl ;
	cout << " 4. B_NEGATIVE " << endl ;
	cout << " 5. O_POSITIVE " << endl ;
	cout << " 6. O_NEGATIVE " << endl ;
	cout << " 7. AB_POSITIVE " << endl ;
	cout << " 8. AB_NEGATIVE " << endl ;
	cout << " ------------------------ " << endl ;
	cout << " Select blood group (1-8) : ";
	cin >> bg ;
	if ( bg >=1 && bg <=8 )
	newPatient.bloodGroup = static_cast <BloodGroup> (bg-1) ;
	else cout << " Invalid Choice! " << endl ;
	cout << " Enter admission date (DD MM YYYY): " ;
	cin >> newPatient.admissionDate.day >> newPatient.admissionDate.month >> newPatient.admissionDate.year ;
	cout << " Enter discharge date (DD MM YYYY): " ;
	cin >> newPatient.dischargeDate.day >> newPatient.dischargeDate.month >> newPatient.dischargeDate.year ;
	newPatient.billAmount = 0.0 ;
	patient [patientCount] = newPatient ;
	patientCount++ ;
	cout << " Patient detail added successfully."<< endl ;
	cout << endl ;
}

// Function for displaying details in a table
void displayAllPatients () 
{
	if (patientCount > MAX_PATIENTS) 
	{
		cout << " No patient admitted." << endl ;
		return ;
	}
	
	cout << " ---------- Patient Details ---------- " << endl ;
	cout << setw(10) << "Patient ID" << setw(20) << "Name"
    << setw(10) << "Age" << setw(15) << "Blood Group"
    << setw(15) << "Bill Amount" << endl;
    
    for (int i=0 ; i<patientCount ; i++)
    {
    	cout << setw(10) << patient[i].patientID 
		<< setw(20)<< patient[i].name 
		<< setw(10)<< patient[i].age 
		<< setw(15)<< bloodGroupToString (patient[i].bloodGroup) 
		<< setw(15)<< fixed << setprecision(2) << patient[i].billAmount  << endl ; 
	}
	cout << endl ;
}

// Function for finding patient by blood group
void findPatientsByBloodGroup(BloodGroup bg)
{
	bool found = false ;
	cout << " Patients with blood group " << bloodGroupToString (bg) <<  ":-" << endl ;
	cout << setw(10) << "Patient ID" << setw(20) << "Name"
    << setw(10) << "Age" << setw(15) << "Blood Group"
    << setw(15) << "Bill Amount" << endl;
	
	for (int i=0 ; i<patientCount ; i++)
	{
		if (patient[i].bloodGroup == bg)
		{
			found = true ;
			cout << setw(10) << patient[i].patientID 
		    << setw(20)<< patient[i].name 
		    << setw(10)<< patient[i].age 
		    << setw(15)<< bloodGroupToString (patient[i].bloodGroup) 
		    << setw(15)<< fixed << setprecision(2) << patient[i].billAmount  << endl ; 
		}
		if (!found)
		cout << " No patient with this blood group found! " << endl ; 
		
		cout << endl ;
	}
}

// Function for calculating Stay duration
int stayDuration (Date admit, Date discharge)
{
	int days = (discharge.year - admit.year) * 365 +
	(discharge.month - admit.month) * 30 +
	(discharge.day - admit.day) ;
	
	return (days > 0) ? days:0 ;
}

// Function for Calculating Bill
void calculateBill(int patientID) 
{
	for (int i = 0; i < patientCount; i++)
	{
		if (patientID == patient[i].patientID)
	{
	int stayDays = stayDuration (patient[i].admissionDate, patient[i].dischargeDate) ;
	double bill = 0.0 ;
	if (stayDays <= 5)
	{
		bill = stayDays * 2000 ;
	}
	else if (stayDays <= 10)
	{
		bill = 5 * 2000 + (stayDays - 5) * 1500 ;
	}
	else
	{
		bill = 5 * 2000 + 5 * 1500 + (stayDays - 10) * 1000 ;
	}
	patient[i].billAmount = bill ;
	cout << "------- Bill Receipt -------" << endl ;
	cout << " Stay Duration: " << stayDays << " days" << endl ;
	cout << " Total bill : Rs. " << fixed << setprecision(2) << bill << endl ; 
	return ;
	}
	} 
	
	cout << " Patient not found." << endl ;
	cout << endl ;
}

// Function for Generating Hospital Report
void generateHospitalReport() 
{
	int highBill = 0 ;
	double totalRevenue ;
	for (int i=0 ; i<patientCount ; i++)
	{
		if (patient[i].billAmount > 5000)
		{
			highBill++ ;
		}
		totalRevenue += patient[i].billAmount ;
	}
	cout << "-------- Hospital Report --------" << endl ;
	cout << " Total Revenue: " << fixed << setprecision(2) << totalRevenue << endl ;
	cout << " Total Patients: " << patientCount << endl ;
	cout << " Total Patients with bill > 5000: " << highBill << endl ;	
		
	if (highBill > 0)
	{
		cout << " ---- High bills Patients ---- " << endl ;
		cout << setw(10) << "Patient ID" << setw(20) << "Name" << setw(15) << "Bill Amount" << endl;
		for (int i=0 ; i<patientCount ; i++)
		cout << setw(10) << patient[i].name 
		     << setw(20) << patient[i].billAmount << setw(15) << endl ; 
	}	
	cout << endl ;
} 

string bloodGroupToString (BloodGroup bg) 
{
	switch (bg)
	{
		case A_POSITIVE : return "A+" ;
		case A_NEGATIVE : return "A-" ;
		case B_POSITIVE : return "B+" ;
		case B_NEGATIVE : return "B-" ;
		case O_POSITIVE : return "O+" ;
		case O_NEGATIVE : return "O-" ;
		case AB_POSITIVE : return "AB+" ;
		case AB_NEGATIVE : return "AB-" ;
		default: return "UNKNOWN" ;
	}
}

