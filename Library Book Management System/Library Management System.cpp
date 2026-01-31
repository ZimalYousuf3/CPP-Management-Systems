#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std ;

// Enum declaration
enum BookCategory {
	FICTION, NON_FICTION, SCIENCE, COMPUTER, HISTORY, ISLAMIC
};

// Structure of Date
struct Date {
	int day ;
	int month ;
	int year ;
};

// Structure of Books
struct Book {
	int bookID ;
	string title ;
	string author ;
	BookCategory category ;
	Date issueDate ;
	Date returnDate ;
	double fineAmount ; 
};

// Array declaration
const int MAX_BOOKS = 50 ;
Book books [MAX_BOOKS] ;
int bookCount = 0 ;

// Function Prototypes
void addBook() ;
void displayAllBooks() ;
void findBooksByCategory(BookCategory cat) ;
int borrowDuration (Date issueDate, Date returnDate) ;
string bookToString (BookCategory cat) ;
void calculateFine(int bookID) ;
void generateLibraryReport() ;

int main ()
{
	int choice ;
	do{
		cout << "============== LIBRARY MANAGEMENT SYSTEM ==============" << endl ;
		cout << " 1. Add New Book. " << endl ;
		cout << " 2. Display all books. " << endl ;
		cout << " 3. Find BookS by Category. " << endl ;
		cout << " 4. Calculate Fine. " << endl ;
		cout << " 5. Generate Library Report. " << endl ;
		cout << " 6. Exit " << endl ;
		cout << "=======================================================" << endl ;
		cout << endl ;
		cout << " Enter your choice (1-6): " ;
		cin >> choice ;
		
		switch (choice)
		{
			case 1:
				{
					addBook() ;
					break ;
				}
			case 2:
				{
					displayAllBooks() ;
					break ;
				}
			case 3:
				{
					int catChoice ;
					cout << " -------- Categories -------- " << endl ;
					cout << " 1. FICTION " << endl ;
					cout << " 2. NON_FICTION " << endl ;
					cout << " 3. SCIENCE " << endl ;
					cout << " 4. COMPUTER " << endl ;
					cout << " 5. HISTORY " << endl ;
					cout << " 6. ISLAMIC " << endl ;
					cout << " ---------------------------- " << endl ;
					cout << " Select the category (1-6) : " ;
					cin >> catChoice ;
					if ( catChoice >= 1 && catChoice <= 6 )
					{
					    findBooksByCategory(static_cast <BookCategory> (catChoice-1)) ;	
					} 
					break ;
				}
			case 4:
				{
					int bookID ;
					cout << " Enter book ID: ";
					cin >> bookID ;
					calculateFine(bookID) ;
					break ;
				}
			case 5:
				{
					generateLibraryReport() ;
					break ;
				}
			case 6:
				{
					cout << " Exiting..." << endl ;
					break ;
				}
			default:
			    {
			    	cout << " Invalid Choice! Try again." << endl ;
				}						
		}
		
		
	} while (choice != 6 ) ;
	return 0 ;
}

// Function for adding books
void addBook()
{
	if (bookCount >= MAX_BOOKS)
	{
		cout << " Maximum books capacity reached!" << endl ;
		return ;
	}
	
	Book newBook ;
	cout << " Enter book ID: ";
	cin >> newBook.bookID ;
	cin.ignore() ;
	
	cout << " Enter book title: ";
	getline(cin, newBook.title) ;
	
	cout << " Enter book author: ";
	getline(cin, newBook.author) ;
	int cat ;
	cout << " ---- Categories ---- " << endl ;
	cout << " 1. FICTION " << endl ;
	cout << " 2. NON_FICTION " << endl ;
	cout << " 3. SCIENCE " << endl ;
	cout << " 4. COMPUTER " << endl ;
	cout << " 5. HISTORY " << endl ;
	cout << " 6. ISLAMIC " << endl ;
	cout << " -------------------- " << endl ;
	cout << " Select the category (1-6) : " ;
	cin >> cat ;
	if ( cat >= 1 && cat <= 6 )
	{
		newBook.category = static_cast <BookCategory> (cat-1) ;				
	}
	cout << " Enter book issue date DD MM YYYY: ";
	cin >> newBook.issueDate.day >> newBook.issueDate.month >> newBook.issueDate.year ;
	
	cout << " Enter book return date DD MM YYYY: ";
    cin >> newBook.returnDate.day >> newBook.returnDate.month >> newBook.returnDate.year ;
    
	newBook.fineAmount = 0.0 ;
	
	books [bookCount] = newBook ;
	bookCount++ ;
	cout << " Book added successfully! " << endl ;
	cout << endl ;
}

