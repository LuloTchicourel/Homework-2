#include "students.h"
#include "course.h"

int global_id = 1;

int main() {
    Course* copy_course = nullptr;
    vector<Student*> all_students;
    string n;
    cout << "Name for the course: "; getline(cin, n); 
    vector<float> averages;
    int num_students;
    cout << "How many students would you like to create? "; cin >> num_students; cin.ignore();
    for (int i = 0; i < num_students; i++){
        string name;
        float a;
        cout << "Enter full name for student #" << (i + 1) << ": "; 
        getline(cin, name);
        cout << "Enter average for the class " << n << ": "; cin >> a; 
        Student* s = new Student(name, global_id++);
        all_students.push_back(s);
        averages.push_back(a);
        cin.ignore();
    }
    Course course(n);
    for (int i = 0; i < all_students.size(); i++) course.enroll(*all_students[i], averages[i]);
    cout << "Course created succesfuly with " << all_students.size() << " students." << endl;

    int option = -1;
    while (option != 0){
        cout << "\n--- COURSE MENU ---\n";
        cout << "1. Enroll a student\n";
        cout << "2. Unenroll a student\n";
        cout << "3. Check if student is enrolled\n";
        cout << "4. Add course and grade to student\n";
        cout << "5. View all students (ordered)\n";
        cout << "6. View a student's course grades\n";
        cout << "7. Check if course is full\n";
        cout << "8. Copy course\n";
        cout << "9. View original and copied course\n";
        cout << "0. Exit\n";
        cout << "Enter option: ";
        cin >> option;

        if (option == 1){
            string n; float avg;
            cout << "Name of the student: "; cin.ignore(); getline(cin, n);
            cout << "Average score: "; cin >> avg; cout << endl;
            Student* new_student = new Student(n, global_id++);
            course.enroll(*new_student, avg);
            all_students.push_back(new_student); 
            cout << "Student has been enrolled with id " << global_id << ".\n";
        }
        else if (option == 2){
            int answer;
            string choice;
            while (choice != "y" && choice != "n"){
                cout << "Would you like to see the names and ID's? (y/n): ";
                cin >> choice;
                if (choice == "y"){
                    all_students = course.get_all_students();
                    for (int i = 0; i < all_students.size(); i++) {
                        cout << "[" << *all_students[i] << ", " << all_students[i]->get_id() << "]" << endl;
                    }
                }
                else if (choice != "n"){
                    cout << "Invalid choice, try again..." << endl;
                }
            }
            cout << "Use name [1] or id [2]? "; cin >> answer;
            while (answer != 1 && answer != 2){
                cout << "Invalid answer, try again...\n";
                cout << "Use name [1] or id [2]? "; cin >> answer; cout << endl;
            }
            Student* result = nullptr;
            if (answer == 1){
                string n;
                cout << "Name of the student: "; cin.ignore(); getline(cin, n); cout << endl;
                result = course.get_student(n);
            }
            else if (answer == 2){
                int m;
                cout << "ID: "; cin >> m; cout << endl;
                result = course.get_student(m);
            }
            if (result != nullptr) course.remove_student(*result);
        }
        else if (option == 3){
            int answer;
            cout << "Use name [1] or id [2]? "; cin >> answer; cout << endl;
            while (answer != 1 && answer != 2){
                cout << "Invalid answer, try again...";
                cout << "Use name [1] or id [2]? "; cin >> answer; cout << endl;
            }
            Student* result = nullptr;
            if (answer == 1){
                string name;
                cout << "Enter name: ";
                cin.ignore(); getline(cin, name);
                result = course.get_student(name);
            } 
            else {
                int id;
                cout << "Enter ID: ";
                cin >> id;
                result = course.get_student(id);
            }
            if (result != nullptr) cout << "Student is enrolled in the course.\n";
            else cout << "Student not found in the course.\n";
        }
        else if (option == 4){
            int id; float grade;
            cout << "Enter student ID: "; cin >> id;
            Student* s = course.get_student(id);
            if (s == nullptr) cout << "Student not found.\n";
            else {
                cout << "Enter grade for course '" << course.get_name() << "': "; cin >> grade;
                s->add_course(&course, grade);
                cout << "Grade added successfully.\n";
            }
        }
        else if (option == 5){
            course.print_ordered();
        }
        else if (option == 6){
            int method;
            cout << "Search by name [1] or ID [2]? "; cin >> method;
            while (method != 1 && method != 2){
                cout << "Invalid choice, please try again.\n";
                cout << "Search by name [1] or ID [2]? "; cin >> method;
            }
            Student* s = nullptr;
            if (method == 1){
                string name;
                cout << "Enter student name: ";
                cin.ignore(); getline(cin, name);
                s = course.get_student(name);
            } 
            else if (method == 2){
                int id;
                cout << "Enter student ID: ";
                cin >> id;
                s = course.get_student(id);
            }
            if (s == nullptr) cout << "Student not found.\n";
            else {
                float avg = s->get_average(course.get_name());
                if (avg == -1) cout << "No grade found for this course.\n";
                else cout << "Grade for course '" << course.get_name() << "': " << avg << endl;
            }
        }
        else if (option == 7){
            if (course.is_full()) cout << "The course is full.\n";
            else cout << "The course has available spots.\n";
        }
        else if (option == 8){
            delete copy_course;
            copy_course = new Course(course.copy());
            cout << "Course copied successfully!\n";
        }
        else if (option == 9){
            cout << "Original Course\n";
            course.print_ordered();
            cout << "Copied Course\n";
            if (copy_course) copy_course->print_ordered();
            else cout << "No copy available yet. Use option 8 first.\n";
        }
        else if (option == 0) cout << "Exiting program...\n";
        else cout << "\nInvalid option. Try again.\n";
    }
    for (Student* s : all_students) delete s;
    return 0;
}