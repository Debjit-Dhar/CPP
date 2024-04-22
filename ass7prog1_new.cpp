#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Student {
    long int roll;
    string name;
    float score;

public:
    Student(long int a, string b, float c) {
        roll = a;
        name = b;
        score = c;
    }

    void display() {
        cout << "Roll= " << roll << ", Name= " << name << ", Score= " << score << '\n';
    }

    // Overloaded comparison operator to compare Student objects by roll number
    bool operator>(const Student& t) const {
        return score > t.score;
    }

    // Getter for roll number
    long int getRoll() const {
        return roll;
    }
};

class System {
    vector<Student> v;
    vector<Student>::iterator it;
public:
    System() {
        int ch, r;
        float s;
        string n;

        while (true) {
            cout << "Enter choice\n1 to add\n2 to remove\n3 to access\n4 to count\n5 to find the highest score\n6 to find student with substring in name\n7 to find students without substring in name\n";
            cin >> ch;

            switch (ch) {
                case 1: {
                    cout << "Enter roll\n";
                    cin >> r;
                    cout << "Enter name\n";
                    cin.ignore(); // Clearing buffer
                    getline(cin, n);
                    cout << "Enter score\n";
                    cin >> s;
                    Student ob(r, n, s);
                    v.push_back(ob);
                    break;
                }
                case 2: {
                    // Logic for removing a student
                    break;
                }
                case 3: {
                    
                    break;
                }
                case 4: {
                    cout << "No of students= " << v.size() << '\n';
                    break;
                }
                case 5: {
                    if (!v.empty()) {
                        it = max_element(v.begin(), v.end(), [](const Student& a, const Student& b) {
                            return a > b;
                        });
                        cout << "Student with the highest score:\n";
                        it->display();
                    } else {
                        cout << "No students available\n";
                    }
                    break;
                }
                case 6: {
                    // Logic for finding a student with a substring in the name
                    break;
                }
                case 7: {
                    // Logic for finding students without substring in the name
                    break;
                }
                default:
                    return;
            }
        }
    }
};

int main() {
    System sys;
    return 0;
}
