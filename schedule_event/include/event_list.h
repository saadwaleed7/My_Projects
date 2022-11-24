#ifndef EVENT_LIST_H
#define EVENT_LIST_H
using namespace std;
#include <string>

class event_list
{
    public:
        event_list();
        virtual ~event_list();

            int top; // initial = 0
            int size;

            bool is_full();
            bool is_empty();
            void sort_event();
            void Stor_Data();
            void Read_Data();
            bool add_event(string name,string place,int start_month,int start_day,int start_time,int event_period,int reminder_time,int done);
            bool is_exist(int m,int d,int h,int p);
            void done_event();
             void Delet(int index);
             void up_date(int index);

    protected:
          void expand_event();
            string *name;
            string *place;
            int* start_month;
            int* start_day;
            int* start_time; // hours
            int* event_period; // how many hour event will stay
            int* reminder_time;
            int* event_done; // 0 for not done || 1 for done



        void append_name(); //add an item at the end to array
        void append_place(); //add an item at the end to array
        void append_start_month(); //add an item at the end to array
        void append_start_day(); //add an item at the end to array
        void append_start_time(); //add an item at the end to array
        void append_event_period(); //add an item at the end to array
        void append_Reminder_time(); //add an item at the end to array
        void append_event_done(); //add an item at the end to array
    private:
};

#endif // EVENT_LIST_H
