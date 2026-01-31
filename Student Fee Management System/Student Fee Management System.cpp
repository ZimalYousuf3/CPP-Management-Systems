#include <iostream> 
#include <fstream> // for file handling
#include <string>  // for strings
#include <sstream> // for stringstream
#include <iomanip> // for setprecision
#include <climits> // for INT_MIN
#include <cstdlib> // for exit()

using namespace std ;

// Structure Declaration
struct Student {
	int studentID;
	string name;
	string department;
	double totalFee;
	double feePaid;
	double dueFee;
}; 

// Structure array declaration
const int MAX_STUDENTS = 100 ;
Student student[MAX_STUDENTS] ;
int stdCount = 0 ;

// Function Prototypes
void readStudentsFromFile(string filename);
void displayAllStudents(Student arr[], int size);
void payFee(int studentID, double amount);
void findHighestDueFeeStudent(Student arr[], int size);
void writeFeeReport(string filename, Student arr[], int size);

int main ()
{
	int choice;
	do{  // Displaying Menu
		cout << " ================= STUDENT FEE MANAGEMENT SYSTEM =============== " << endl ;
		cout << " 1. Read student data from file " << endl ;
		cout << " 2. Display all students " << endl ;
		cout << " 3. Pay student fee " << endl ;
		cout << " 4. Find student with highest due fee " << endl ;
		cout << " 5. Generate fee report " << endl ;
		cout << " 6. Exit " << endl ;
		cout << " =============================================================== " << endl ;
		cout << " Enter your choice (1-6): ";
		cin >> choice ;
		cout << endl ;
		
		switch (choice)
		{
			case 1:
				{
					readStudentsFromFile("studentsNew.txt");
					break ;
				}
				
			case 2:
				{
					displayAllStudents(student, stdCount);
					break ;
				}
				
			case 3:
				{
					int studentID ;
					double amount ;
					
					cout << " Enter student ID: ";
					cin >> studentID ;
					
					cout << " Enter the amount: " ;
					cin >> amount ;
					
					payFee(studentID, amount);
					break ;
				}
				
			case 4:
				{	
					findHighestDueFeeStudent(student, stdCount);
					break ;
				}
				
			case 5:
				{
					writeFeeReport("studentReport.txt", student, stdCount);
					break ;
				}
				
			case 6:
				{
					cout << " Exiting.... " << endl ;
					break ;
				}
				
			default:
			    {
			    	cout << " Invalid Choice: Try Again!" << endl ;
				}						
		}
		
	} while (choice != 6) ;
	
	return 0 ;
}

// Function for reading student data
void readStudentsFromFile(string filename)
{
	ifstream inFile ;
	inFile.open(filename) ;
	if (inFile)
	{
		string line, temp ;
		Student std ;
		stdCount = 0 ;
		
		while (getline (inFile, line))
		{
			if (line == "") continue ;
			
			stringstream ss (line) ;
			
			getline (ss, temp, ',') ;
			std.studentID = stoi(temp) ;
			
			getline (ss, std.name, ',') ; 
			
			getline (ss, std.department, ',') ;
			
			getline (ss, temp, ',') ;
			std.totalFee = stod(temp) ;
			
			getline (ss, temp) ;
			std.feePaid = stod(temp) ;	
			
			std.dueFee = std.totalFee - std.feePaid ;
			
			student [stdCount] = std ;
			stdCount ++ ;
		}
	    cout << " Data read successfully from studentsNew.txt " << endl ;	
	} 
	
	else
	{
		cout << " Error: Could'nt read from the file! " << endl ;
		exit (1) ;
	}
	inFile.close() ;
	cout << endl ;
}

// Function for displaying the records
void displayAllStudents(Student arr[], int size)
{
	cout << " --------------------------------- Students Record -------------------------------- " << endl ;
	cout << setw(5) <<"ID" << setw(15) << "Name" 
	     << setw(15) << "Department" << setw(15) << "Total Fee" 
	     << setw(15) << "Fee Paid" << setw(15) << "Due Fee" << endl ;
	cout << " ---------------------------------------------------------------------------------- " << endl ;     
	     
	for (int i = 0 ; i < stdCount ; i++)
	{
		cout << setw(5) << student[i].studentID << setw(15) << student[i].name 
	     << setw(15) << student[i].department << setw(15) << student[i].totalFee 
	     << setw(15) << student[i].feePaid << setw(15) << student[i].dueFee << endl ;
	}
	cout << " ---------------------------------------------------------------------------------- " << endl ;
	cout << endl ;
}

// Funtion for paying fee 
void payFee(int studentID, double amount)
{
	bool found = false ;
	for (int i = 0 ; i < stdCount ; i++)
	{
		if (student[i].studentID == studentID)
		{
			found = true ;
			student[i].feePaid += amount ;
			cout << " Fee Paid Successfully " << endl ;
			
			student[i].dueFee = student[i].totalFee - student[i].feePaid ;
			
			if (student[i].dueFee > 0)
			{
				cout << " Fee Remaining " << endl ;
			}
			if (student[i].dueFee == 0)
			{
				cout << " Fee Cleared " << endl ;
			}
			
			return ;
		}
	}
	if (!found)
		{
			cout << " Student with this ID not found!" << endl ;
		}
	cout << endl ;
}

// Function for finding highest due fee student
void findHighestDueFeeStudent(Student arr[], int size)
{
	double highest = INT_MIN ;
	string highest_due_fee_std_name ;
	int highest_due_fee_std_ID ; 
	
	for (int i = 0 ; i < stdCount ; i++)
	{
		if (student[i].dueFee > highest)
		{
			highest = student[i].dueFee ;
			highest_due_fee_std_ID = student[i].studentID ;
			highest_due_fee_std_name = student[i].name ;
		}
	}
	cout << " Highest Due fee student:- " << endl ;
	cout << " Student Name: " << highest_due_fee_std_name << endl ;
	cout << " Student ID: " << highest_due_fee_std_ID << endl ;
	cout << " Due Fee: Rs." << highest << endl ;
	cout << endl ;
}

// Function for Writing Fee Report
void writeFeeReport(string filename, Student arr[], int size)
{
	double totalFee = 0.0 ;
	int pendingFeeCount = 0 ;
	double highest = INT_MIN ;
	string highest_due_fee_std_name ;
	
	for (int i = 0 ; i < stdCount ; i++)
	{
		totalFee += student[i].feePaid ;
		if (student[i].dueFee > 0)
		{
			pendingFeeCount++ ;
		}
		if (student[i].dueFee > highest)
		{
			highest = student[i].dueFee ;
			highest_due_fee_std_name = student[i].name ;
		}
	}
	
	ofstream outFile ;
	outFile.open(filename) ;
	
	if (outFile) 
	{
		outFile << " ===== Fee Report ===== " << endl ;
		outFile << " Total Students: " << stdCount << endl ;
		outFile << " Total Fee Collected: " << totalFee << endl ;
		outFile << " Students With Pending Fee: " << pendingFeeCount << endl ;
		outFile << " Highest Due Fee Student: " << highest_due_fee_std_name << " (Rs. " << highest << ")" << endl ;
	}
	else 
	{
		cout << " Error: Could'nt write in the file! " << endl ;
		exit (1) ;
	}
	outFile.close() ;
	
	cout << " Fee Report successfully generated in studentReport.txt " << endl ;
	cout << endl ;
}





