#include<iostream>
using namespace std;
/*
Create a class tollbooth. The two data items are a type int to hold the total number
of cars and a type double to hold the total amount of money collected. A
constructor initializes both these to 0. When a car passes the toll, a member
function called payingCar( ) increments the car total and adds 0.50 to the cash
total. Another member function displays the two totals. DESIGN and IMPLEMENT
this case. Make assumptions (if required) and include it in the description before
designing the solution.
*/
class TollBooth{
	int totalCars;
	double amountCollected;
	public:
		TollBooth(){
			totalCars = 0;
			amountCollected = 0; 
		}
		void payingCar(){
			totalCars++;
			amountCollected += 0.50;
		}
		void display(){
			cout<<"Total cars : "<<totalCars<<endl;
			cout<<"Total amount collected: "<<amountCollected;
		}
};
int main(){
	TollBooth t1;
	t1.payingCar();
	t1.payingCar();
	t1.display();
	return 0;
}