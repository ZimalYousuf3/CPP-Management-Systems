#include <iostream>
#include <fstream> // for File I/O
#include <iomanip> // for setprecision ()
#include <cstdlib> // for exit (1)
#include <climits> // for INT_MIN & INT_MAX 
using namespace std ;

int main ()
{
	int totalPoints = 0 , Good = 0 , Moderate = 0 , Unhealthy = 0 ;
	double value = 0.0 , total = 0.0 , average = 0.0 , maximum = INT_MIN , minimum = INT_MAX ;   
	
	// Reading the file
	ifstream inFile ;
	inFile.open ("air_quality.txt") ;
	if (inFile)
	{
		while (inFile >> value)
		{
			totalPoints++ ;
			total += value ;
			
			// Categorizing Air Qualities
			if (value <= 35)
			{
				Good++ ;
			}
			
			else if (value <= 75) 
			{
				Moderate++ ;
			}
			
			else
			{
				Unhealthy++ ;
			}
			// Maximum and Minimum Air Qualities
			if (value > maximum)
			{
				maximum = value ;
			}
			if (value < minimum)
			{
				minimum = value ;
			}
		}
		// Calculating Average
		average = total / static_cast <double> (totalPoints) ;
		
	}
	else
	{
		cout << " Error reading the file! " ;
		exit (1) ;
	}
	
	inFile.close() ;
	
	// Writing the report to the file
	ofstream outFile ;
	outFile.open("air_quality_report.txt") ;
	if (outFile)
	{
		outFile << "------------------------------------ AIR QUALITY REPORT ----------------------------------" << endl ;
		outFile << " Total no. of air quality points: " << totalPoints << endl ;
		outFile << " Total : " << fixed << setprecision(2) << total << endl ;
		outFile << " Average Air Quality: " << fixed << setprecision(2) << average << endl ;
		outFile << " Maximum Air Quality: " << fixed << setprecision(2) << maximum << endl ;
		outFile << " Minimum Air Quality: " << fixed << setprecision(2) << minimum << endl ;
		outFile << " Air quality distribution across categories:- " << endl ;
		outFile << " Good Quality: " << Good << endl ;
		outFile << " Moderate Quality: " << Moderate << endl ;
		outFile << " Unhealthy Quality: " << Unhealthy << endl ;
		outFile << " ======================== Health Recommendations ======================= " << endl ;
		if (average <= 35)
		{
			outFile << " Air quality is clean, so it is safe to enjoy outdoor activities and normal daily routines. " << endl ;
		}
		else if (average <= 75)
		{
			outFile << " Air quality is Moderate. Sensitive individuals should limit prolonged outdoor exertion, " << endl ;
			outFile << " while others can continue activities with minor precautions. " << endl ;
		}
		else
		{
			outFile << " Air quality is very bad. Avoid outdoor activities, especially for children, " << endl ;
			outFile << " elderly, and people with respiratory problems, and stay indoors if possible. " << endl ;
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
	cout << "------------------------------------ AIR QUALITY REPORT ----------------------------------" << endl ;
	cout << " Total no. of air quality points: " << totalPoints << endl ;
	cout << " Total : " << fixed << setprecision(2) << total << endl ;
	cout << " Average Air Quality: " << fixed << setprecision(2) << average << endl ;
	cout << " Maximum Air Quality: " << fixed << setprecision(2) << maximum << endl ;
    cout << " Minimum Air Quality: " << fixed << setprecision(2) << minimum << endl ;
	cout << " Air quality distribution across categories:- " << endl ;
	cout << " Good Quality: " << Good << endl ;
	cout << " Moderate Quality: " << Moderate << endl ;
	cout << " Unhealthy Quality: " << Unhealthy << endl ;
	cout << " ======================== Health Recommendations ======================= " << endl ;
	if (average <= 35)
		{
			cout << " Air quality is clean, so it is safe to enjoy outdoor activities and normal daily routines. " << endl ;
		}
		else if (average <= 75)
		{
			cout << " Air quality is Moderate. Sensitive individuals should limit prolonged outdoor exertion, " << endl ;
			cout << " while others can continue activities with minor precautions. " << endl ;
		}
		else
		{
			cout << " Air quality is very bad. Avoid outdoor activities, especially for children, " << endl ;
			cout << " elderly, and people with respiratory problems, and stay indoors if possible. " << endl ;
		}   
	cout << "-------------------------------------------------------------------------------------------" << endl ;
	
	return 0 ;
}
