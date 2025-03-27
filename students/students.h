#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Student{
    private:
        string full_name;
        int id;
        vector<pair<string, float>> classes;
    public:
        Student(string fn, int n);
        string get_name();
        int get_id();
        float get_average(string course);
        bool operator < (Student student);
        string operator << (Student student);
};

class Course{
    private:
        vector<Student> students;
        const int capacity = 20;
    public:
        Course(vector<Student> student_list = {});
        void enroll(Student student);
        void remove_student(Student student);
        bool is_full();
        void print_ordered();
        Course copy();
};