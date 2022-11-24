#include "event_list.h"
#include <iostream>

#include <fstream>
using namespace std;
event_list::event_list()
{
       size = 3;
    top=0;
	place = new string[size];
	name = new string[size];
	start_month = new int[size];
	start_day = new int[size];
	start_time = new int[size];
	event_period = new int[size];
	reminder_time = new int[size];
	event_done = new int[size];
	Read_Data();

}

void event_list::sort_event(){
     for(int m =0;m<=12;m++){
            for(int d =0;d<=31;d++){
                for(int h =0;h<=24;h++){
                     for(int e =0;e<top;e++){
                        if(start_month[e]==m ){
                            if(start_day[e]==d ){
                            if(start_time[e]==h ){
                                    if(event_done[e]==0 ){
                                  // cout<<" ---------------------------------------------------------------------------------------------------"<<endl;
                              cout<<"| id :"<<e <<" | "<<"name :"<<name[e]<<"   | "<<"place :"<<place[e]<<"  | m : "<<start_month[e]<<"  | d : "<<start_day[e]<<"  | h : "<<start_time[e]<< "  | "<<"event_period :"<<event_period[e]<<"   | "<<"remender time  :"<<reminder_time[e]<<"  | "<<endl;
                                   //  cout<<" ----------------------------------------------------------------------------------------------------"<<endl;
                                    }
                                    }
                                }
                            }
                    }
                }
            }
        }
}

void event_list::done_event(){
     for(int m =0;m<=12;m++){
            for(int d =0;d<=31;d++){
                for(int h =0;h<=24;h++){
                     for(int e =0;e<top;e++){
                        if(start_month[e]==m ){
                            if(start_day[e]==d ){
                            if(start_time[e]==h ){
                                    if(event_done[e]==1 ){
                                   // cout<<" ------------------------------------------------------------------------------------------------------------------"<<endl;
                              cout<<"| id :"<<e <<" | "<<"name :"<<name[e]<<"   | "<<"place :"<<place[e]<<"  | m : "<<start_month[e]<<"  | d : "<<start_day[e]<<"  | h : "<<start_time[e]<< "  | "<<"event_period :"<<event_period[e]<<"   | "<<"remender time  :"<<reminder_time[e]<<"  | "<<endl;
                                    // cout<<" -----------------------------------------------------------------------------------------------------------------"<<endl;
                                    }
                                    }
                                }
                            }
                    }
                }
            }
        }
}

bool event_list::add_event(string n,string pl,int month,int day,int time,int period,int reminder,int done)
{
    if(is_full()){
        expand_event();
    }
    if(is_exist(month,day,time,period))
    {
    cout<<"you have event in same time"<<endl;
    return false;
    }
        place [top]=pl;
        name [top]=n;
        start_month [top]=month;
        start_day[top]=day;
        start_time [top]=time;
        event_period [top]=period;
        reminder_time [top]=reminder;
        event_done [top]=done;
        cout<<"add event successfully"<<endl;
    top++;
        return true;
}

void event_list::up_date(int index)
{

    cout << "Enter the Event`place : ";            cin >> place[index];
	cout << "Enter the Event`name : ";             cin >> name[index];
	cout << "Enter the Event`start_month : ";      cin >> start_month[index];
    cout << "Enter the Event`start_day : ";        cin >> start_day[index];
	cout << "Enter the Event`start_time : ";       cin >> start_time[index];
	cout << "Enter the Event`event_period : ";     cin >> event_period[index];
	cout << "Enter the Event`reminder_time : ";    cin >> reminder_time[index];
	cout << "Enter the Event`event_done : ";       cin >> event_done[index];
	cout<<"updata event successfully"<<endl;
}

