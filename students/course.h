#pragma once
#include "students.h"
#include <string>
#include <vector>

using namespace std;

class Student;

class Course{
    private:
        string name;
        vector<Student*> students;
        const int capacity = 20;
    public:
        Course(string n); 
        string get_name();
        Student* get_student(string name);
        Student* get_student(int id);
        vector<Student*> get_all_students();
        void enroll(Student &student, float average);
        void remove_student(Student &student);
        bool is_full();
        void print_ordered();
        Course copy();
};