#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;


	

// -------------------- COURSE CLASS --------------------
class Course {
private:
    string name;
    int score;
    char grade;

public:
    Course(string n = "", int s = 0) {
        name = n;
        setScore(s);
    }

    char calculateGrade(int score) {
        if (score >= 80) return 'A';
        else if (score >= 70) return 'B';
        else if (score >= 60) return 'C';
        else if (score >= 50) return 'D';
        else return 'F';
    }

    void setScore(int s) {
        score = s;
        grade = calculateGrade(s);
    }

    string getName() { return name; }
    int getScore() { return score; }
    char getGrade() { return grade; }

    void display() {
        cout << left << setw(30) << name
             <<left<< setw(30) << score
             <<left<< setw(30) << grade << endl;
    }
};

// -------------------- STUDENT CLASS --------------------
class Student {
private:
    string name;
    int id;
    vector<Course> courses;

public:
    Student(string n = "", int i = 0) {
        name = n;
        id = i;
    }

    int getId() { return id; }
    string getName() { return name; }

    void addCourse(string cname) {
        courses.push_back(Course(cname, 0));
    }

    void enterScores() {
        for (auto &c : courses) {
            int score;
            cout << "Enter score for " << c.getName() << ": ";

            while (!(cin >> score) || score < 0 || score > 100) {
                cout << "Invalid. Enter 0-100: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }

            c.setScore(score);
        }
    }

    double calculateGPA() {
        double total = 0;
        for (auto &c : courses) {
            switch (c.getGrade()) {
                case 'A': total += 4; break;
                case 'B': total += 3; break;
                case 'C': total += 2; break;
                case 'D': total += 1; break;
                default: total += 0;
            }
        }
        return courses.empty() ? 0 : total / courses.size();
    }

    string getClassification() {
        double gpa = calculateGPA();
        if (gpa >= 3.5) return "First Class";
        else if (gpa >= 3.0) return "Second Class Upper";
        else if (gpa >= 2.0) return "Second Class Lower";
        else return "Pass";
    }

    void displayTranscript() {
        cout << "\n===== TRANSCRIPT =====\n";
        cout << "Name: " << name << " | ID: " << id << endl;

        cout << left << setw(15) << "Course"
             << setw(10) << "Score"
             << setw(10) << "Grade" << endl;

        for (auto &c : courses)
            c.display();

        cout << "GPA: " << fixed << setprecision(2) << calculateGPA() << endl;
        cout << "Class: " << getClassification() << endl;
    }

    void save(ofstream &f) {
        f << id << "\n" << name << "\n" << courses.size() << "\n";
        for (auto &c : courses)
            f << c.getName() << " " << c.getScore() << "\n";
    }

    void load(ifstream &f) {
        int count;
        f >> id;
        f.ignore();
        getline(f, name);
        f >> count;

        courses.clear();

        for (int i = 0; i < count; i++) {
            string cname;
            int score;
            f >> cname >> score;
            courses.push_back(Course(cname, score));
        }
    }
};

// -------------------- SYSTEM CLASS --------------------
class SchoolSystem {
private:
    vector<Student> students;

    // ?? simple login
    bool login() {
        string user, pass;
        cout << "Username: ";
        cin >> user;
        cout << "Password: ";
        cin >> pass;

        return (user == "admin" && pass == "0927");
    }

public:
    void addStudent() {
        int id;
        string name;

        cout << "ID: ";
        cin >> id;
        cin.ignore();

        cout << "Name: ";
        getline(cin, name);

        Student s(name, id);

        int n;
        cout << "Number of courses: ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            string cname;
            cin.ignore();
            cout << "Course: ";
            getline(cin, cname);
            s.addCourse(cname);
        }

        s.enterScores();
        students.push_back(s);

        cout << "Added successfully!\n";
    }

    void searchStudent() {
        int id;
        cout << "Enter ID to search: ";
        cin >> id;

        for (auto &s : students) {
            if (s.getId() == id) {
                s.displayTranscript();
                return;
            }
        }
        cout << "Student not found.\n";
    }

    void deleteStudent() {
        int id;
        cout << "Enter ID to delete: ";
        cin >> id;

        for (int i = 0; i < students.size(); i++) {
            if (students[i].getId() == id) {
                students.erase(students.begin() + i);
                cout << "Deleted.\n";
                return;
            }
        }
        cout << "Not found.\n";
    }

    void viewAll() {
        for (auto &s : students) {
            s.displayTranscript();
            cout << "-----------------\n";
        }
    }

    void save() {
        ofstream f("data.txt");
        f << students.size() << "\n";
        for (auto &s : students)
            s.save(f);
        cout << "Saved.\n";
    }

    void load() {
        ifstream f("data.txt");
        if (!f) {
            cout << "No file.\n";
            return;
        }

        int count;
        f >> count;

        students.clear();

        for (int i = 0; i < count; i++) {
            Student s;
            s.load(f);
            students.push_back(s);
        }

        cout << "Loaded.\n";
    }

    void menu() {
        if (!login()) {
            cout << "Access denied.\n";
            return;
        }

        int choice;
        do {
            cout << "\n==== MENU ====\n";
            cout << "1. Add Student\n";
            cout << "2. View All\n";
            cout << "3. Search\n";
            cout << "4. Delete\n";
            cout << "5. Save\n";
            cout << "6. Load\n";
            cout << "7. Exit\n";
            cout << "Choice: ";
            cin >> choice;

            switch (choice) {
                case 1: addStudent(); break;
                case 2: viewAll(); break;
                case 3: searchStudent(); break;
                case 4: deleteStudent(); break;
                case 5: save(); break;
                case 6: load(); break;
            }

        } while (choice != 7);
    }
};

// -------------------- MAIN --------------------
int main() {
    SchoolSystem system;
    system.menu();
    return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
