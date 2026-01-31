#include <iostream>
#include <string>
#include <iomanip> // for setprecision ()
using namespace std;

int main ()
{
	int choice = 0 ;
	int no_of_wings = 0 , wings_stock = 50 ;
	int no_of_dumplings = 0 , dumplings_stock = 50 ;
	int no_of_calzones = 0 , calzone_stock = 50 ;
	int no_of_pizza1 = 0 , pizza1_stock = 50 ;
	int no_of_pizza2 = 0 , pizza2_stock = 50 ;
	int no_of_pizza3 = 0 , pizza3_stock = 50 ;
	
	int dip = 0 ;
	int sauce = 0 ;
	int size1 = 0 ;
	int size2 = 0 ;
	int size3 = 0 ;
	int price_of_pizza1 = 0 ;
	int price_of_pizza2 = 0 ;
	int price_of_pizza3 = 0 ;
	string calzone_instruction ;
	
	// Displaying Menu
	cout << " Welcome to Cheezious! " << endl ;
	do{
		cout << " ================== MENU ==================" << endl ;
	    cout << endl ;
	    cout << "       --------- Starters --------- " << endl ;
	    cout << " 1. Crispy Wings (x6) : Rs.700 " << endl ;
	    cout << " 2. Dumplings (x4) : Rs.800 " << endl ;
	    cout << " 3. Calzone : Rs.1150" << endl ;
	    cout << endl ;
	    cout << "       ---------- Mains ----------  " << endl ;
	    cout << " 4. Pepperoni Pizza : Rs.1550" << endl ;
	    cout << " 5. Crown Crust Pizza : Rs.1550" << endl ;
	    cout << " 6. Chicken Fajita : Rs.690" << endl ;
	    cout << " 7. Place Order " << endl ;
	    cout << " ==========================================" << endl ;
	    cout << endl ;
	    
	    // Placing Order
	    cout << " =============== ORDER HERE ===============" << endl ;
	    cout << endl ;
	    cout << " Select your order choice (1-7) : " ;
	    cin >> choice ; 
	    
	    switch (choice)
	    {
	    	case 1:
	    		{
	    			cout << " How many wings do you want? : " ;
		            cin >> no_of_wings ;
		            // Managing Inventory
		            if ( no_of_wings <= wings_stock ) 
		            {
		            	wings_stock -= no_of_wings ;  
					}
					else 
					{
						cout << " Not enough wings in the stock. " << endl ;
						break ;
					}
		            cout << " -------- DIPS -------- " << endl ;
		            cout << " 1.Ranch " << endl ;
		            cout << " 2.Garlic Sauce " << endl ;
		            cout << " 3.Siracha Sauce " << endl ;
		            cout << " Select the dips you want (1-3) : " ;
		            cin >> dip ;
		            cout << endl ;
		            break ;
				}
			case 2:
			    {
			    	cout << " How many dumplings you want? : " ;
		            cin >> no_of_dumplings ;
		            // Managing Inventory
		            if ( no_of_dumplings <= dumplings_stock )
		            {
		            	dumplings_stock -= no_of_dumplings ;
					}
					else 
					{
						cout << " Not enough dumplings in the stock. " << endl ;
						break ;
					}
		            cout << " --------- SAUCES --------- " << endl ;
		            cout << " 1.Soy Garlic Sauce " << endl ;
		            cout << " 2.Chilli Oil " << endl ;
		            cout << " Select the dumpling sauce you want (1-2) : " ;
		            cin >> sauce ;
		            cout << endl ;
		            break ;
				}
			case 3:
			    {
			    	cout << " How many Calzones you want? : " ;
		            cin >> no_of_calzones ;
		            // Managing Inventory
		            if ( no_of_calzones <= calzone_stock )
		            {
		            	calzone_stock -= no_of_calzones ;
					}
					else 
					{
						cout << " Not enough calzones in the stock. " << endl ;
						break ;
					}
		            cout << " Any special instructions about calzone ? : " ; 
		            cin.ignore() ;
		            getline(cin, calzone_instruction) ;
		            cout << endl ;
		            break ;
				}		
			case 4:
			    {
			    	cout << " How many pizzas you want? : " ;
		            cin >> no_of_pizza1 ;
		            // Managing Inventory
		            if ( no_of_pizza1 <= pizza1_stock )
		            {
		            	pizza1_stock -= no_of_pizza1 ;
					}
					else 
					{
						cout << " Not enough Pepperoni Pizza's in the stock. " << endl ;
						break ;
					}
		            cout << " Select the size (1-3) : " << endl ;
		            cout << " 1.Small (10 inches) : Rs.1550 " << endl ;
		            cout << " 2.Medium (12 inches) : Rs.1750 " << endl ;
		            cout << " 3.Large (14 inches) : Rs.1950 " << endl ;
		            cout << " Size: " ;
		            cin >> size1 ;
		            if (size1 == 1)
		            {
		            	price_of_pizza1 = 1550 ;
		            }
		            else if (size1 == 2)
		            {
		            	price_of_pizza1 = 1750 ;
	            	}
		            else
		            {
		            	price_of_pizza1 = 1950 ;
	            	}
	            	cout << endl ;
	            	break ;
				}	
			case 5:
				{
					cout << " How many pizzas you want? : " ;
		            cin >> no_of_pizza2 ;
		            // Managing Inventory
		            if ( no_of_pizza2 <= pizza2_stock )
		            {
		            	pizza2_stock -= no_of_pizza2 ;
					}
					else 
					{
						cout << " Not enough Crown Crust Pizza's in the stock. " << endl ;
						break ;
					}
		            cout << " Select the size (1-3) : " << endl ;
		            cout << " 1.Small (10 inches) : Rs.1550 " << endl ;
		            cout << " 2.Medium (12 inches) : Rs.1750 " << endl ;
		            cout << " 3.Large (14 inches) : Rs.1950 " << endl ;
		            cout << " Size: " ;
		            cin >> size2 ;
		            if (size2 == 1)
		            {
			            price_of_pizza2 = 1550 ;
	            	}
		            else if (size2 == 2)
		            {
			            price_of_pizza2 = 1750 ;
		            }
		            else
		            {
			            price_of_pizza2 = 1950 ;
		            }
		            cout << endl ;
		            break ;
				}
			case 6:
			    {
			    	cout << " How many pizzas you want? : " ;
		            cin >> no_of_pizza3 ;
		            // Managing Inventory
		            if ( no_of_pizza3 <= pizza3_stock )
		            {
		            	pizza3_stock -= no_of_pizza3 ;
					}
					else 
					{
						cout << " Not enough Chicken Fajita Pizza's in the stock. " << endl ;
						break ;
					}
		            cout << " Select the size (1-3) : " << endl ;
		            cout << " 1.Small (10 inches) : Rs.690 " << endl ;
		            cout << " 2.Medium (12 inches) : Rs.890 " << endl ;
		            cout << " 3.Large (14 inches) : Rs.1190 " << endl ;
		            cout << " Size: " ;
		            cin >> size3 ;
		            if (size3 == 1)
		            {
			           price_of_pizza3 = 690 ;
		            }
		            else if (size3 == 2)
		            {
			           price_of_pizza3 = 890 ;
		            }
		            else
		            {
			        price_of_pizza3 = 1190 ;
		            }
		            cout << endl ;
		            break ;
				}	
			case 7:
			    {
			    	cout << " Order placed successfully! " << endl ;
			    	break;
			    	cout << endl ;
				}
			default:
			    {
			    	cout << " Invalid choice! Choose between 1-7 " << endl ;
			    	cout << endl ;
				}		
		}
	    
	} while (choice != 7) ;
	
	// Billing Variables
	int price_of_wings = 700 , price_of_dumplings = 800 , price_of_calzone = 1150 ;
	const double tax_rate = 0.079 ;
	double wings = ( no_of_wings * price_of_wings ) ;
	double dumplings = ( no_of_dumplings * price_of_dumplings ) ;
	double calzone = ( no_of_calzones * price_of_calzone ) ;
	double pizza1 = ( no_of_pizza1 * price_of_pizza1 ) ;
	double pizza2 = ( no_of_pizza2 * price_of_pizza2 ) ;
	double pizza3 = ( no_of_pizza3 * price_of_pizza3 ) ;
	
	// Coupone Codes & Discounts
	double discount = 0 ;
	bool coupon = false , valid = false ;
	string entered_code ;
	
	cout << " Do you have any coupon ? ( Enter 1 for YES : 0 for NO ) : " ;
	cin >> coupon ;
	if ( coupon == true )
	{
		do{
			cout << " Enter the coupon code (ALL CAPS & NO SPACES): " ;
		    cin >> entered_code ;
		
		if ( entered_code == "DISCOUNT10")
		{
			valid = true ;
			cout << " CONGRATS! You will avail 10% discount on your order. " << endl ;
			discount = 0.90 ;
			cout << endl ;
		}
		
		else if ( entered_code == "DISCOUNT20")
		{
			valid = true ;
			cout << " CONGRATS! You will avail 20% discount on your order. " << endl ;
			discount = 0.80 ;
			cout << endl ;
		}
		
		else if ( entered_code == "DISCOUNT30")
		{
			valid = true ;
			cout << " CONGRATS! You will avail 30% discount on your order. " << endl ;
			discount = 0.70 ;
			cout << endl ;
		}
		
		else
		{
			cout << " INVALID CODE! " << endl ;
		}
			
		} while (valid!=true) ;
	}
	
	// Billing Logic
	double subtotal = wings + dumplings + calzone + pizza1 + pizza2 + pizza3 ;
	double tax = subtotal * tax_rate ;
	double final_total = subtotal + tax ;
	double discounted_total = final_total * discount ;
	
	// Bill Receipt
	cout << "============== BILL RECEIPT ===============" << endl ;
	cout << endl ;
	cout << " Subtotal : Rs." << fixed << setprecision(2) << subtotal << endl ;
	cout << " Final Total : Rs." << fixed << setprecision(2) <<  final_total << endl ;
	cout << " Discounted Total : Rs." << fixed << setprecision(2) << discounted_total << endl ;
	cout << " Tax : Rs."  << fixed << setprecision(2) << tax << endl ;
	
	return 0;
}
