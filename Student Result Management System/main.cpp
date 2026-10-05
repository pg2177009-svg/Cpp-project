#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    int rollNo;
    string name;
    int marks[5];
    int total;
    float percentage;
    char grade;
};

void displayMenu() {
    cout << "\n========================================\n";
    cout << "     STUDENT RESULT MANAGEMENT SYSTEM\n";
    cout << "========================================\n";
    cout << "1. Add Student\n";
    cout << "2. Display All Students\n";
    cout << "3. Search Student\n";
    cout << "4. Display Student Result\n";
    cout << "5. Find Topper\n";
    cout << "6. Sort by Percentage\n";
    cout << "7. Display Failed Students\n";
    cout << "8. Exit\n";
    cout << "========================================\n";
    cout << "Enter your choice: ";
}

void addStudent(vector<Student>& students) {

    Student s;

    cout << "\n========== ADD STUDENT ==========\n";

    cout << "Enter Roll Number: ";
    cin >> s.rollNo;

    for (const Student& student : students) {
        if (student.rollNo == s.rollNo) {
            cout << "Error: Roll number already exists!\n";
            return;
        }
    }

    cin.ignore();

    cout << "Enter Student Name: ";
    getline(cin, s.name);

    string subjects[5] = {
        "C++",
        "DSA",
        "Mathematics",
        "Physics",
        "English"
    };

    s.total = 0;

    for (int i = 0; i < 5; i++) {

        do {
            cout << "Enter marks in " << subjects[i] << " (0-100): ";
            cin >> s.marks[i];

            if (s.marks[i] < 0 || s.marks[i] > 100) {
                cout << "Invalid marks! Enter marks between 0 and 100.\n";
            }

        } while (s.marks[i] < 0 || s.marks[i] > 100);

        s.total += s.marks[i];
    }

    s.percentage = s.total / 5.0;

    if (s.percentage >= 90) {
        s.grade = 'A';
    }
    else if (s.percentage >= 80) {
        s.grade = 'B';
    }
    else if (s.percentage >= 70) {
        s.grade = 'C';
    }
    else if (s.percentage >= 60) {
        s.grade = 'D';
    }
    else if (s.percentage >= 40) {
        s.grade = 'E';
    }
    else {
        s.grade = 'F';
    }

    students.push_back(s);

    cout << "\nStudent added successfully!\n";
    cout << "Total: " << s.total << "/500\n";
    cout << "Percentage: " << s.percentage << "%\n";
    cout << "Grade: " << s.grade << "\n";
}

void displayAllStudents(const vector<Student>& students) {

    if (students.empty()) {
        cout << "\nNo students found!\n";
        return;
    }

    cout << "\n================ ALL STUDENTS ================\n";

    cout << "Roll No.\tName\t\tTotal\tPercentage\tGrade\n";

    cout << "------------------------------------------------------------\n";

    for (const Student& s : students) {

        cout << s.rollNo << "\t\t"
             << s.name << "\t\t"
             << s.total << "\t"
             << s.percentage << "%\t\t"
             << s.grade << "\n";
    }

    cout << "============================================================\n";
}

int main() {

    vector<Student> students;

    int choice;

    do {

        displayMenu();

        cin >> choice;

        switch (choice) {

            case 1:
                addStudent(students);
                break;

            case 2:
                displayAllStudents(students);
                break;

            case 3:
                cout << "\nSearch Student feature will be added soon.\n";
                break;

            case 4:
                cout << "\nDisplay Result feature will be added soon.\n";
                break;

            case 5:
                cout << "\nFind Topper feature will be added soon.\n";
                break;

            case 6:
                cout << "\nSort feature will be added soon.\n";
                break;

            case 7:
                cout << "\nFailed Students feature will be added soon.\n";
                break;

            case 8:
                cout << "\nThank you for using Student Result Management System!\n";
                break;

            default:
                cout << "\nInvalid choice! Please enter a number between 1 and 8.\n";
        }

    } while (choice != 8);

    return 0;
}