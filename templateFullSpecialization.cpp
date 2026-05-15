#include<iostream>
#include<string>
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

template<>
class Pair<int, int*>{
    int first;
    int* second;
    public:
        Pair(){
            cout<<"specialized template.\n";
        }

}
int main(){
    

    return 0;
}