#include<iostream>
using namespace std;

class Car{
	string brand;
	int currentSpeed;
	int maxSpeed;
	
	public:
		Car(string b, int m){
			brand = b;
			maxSpeed = m;
			currentSpeed = 0;
		}
		void accelerate(int delta){
			if (delta>0)
			currentSpeed += delta;
			
			if(currentSpeed > maxSpeed){
				currentSpeed = maxSpeed;
			}
		}
		void brake(int delta){
			if (delta>0)
			currentSpeed -= delta;
			
			if(currentSpeed < 0){
				currentSpeed = 0;
			}
		}
		void displayStatus(){
			cout<<"Brand: "<<brand<<", Speed"<<currentSpeed<<" km/h (Max: "<< maxSpeed << " km/h)\n";
		}
};

int main(){
	Car c("Toyota", 180);
	c.accelerate(50);
	c.displayStatus();
	
	c.accelerate(100);
	c.displayStatus();
	
	c.accelerate(60);
	c.displayStatus();
	
	c.brake(200);
	c.displayStatus();
	
	return 0;
}