void event_list::Delet(int index){
	for (int i = index; i < top; i++) {
		place[i] = place[i + 1];
		name[i] = name[i + 1];
		start_month[i] = start_month[i + 1];
		start_day[i] = start_day[i + 1];
		start_time[i] = start_time[i + 1];
		event_period[i] = event_period[i + 1];
		reminder_time[i] = reminder_time[i + 1];
		event_done[i] = event_done[i + 1];
		cout<<"delete event successfully"<<endl;
	}
}
bool event_list::is_exist(int m,int d,int h,int p){

    for(int e =0;e<top;e++){
            if(start_month[e]==m &&start_day[e]==d ){
                   // cout<<  start_time[e] <<"\t"<<h<<endl;
                if(start_time[e]==h ){
                  //cout<<"place "+place[e]<<"\t m : "<<start_month[e]<<"\t d : "<<start_day[e]<<"\t h : "<<start_time[e]<<endl;
                            return true;
                        }
                        if(start_time[e]+event_period[e]>h&&start_time[e]<h){
                             return true;

                        }
                        if(start_time[e]+event_period[e]>h+p&&start_time[e]<h+p){
                             return true;

                        }

                    }
                }
                return false;
}


bool event_list::is_full(){
    if(top==size-1)
        return true;
    else
        return false;
}
bool event_list::is_empty(){
    if(top==0)
        return true;
    else
        return false;
}

void event_list::expand_event()
{
        size*=2;
        append_name();
        append_place();
        append_start_month();
         append_start_day();
         append_start_time();
         append_Reminder_time();
         append_event_period();
         append_event_done();

}
void event_list::append_name()//add an item at the end to array
{
	 //define new capacity
	string * tmp=new string[size];
	for(int i=0; i<top;i++)
		tmp[i]=name[i];
	delete name; //release old space
	name=tmp;
}
void event_list::append_place()//add an item at the end to array
{
 //size*=2; //define new capacity
	string * tmp=new string[size];
	for(int i=0; i<top;i++)
		tmp[i]=place[i];
	delete place; //release old space
	place=tmp;
}
void event_list::append_start_month() //add an item at the end to array
{
   // size*=2; //define new capacity
	int * tmp=new int[size];
	for(int i=0; i<top;i++)
		tmp[i]=start_month[i];
	delete start_month; //release old space
	start_month=tmp;
}
void event_list::append_start_day() //add an item at the end to array
{
    //size*=2; //define new capacity
	int * tmp=new int[size];
	for(int i=0; i<top;i++)
		tmp[i]=start_day[i];
	delete start_day; //release old space
	start_day=tmp;
}
void event_list::append_start_time()//add an item at the end to array
{
   // size*=2; //define new capacity
	int * tmp=new int[size];
	for(int i=0; i<top;i++)
		tmp[i]=start_time[i];
	delete start_time; //release old space
	start_time=tmp;
}
void event_list::append_event_period()//add an item at the end to array
{
    //size*=2; //define new capacity
	int * tmp=new int[size];
	for(int i=0; i<top;i++)
		tmp[i]=event_period[i];
	delete event_period; //release old space
	event_period=tmp;
}
void event_list::append_Reminder_time()//add an item at the end to array
{
    //size*=2; //define new capacity
	int * tmp=new int[size];
	for(int i=0; i<top;i++)
		tmp[i]=reminder_time[i];
	delete reminder_time; //release old space
	reminder_time=tmp;
}
void event_list::append_event_done() //add an item at the end to array
{
    //size*=2; //define new capacity
	int * tmp=new int[size];
	for(int i=0; i<top;i++)
		tmp[i]=event_done[i];
	delete event_done; //release old space
	event_done=tmp;
}


void event_list::Stor_Data(){
	ofstream store("Event_File.txt");

	if (store.is_open()){
		for (int i = 0; i <top; i++){
			store << name[i] << "\t" << place[i] << "\t" << start_month[i] << "\t" << start_day[i] <<
				"\t" << start_time[i] << "\t" << event_period[i] << "\t" << reminder_time[i] << "\t" << event_done[i] << endl;
		}
	}
	else{
		cout << "Error!" << endl;
	}
	store.close();
}


void event_list::Read_Data(){

       string myText;
            int row=0;
       ifstream re("Event_File.txt");
        while (getline(re, myText))
        {
                row++;
        }
        re.close();

    ifstream read("Event_File.txt");
	if (read.is_open()){
		for (int i = 0; i < row; i++){
                 if(is_full()){
                expand_event();
                    }
			read >> name[i];
			read >> place[i];
			read >> start_month[i];
			read >> start_day[i];
			read >> event_period[i];
			read >> start_time[i];
			read >> reminder_time[i];
			read >> event_done[i];
			top++;
		}

    }else{
		cout << "Error!" << endl;
	}
	read.close();
}


event_list::~event_list()
{
    //dtor
}
