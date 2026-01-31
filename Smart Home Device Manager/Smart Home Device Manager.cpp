#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

enum DeviceType {
	LIGHT, THERMOSTAT, SECURITY_CAMERA, SPEAKER 
};

struct Device {
	int deviceID ;
	string deviceName ;
	string room ;
	DeviceType type ;
	
	union Specifics {
	int brightness ;
	float temperature ;
	bool isRecording ;
	int volume ;
} specs ;
};


const int MAX_DEV = 10 ;
Device devices[MAX_DEV] ;
int count = 0 ;

void addDevices();
void displayDevices();
void changeDeviceSetting(Device &dev) ;
int findDevicesInRoom(Device devices[], int size, string room) ;
void showStats();

int main()
{
	int choice ;
	do{
		cout << " ========= SMART HOME DEVICE MANAGER ========= " << endl;
		cout << " 1. Add new device " << endl;
		cout << " 2. View all devices " << endl;
		cout << " 3. Change device setting " << endl;
		cout << " 4. Find devices in a room " << endl;
		cout << " 5. Show memory statistics "<< endl;
		cout << " 6. Exit " << endl;
		cout << " ============================================= " << endl ;
		cout << " Enter your choice (1-6): ";
		cin >> choice ;
		
		switch (choice)
		{
			case 1:
				{
					if (count < MAX_DEV)
					{
						addDevices();
					}
					else{
						cout << " Maximum limit reached!";
					}
					break ;
				}
				
			case 2:
			    {
					displayDevices();
				break ;	
				}	
				
			case 3:
			    {
			    	int id ;
			    	cout << " Enter device ID to modify: ";
			    	cin >> id ;
			    	if (id > 0 && id <= count)
			    	{
			    		changeDeviceSetting(devices[id-1]) ;
					}
					else{
						cout << " Invalid ID!" ;
					}
			    break ;	
				}	
				
			case 4:
			    {
			       string room ;
			       cout << " Enter room name: ";
			       cin.ignore() ;
			       getline(cin,room);
			       findDevicesInRoom(devices, count,room) ;
			       cout << endl ;
				   break ;	
				}	
				
			case 5:
			    {
			    	showStats();
			    	break ;
				}	
			
			case 6:
			    cout << " Exiting..." << endl ;
				break;
				
			default :
			    cout << " Invalid choice! Try Again.";	
		}
		
		cout << endl;
	} while (choice != 0) ;
	
	return 0 ;
}

void addDevices()
{
	Device dev ;
	int typeChoice ;
	dev.deviceID = count + 1 ;
	
	cout << " Enter details for Device " << dev.deviceID << " :" << endl ;
	cout << " Device Type (1.LIGHT 2.THERMOSTAT 3.SECURITY_CAMERA 4.SPEAKER): " ;
	cin >> typeChoice;
	dev.type = static_cast <DeviceType> (typeChoice-1) ;
	cout << " Device Name: " ;
	cin.ignore() ;
	getline(cin,dev.deviceName);
	cout << " Room: " ;
	getline (cin,dev.room) ;
	
	switch (dev.type)
	{
		case LIGHT:
			{
				cout << " Enter brightness (0-100): " ;
				cin >> dev.specs.brightness ;
				break ;
			}
			
		case THERMOSTAT:
		    {
		    	cout << " Enter temperature (10.0-30.0): " ;
		    	cin >> dev.specs.temperature ;
		    	break ;
			}
			
		case SECURITY_CAMERA:
		    {
		    	cout << " Is recording? (1 for Yes, 0 for No): ";
		    	cin >> dev.specs.isRecording ;
		    	break ;
			}
			
		case SPEAKER:
		    {
		    	cout << " Enter volume (0-100): ";
		    	cin >> dev.specs.volume ;
		    	break ;
			}	
	}
	devices[count] = dev ;
	count ++ ;
	cout << " Device added successfully!" << endl ;
	cout << endl ;
}

void displayDevices()
{
    cout << "\n============ ALL DEVICES ============\n";
    cout << "--------------------------------------------------------------------------------------" << endl ;
    cout << left << setw(4) << "ID"
         << setw(25) << "Device Name"
         << setw(20) << "Room"
         << setw(20) << "Type"
         << "Specific Setting\n";
    cout << "--------------------------------------------------------------------------------------" << endl ;     

    for (int i = 0; i < count; i++) {

        cout << setw(4) << devices[i].deviceID
             << setw(25) << devices[i].deviceName
             << setw(20) << devices[i].room;

        switch (devices[i].type) {

        case LIGHT:
            cout << setw(20) << "LIGHT"
                 << "Brightness: " << devices[i].specs.brightness << "%\n";
            break;

        case THERMOSTAT:
            cout << setw(20) << "THERMOSTAT"
                 << "Temperature: " << devices[i].specs.temperature << " C\n";
            break;

        case SECURITY_CAMERA:
            cout << setw(20) << "SECURITY_CAMERA"
                 << "Recording: " << (devices[i].specs.isRecording ? "Yes" : "No") << "\n";
            break;

        case SPEAKER:
            cout << setw(20) << "SPEAKER"
                 << "Volume: " << devices[i].specs.volume << "%\n";
            break;
        }
    }
    cout << "--------------------------------------------------------------------------------------" << endl ;
}

void changeDeviceSetting(Device &dev) 
{
	cout << " Changing setting of device with ID: " << dev.deviceID << endl ;
	switch (dev.type)
	{
		case LIGHT:
			{
				cout << " Enter new brightness (0-100): " ;
				cin >> dev.specs.brightness ;
				break ;
			}
			
		case THERMOSTAT:
		    {
		    	cout << " Enter new temperature (10.0-30.0): " ;
		    	cin >> dev.specs.temperature ;
		    	break ;
			}
			
		case SECURITY_CAMERA:
		    {
		    	cout << " Is recording? (1 for Yes, 0 for No): ";
		    	cin >> dev.specs.isRecording ;
		    	break ;
			}
			
		case SPEAKER:
		    {
		    	cout << " Enter new volume (0-100): ";
		    	cin >> dev.specs.volume ;
		    	break ;
			}	
	}
	cout << " Settings updated! " << endl;
	cout << endl ;
}

int findDevicesInRoom(Device devices[], int size, string room)
{
	int found = 0 ;
	cout << " Devices in room: " << room << endl ;
	for (int i=0 ; i<count ; i++)
	{
		if (room == devices[i].room)
		{
			cout << " - " << devices[i].deviceName << endl ;
			found++ ; 
		}
	}
	if (found == 0)
	
		cout << " No devices found! " << endl ;
    return found ;
}

void showStats()
{
	int withUnion = sizeof(Device) ;
	int withoutUnion = sizeof(int) + sizeof(string) + sizeof(string) + sizeof(DeviceType) +  
	                   sizeof(int) + sizeof(float) + sizeof(bool) + sizeof(int) ;
	
    cout << " ==== MEMORY STATISTICS ==== " << endl ;
    cout << " Size of Device struct: " << withUnion << " bytes" << endl ;
    cout << " Size without union (individual members):" << withoutUnion << " bytes" << endl ;
    cout << " Memory saved using union:" << (withoutUnion - withUnion) << " bytes" << endl ;

}



