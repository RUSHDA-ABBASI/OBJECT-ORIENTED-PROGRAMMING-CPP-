#include<iostream>
#include<string>
using namespace std;
class Date{
    int day;
    int month;
    int year;
    public:
    Date(int day=1, int month=1, int year=2000){
        this -> day = day;
        this -> month = month;
        this -> year = year;

        cout<<"Default date: "<<day<<"/"<<month<<"/"<<year<<endl;
        }
        int setDay(int num){
            if(num<=0 || num>31){
                cout<<"Invalid date.\n";
            }
            else
                day = num;
                return day;
        }
        int getDay(){
            return day;
        }
        int setMonth(int num){
            if(num<=0 || num>12){
                cout<<"Invalid month.\n";
            }
            else
                month = num;
                return month;
        }
        int getMonth(){
           return month ;
        }
        int setYear(int num){
            if(num <= 0 || num>2026){
                cout<<"Invalid year.\n";
            }
            else
                year = num;
                return year;
        }
        int getYear(){
            return year;
        }

        void displayDate() const{
            cout<<day<<"/"<<month<<"/"<<year<<endl;
        }
};
int main(){
    Date d;
    d.displayDate();
    d.setDay(19);
    d.setMonth(05);
    d.setYear(2006);
    d.displayDate();
    return 0;
}