// Kai Rowlands
// Newton-Raphson Method

#include <cmath>    // Used for the absolute value function and the sine function
#include <iostream>

using namespace std;

// Define the function we are applying the Newton-Raphson method to
double f(double x){
    return x * x * x / 5.0 + sin(2.0 * x) - 2.0;
}

// Define the derivative of f
double df(double x){
    return 3.0 / 5.0 * x * x + 2.0 * cos(2.0 * x);
}

// Define the Newton-Raphson method
double newton(double x0){
    double h = f(x0) / df(x0);
    double tolerance = 0.00001;

    while(abs(h) >= tolerance){
        h = f(x0) / df(x0);
        x0 = x0 - h;            // Newton-Raphson formula
    }
    cout << "The root of the f is: " << x0;   // Output message followed by corresponding numeric value

    return x0;   // Returns the root of f
}

int main(){
    double x0 = -1.0;   // Initial guess

    newton(x0);         // Computes the Newton-Raphson method evaluated at x0

    return 0;
}