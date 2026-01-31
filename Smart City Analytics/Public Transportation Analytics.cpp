#include <iostream>
#include <fstream> // for file handling
#include <iomanip> // for setprecision ()
#include <cstdlib> // for exit (1)
#include <climits> // for INT_MAX & INT_MIN
using namespace std;

 // Advanced Challenge Function
int suggestAdditionalVehicles(int passengers)
{
    int capacityPerVehicle = 1000;

    if (passengers <= 3000)
        return 0;
    else
        return (passengers - 3000) / capacityPerVehicle + 1;
}

int main()
{   // Declaring variables
    int totalDays = 0;
    int Light = 0, Moderate = 0, Heavy = 0;
    int peakDay = 0, day = 0;

    double value = 0.0, totalPassengers = 0.0, weeklyAverage = 0.0, monthlyAverage = 0.0 ;
    double maximum = INT_MIN;
    double minimum = INT_MAX;

 // Reading passenger load from file
    ifstream inFile;
    inFile.open("transportation.txt");

    if (inFile)
    {
        while (inFile >> value)
        {
            totalDays++;
            day++;
            totalPassengers += value;

            // Categorizing Passenger Load
            if (value < 1000)
                Light++;
            else if (value <= 3000)
                Moderate++;
            else
                Heavy++;

            // Finding Peak and Minimum
            if (value > maximum)
            {
                maximum = value;
                peakDay = day;
            }

            if (value < minimum)
                minimum = value;
        }

        weeklyAverage = totalPassengers / 7.0;
        monthlyAverage = totalPassengers / 30.0;
    }
    else
    {
        cout << "Error reading the file!" << endl;
        exit(1);
    }

    inFile.close();

    ofstream outFile;
    outFile.open("transportation_report.txt");

    if (outFile)
    {
        outFile << "--------------------------- PUBLIC TRANSPORTATION REPORT ---------------------------" << endl;
        outFile << " Total Days Recorded: " << totalDays << endl;
        outFile << " Total Passengers: " << fixed << setprecision(2) << totalPassengers << endl;
        outFile << " Weekly Average Passengers: " << weeklyAverage << endl;
        outFile << " Monthly Average Passengers: " << monthlyAverage << endl;
        outFile << " Peak Passenger Count: " << maximum << " (Day " << peakDay << ")" << endl;
        outFile << " Minimum Passenger Count: " << minimum << endl;

        outFile << " Passenger Load Distribution:" << endl;
        outFile << " Light Load Days: " << Light << endl;
        outFile << " Moderate Load Days: " << Moderate << endl;
        outFile << " Heavy Load Days: " << Heavy << endl;

        outFile << " ================= Vehicle Allocation Suggestion ================= " << endl;
        outFile << " Additional Vehicles Needed on Peak Day (Day " << peakDay << "): " ;
        outFile << suggestAdditionalVehicles(maximum) << endl;

        outFile << "------------------------------------------------------------------------------------" << endl;
    }
    else
    {
        cout << "Error creating report file!" << endl;
        exit(1);
    }

    outFile.close();

    // Displaying Report
    cout << "--------------------------- PUBLIC TRANSPORTATION REPORT ---------------------------" << endl;
    cout << " Total Days Recorded: " << totalDays << endl;
    cout << " Total Passengers: " << totalPassengers << endl;
    cout << " Weekly Average Passengers: " << weeklyAverage << endl;
    cout << " Monthly Average Passengers: " << monthlyAverage << endl;
    cout << " Peak Passenger Count: " << maximum << " (Day " << peakDay << ")" << endl;
    cout << " Minimum Passenger Count: " << minimum << endl;

    cout << " Passenger Load Distribution:" << endl;
    cout << " Light Load Days: " << Light << endl;
    cout << " Moderate Load Days: " << Moderate << endl;
    cout << " Heavy Load Days: " << Heavy << endl;

    cout << " Additional Vehicles Needed on Peak Day (Day " << peakDay << "): " ;
    cout << suggestAdditionalVehicles(maximum) << endl;

    cout << "------------------------------------------------------------------------------------" << endl;

    return 0;
}
