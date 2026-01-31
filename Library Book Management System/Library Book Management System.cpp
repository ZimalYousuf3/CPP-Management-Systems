// LIBRARY BOOK MANAGEMENT SYSTEM

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std ;

// Inline function
inline bool isAntiqueBook(int publication_year)
{
	return (2025 - publication_year >= 50) ;
}

// Overloaded Functions
double calculateBookValue(double base_price , double condition_factor)
{
	return (base_price * condition_factor) ;
}

double calculateBookValue(double base_price , double condition_factor, double rarity_multiplier)
{
	return (base_price * condition_factor * rarity_multiplier) ;
}

// Recursive Function
int calculateFactorial(int n)
{
	if (n <= 1) return 1;
	return (n * calculateFactorial(n-1)) ;
}

// Categorizing Books
int categorizeBook(int publication_year, int &newCount, int &recentCount, int &classicCount )
{
	int age = 2025 - publication_year ;
	if (age <= 5) 
	{
		newCount++;
		cout << " Category: New " << endl ;
	}
	else if (age <= 20) 
	{
		recentCount++;
		cout << " Category: Recent " << endl ;
	}
	else
	{
		classicCount++;
		cout << " Category: Classic " << endl ;
	}
}

int readBookData(int &total_year_sum, int &newCount, int &recentCount, int &classicCount)
{
	int bookCount = 0 ;
	total_year_sum = 0 ;
	ifstream inFile ;
	inFile.open("books.txt") ;
	if (inFile)
	{
		int publication_year ;
		while (inFile >> publication_year)
		{
			bookCount++ ;
		    total_year_sum += publication_year ;
		    categorizeBook(publication_year, newCount, recentCount, classicCount ) ;
		}
	}
	else
	{
		cout << " Error: Could not read the file! " ;
		exit (1) ;
	}   
	inFile.close() ; 
	return bookCount;                                                                                                                                                                                                                                                        
}

// Calculating Average
double calculateAverageYear(int total_year_sum, int bookCount) 
{
	return static_cast <double>(total_year_sum)/bookCount ;
}

int main ()
{
	int newCount = 0, recentCount = 0, classicCount = 0 ,total_year_sum = 0 ,publication_year ;
	
	int bookCount = readBookData(total_year_sum, newCount, recentCount, classicCount) ;
	double total_average = calculateAverageYear(total_year_sum, bookCount) ;
	
	// Displaying Report
	cout << " ------ LIBRARY BOOK MANAGEMENT SYSTEM ------ " << endl;
	cout << " Total No. of Books: " << bookCount << endl ;
	cout << " Total Average of Books: " << fixed << setprecision(2) << total_average << endl ;
	cout << " Books Categories: " << endl ;
	cout << " New Books (0-5 years): " << recentCount << endl ;
	cout << " Recent Books (6-20 years): " << recentCount << endl ;
	cout << " Clasic Books (21+ years): " << classicCount << endl ;
	
	// Checking Inline function
	int testYear = 0 ;
	cout << " Enter the year to test the age: ";
	cin >> testYear ;
	cout << " Is publication year " << testYear << " an antique book? "<< endl ;
	if (isAntiqueBook(testYear)) cout << " YES " << endl ;
	else cout << " NO " << endl ;
	
	// Checking Overloded Functions
	cout << " Checking book value:- " << endl ;
	cout << " Book value (standard): " << calculateBookValue(100.5,0.8) << endl ;
	cout << " Book value (rare): " << calculateBookValue(25.45,13.3,3.0) << endl ;
	
	// Testing factorial
	int n ;
	cout << " Enter the number for factorial: ";
	cin >> n ;
	cout << " Factorial of "<< n << " is " << calculateFactorial(n) ;

    return 0 ;	
}


