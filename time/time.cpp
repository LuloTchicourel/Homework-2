#include "time.h"

int main() {
    int option = -1;
    while (option != 0) {
        cout << "\n=== MENU ===\n";
        cout << "1. Initializing default\n";
        cout << "2. Initializing with hour\n";
        cout << "3. Initializing with hour and minute\n";
        cout << "4. Initializing with hour, minute and second\n";
        cout << "5. Initializing with hour, minute, second and period\n";
        cout << "6. Setting and getting individual values\n";
        cout << "7. Military time format\n";
        cout << "0. Exit\n";
        cout << "Select an option: " << endl;
        cin >> option;
        cout << "\n";

        if (option == 1) {
            Time t;
            t.print();
        } 
        else if (option == 2) {
            int h;
            cout << "Hour: "; cin >> h;
            Time t(h);
            t.print();
        } 
        else if (option == 3) {
            int h, m;
            cout << "Hour: "; cin >> h;
            cout << "Minute: "; cin >> m;
            Time t(h, m);
            t.print();
        } else if (option == 4) {
            int h, m, s;
            cout << "Hour: "; cin >> h;
            cout << "Minute: "; cin >> m;
            cout << "Second: "; cin >> s;
            Time t(h, m, s);
            t.print();
        } else if (option == 5) {
            int h, m, s; string p;
            cout << "Hour: "; cin >> h;
            cout << "Minute: "; cin >> m;
            cout << "Second: "; cin >> s;
            cout << "Period: "; cin >> p;
            Time t(h, m, s, p);
            t.print();
        } else if (option == 6) {
            Time t;
            cout << "Creating default...\n";
            t.print();

            int h, m, s; string p;
            vector<string> possibilities = {"hour", "minute", "second", "period"};
            for (int i = 0; i < possibilities.size(); i++){
                string answer = "";
                while (true){
                    cout << "Would you like to set the " << possibilities[i] << "? (y/n)\n";
                    cin >> answer;
                    if (answer == "y"){
                        if (possibilities[i] == "hour"){
                            cout << "New hour: "; cin >> h;
                            t.set_hour(h);
                        }
                        else if (possibilities[i] == "minute"){
                            cout << "New minute: "; cin >> m;
                            t.set_minute(m);    
                        }
                        else if (possibilities[i] == "second"){
                            cout << "New second: "; cin >> s;
                            t.set_second(s);    
                        }
                        else if (possibilities[i] == "period"){
                            cout << "New period: "; cin >> p;
                            t.set_period(p);
                        }
                        break;
                    }
                    else if (answer == "n") break;
                    else cout << "Invalid answer, please try again...\n";
                }
            }

            t.print();

            for (int i = 0; i < possibilities.size(); i++) {
                string answer = "";
                while (true) {
                    cout << "Would you like to get the " << possibilities[i] << "? (y/n)\n";
                    cin >> answer;
                    if (answer == "y") {
                        if (possibilities[i] == "hour") t.get_hour();
                        else if (possibilities[i] == "minute") t.get_minute();
                        else if (possibilities[i] == "second") t.get_second();
                        else if (possibilities[i] == "period") t.get_period();
                        break;
                    }
                    else if (answer == "n") break;
                    else cout << "Invalid answer, please try again...\n";
                }
            }
        } 
        else if (option == 7) {
            int h, m, s; string p;
            cout << "Hour: "; cin >> h;
            cout << "Minute: "; cin >> m;
            cout << "Second: "; cin >> s;
            cout << "Period: "; cin >> p;
            Time t(h, m, s, p);
            cout << "Military time:\n\n";
            t.military_time();
        } 
        else if (option == 0) cout << "Exiting program...\n";
        else cout << "\nInvalid option. Try again.\n";
    }

    return 0;
}