#include <iostream>
#include <fstream> // for File I/O
#include <iomanip> // for setprecision ()
#include <cstdlib> // for exit (1)
#include <climits> // for INT_MIN  
using namespace std ;

int main ()
{
	int Low = 0 , Medium = 0 , High = 0 , day = 0 , high_day = 0 ;
	int Small_truck = 0 , Medium_truck = 0 , Large_truck = 0 ;
	double value = 0.0 , total = 0.0 , average = 0.0 , high = INT_MIN ;   
	
	// Reading the file
	ifstream inFile ;
	inFile.open ("waste_data.txt") ;
	if (inFile)
	{
		while (inFile >> value)
		{
			day++ ;
			total += value ;
			
			// Categorizing waste generation
			if (value < 50)
			{
				Low++ ;
			}
			
			else if (value <= 100) 
			{
				Medium++ ;
			}
			
			else
			{
				High++ ;
			}
			
			// Optimizing truck allocation
			if (value < 30)
			{
				Small_truck++ ;
			}
			
			else if (value <= 70) 
			{
				Medium_truck++ ;
			}
			
			else
			{
				Large_truck++ ;
			}
			
			
			// Calculating high-generation days 
			if (value > high)
			{
				high = value ;
				high_day = day ;
			}
			
		}
		// Calculating average weekly patterns
		average = total / 7.0 ;
		
	}
	else
	{
		cout << " Error reading the file! " ;
		exit (1) ;
	}
	
	inFile.close() ;
	
	// Writing the report to the file
	ofstream outFile ;
	outFile.open("waste_data_report.txt") ;
	if (outFile)
	{
		outFile << "------------------------------------ WASTE MANAGEMENT REPORT ----------------------------------" << endl ;
		outFile << " Weekly Average: " << fixed << setprecision(2) << average << endl ;
		outFile << " High-generation : " << fixed << setprecision(2) << high << " on Day-" << high_day << endl ;
		outFile << " Waste generation distribution across categories:- " << endl ;
		outFile << " Low: " << Low << endl ;
		outFile << " Medium: " << Medium << endl ;
		outFile << " High: " << High << endl ;
		outFile << "      ============================ Truck Allocation Summary ============================= " << endl ;
		outFile << " Small truck required (Days): " << Small_truck << endl ;
		outFile << " Medium truck required (Days): " << Medium_truck << endl ;
		outFile << " Large truck required (Days): " << Large_truck << endl ;
		outFile << "      ========================== Waste Management Recommendations ======================= " << endl ;
		if (average < 50 )
		{
			outFile<<" Low generation: Maintain regular waste collection and promote recycling to keep waste levels under control. "<< endl;
		}
		else if (average <= 100)
		{
			outFile << " Medium generation: Increase collection frequency and strengthen recycling and segregation programs " << endl; 
			outFile << " to manage rising waste. " << endl ;
		}
		else
		{
			outFile << " High generation: Implement urgent waste reduction strategies, expand disposal facilities, and "<< endl;
			outFile << " enforce strict recycling and treatment measures. " << endl ;
		}
 
		outFile << "-------------------------------------------------------------------------------------------" << endl ;
	}
	else
	{
		cout << " Error creating the file! " ;
		exit (1) ;
	}
	outFile.close() ;
	
	// Displaying the report
	    cout << "------------------------------------ WASTE MANAGEMENT REPORT ----------------------------------" << endl ;
		cout << " Weekly Average: " << fixed << setprecision(2) << average << endl ;
		cout << " High-generation : " << fixed << setprecision(2) << high << " on Day-" << high_day << endl ;
		cout << " Waste generation distribution across categories:- " << endl ;
		cout << " Low: " << Low << endl ;
		cout << " Medium: " << Medium << endl ;
		cout << " High: " << High << endl ;
		cout << "      ============================ Truck Allocation Summary ============================= " << endl ;
		cout << " Small truck required (Days): " << Small_truck << endl ;
		cout << " Medium truck required (Days): " << Medium_truck << endl ;
		cout << " Large truck required (Days): " << Large_truck << endl ;
		cout << "      ========================== Waste Management Recommendations ======================= " << endl ;
	if (average < 50)
		{
			cout << " Low generation: Maintain regular waste collection and promote recycling to keep waste levels under control. " << endl;
		}
		else if (average <= 100)
		{
			cout << " Medium generation: Increase collection frequency and strengthen recycling and segregation programs to manage " << endl; 
			cout << " rising waste. " << endl ;
		}
		else
		{
			cout << " High generation: Implement urgent waste reduction strategies, expand disposal facilities, and enforce strict "<< endl;
			cout << " recycling and treatment measures. " << endl ;
		}   
	cout << "-------------------------------------------------------------------------------------------" << endl ;
	
	return 0 ;
}


