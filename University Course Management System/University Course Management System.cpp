#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std ;

// Inline function
inline bool isAdvancedCourse(int creditHours)
{
	return (creditHours >= 4) ;
}

// Overloaded Functions
double calculateCourseWorkload(double credit_hours , double difficulty_factor)
{
	return (credit_hours * difficulty_factor) ;
}

double calculateCourseWorkload(double credit_hours , double difficulty_factor, double lab_requirement_multiplier)
{
	return (credit_hours * difficulty_factor * lab_requirement_multiplier) ;
}

// Recursive Function
int calculateFactorial(int n)
{
	if (n <= 1) return 1;
	return (n * calculateFactorial(n-1)) ;
}

// Categorizing Courses
int categorizeCourse(int creditHours,int &introductoryCount, int &intermediateCount, int &advancedCount)
{
	if (creditHours >=1  && creditHours <=2 ) 
	{
		introductoryCount++;
		cout << " Category: Introductory Course " << endl ;
	}
	else if (creditHours <= 3) 
	{
		intermediateCount++;
		cout << " Category: Intermediate Course " << endl ;
	}
	else
	{
		advancedCount++;
		cout << " Category: Advanced Course " << endl ;
	}
}

// Reading course data from file
int readCourseData(int &total_of_courses, int &introductoryCount, int &intermediateCount, int &advancedCount)
{
	int courseCount = 0 ;
	total_of_courses = 0 ;
	ifstream inFile ;
	inFile.open("courses.txt") ;
	if (inFile)
	{
		int creditHours ;
		while (inFile >> creditHours)
		{
			courseCount++ ;
			total_of_courses += creditHours ;
			categorizeCourse(creditHours,introductoryCount, intermediateCount, advancedCount) ;
		}
	}
	else
	{
		cout << " Error: Could not read the file! " ;
		exit (1) ;
	}   
	inFile.close() ; 
	return courseCount;                                                                                                                                                                                                                                                        
}

// Calculating Average
double calculateAverageCredits(int &total_of_courses, int courseCount) 
{
	return static_cast <double>(total_of_courses)/courseCount ;
}

int main ()
{
	int introductoryCount = 0, intermediateCount = 0, advancedCount = 0, total_of_courses = 0, value; 
	int courseCount = readCourseData(total_of_courses, introductoryCount, intermediateCount, advancedCount) ;
	double total_average = calculateAverageCredits(total_of_courses, courseCount) ;
	
	// Displaying Report
	cout << " ------ UNIVERSITY COURSE MANAGEMENT SYSTEM ------ " << endl;
	cout << " Total No. of Courses: " << courseCount << endl ;
	cout << " Total Average Credits: " << fixed << setprecision(2) << total_average << endl ;
	cout << " Courses Categories: " << endl ;
	cout << " Introductory: 1-2 credit hours: " << introductoryCount << endl ;
	cout << " Intermediate: 3 credit hours: " << intermediateCount << endl ;
	cout << " Advanced: 4+ credit hours: " << advancedCount << endl ;
	
	// Checking Inline function
	int creditHours = 0 ;
	cout << " Enter the credit hours to test: ";
	cin >> creditHours ;
	cout << " Is creditHours >= 4? "<< endl ;
	if (isAdvancedCourse(creditHours)) cout << " YES " << endl ;
	else cout << " NO " << endl ;
	
	// Checking Overloded Functions
	cout << " Checking course workload:- " << endl ;
	cout << " Course workload (standard): " << calculateCourseWorkload(4 , 8) << endl ;
	cout << " Course workload (difficult): " << calculateCourseWorkload(5,10.8,13) << endl ;
	
	// Testing factorial
	int n ;
	cout << " Enter the number for factorial: ";
	cin >> n ;
	cout << " Factorial of "<< n << " is " << calculateFactorial(n) ;

    return 0 ;	
}


