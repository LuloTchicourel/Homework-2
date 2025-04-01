#pragma once
#include <iostream>
#include <string>

using namespace std;

class Time {
private:
    int hour;
    int minute;
    int second;
    string period;

public:
    Time(int h = 0, int m = 0, int s = 0, string p = "a.m.");
    
    void read_time_values();

    void print();
    
    void set_hour(int new_h);
    void set_minute(int new_m);
    void set_second(int new_s);
    void set_period(string new_p);

    void get_hour();
    void get_minute();
    void get_second();
    void get_period();

    void military_time();
};