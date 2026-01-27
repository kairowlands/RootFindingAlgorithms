// Kai Rowlands
// Modified Secant Method

#include <cmath>
#include <iostream>

using namespace std;

// Define the function we are applying the modified secant method to
double f(double x){
    return x * x * x / 5.0 + sin(2.0 * x) - 2.0;
}

double delta = 0.01;    // Define the pertubation value

double secant(double x0){
    double h = (delta * f(x0)) / (f(x0 + delta) - f(x0));
    double tolerance = 0.00001;

    while(abs(h) >= tolerance){
        h = (delta * f(x0)) / (f(x0 + delta) - f(x0));
        x0 = x0 - h;                                    // Modified secant method formula
    }
    cout << "The root of the f is: " << x0;

    return x0;   // Returns the root of f
}

int main(){
    double x0 = -1.0;   // Initial guess
    
    secant(x0);         // Computes the modified secant method evaluated at x0

    return 0;
}
