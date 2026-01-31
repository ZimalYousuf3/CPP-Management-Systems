#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std ;

// Function for calculating satisfaction level
char calculateSatisfactionLevel (float score)
{
	if(score >= 85) return 'A' ;
	else if(score >= 75) return 'B' ;
	else if(score >= 65) return 'C' ;
	else if(score >= 50) return 'D' ;
	else return 'F' ;
}

// Function for score validation
bool validScore (float score)
{
	return ( score >=0 && score <=100 ) ;
}

int main ()
{
	int choice , ID ;
	string name ;
	float score ;
	
	do{
		cout << " -------- CUSTOMER FEEDBACK RECORD SYSTEM -------- " << endl ;
		cout << " 1. Add customer record. " << endl ;
		cout << " 2. View customer record. " << endl ;
		cout << " 3. Save record to the file. " << endl ;
		cout << " 4. Exit " << endl ;
		cout << endl ;
		cout << " Enter your choice (1-4): " ;
		cin >> choice ;
		cout << endl ;
		
		switch (choice)
		{
			case 1:
				{
					cout << " ------- Add Record ------- " << endl ;
	                cout << " Customer Name: " ;
	                cin.ignore() ;
	                getline (cin, name) ;
	                cout << " Feedback ID: " ;
	                cin >> ID ;
	                do{
	                	cout << " Customer Satisfaction Score (0-100) : ";
	                	cin >> score ;
	                	if (!validScore(score))
	                	{
	                		cout << " Invalid Score! Enter again:" ;
	                		cin >> score ;
						}
					} while (!validScore(score)) ;
                    cout << endl ;
					break ;
				}
				
			case 2:
			    {
			    	if (name.empty())
			    	{
			    		cout << " No record found." << endl ;
					}
					else
					{ 
						cout << " ----- Viewing Record ----- " << endl ;
			    	    cout << " Customer Name: " << name << endl ;
	                    cout << " Feedback ID: " << ID << endl ;
	                    cout << " Customer Satisfaction Score : " << score << endl ;
	                    cout << " Customer Satisfaction Level: " << calculateSatisfactionLevel (score) << endl ;
	                    cout << endl ;
					}
			    	break ;
				}	
			case 3:	
			    {
			    	ofstream outFile ;
			    	outFile.open("customer.txt", ios::app) ;
					if (outFile)
					{
						outFile << " Name: " << name << " , ID: " << ID << endl ;
						outFile << ", Score: " << score << " , Satisfaction Level: " << calculateSatisfactionLevel (score) << endl ;
					} 
					else
					{
						cout << " Error! File not opened for writing." << endl ;
						return 1 ;
					}
					outFile.close() ;
					cout << " Record saved successfully." << endl ;
					cout << endl ;
					break ;
				}
			case 4:
			    {
			    	cout << " Exiting " << endl ;
			    	break ;
				}	
			default :
			    cout << " Invalid Choice! Choose between (1-4):" << endl ;
				cout << endl ;	
		}
	} while (choice != 4) ;
	return 0 ;
}

