#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std ;

bool isValid_ID (string &ID)
{
	if (ID.length()!=6)
	{
		return false ;
	}
	
	else if (ID.substr(0,3) != "EMP")
	{
		return false ;
	}
	
	else {
		return true ;
	}
}

bool isValid_hoursWorked ( float &hours_worked)
{
	if ( hours_worked < 0 && hours_worked > 80)
	{
		return false ;
	}
}

bool isValid_hourlyWage ( float &hourly_wage)
{
	if ( hourly_wage < 15.00 && hourly_wage > 100.0 )
	{
		cout << " Invalid entry! Enter again : " ;
	}
}

double calculate_salary ( float hours_worked , float hourly_wage ) 
{
	if (hours_worked > 40)
	    {
		   return (hours_worked * (hourly_wage * 1.5)) ;
	    }
	else 
    	{
		   return (hours_worked * hourly_wage) ;
	    }
}
	
void addRecords( string name,string EMPID, float hours_worked, float hourly_wage )
{
	cout << " Enter name of employee: " ;
	cin >> name ;
		 
    while (true) 
	{
		cout << " Enter employee ID (e.g EMPXXX) : " ;
		cin >> EMPID ;
	     if ( isValid_ID (EMPID) == true )
	     {
			break ;
	     }
	     else
	     {
	     	cout << " Invalid ID ! " << endl ;
		 }
		
	}
						
    while (true)
	{
	 	
		cout << " Enter how many hours the employee works: " ;
		cin >> hours_worked ;
		 if (isValid_hoursWorked ( hours_worked ) )
		 {
		 	break ;
		 }
	     else
			{
			  cout << " Invalid entry! " ;
			}
	}
				
	while (true)
	{
		cout << " Enter the hourly wage of employee: $ " ;
		cin >> hourly_wage ;
		 if (isValid_hourlyWage ( hourly_wage ) )
		 {
		 	 break;
		 }
            
         else    
		   {
			  cout << " Invalid entry! " ;
		   }
    }
    
    double total_salary = calculate_salary(hours_worked , hourly_wage ) ; 
				
	ofstream outFile ;
	outFile.open("employees.txt" , ios::app) ;
		if (!outFile)
		    {
		    	cout << " Error! Cannot open the File." << endl ;
		    	exit (1) ;
			}
	cout << fixed << setprecision (2) ;			
	outFile << " Employee Name: " << name << endl ;
	outFile << " Employee ID: " << EMPID << endl ;
	outFile << " Hours Worked: " << hours_worked << endl ;
	outFile << " Hourly Wage:$ " << hourly_wage << endl ;
				
	outFile.close() ;
	cout << endl ;			
	cout << " Data saved successfuly in the file!" << endl ;
	cout << endl ;
	cout << " Total Salary of the employee : $ " << setprecision(2) << total_salary << endl ; 
	cout << endl ;
				
}

void viewRecords ()
{
	cout << " ---- EMPLOYEE RECORDS ---- " << endl ; ;
	ifstream inFile ;
	inFile.open("employees.txt", ios::app);
	if (!inFile)
	{
		cout << " Error reading the file ! " << endl ;
		exit (1) ;
	} 
	
	string line ;
	while (getline(inFile,line))
	cout << line << endl ;
	
	inFile.close() ;
}
	
int main ()
{
	string name , EMPID ;
	int choice  ;
	float hours_worked , hourly_wage ;
	cout << "-------MENU-------" << endl ;
	cout << " 1. Add new employee record. " << endl ;
	cout << " 2. View all saved records. " << endl ;
	cout << " 3. Save records to the file and exit. " << endl ;
	cout << endl ;
	
	do {
		cout << " Enter your choice: " ;
	    cin >> choice ;
		switch (choice)
	 {
		case 1 :
			addRecords( name, EMPID, hours_worked,  hourly_wage ) ;
			break ;
			
		case 2 :
		    viewRecords () ;
			cout << endl ;			
			break ;
		case 3 :
		{
			cout << " Records are saved to File ! Exiting  " << endl ;
		}
		   break ;	
		
		default :
			cout << " Invalid choice!" << endl ;
	 }
	} while (choice!=3) ;
	
	return 0 ;
}
