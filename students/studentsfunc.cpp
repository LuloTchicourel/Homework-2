#include "students.h"

Student::Student(string fn, int n){
    full_name = fn; id = n;
}

string Student::get_name(){return full_name;}
int Student::get_id(){return id;}

void Student::add_course(Course* course, float avg){
    classes.push_back({course, avg});
}

void Student::remove_course(Course* course){
    string name = course->get_name();
    for (int i = 0; i < classes.size(); i++){
        if (classes[i].first->get_name() == name){
            classes.erase(classes.begin() + i);
            return;
        }
    }
    cout << "Course " << name << " does not exist." << endl;
}

float Student::get_average(string course){
    for (int i = 0; i < classes.size(); i++){
        if (classes[i].first->get_name() == course) return classes[i].second;
    }
    return 0;
}
bool Student::operator < (const Student student) const {return full_name < student.full_name;}

ostream& operator << (ostream& os, Student student){
    os << student.get_name();
    return os;
}


