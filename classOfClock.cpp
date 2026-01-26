#include<iostream>
using namespace std;

class Clock{
	int hours;
	int minutes;
	
	public:
		Clock(int h, int m){
			setTime(h,m);
		}
		void setTime(int h, int m){
			if(h <= 23 && h >= 0){
				hours = h;
			}
			else{
				cout<<"Invalid input. Setting hours to 0.\n";
				h = 00;
			}
			if(m <= 59 && m>= 0){
				minutes = m;
			}
			else{
				cout<<"Invalid input. Setting minutes to 0.\n";
				m = 00;
			}
		}
		void tick(){
			minutes++;
			if(minutes == 60){
				minutes = 0;
				hours++;
			}
			if(hours == 24){
				hours = 0;
				minutes++;
			}
		}
		void display(){
		 if (hours < 10){
            cout << "0";
        }
        cout << hours << ":";

        if (minutes < 10){
            cout << "0";
        }
        cout << minutes << endl;
		}
		
};

int main(){
	Clock c(23,58);
	for(int i = 1; i<= 5; i++){
		c.tick();
		c.display();
	}
	
	return 0;
}