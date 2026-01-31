#include <iostream>
using namespace std ;
int main()
{
	int vehicle_count , light_duration ;
	string time_of_day ;
	bool emergency_vehicle = false ;
	bool pedestrian_waiting = false ;
	
	cout << "   SMART TRAFFIC LIGHT SYSTEM   " << endl ;
	// Inputing data
	cout << " Enter the vehicle count : " ;
	cin >> vehicle_count ;
	cout << " Enter the time of the day (morning, afternoon, evening, night) : " ;
	cin >> time_of_day ;
	cout << " Is there any Emergency vehicle? ( 1 for YES & 0 for NO ) :  " ;
	cin >> emergency_vehicle ;
	cout << " Is there any pedestrian waiting? ( 1 for YES & 0 for NO ) :  " ;
	cin >> pedestrian_waiting ;
	
	// Scenarios
	if (emergency_vehicle)
	{
		cout << " Emergency Vehicle approaching! ; Extending green light duration to 60s " << endl ;
		light_duration = 60 ;
	}
	else if (vehicle_count == 0)
	{
		if(time_of_day == "night")
		{
			cout << " Yellow light for 5s " << endl ;
			light_duration = 5 ;
		}
		else
		{
			cout << " Yellow light for 10s " << endl ;
			light_duration = 10 ; 
		}
	}
	else if (vehicle_count <= 5)
	{
		cout << " LIGHT TRAFFIC : Extending green light to 20s " << endl ;
		light_duration = 20 ;
	}
	else if (vehicle_count <= 15)
	{
		cout << " Extending green light to 30s " << endl ;
		light_duration = 30 ;
	}
	else if (vehicle_count <= 25)
	{
		cout << " Extending green light to 40s " << endl ;
		light_duration = 40 ;
	}
	else if (vehicle_count <= 45)
	{
		cout << " HEAVY TRAFFIC : Extending green light to 45s " << endl ;
		light_duration = 45 ;
	}
	// Pedestrian Crossing
	if ( pedestrian_waiting && !emergency_vehicle )
	{
		cout << " Pedestrian Detected : 10s for crossing " << endl ;
		light_duration += 10 ;
	}
	// Rush Hour
	if ( time_of_day == "morning" || time_of_day == "evening" && vehicle_count <=10 )
	{
		cout << " Rush Hour : additional 20s " << endl ;
		light_duration += 20 ;
	}
	 cout << " Final Green Light duration " << light_duration << " seconds. " << endl ;
	return 0 ;
}

