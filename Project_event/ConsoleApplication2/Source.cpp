#include <iostream>
#include "event_list.h"

using namespace std;

int main()
{
	event_list e;
	cout << "Hi." << endl << "Let's start. " << endl << endl;;
	bool on = true;
	do{
		string place, name;
		int start_month, start_day, start_time, event_period, reminder_time, event_done, id;
		if (e.is_empty()){
			cout << "your schedule_event is empty you must add one " << endl;
			cout << "Enter the Event`place : ";                           cin >> place;
			cout << "Enter the Event`name : " ;                           cin >> name;
			cout << "Enter the Event`start_month : ";                     cin >> start_month;
			cout << "Enter the Event`start_day : ";                       cin >> start_day;
			cout << "Enter the Event`start_time format 24 h : " ;         cin >> start_time;
			cout << "Enter the Event`event_period : ";                    cin >> event_period;
			cout << "Enter the Event`reminder_time : ";                   cin >> reminder_time;
			cout << "Enter  1 if event done else 0 : " ;                  cin >> event_done;

			e.add_event(name, place, start_month, start_day, start_time, event_period, reminder_time, event_done);
			e.Stor_Data();
		}

		int select;
		cout << "0- Show Event that not done. " << endl;
		cout << "1- Add Event." << endl;
		cout << "2- Updata Event." << endl;  
		cout << "3- Delet Event." << endl; 
		cout << "4- Sort event that done." << endl;
		cout << "5- To close. " << endl;
		cout << endl;

		cout << "Enter your Choice: ";
		cin >> select;

		switch (select){

		case 0:
			e.sort_event();
			break;
		case 1:
			cout << "Enter the Event`place : " ;                    cin >> place;
			cout << "Enter the Event`name : " ;                     cin >> name;
			cout << "Enter the Event`start_month : " ;              cin >> start_month;
			cout << "Enter the Event`start_day : " ;                cin >> start_day;
			cout << "Enter the Event`start_time format 24 h : ";    cin >> start_time;
			cout << "Enter the Event`event_period : " ;             cin >> event_period;
			cout << "Enter the Event`reminder_time : ";             cin >> reminder_time;
			cout << "Enter  1 if event done else 0 : ";             cin >> event_done;

			e.add_event(name, place, start_month, start_day, start_time, event_period, reminder_time, event_done);
			e.Stor_Data();
			break;

		case 2:
			e.sort_event();
			e.done_event();
			cout << "Enter the Event id : " << endl;
			cin >> id;
			e.up_date(id);
			e.Stor_Data();

			break;
		case 3:
			e.sort_event();
			e.done_event();
			cout << "Enter the Event id : " << endl;
			cin >> id;
			e.Delet(id);
			e.Stor_Data();
			break;
		case 4:
			e.done_event();
			break;
		case 5:
			on = false;

			break;
		default:
			on = false;

		}
	} while (on);

	cout << "thank you " << endl;

	return 0;
}
