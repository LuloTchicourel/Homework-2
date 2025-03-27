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
    
    void change_hour(int new_h);
    void change_minute(int new_m);
    void change_second(int new_s);
    void change_period(string new_p);

    void peek_hour();
    void peek_minute();
    void peek_second();
    void peek_period();

    void military_time();
};