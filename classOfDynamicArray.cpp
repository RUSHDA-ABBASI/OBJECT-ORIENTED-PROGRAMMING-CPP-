#include<iostream>
using namespace std;
class DynamicArray{
	int* data;
	int size;
	public:
		DynamicArray(){
			size = 0;
			data = nullptr;
		}
		DynamicArray(int n){
			size = n;
			data = new int[size];
			for(int i = 0; i < size; i++){
				data [i] = 0;
			}	
		}
		DynamicArray(const DynamicArray &other){
			size = other.size;
			data = new int [size];
			for(int i=0; i<size; i++)
				data[i] = other.data[i];
			cout << "Deep copy made!\n";
		}
		int getsize() const{
			return size;
		}
		int& operator[](int index){
    		return data[index];
		}
		~DynamicArray(){
			delete[] data;
		}
};
int main(){
	DynamicArray a(3);
    a[0] = 10;

    DynamicArray b = a; // deep copy
    b[0] = 20;

    cout << a[0];
	return 0;
}