#include <iostream>
#include <iomanip>

using namespace std;

class Time{
    private:
        int hour;
        int minute;
        int second;
        string period;
    public:
        Time(int h = 0, int m = 0, int s = 0, string p = "a.m."){
            if (h < 0 || h > 12){
                cout << "Invalid hour (" << h << "). Try again.\n";
                while (h < 0 || h > 12){
                    cout << "Hour: "; cin >> h;
                }
            }
            if (m < 0 || m > 59){
                cout << "Invalid minute (" << m << "). Try again.\n";
                while (m < 0 || m > 59){
                    cout << "Minute: "; cin >> m;
                }
            }
            if (s < 0 || s > 59){
                cout << "Invalid second (" << s << "). Defaulting to 00.\n";
                while (s < 0 || s > 59){
                    cout << "Second: "; cin >> s;
                }
            }
            if (p != "a.m." && p != "p.m."){
                cout << "Invalid period (" << p << "). Defaulting to 'a.m.'.\n";
                while (p != "a.m." && p != "p.m."){
                    cout << "Period: "; cin >> p;
                }
            }
            hour = h;
            minute = m;
            second = s;
            period = p;
        }
        void read_time_values() {
            int h = -1, m = -1, s = -1; 
            string p;
            while (h < 0 || h > 12) {
                cout << "Hour: ";
                cin >> h;
            }
            while (m < 0 || m > 59) {
                cout << "Minute: ";
                cin >> m;
            }
            while (s < 0 || s > 59) {
                cout << "Second: ";
                cin >> s;
            }
            while (p != "a.m." && p != "p.m.") {
                cout << "Period: ";
                cin >> p;
            }
            hour = h;
            minute = m;
            second = s;
            period = p;
        }
        void print(){
            cout << setfill('0') << setw(2) << hour << "h, " << setw(2) << minute << "m, " << setw(2) << second << "s " << period << endl;
        }
        void change_hour(int new_h) {
            if (new_h < 0 || new_h > 12) {
                cout << "Invalid hour (" << new_h << "). Try again.\n";
                while (new_h < 0 || new_h > 12) {
                    cout << "Hour: ";
                    cin >> new_h;
                }
            }
            hour = new_h;
        }
        void change_minute(int new_m) {
            if (new_m < 0 || new_m > 59) {
                cout << "Invalid minute (" << new_m << "). Try again.\n";
                while (new_m < 0 || new_m > 59) {
                    cout << "Minute: ";
                    cin >> new_m;
                }
            }
            minute = new_m;
        }
        void change_second(int new_s) {
            if (new_s < 0 || new_s > 59) {
                cout << "Invalid second (" << new_s << "). Try again.\n";
                while (new_s < 0 || new_s > 59) {
                    cout << "Second: ";
                    cin >> new_s;
                }
            }
            second = new_s;
        }
        void change_period(string new_p) {
            if (new_p != "a.m." && new_p != "p.m.") {
                cout << "Invalid period (" << new_p << "). Try again.\n";
                while (new_p != "a.m." && new_p != "p.m.") {
                    cout << "Period (a.m./p.m.): ";
                    cin >> new_p;
                }
            }
            period = new_p;
        }
        void peek_hour(){
            cout << "Hour: " << setw(2) << setfill('0') << hour << "h" << endl;
        }
        void peek_minute(){
            cout << "Minute: " << setw(2) << setfill('0') << minute << "m" << endl;
        }
        void peek_second(){
            cout << "Second: " << setw(2) << setfill('0') << second << "s" << endl;
        }
        void peek_period(){
            cout << "Period: " << period << endl;
        }
        void military_time(){
            int h24 = hour;
            if (period == "a.m." && hour == 12) h24 = 0;
            if (period == "p.m." && hour != 12) h24 = hour + 12;
            cout << setfill('0') << setw(2) << h24 << ":" << setw(2) << minute << ":" << setw(2) << second << endl;
        }
};