// Function for displaying the books
void displayAllBooks()
{
	if (bookCount == 0)
	{
		cout << " No books found to be displayed! " << endl ;
	}
	cout << "-------------- All Books --------------" << endl ;
	cout << setw(10) << "Book ID" << setw(12) << "Title" << setw(18) << "Author"
	     << setw(18) << "Category" << setw(20) << "Fine Amount" << endl ; 
	for (int i=0 ; i<bookCount ; i++)
	{
		cout << setw(10) << books[i].bookID << setw(15) << books[i].title << setw(20) << books[i].author 
		     << setw(15) << bookToString(books[i].category) << setw(15) << books[i].fineAmount << endl ;	  
	}
	cout << endl ;
}

// Function for finding book by category 
void findBooksByCategory(BookCategory catChoice) 
{
	bool found = false ;
	cout << " Books in category " << bookToString(catChoice) << ":-" << endl ;
	cout << setw(10) << "Book ID" << setw(15) << "Title" << setw(15) << "Author" << endl ; 
	for (int i=0 ; i<bookCount ; i++)
	{
		if (books[i].category == catChoice)
		{
			found = true ;
			cout << setw(10) << books[i].bookID << setw(15) << books[i].title << setw(15) << books[i].author << endl ;	
		}
    }	 
	if (!found)
	    {
	    	cout << " Books not found! " << endl ;
		}    
	cout << endl ;		
}


// Function for calculating borrow duration
int borrowDuration (Date issueDate, Date returnDate)
{
	int days = (returnDate.year - issueDate.year) * 365 + (returnDate.month - issueDate.month) * 30 + (returnDate.day - issueDate.day) ;
	return (days > 0)? days : 0 ; 
}

// Function for fine calculation
void calculateFine(int bookID) 
{
	for (int i=0 ; i<bookCount ; i++)
	{
		double fine ;
	if (books[i].bookID == bookID)
	{
		int borrowDays = borrowDuration (books[i].issueDate, books[i].returnDate) ;
		if (borrowDays <= 7)
		{
			fine = 0.0 ;
		}
		else if (borrowDays <= 14)
		{
			fine =   (borrowDays - 7) * 50 ;
		}
		else
		{
			fine = (7 * 50) + (borrowDays - 14) * 100 ;
		}
		books[i].fineAmount = fine ;
		
	cout << " Fine calculated successfully! " << endl ;
	cout << " Borrow Duration: " << borrowDays << " days" << endl ;
	cout << " Total Fine: " << fixed << setprecision (2) << fine << endl ;
	return ;
	}
	}
	cout << " Book not found!" << endl ;
	cout << endl ;
}

// Function for generating report
void generateLibraryReport() 
{
	double totalFine = 0.0 ;
	int highFineCount = 0 ;
	if (bookCount == 0)
	{
		cout << " No books record to generate record!" << endl ;
	}
	for (int i=0 ; i<bookCount ; i++)
	{
		totalFine += books[i].fineAmount ; 
		if (books[i].fineAmount > 2000){
			highFineCount ++ ;
		}
	}
	
	cout << " -------------- Library Report -------------- " << endl;
	cout << " Total No. of books:  " << bookCount << endl ;
	cout << " Total Fine calculated: " << totalFine <<  endl ;
	cout << " Books with High fine (fine > Rs. 2000) :-" << endl ;
	cout << setw(10) << "Book ID" << setw(15) << "Title" << setw(15) 
		 << setw(15) << "Fine Amount" << endl ; 
	if (highFineCount > 0)
	{
		for (int i=0 ; i<bookCount ; i++)
	{
		cout << setw(10) << books[i].bookID << setw(15) << books[i].title 
			 << setw(15) << books[i].fineAmount << endl ;	  
	}
	}
	cout << endl ;
}

// Function for changing book to string
string bookToString (BookCategory cat) 
{
	switch (cat)
	{
		case FICTION: return " Fiction " ;
		case NON_FICTION: return " Non Fiction " ;
		case SCIENCE: return " Science " ;
		case COMPUTER: return " Computer " ;
		case HISTORY: return " History " ;
		case ISLAMIC: return " Islamic " ;
		default: return " Invalid Choice! ";
	}
}

 

