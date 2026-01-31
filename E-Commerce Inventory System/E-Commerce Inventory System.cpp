#include <iostream>
#include <fstream> // for file handling
#include <string> // for strings
#include <sstream> // for stringstream
#include <iomanip> // for setw()
#include <cstdlib> // for exit(1)
#include <climits> // for INT_MIN
using namespace std ;

// Declaring Structure
struct Product{
	int productID;
	string name;
	string category;
	double price;
	int quantity;
	int reorderLevel;
};

const int MAX_PRD = 50 ;
Product products [MAX_PRD] ;
int productCount = 0 ;

// Function Prototypes
void readProductsFromFile(string filename) ;
void sellProduct(int productID, int quantity) ; 
void displayAllProducts(Product arr[], int size) ;
void findMostExpensiveProduct(Product arr[], int size) ;
void writeInventoryReport(string filename, Product arr[], int size) ;

int main ()
{
	int choice, productID, quantity ;
	do{ // Displaying Menu
		cout << " ======== E-commerce Inventory System ======== " << endl ;
		cout << " 1. Read products from file. " << endl ;
		cout << " 2. Display all the products. " << endl ;
		cout << " 3. Sell a product " << endl ;
		cout << " 4. Find most expensive product. " << endl ;
		cout << " 5. Generate inventory report. " << endl ;
		cout << " 6. Exit " << endl ;
		cout << " ============================================= " << endl ;
		cout << endl ;
		cout << " Enter your choice (1-6): ";
		cin >> choice ;
		switch (choice)
		{
			case 1:
				{
					readProductsFromFile("inventory.txt") ;
					break ;
				}
			case 2:
				{
					displayAllProducts(products, productCount) ;
					break ;
				}
			case 3:
				{
					cout << " Enter product ID: ";
	                cin >> productID ;
	                cout << " Enter product quantity: ";
	                cin >> quantity;
					sellProduct(productID, quantity) ; 
					break ;
				}
			case 4:
				{
					findMostExpensiveProduct(products, productCount) ;
					break ;
				}
			case 5:
				{
					writeInventoryReport("inventory_report.txt",products, productCount ) ;
					break ;
				}
			case 6:
				{
					cout << " Exiting...." << endl ;
					break ;
				}
			default:
			    {
			    	cout << " Invalid choice! Choose between 1-6." << endl ;
				}						
		}
		
		
	} while (choice != 6 ) ;
	return 0 ;
}

// Function for reading data from file
void readProductsFromFile(string filename) 
{
	ifstream inFile ;
	inFile.open(filename) ;
	if (inFile)
	{
		string temp;
		Product p ;
		productCount = 0 ;
		string line ;
		
		while (getline (inFile, line)) {
			if (line == "")
			continue ;
			
			stringstream ss (line) ; 
			
			getline(ss, temp, ',') ;
			p.productID = stoi(temp);
			
			getline(ss, p.name,',') ;
			
			getline(ss, p.category,',') ;
			
			getline(ss , temp,',') ;
			p.price = stod(temp) ;
			
			getline(ss, temp,',') ;
			p.quantity = stoi(temp);
			
			getline(ss, temp) ;
			p.reorderLevel = stoi(temp);
			
			products[productCount] = p ;
			
			productCount++ ;
		}
		cout << " Data read successfully! ";
	}
	
	else
	{
		cout << " Error! Could not read the file.";
		exit (1) ;
	}
	inFile.close();
	cout << endl ;
}

// Function for displaying products
void displayAllProducts(Product arr[], int size) 
{
	cout << "-------------------------------------------------------------"
	        "----------------------------------" << endl ;
	cout << setw(10) << "Product ID" 
	     << setw(20) << "Product Name" 
	     << setw(15) << "Category"
	     << setw(15) << "Price"
	     << setw(15) << "Quantity"
	     << setw(20) << "Reorder level" << endl ;
    cout << "-------------------------------------------------------------"
	        "----------------------------------" << endl ;
	     
	for (int i=0 ; i<productCount ; i++)
	{
		cout << setw(8) << products[i].productID 
	         << setw(18) << products[i].name 
	         << setw(20) << products[i].category
	         << setw(14) << products[i].price
	         << setw(12) << products[i].quantity
	         << setw(15) << products[i].reorderLevel << endl ;
	}     
	cout << endl ;
}

// Function for selling product
void sellProduct(int productID, int quantity) 
{
	bool found = false ; 
	double totalSale ;
	for ( int i=0 ; i<productCount ; i++ )
	{
		if ( productID == products[i].productID )
		{
			found = true ;
			if (products[i].quantity >= quantity)
			{
				products[i].quantity -= quantity ;
			    totalSale = quantity * products[i].price ;
			    cout << " Total Sale Amount: Rs. " << totalSale << endl ;
			    
			if (products[i].quantity <= products[i].reorderLevel)
			{
				cout << " REORDER NEEDED" << endl ;
			}
			    
			}
			else {
				cout << " Insufficient Stock." << endl;
			}
			return ;
		}
	}
	if (!found) 
	{
		cout << " Product ID not found. " << endl ;
	}
	cout << endl ;
}

// Function for finding most expensive product
void findMostExpensiveProduct(Product arr[], int size) 
{
	string expensiveProduct ;
	int expensive = INT_MIN ;
	for (int i=0 ; i<productCount ; i++)
	{
		if ( products[i].price > expensive )
		{
			expensive = products[i].price;
			expensiveProduct = products[i].name ;
		}
	}
	cout << " Most Expensive Product : " << expensiveProduct << " (Rs. " << expensive <<")"<< endl ;
	cout << endl ;
}

// Function for writing report in file
void writeInventoryReport(string filename, Product arr[], int size)
{
	double totalValue = 0 ;
	int belowReorder = 0 ;
	int expensive = INT_MIN ;
	string expensiveProduct ;
	
	for (int i=0 ; i < productCount ; i++)
	{
		totalValue += products[i].price ;
		if (products[i].quantity <= products[i].reorderLevel) belowReorder++ ;
		if ( products[i].price > expensive )
		{
			expensive = products[i].price;
			expensiveProduct = products[i].name ;
		}
	} 
	
	ofstream outFile ;
	outFile.open (filename) ;
	if (outFile)
	{
		outFile << " ======== Inventory Report ======== " << endl ;
	    outFile << " Total Products: " << productCount << endl ;
	    outFile << " Total Inventory Value: " << totalValue << endl ;
	    outFile << " Products Below Reorder Level: " << belowReorder << endl ;
	    outFile << " Most Expensive Product: " << expensiveProduct << endl ;
	}
	else
	{
		cout << " Error! Could not open the file.";
		exit (1) ;
	}
    outFile.close();
    cout << " Data successfully written to " << filename << endl ;
    cout << endl ;
}

