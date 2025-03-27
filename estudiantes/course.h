#include "students.h"

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