#include "course.h"

Course::Course(string n){
    name = n;
}

string Course::get_name(){return name;}

Student* Course::get_student(string name){
    for (int i = 0; i < students.size(); i++){
        if (students[i]->get_name() == name) return students[i];
    }
    cout << "Student does not belong in this course." << endl;
    return nullptr;
}

Student* Course::get_student(int id){
    for (int i = 0; i < students.size(); i++){
        if (students[i]->get_id() == id) return students[i];
    }
    cout << "Student does not belong in this course." << endl;
    return nullptr;
}

vector<Student*> Course::get_all_students(){return students;}

void Course::enroll(Student &student, float avg){
    students.push_back(&student);
    student.add_course(this, avg);
    cout << "Student has been enrolled succesfully\n";
}

void Course::remove_student(Student &student){
    for (int i = 0; i < students.size(); i++){
        if (students[i]->get_id() == student.get_id()){
            students.erase(students.begin() + i); // para incializar el iter de vector
            cout << "Student has been erased succesfully\n";
            student.remove_course(this);
            return; // freno el loop cuando se encuentre
        }
    }
    cout << "Student does not belong to this course\n";
}

bool Course::is_full(){return students.size() >= 20;}

void Course::print_ordered(){
    vector<Student> order;
    for (int i = 0; i < students.size(); i++) order.push_back(*students[i]);
    sort(order.begin(), order.end());
    cout << "Students in order: ";
    for (int i = 0; i < students.size(); i++){
        if (i == students.size() - 1){
            cout << order[i] << ".";
        }
        else cout << order[i] << ", ";
    }
    cout << endl;
}

Course Course::copy(){
    return *this;
}