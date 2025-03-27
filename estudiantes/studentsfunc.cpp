#include "students.h"

Student::Student(string fn, int n){
    full_name = fn; id = n;
}

string Student::get_name(){return full_name;}
int Student::get_id(){return id;}
float Student::get_average(string course){
    for (int i = 0; i < classes.size(); i++){
        if (classes[i].first == course) return classes[i].second;
    }
    return 0;
}
bool Student::operator < (Student student){return full_name < student.full_name;}
string Student::operator << (Student student){return student.full_name;}

Course::Course(vector<Student> student_list){
    students = student_list;
}

void Course::enroll(Student student){
    students.push_back(student);
    cout << "Student has been enrolled succesfully\n";
}

void Course::remove_student(Student student){
    for (int i = 0; i < students.size(); i++){
        if (students[i].get_id() == student.get_id()){
            students.erase(students.begin() + i); // para incializar el iter de vector
            cout << "Student has been erased succesfully\n";
            return; // freno el loop cuando se encuentre
        }
    }
    cout << "Student does not belong to this course\n";
}

bool Course::is_full(){return students.size() >= 20;}

void Course::print_ordered(){
    vector<string> names;
    for (int i = 0; i < students.size(); i++){
        names.push_back(students[i].get_name());
    }
    sort(names.begin(), names.end());
    cout << "Students in order: ";
    for (int i = 0; i < names.size(); i++){
        cout << names[i] << ", ";
    }
}


