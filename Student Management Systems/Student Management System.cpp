// STUDENT MANAGEMENT SYSTEM

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib> // for exit ()
using namespace std ;

const int MAX_STUDENTS = 100 ;

// Function for adding student record
void addStudentToFile (string name, double GPA)
{
    cout << "\n--- Add New Student ---\n";
    cout << " Enter the student name: " ;
    cin.ignore() ;
    getline(cin,name) ;
    cout << " Enter your GPA (0.0-4.0): " ;
    cin >> GPA ;
    cin.ignore() ;
    
    // Validation for GPA
    while ( GPA < 0.0 || GPA > 4.0 )
    {
       cout << " Invalid!Enter again :";
       cin >> GPA ;
    }
    // Writing to a file
    ofstream outFile ;
    outFile.open ("students.txt",ios::app) ;
    if (outFile)
    {
       outFile << name << endl ;
       outFile << GPA << endl ;
    }
    else  // Error handling
    {
       cout << " Error could not open the file!" ;
       exit (1) ;
    }
    outFile.close() ;
    cout << " Data added sucessfully!" << endl ;
}

// Function for displaying student data
void displayAllStudents(string name,double GPA)
{
    cout<<"----ALL STUDENT'S DATA----" << endl ;
    // Reading from a file
    ifstream inFile;
    inFile.open("students.txt");
    if (inFile)
    {
    	while (getline(inFile, name))
            {
            inFile >> GPA ;
            inFile.ignore() ;
            // Displaying on the console
            cout << " Name: " << name << ", GPA: " << GPA << endl ;
            }
    }
    else
    {   // Error handling
        cout << "Error reading the file!";
        exit (1) ;
    }
    inFile.close() ;
}

// Function for loading data into memory
void loadStudentsIntoArray( string names[] , double GPAs[], int& stdCount )
{  
    string name ;
	double GPA ;
	stdCount = 0 ;
    ifstream inFile;
    inFile.open("students.txt");
    if (inFile)
    {
         while (getline(inFile, name) && stdCount < MAX_STUDENTS)
            {
            inFile >> GPA ;
            inFile.ignore() ;
           
            names[stdCount] = name ;
            GPAs [stdCount] = GPA ;
           
            stdCount++ ;
            }
    }
    else
    {
        cout << "Error reading the file!";
        exit (1) ;
    }
    inFile.close() ;
    cout << " Loaded " << stdCount << " students into the memory." << endl ;
}

// Function for searching a student's data by name
void searchStudent( string searchSTD , string names[] , double GPAs[] , int stdCount )
{
	if (stdCount == 0) // Validation to check if there is no student data.
	{
		cout << " No students loaded into the memory. Please load the data first." << endl ;
		return ;
	}
    cout << "----SEARCHING STUDENT----" << endl ;
    cout << " Enter the student to search: " ;
    cin.ignore() ;
    getline (cin,searchSTD) ;
    
    bool found = false ;
    // Linear Search
    for ( int i=0 ; i<stdCount ; i++ )
    {
        if ( names[i] == searchSTD )
        {
          cout << " Student Found! " << endl ;	
          cout << " Student Name: " << names[i] << endl ;
          cout << " Student GPA: " << GPAs[i] << endl ;
          found = true ;
          break ;
        }
    }
    if (!found)
        {
        	cout << " Student not found! " << endl ;
		}
}

// Function for displaying Students GPAs using pointers
void displayUsingPointers(double GPAs[] , int stdCount )
{
	if (stdCount == 0) // Validation to check if there is no student data.
	{
		cout << " No students loaded into the memory. Please load the data first." << endl ;
		return ;
	}
	double *ptr = GPAs ;
    cout << "----DISPLAYING GPAs----" << endl ;
    for ( int i=0 ; i<stdCount ; i++ )
    {
    	cout << "Student "<< i+1 << " GPA: " << *ptr << endl ;
    	ptr++ ;
	}
}

// Function for calculating the statistics
void calculateStats( double GPAs[], int stdCount, double &average, double &topGPA )
{ 
    if (stdCount == 0) // Validation to check if there is no student data.
	{
		cout << " No students loaded into the memory. Please load the data first." << endl ;
		average = 0.0;
        topGPA = 0.0;
		return ;
	}
	
    double sum = 0 ;
    topGPA = GPAs[0] ;
	for ( int i=0 ; i<stdCount ; i++ )
    {
    	sum += GPAs[i] ;
    	
    	if ( GPAs[i] > topGPA )
	   {
		  topGPA = GPAs[i] ;
	   }
	}
	average = sum / stdCount ;
	
	// Displaying Report on console
	cout << "-----AVERAGE & HIGHEST GPA----- " << endl ;
	cout << " Average GPA: " << fixed << setprecision(2) << average << endl ;
	cout << " Highest GPA: " << fixed << setprecision(2) << topGPA << endl ;
}

int main ()
{
    int stdCount = 0 ;
    string name , searchSTD ;
    double GPA ;
    string names[MAX_STUDENTS] ;
    double GPAs[MAX_STUDENTS] ;
    double average = 0 , topGPA ; 
    
	int choice ;
	do{   // MENU FOR STUDENT MANAGEMENT SYSTEM
		cout << " --- Student Management System ---" << endl ;
	    cout << " 1. Add a new student" << endl ;
	    cout << " 2. Display all students" << endl ;
	    cout << " 3. Load students into memory" << endl ;
	    cout << " 4. Search for a student by name" << endl ;
	    cout << " 5. Display statistics (Average GPA, Highest GPA)" << endl ;
	    cout << " 6. Display GPAs using pointers" << endl ;
	    cout << " 7. Exit" << endl ;
	    cout << " --------------------------------- " << endl ;
	    
	    cout << " Enter your choice (1-7): " ;
	    cin >> choice ;
	    
	    switch (choice)
	    {
	    	case 1 :
	    		addStudentToFile (name, GPA) ;
	    		break ;
	    		
	    	case 2 :
			    displayAllStudents(name, GPA) ;
				break ;
				
			case 3 :
			    loadStudentsIntoArray( names , GPAs, stdCount ) ;
	            break ;
				
			case 4 :
			    searchStudent( searchSTD , names , GPAs , stdCount ) ;	
			    break ;
			
			case 5 :
			    calculateStats( GPAs,stdCount, average, topGPA ) ;
				break ;
			
			case 6 :
			    displayUsingPointers( GPAs , stdCount ) ;
				break ;
				
			case 7 :
			    cout << " Exiting. GOODBYE! " << endl ;
				break ;
				
			default :
			    cout << " Invalid choice! Enter again" << endl ;			  
		}
	} while ( choice != 7 ) ;
	
	return 0 ;
}






