#include<iostream>
using namespace std;

class Vector{
    public:
    int size;
    int capacity;
    int* arr;

    Vector(){
        size = 0;
        capacity = 1;
        arr = new int [1];
    }
    void add(int elem){
        if(size == capacity){
            capacity *= 2;
            int* arr2 = new int [capacity * 2];
            for(int i = 0; i< size; i++){
                arr2[i] = arr[i];
            }
            arr = arr2;
        }
        arr[size] = elem;
        size++;
    }
    void print(){
        cout<<"Array: ";
        for(int i = 0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    int getInd(int idx){
        if(size == 0){
            cout<<"Array is empty.\n";
            return -1;
        }
        if(idx >= size || idx < 0){
            cout<<"Invalid index.\n";
            return -1;
        }
        return arr[idx];
    }

    void remove(){
        if(size == 0){
            cout<<"Array is empty.\n";
        }
        size--;
    }
};
int main(){
    Vector v;
    v.getInd(0);
    cout<<"size: "<<v.size<<endl;
    cout<<"capacity: "<<v.capacity<<endl;

    v.add(10);
    v.print();
    cout<<"size: "<<v.size<<endl;
    cout<<"capacity: "<<v.capacity<<endl;

    v.add(20);
    v.print();
    cout<<"size: "<<v.size<<endl;
    cout<<"capacity: "<<v.capacity<<endl;

    v.add(30);
    v.print();
    cout<<"size: "<<v.size<<endl;
    cout<<"capacity: "<<v.capacity<<endl;

   cout<<v.getInd(1);
    return 0;
}
