#include <iostream>
#include "event_list.h"

using namespace std;

int main()
{
    event_list e;
        cout<<"hi : i'm L this is my name \n let's start ";
        bool on=true;
        do{
                string place,name;
        int start_month,start_day,start_time,event_period,reminder_time,event_done,id;
                if(e.is_empty()){
                        cout << "your schedule_event is empty you mast add one "<<endl;
                        cout << "Enter the Event`place : "<<endl;            cin >> place;
                        cout << "Enter the Event`name : "<<endl;             cin >> name;
                        cout << "Enter the Event`start_month : "<<endl;      cin >> start_month;
                        cout << "Enter the Event`start_day : "<<endl;        cin >> start_day;
                        cout << "Enter the Event`start_time format 24 h : "<<endl;  cin >> start_time;
                        cout << "Enter the Event`event_period : "<<endl;     cin >> event_period;
                        cout << "Enter the Event`reminder_time : "<<endl;    cin >> reminder_time;
                        cout << "Enter  1 if event done else 0 : "<<endl;       cin >> event_done;
                        e.add_event( name,place,start_month,start_day,start_time,event_period,reminder_time,event_done);

                }
                int select;
                cout << "enter 0 to event that not done : 1 to add : 2 to updata : 3 delet : 4 sort event that done :5 to close "<<endl;
                cin>>select;
                switch(select){

                case 0:
                    e.sort_event();
                break;
                case 1:
                          cout << "Enter the Event`place : "<<endl;            cin >> place;
                        cout << "Enter the Event`name : "<<endl;             cin >> name;
                        cout << "Enter the Event`start_month : "<<endl;      cin >> start_month;
                        cout << "Enter the Event`start_day : "<<endl;        cin >> start_day;
                        cout << "Enter the Event`start_time format 24 h : "<<endl;  cin >> start_time;
                        cout << "Enter the Event`event_period : "<<endl;     cin >> event_period;
                        cout << "Enter the Event`reminder_time : "<<endl;    cin >> reminder_time;
                        cout << "Enter  1 if event done else 0 : "<<endl;       cin >> event_done;
                        e.add_event( name,place,start_month,start_day,start_time,event_period,reminder_time,event_done);


                break;
                case 2:
                     e.sort_event();
                     e.done_event();
                    cout << "Enter the Event id : "<<endl;
                    cin >> id;
                    e.up_date(id);

                break;
                case 3:
                      e.sort_event();
                     e.done_event();
                    cout << "Enter the Event id : "<<endl;
                    cin >> id;
                    e.Delet(id);
                break;
                case 4:
                    e.done_event();
                break;
                case 5:
                    on=false;

                break;
                default:
                       on=false;

                }
        }while(on);

                 cout <<"thank you "<<endl;

    return 0;
}
