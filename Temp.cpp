#include <iostream>

using namespace std;

int main() {
    string type;
    string check;
    string speed_check;
    float speed;
    float tin;
while (type != "stop"){
        cout << "Select speed or temp: ";
        cin >> type;
        if (type == "temp"){
            while (check != "return"){
                cout << "Select imperial or metric conversion: ";
                cin >> check;
                while (tin != 9999.0){
                    if (check == "imperial"){
                        cout << "Enter fahrenheit temp: ";
                        cin >> tin;
                        cout << (5.0/9.0) * (tin - 32.0) << " celsius" << ".\n";
                    }
                    if (check == "metric"){
                        cout << "Enter celcius temp: ";
                        cin >> tin;
                        cout << (tin / 5.0) * 9.0 + 32.0 << " fahrenheit" <<  ".\n";
                    }
                    if (tin == 9999.0){
                        break;
                    }
                }       
                if (check == "return"){
                    break;
                }    
            }
        }
        while (speed_check != "return"){
            if (type == "speed"){
                cout << "Select miles of kilometers: ";
                cin >> speed_check;
                while (speed != 9999){
                    if (speed_check == "miles"){
                        cout << "Enter speed in miles: ";
                        cin >> speed;
                        cout << speed * 1.609 << " kilometers per hour" << ".\n";
                    }
                    if (speed_check == "kilometers"){
                        cout << "Enter speed in kilometers: ";
                        cin >> speed;
                        cout << speed / 1.609 << " miles per hour" << ".\n";
                    }
                }
                if (speed == 9999){
                    break;
                }
            }    
            if (speed_check == "return"){
                break;
            }
        }    
        if (type == "stop"){
            break;
        }
    }
    return 0;
}
