#pragma once
#include <iostream>
#include "course.h"
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

class Course; 

class Student{
    private:
        string full_name;
        int id;
        vector<pair<Course*, float>> classes;
    public:
        Student(string fn, int n);
        string get_name();
        int get_id();
        void add_course(Course* course, float avg);
        void remove_course(Course* course);
        float get_average(string course);
        bool operator < (const Student student) const;
        friend ostream& operator<<(ostream& os, Student dt);
};
