#include<iostream>
using namespace std;

class Temperature {
    float cel;   // private

public:
    Temperature(float c = 0) {
        setCelsius(c);
    }

    void setCelsius(float c) {
        if (c >= -273.15)
            cel = c;
        else {
            cout << "Invalid temperature! Setting to 0°C.\n";
            cel = 0;
        }
    }

    void displayCelsius() {
        cout << "Celsius: " << cel << endl;
    }

    void displayFahrenheit() {
        cout << "Fahrenheit: " << (cel * 9 / 5) + 32 << endl;
    }

    void displayKelvin() {
        cout << "Kelvin: " << cel + 273.15 << endl;
    }
};

int main() {
    Temperature t(25);

    t.displayCelsius();
    t.displayFahrenheit();
    t.displayKelvin();

    return 0;
}
