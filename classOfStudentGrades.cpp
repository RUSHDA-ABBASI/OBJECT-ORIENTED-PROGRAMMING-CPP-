#include<iostream>
using namespace std;

class StudentGrades{
	string name;
	float grades[5];
	int count;
	
	public:
		StudentGrades(string n){
			name = n;
			count = 0;
		}
	bool addGrade(float g) {
        if (g < 0 || g > 100) {
            return false;   // invalid grade
        }
        if (count >= 5) {
            return false;   // no space
        }
        grades[count] = g;
        count++;
        return true;
    }
    float getAverage() {
        if (count == 0) return 0;

        float sum = 0;
        for (int i = 0; i < count; i++) {
            sum += grades[i];
        }
        return sum / count;
    }

    void printReport() {
        cout << "\nStudent: " << name << endl;
        cout << "Grades: ";

        for (int i = 0; i < count; i++) {
            cout << grades[i] << " ";
        }

        cout << "\nAverage: " << getAverage() << endl;
    }

};

int main(){
	StudentGrades s("Ali");

    s.addGrade(85);
    s.addGrade(90);
    s.addGrade(78);
    s.addGrade(88);

    if (!s.addGrade(120)) {
        cout << "Invalid grade rejected\n";
    }

    if (!s.addGrade(92)) {
        cout << "Extra grade rejected (array full)\n";
    }

    s.printReport();
	return 0;
}