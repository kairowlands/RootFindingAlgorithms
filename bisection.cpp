// Kai Rowlands
// Bisection Method

#include <cmath>
#include <iostream>

using namespace std;

// Define the function we are applying the bisection method to
double f(double x){
    return x * x * x / 5.0 + sin(2.0 * x) - 2.0;
}

// Define the bisection method
double bisection(double a, double b){
    double c = a;                       // Assigns the value of a to c, c will become a new bound
    double tolerance = 0.00001;

    while((b - a) >= tolerance){
        c = (a + b) / 2.0;          // Compute the midpoint of a and b

        // Determines if a sign change occurs between a and c
        if(f(a) * f(c) < 0){
            b = c;              // If sign change occurs, then c will become the new upper bound
        }
        else{
            a = c;  // If sign change does not occur, then c becomes the new lower bound
        }
    }
    cout << "The root of the f is: " << c;

    return c;   // Returns the root of f
}

int main(){
    double a = 1.0; // Lower bound guess
    double b = 4.0; // Upper bound guess

    bisection(a, b);

    return 0;
}