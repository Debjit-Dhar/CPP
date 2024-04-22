#include <iostream>
#include <unordered_map>
using namespace std;

class Student {
private:
    int roll;
    float score;

public:
    Student(int r = 0,float s=0) {
        roll = r;score=s;
    }

    int get_roll() const {
        return roll;
    }

    void display() const {
        cout << "Roll = " << roll <<"Score= "<<score<< '\n';
    }
};

class Hash {
public:
    size_t operator()(int roll) const {
        return roll % 10;
    }
};

class Equality {
public:
    bool operator()(const Student& s1, const Student& s2) const {
        return s1.get_roll() == s2.get_roll();
    }
};

class StudentContainer {
private:
    unordered_map<int, Student, Hash,Equality> smap;
    

public:
    void accept() {
        int r;
        float s;
        cout << "Enter roll: ";
        cin >> r;
        cout<<"Enter score:";
        cin>>s;
        Student newStudent(r,s);
        smap.insert(pair<int,Student>(r, newStudent));
    }

    void displayStudents() const {
        cout << "Students in the container:\n";
        for (const auto& pair : smap) {
            pair.second.display();
        }
    }
    void searchStudent(int roll) const {
        auto it = smap.find(roll);
        if (it != smap.end()) {
            cout << "Student with Roll = " << roll << " found:\n";
            it->second.display();
        } else {
            cout << "Student with Roll = " << roll << " not found.\n";
        }
    }
    
    
};

int main() {
    StudentContainer container;
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add student\n";
        cout << "2. Display all students\n";
        cout << "3. Search a student\n";
        cout<< "4. Exit.\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                container.accept();
                break;
            case 2:
                container.displayStudents();
                break;
            case 3:
            {
                cout<<"Enter roll to be searched.\n";
                int r;
                cin>>r;
                container.searchStudent(r);
                break;
            }
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
