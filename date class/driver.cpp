#include <iostream>
#include "date.h"
#include <string>

using namespace std;

int main(){
    date date_object;
    date_object.init();
    do{
        cout<<"-------------------------------------------\n"
              "\t\tCALENDAR MENU\n"
              "-------------------------------------------\n"
              "A) Set Date\n"
              "B) Display date (mm/dd/yyy)\n"
              "C) Display date (Weekday, Month day, year)\n"
              "D) Display future date\n"
              "E) Display past date\n"
              "F) Number of days passed in current year\n"
              "G) Number of days remaining in current year\n"
              "H) Compares dates\n"
              "I) Increment current date\n"
              "J) Decrement current date\n"
              "K) Display current monthly calendar\n"
              "L) Display holidays\n"
              "M) Exit the program\n\n"
              "Enter your choice: ";
        char selection;
        cin>>selection;
        cout<<endl;
        switch (selection) {
            case 'A':
                date_object.set_day();
                break;
            case 'B':
                date_object.display_date();
                break;
            case 'C':
                date_object.display_date_altered();
                break;
            case 'D':
                date_object.display_future_date();
                break;
            case 'E':
                date_object.display_past_date();
                break;
            case 'F':
                date_object.number_of_days_passed_in_current_year();
                break;
            case 'G':
                date_object.number_of_days_remaining_in_current_year();
                break;
            case 'H':
                date_object.compare_dates();
                break;
            case 'I':
                date_object.increment_current_date();
                break;
            case 'J':
                date_object.decrement_current_date();
                break;
            case 'K':
                date_object.display_current_monthly_calendar();
                break;
            case 'L':
                date_object.display_holiday();
                break;
            case 'M':
                cout<<"Exit program.\n\n";
                return 0;
            default:
                cout<<"[WARNING] Please enter a valid letter to start.\n\n";
                break;
        }
    } while (true);
}