#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Professor {
private:
string name;
string subject;
int yearsOfExp;
public:

Professor(string n, string sub, int exp) : name(n), subject(sub), yearsOfExp(exp) {
cout << " [Professor] " << name << " hired\n";
}

~Professor() {
cout << " [Professor] " << name << " retired\n";
}
string getName() const { return name; }

string getSubject() const { return subject; }

void teach() const {
cout << " Prof." << name << " delivers lecture on "
<< subject << " (" << yearsOfExp << "years experience) \n";
}

void conductResearch() const {
cout << " Prof." << name << " publishes research paper\n";
}
};
class Department {
private:
string name;
vector<Professor*> faculty; // stored pointers — no ownership aka aggregation.

public:
Department(string n) : name(n) {
cout << " [Dept] '" << name << "' department opened\n";
}

~Department() {
cout << " [Dept] '" << name << "' department closed\n";
// DO NOT delete faculty — professors exist independently!
}

void assignProfessor(Professor* p) {
faculty.push_back(p);
cout << " Prof." << p->getName()<< " assigned to " << name<<endl;
}

void removeProfessor(Professor* p) {
auto it = find(faculty.begin(), faculty.end(), p); //find is fn of algorithm library.
if (it != faculty.end()) {
faculty.erase(it);
cout << " Prof." << p->getName()<< " removed from " << name<<endl; }
}

void holdLectures() const {
cout << " -- " << name << " dept lectures --\n";
for (auto* p : faculty) p->teach();
}

void researchWeek() const {
cout << " -- " << name << " research week --\n";
for (auto* p : faculty) p->conductResearch();
}

string getName() const { return name; }
int size() const { return faculty.size(); }
};

class University {
private:
string name;
vector<Department*> depts;
public:
University(string n) : name(n) {
cout << "[University] " << name << " founded\n";
}
~University() {
    for (auto* d : depts) delete d;
    cout << "[University] " << name << " closed\n";
}
Department* addDept(string name) {  //change is hereh
    Department* newDept = new Department(name);
    depts.push_back(newDept);
    return newDept;
}
void printSummary() const {
cout << "\n University '" << name << "' summary:";
for (auto* d : depts)
cout << " " << d->getName() << ": " << d->size() << " professors\n";
}
void removeAndDestroyDept(string deptName) {
    for (auto it = depts.begin(); it != depts.end(); ++it) {
        if ((*it)->getName() == deptName) {
            cout << "\nManually closing " << deptName << " department. \n";
            delete *it;      
            depts.erase(it); 
            return;
        }
    }
    cout << "Department not found!\n";
}
};

int main() {
	
    Professor p1("Dr. Ali", "Data Structures", 10);
    Professor p2("Dr. Sara", "Algorithms", 8);
    Professor p3("Dr Zara", "OOP", 9);

    University uni("NED University");
    {   //change is here
        Department* cs = uni.addDept("Computer Science");
        Department* se = uni.addDept("Software Engineering");

        cs->assignProfessor(&p1);
        se->assignProfessor(&p2);
        cs->holdLectures();

        uni.printSummary();

        cs->removeProfessor(&p3);

    } 
    
    p1.teach(); 
    p2.teach();

    uni.removeAndDestroyDept("Software Department.\n"); //destroying dept. this wont destroy profs.
    uni.printSummary();
 
    // <--- University is destroyed here, deleting all departments (Composition)
   // <--- Professors are destroyed here (End of main)
    return 0;
}