#include "real.h"
#include "complex.h"
#include "integer.h"

int main(){
    int option = -1;
    while (option != 0){
        cout << "\n== NUMBERS MENU ==\n";
        cout << "1. Integers\n";
        cout << "2. Complex\n";
        cout << "3. Real\n";
        cout << "0. Exit\n";
        cout << "Option: "; cin >> option; cout << endl;

        if (option == 1){
            int n;
            cout << "Value: "; cin >> n; cout << endl;
            unique_ptr<Number> number = make_unique<Integer>(n);
            cout << "Your number: " << number->to_string() << endl;
            int option2 = -1;
            while (option2 != 0){
                cout << "\n== INTEGER MENU ==\n";
                cout << "1. Add\n";
                cout << "2. Subtract\n";
                cout << "3. Multiply\n";
                cout << "4. Divide\n";
                cout << "0. Exit\n";
                cout << "Option: "; cin >> option2; cout << endl;

                if (option2 == 1){
                    int v;
                    cout << "New number value: "; cin >> v; cout << endl;
                    unique_ptr<Number> number2 = make_unique<Integer>(v);
                    cout << "Doing addition of " << number->to_string() << " + " << v << " ..." << endl;
                    unique_ptr<Number> result(number->add(*number2));
                    cout << "Result = " << result->to_string() << endl;
                    cout << "This is now your new number...\n";
                    number = std::move(result);
                }
                else if (option2 == 2){
                    int v;
                    cout << "New number value: "; cin >> v; cout << endl;
                    unique_ptr<Number> number2 = make_unique<Integer>(v);
                    cout << "Doing subtraction of " << number->to_string() << " - " << v << " ..." << endl;
                    unique_ptr<Number> result(number->subtract(*number2));
                    cout << "Result = " << result->to_string() << endl;
                    cout << "This is now your new number...\n";
                    number = std::move(result);
                }
                else if (option2 == 3){
                    int v;
                    cout << "New number value: "; cin >> v; cout << endl;
                    unique_ptr<Number> number2 = make_unique<Integer>(v);
                    cout << "Doing multiplication of " << number->to_string() << " * " << v << " ..." << endl;
                    unique_ptr<Number> result(number->multiply(*number2));
                    cout << "Result = " << result->to_string() << endl;
                    cout << "This is now your new number...\n";
                    number = std::move(result);

                }
                else if (option2 == 4){
                    int v;
                    cout << "New number value: "; cin >> v; cout << endl;
                    unique_ptr<Number> number2 = make_unique<Integer>(v);
                    cout << "Doing division of " << number->to_string() << " / " << v << " ..." << endl;
                    unique_ptr<Number> result(number->divide(*number2));
                    if (result == nullptr){
                        cout << "Invalid operation, try again...\n";
                        continue;
                    }
                    cout << "Result = " << result->to_string() << endl;
                    cout << "This is now your new number...\n";
                    number = std::move(result);
                }
                else if (option2 == 0){
                    cout << "Exiting...\n"; break;
                }
                else cout << "Invalid option. Try again.\n";
            }
        }
        if (option == 2){
            float r, i;
            cout << "Real value: "; cin >> r; cout << endl;
            cout << "Imaginary value: "; cin >> i; cout << endl;
            unique_ptr<Number> number = make_unique<Complex>(r, i);
            cout << "Your number: " << number->to_string() << endl;
            int option2 = -1;
            while (option2 != 0){
                cout << "\n== COMPLEX MENU ==\n";
                cout << "1. Add\n";
                cout << "2. Subtract\n";
                cout << "3. Multiply\n";
                cout << "4. Divide\n";
                cout << "0. Exit\n";
                cout << "Option: "; cin >> option2; cout << endl;

                if (option2 == 1){
                    float r2, i2;
                    cout << "Real value: "; cin >> r2; cout << endl;
                    cout << "Imaginary value: "; cin >> i2; cout << endl;
                    unique_ptr<Number> number2 = make_unique<Complex>(r2, i2);
                    cout << "Doing addition of " << number->to_string() << " + " << number2->to_string() << " ..." << endl;
                    unique_ptr<Number> result(number->add(*number2));
                    cout << "Result = " << result->to_string() << endl;
                    cout << "This is now your new number...\n";
                    number = std::move(result);
                }
                else if (option2 == 2){
                    float r2, i2;
                    cout << "Real value: "; cin >> r2; cout << endl;
                    cout << "Imaginary value: "; cin >> i2; cout << endl;
                    unique_ptr<Number> number2 = make_unique<Complex>(r2, i2);
                    cout << "Doing subtraction of " << number->to_string() << " - (" << number2->to_string() << ") ..." << endl;
                    unique_ptr<Number> result(number->subtract(*number2));
                    cout << "Result = " << result->to_string() << endl;
                    cout << "This is now your new number...\n";
                    number = std::move(result);
                }
                else if (option2 == 3){
                    float r2, i2;
                    cout << "Real value: "; cin >> r2; cout << endl;
                    cout << "Imaginary value: "; cin >> i2; cout << endl;
                    unique_ptr<Number> number2 = make_unique<Complex>(r2, i2);
                    cout << "Doing multiplication of " << number->to_string() << " * " << number2->to_string() << " ..." << endl;
                    unique_ptr<Number> result(number->multiply(*number2));
                    cout << "Result = " << result->to_string() << endl;
                    cout << "This is now your new number...\n";
                    number = std::move(result);
                }
                else if (option2 == 4){
                    float r2, i2;
                    cout << "Real value: "; cin >> r2; cout << endl;
                    cout << "Imaginary value: "; cin >> i2; cout << endl;
                    unique_ptr<Number> number2 = make_unique<Complex>(r2, i2);
                    cout << "Doing division of " << number->to_string() << " / " << number2->to_string() << " ..." << endl;
                    unique_ptr<Number> result(number->divide(*number2));
                    if (result == nullptr){
                        cout << "Invalid operation, try again...\n";
                        continue;
                    }
                    cout << "Result = " << result->to_string() << endl;
                    cout << "This is now your new number...\n";
                    number = std::move(result);
                }
                else if (option2 == 0){
                    cout << "Exiting...\n"; break;
                }
                else cout << "Invalid option. Try again.\n";
            }
        }
        else if (option == 3){
            float f;
            cout << "Value: "; cin >> f; cout << endl;
            unique_ptr<Number> number = make_unique<Real>(f);
            cout << "Your number: " << number->to_string() << endl;
            int option2 = -1;
            while (option2 != 0){
                cout << "\n== REAL MENU ==\n";
                cout << "1. Add\n";
                cout << "2. Subtract\n";
                cout << "3. Multiply\n";
                cout << "4. Divide\n";
                cout << "0. Exit\n";
                cout << "Option: "; cin >> option2; cout << endl;

                if (option2 == 1){
                    float v;
                    cout << "New number value: "; cin >> v; cout << endl;
                    unique_ptr<Number> number2 = make_unique<Real>(v);
                    cout << "Doing addition of " << number->to_string() << " + " << v << " ..." << endl;
                    unique_ptr<Number> result(number->add(*number2));
                    cout << "Result = " << result->to_string() << endl;
                    cout << "This is now your new number...\n";
                    number = std::move(result);
                }
                else if (option2 == 2){
                    float v;
                    cout << "New number value: "; cin >> v; cout << endl;
                    unique_ptr<Number> number2 = make_unique<Real>(v);
                    cout << "Doing subtraction of " << number->to_string() << " - " << v << " ..." << endl;
                    unique_ptr<Number> result(number->subtract(*number2));
                    cout << "Result = " << result->to_string() << endl;
                    cout << "This is now your new number...\n";
                    number = std::move(result);
                }
                else if (option2 == 3){
                    float v;
                    cout << "New number value: "; cin >> v; cout << endl;
                    unique_ptr<Number> number2 = make_unique<Real>(v);
                    cout << "Doing multiplication of " << number->to_string() << " * " << v << " ..." << endl;
                    unique_ptr<Number> result(number->multiply(*number2));
                    cout << "Result = " << result->to_string() << endl;
                    cout << "This is now your new number...\n";
                    number = std::move(result);
                }
                else if (option2 == 4){
                    float v;
                    cout << "New number value: "; cin >> v; cout << endl;
                    unique_ptr<Number> number2 = make_unique<Real>(v);
                    cout << "Doing division of " << number->to_string() << " / " << v << " ..." << endl;
                    unique_ptr<Number> result(number->divide(*number2));
                    if (result == nullptr){
                        cout << "Invalid operation, try again...\n";
                        continue;
                    }
                    cout << "Result = " << result->to_string() << endl;
                    cout << "This is now your new number...\n";
                    number = std::move(result);
                }
                else if (option2 == 0){
                    cout << "Exiting...\n"; break;
                }
                else cout << "Invalid option. Try again.\n";
            }
        }
        else if (option == 0){
            cout << "Exiting program...\n"; break;
        }
        else cout << "Invalid option. Try again.\n";
    }

    return 0;
}