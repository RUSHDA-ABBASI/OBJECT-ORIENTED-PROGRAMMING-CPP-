#include<iostream>

using namespace std;
//  Create a Counter class for a website visitor tracker: Data members: counterID, totalVisits, 
// count. Methods: constructors, increment(), getCount(), getTotalVisits(), reset(). Make use of 
// const and static keywords wherever applicable. Here, count refers to the number of visitors at a 
// counter, and total visits refers to the total number of visitors across all counters. The method 
// reset(), resets the counter to zero. 
class Counter{
    const int counterID;
    static int totalVisits;
    int count;
public:
    Counter(int id=0):counterID(id){
        count = 0;
    }
    int increment(){
        count++;
        totalVisits++;
        return count, totalVisits;
    }
    int getCount()const{
        return count;
    }
    static int getTotalVisits(){
        return totalVisits;
    }
    int reset(){
        count = 0;
        return count;
    }
};
int Counter :: totalVisits = 0;
int main(){
    Counter c(1);
    c.increment();
    cout<<c.getCount()<<endl;
    cout<<c.getTotalVisits()<<endl;
    cout<<c.reset();

    return 0;
}