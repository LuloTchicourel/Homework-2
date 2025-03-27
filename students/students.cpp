#include "students.h"

int main(){
    Student chalar = Student("Mario Chalar", 1);
    Student eze = Student("Ezequile Velimirovich", 2);
    Student poli = Student("Poli Mardo", 3);
    vector<Student> p = {chalar, eze, poli};
    Course c = Course(p);
    c.print_ordered();
    return 0;
}