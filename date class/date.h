#include <iostream>
#include <string>
#include <stdlib.h>
#include <tuple>
using namespace std;

class date{
private:
    int month;
    int month_date;
    int year;
    int day;
    string weekdays[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    string months[13] = {"padding", "January", "February", "March", "April", "May", "June",
                         "July", "August", "September", "October", "November", "December"};
    int month_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
public:
    void init(){
        month = 1;
        month_date = 1;
        year = 1753;
        day = 1;
    }
    int return_year_days(int y){
        if (y % 4 == 0) {
            if (y % 100 == 0) {
                if (y % 400 == 0)
                    return 366;
                else
                    return 365;
            } else
                return 366;
        } else
            return 365;
    }
    int return_month_day(int m, int y){
        if(m!=2){
            return month_days[m];
        } else{
            if(return_year_days(y)==366){
                return month_days[m] + 1;
            } else{
                return month_days[m];
            }
        }
    }
    int days_pass(int m, int d, int y){
        int total = return_year_days(y);
        int rt = 0;
        for(int i=1; i<m; i++){
            if(i!=2){
                rt += month_days[i];
            } else{
                if(total == 366)
                    rt += month_days[i] + 1;
                else
                    rt += month_days[i];
            }
        }
        return rt + d;
    }
    int days_remain(int m, int d, int y){
        int total = return_year_days(y);
        return total - days_pass(m, d, y);
    }
    int different_in_days(int m, int d, int y, int m2, int d2, int y2){
        int diff_days = 0;
        if(y==y2){
            int date1_pass = days_pass(m, d, y);
            int date2_pass = days_pass(m2, d2, y2);
            diff_days = date2_pass - date1_pass;
        } else{
            if(y>y2){
                int date2_remain = days_remain(m2, d2, y2);
                int date1_pass = days_pass(m, d, y);
                for(int i=y-1; i>y2; i--){
                    diff_days -= return_year_days(i);
                }
                diff_days = diff_days - date1_pass - date2_remain;
            } else if(y<y2){
                int date2_pass = days_pass(m2, d2, y2);
                int date1_remain = days_remain(m, d, y);
                for(int i=y+1; i<y2; i++){
                    diff_days += return_year_days(i);
                }
                diff_days = diff_days + date2_pass + date1_remain;
            }
        }
        return diff_days;
    }
    tuple<int, int, int> date_input_validation(){
        int m, d, y;
        while (true) {
            cout << "Enter the month: ";
            cin >> m;
            if(m>12 || m<=0){
                cout<<"[WARNING] "<<m<<" is an invalid month representation number!\tTry again!\n";
                continue;
            }
            cout << "Enter the day: ";
            cin >> d;
            if(d<1){
                cout<<"[WARNING] "<<d<<" is an invalid date in a month!\tTry again!\n";
                continue;
            } else if((m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m== 12) && d>31) {
                cout << "[WARNING] " << d << " is an invalid date for " << months[m - 1] << "!\tTry again!\n";
                continue;
            } else if((m==4 || m==6 || m==9 || m==11) && d>30){
                cout << "[WARNING] " << d << " is an invalid date for " << months[m - 1] << "!\tTry again!\n";
                continue;
            } else if(m==2 && d>29){
                cout << "[WARNING] " << d << " is an invalid date for " << months[m - 1] << "!\tTry again!\n";
                continue;
            }
            cout << "Enter the year: ";
            cin >> y;
            if(y<0){
                cout<<"[WARNING] "<<y<<" is an invalid year!\tTry again!\n";
                continue;
            } else if(return_year_days(y)==365 && m==2 && d>28){
                cout << "[WARNING] " << d << " is an invalid date for " << months[m - 1] <<" in year "<<y<<"!\tTry again!\n";
                continue;
            }
            break;
        }
        return {m, d, y};
    }
    void set_day(){
        int m, d, y;
        tie(m, d, y) = date_input_validation();
        int diff = abs(different_in_days(month, month_date, year, m, d, y));
        int temp_day = day + diff%7;
        while(temp_day>6) {
            temp_day -= 7;
        }
        day = temp_day;
        month = m;
        month_date = d;
        year = y;
        cout<<"\n  Date Updated!\n\n";
    }
    void display_date(){
        cout<<"Date: "<<month<<'/'<<month_date<<'/'<<year<<"\n\n";
    }
    void display_date_altered(){
        cout<<"\n"<<weekdays[day]<<", "<<months[month]<<' '<<month_date<<", "<<year<<"\n\n";
    }
    tuple<int, int, int, int> future_date(int n){
        int wd=day, m=month, d=month_date, y=year;
        int cpy_n = n;
        while(cpy_n!=0){
            int remain_day_in_month = return_month_day(m, y) - d;
            if(remain_day_in_month >= cpy_n){
                d += cpy_n;
                cpy_n = 0;
            } else{
                d = 1;
                m += 1;
                if(m>12){
                    m = 1;
                    y += 1;
                }
                cpy_n -= (remain_day_in_month + 1);
            }
        }
        wd = wd + n%7;
        while(wd > 6) {
            wd -= 7;
        }
        return {wd, m, d, y};
    }
    void display_future_date(){
        cout<<"Enter the number of days to add: ";
        int days_to_add;
        cin>>days_to_add;
        int wd, m, d, y;
        tie(wd, m, d, y) = future_date(days_to_add);
        cout<<"\n"<<days_to_add<<" days from now, the date will be "<<weekdays[wd]<<", "<<months[m]<<' '<<d<<", "<<y<<"\n\n\n";
    }
    tuple<int, int, int, int> past_date(int n){
        int wd=day, m=month, d=month_date, y=year;
        int cpy_n = n;
        while(cpy_n!=0){
            if(d > cpy_n){
                d -= cpy_n;
                cpy_n = 0;
            } else{
                cpy_n -= d;
                m --;
                if(m < 1){
                    m=12;
                    y --;
                }
                d = return_month_day(m, y);
            }
        }
        wd = wd - n%7;
        while(wd < 0) {
            wd += 7;
        }
        return {wd, m, d, y};
    }
    void display_past_date(){
        cout<<"Enter the number of days to subtract: ";
        int days_to_subtract;
        cin>>days_to_subtract;
        int wd, m, d, y;
        tie(wd, m, d, y) = past_date(days_to_subtract);
        cout<<"\n"<<days_to_subtract<<" days ago, the date was "<<weekdays[wd]<<", "<<months[m]<<' '<<d<<", "<<y<<"\n\n\n";
    }
    void number_of_days_passed_in_current_year(){
        cout<<days_pass(month, month_date, year) - 1<<" days have passed this year.\n";
    }
    void number_of_days_remaining_in_current_year(){
        cout<<days_remain(month, month_date, year)<<" days left this year.\n";
    }
    void compare_dates(){
        int m, d, y;
        tie(m, d, y) = date_input_validation();
        int diff = different_in_days(month, month_date, year, m, d, y);
        if(diff < 0){
            cout<<"\nThe date entered has passed "<<abs(diff)<<" days ago!\n";
        } else{
            cout<<"\nThe date entered will be reach in "<<diff<<" days!\n";
        }
    }
    void increment_current_date(){
        int wd, m, d, y;
        tie(wd, m, d, y) = future_date(1);
        day = wd;
        month = m;
        month_date = d;
        year = y;
        cout<<"Date incremented!\n\n"<<weekdays[day]<<", "<<months[m]<<' '<<month_date<<", "<<year<<"\n\n";
    }
    void decrement_current_date(){
        int wd, m, d, y;
        tie(wd, m, d, y) = past_date(1);
        day = wd;
        month = m;
        month_date = d;
        year = y;
        cout<<"Date decremented!\n\n"<<weekdays[day]<<", "<<months[m]<<' '<<month_date<<", "<<year<<"\n\n";
    }
    void display_current_monthly_calendar(){
        int total_days = return_month_day(month, year);
        int position = day - (month_date - 1)%7;
        while(position < 0){
            position += 7;
        }
        string display = "\n\t" + months[month] + " " + to_string(year) + "\n" +
                         "Su MO Tu We Th Fr Sa\n";
        for(int i = 0; i<position; i++){
            display += "   ";
        }
        for(int i=1; i<=total_days; i++){
            if(i < 10)
                display += ' ';
            display += to_string(i) + ' ';
            position ++;
            if(position > 6){
                position = 0;
                display += "\n";
            }
        }
        display += "\n";
        cout<<display;
    }
    tuple<int, int, int> locate_fixed_holiday(int ye, int mon, int md){
        int wd, m, d, y;
        int diff_days = different_in_days(month, month_date, year, mon, md, ye);
        if(diff_days < 0){
            tie(wd, m, d, y) = past_date(abs(diff_days));
        } else{
            tie(wd, m, d, y) = future_date(diff_days);
        }
        return {wd, m, d};
    }

    tuple<int, int, int> locate_holiday(int ye, int mon, int weekday, int n){
        int wd, m, d;
        if(n > 0) {
            tie(wd, m, d) = locate_fixed_holiday(ye, mon, 1);
            while (n != 0) {
                if (wd > 6) {
                    wd -= 7;
                }
                if (wd == weekday) {
                    n -= 1;
                    if (n == 0) {
                        break;
                    }
                }
                wd++;
                d++;
            }
        } else{
            tie(wd, m, d) = locate_fixed_holiday(ye, mon, return_month_day(mon, ye));
            while (n != 0){
                if (wd < 0) {
                    wd += 7;
                }
                if(wd == weekday){
                    n += 1;
                    if(n == 0){
                        break;
                    }
                }
                wd--;
                d--;
            }
        }
        return {wd, m, d};
    }

    void display_holiday(){
        cout<<"\nEnter the year: ";
        int wd, m, d, y;
        string display = "\n";
        cin>>y;
//        new year -Jan 1
        tie(wd, m, d) = locate_fixed_holiday(y, 1, 1);
        display += weekdays[wd] + ", " + months[m] + " " + to_string(d) + "\t- New Year's Day\n";
//        Martin Luther King, Jr. Day - Third Monday of January
        tie(wd, m, d) = locate_holiday(y, 1, 1, 3);
        display += weekdays[wd] + ", " + months[m] + " " + to_string(d) + "\t- Martin Luther King, Jr. Day\n";
//        President's Day - Third Monday of February
        tie(wd, m, d) = locate_holiday(y, 2, 1, 3);
        display += weekdays[wd] + ", " + months[m] + " " + to_string(d) + "\t- President's Day\n";
//        Memorial Day - Last Monday of May
        tie(wd, m, d) = locate_holiday(y, 5, 1, -1);
        display += weekdays[wd] + ", " + months[m] + " " + to_string(d) + "\t\t- Memorial Day\n";
//        Independence Day - July 4th
        tie(wd, m, d) = locate_fixed_holiday(y, 7, 4);
        display += weekdays[wd] + ", " + months[m] + " " + to_string(d) + "\t\t- Independence Day\n";
//        Labor Day - First Monday of September
        tie(wd, m, d) = locate_holiday(y, 9, 1, 1);
        display += weekdays[wd] + ", " + months[m] + " " + to_string(d) + "\t- Labor Day\n";
//        Columbus Day - Second Monday of October
        tie(wd, m, d) = locate_holiday(y, 10, 1, 2);
        display += weekdays[wd] + ", " + months[m] + " " + to_string(d) + "\t- Columbus Day\n";
//        Veterans Day - November 11th
        tie(wd, m, d) = locate_fixed_holiday(y, 11, 11);
        display += weekdays[wd] + ", " + months[m] + " " + to_string(d) + "\t- Veterans Day\n";
//        Thanksgiving Day - Fourth Thursday of November
        tie(wd, m, d) = locate_holiday(y, 11, 4, 4);
        display += weekdays[wd] + ", " + months[m] + " " + to_string(d) + "\t- Thanksgiving Day\n";
//        Christmas Day - December 25th
        tie(wd, m, d) = locate_fixed_holiday(y, 12, 25);
        display += weekdays[wd] + ", " + months[m] + " " + to_string(d) + "\t- Christmas Day\n";

        display += "\n";
        cout<<display;
    }
};