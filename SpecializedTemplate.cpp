#include<iostream>
using namespace std;
template<class U, class V>
class Pair{
	U first;
	V second;
	public:
		Pair(U a = 0, V b = 0):first(a), second(b){
			cout<<"generalized template.\n";
		}
};
template<class T>
class Pair<T, T*>{
	T first;
	T* second;
	public:
		Pair(T a = 0, T* b = nullptr):first(a), second(b){
			cout<<"partially specialized.\n";
		}
};

int main(){
	Pair<int, float> ob(2,3.5);
	char m = 'c';
	Pair<char, char*> ob2('a', &m);
	int a = 20;
	Pair<float, int*> ob3(2.5, &a);
	return 0;
}