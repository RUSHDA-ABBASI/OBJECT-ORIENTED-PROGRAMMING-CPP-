#include<iostream>
using namespace std;

class rectangle{
	double length;
	double width;
	public: 
	rectangle(double l, double w){
		if(l>0 && w>0){
			length = l;
			width = w;
		}
		else
		cout<<"Invalid. Dimensions cant be negative."<<endl;
		length = width = 1.0;
	}
	double area(){
		return length * width;
	}
	double perimeter(){
	  return 2 * (length + width);
	}
	bool isSquare(){
		return (length == width);
	}
	void scale(double factor){
		if(factor>0){
			length *= factor;
			width *= factor;
		}
		else
		cout<<"Scale factor must be positive.\n";
	}
};
int main(){
	
	rectangle r1(4.0, 3.0);
	rectangle r2(2.0, 4.0);
	
	cout << "r1 Area: " << r1.area() << ", Perimeter: " << r1.perimeter()
    << ", Is Square? " << (r1.isSquare() ? "Yes" : "No") << "\n"; 
   
   cout << "r2 Area: " << r2.area() << ", Perimeter: " << r2.perimeter()

   << ", Is Square? " << (r2.isSquare() ? "Yes" : "No") << "\n";

   r1.scale(2.0);
   cout << "After scaling r1 by 2x: Area = " << r1.area() << "\n";

   r1.scale(-1); // Should show error

	return 0;
}