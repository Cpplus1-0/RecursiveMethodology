#include <iostream>
#include <fstream>
#include <limits>
#include <cmath>

#include "Series.h"
#include "Series.cpp"

using namespace std;

int main()
{
    //Considering counting from 0 for array indices of sequence elements there n is converted to n--

    cout << "Create a series and compute the sum of its m to n elements. " << endl;

    cout << "Choose:\t(1) Arithmetic Series " << endl;
    cout << "\t(2) Geometric Series " << endl;
    cout << "\t(3) Convergent Series " << endl;
    cout << "\t(4) Harmonic Series " << endl;
    cout << "\t(5) Fibonacci Series " << endl;
    cout << "\t(6) Harmonic Series with Prime-Denominator" << endl;
    cout << "\t(7) Sum of Squares Series" << endl;
    cout << "\t(8) Prime Series " << endl << endl;
    cout << "Enter choice: ";
    int choice;
    cin >> choice;

    cout << endl;

    double firstElement;

    if(choice < 3)
    {
        cout << endl << "Enter 1st element: ";
        cin >> firstElement;
    }
    Series series;
    series.setFirstElement(firstElement);

    double delta, sum; int n;
    switch(choice)
    {
        case 1:
            cout << "Enter rate of change: ";
            cin >> delta;
            series.setDelta(delta);

            cout << endl << "Find nth element of the arithmetic series and the sum of its first n elements. " << endl << endl;
            cout << "Enter n: ";
            cin >> n;
            cout << "  Arithmetic(n) = Arithmetic(" << n << "): " << series.arithmetic(n-1) << endl;
            cout << "  ArithmeticSum(n) = ArithmeticSum(" << n << "): ";
            series.printArithmetic(n-1);
            cout << " = " << series.arithmeticSum(firstElement, n) << endl;

            break;

        case 2:
            cout << "Enter ratio: "; cin >> delta;
            if(delta < 1)
                cout << "Ratio is less than 1 and it is a convergent series where the sum of all the values in the ";

            cout << endl << "Find nth element of the geometric series and the sum of its first n elements. " << endl << endl;
            cout << "Enter n: "; cin >> n;

            series.setDelta(delta);
            cout << "  Geometric(" << n << "): " << series.geometric(n-1) << endl;

            cout << "  GeometricSum(n, ratio): GeometricSum(" << n << ", " << delta << ") = ";
            series.printGeometric(n-1);

            cout << " = " <<  series.geometricSum(firstElement, n) << endl;
            break;

        case 3:
            cout << "Geometric series with a ratio of less than 1 are convergent. " << endl;
            cout << "Enter first element: ";
            cin >> firstElement;
            cout << "Enter rate of change: ";
            for(cin >> delta; delta >= 1; cin >> delta)
            {
                cin.clear();
                cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                cout << endl << "Invalid input, convergent series have a ratio less than 1. " << endl;
                cout << "Please try again, enter rate of change: ";
            }
            series.setDelta(delta);
            cout << "ConvergentSum(firstElement, ratio) = ConvergentSum(" << firstElement << ", " << delta << ") = ";
            series.printConvergent(firstElement);
            cout << series.convergentSum(firstElement) << " = ";
            cout << float((int)(series.convergentSum(firstElement) * 10 + 0.5))/10 << endl;

            break;

        case 4:
            cout << "Harmonic sum is the reciprocal summation. " << endl;
            cout << "Enter the index of the 1st and last element to compute the sum of the elements. " << endl;
            cout << "Enter first element: "; cin >> firstElement;
            cout << "Enter n: "; cin >> n;
            series.setFirstElement(firstElement);
            cout << "HarmonicSum(" << firstElement << "," << n << "):\t";
            series.printHarmonic_fraction(n);
            cout << endl << "\t\t\t = ";
            series.printHarmonic_decimal(n);
            cout << " = " << series.harmonicSum(n) << endl;
            break;

        case 5:     //sum calculates too early
            cout << endl << "Fibonacci series is a special series with, " << endl;
            cout << "nth element calculated as the sum of the previous 2 terms, where " << endl;
            cout << "First term = 0 \t Second term = 1" << endl;

            cout << endl << "(1)\tFind nth element \t(2) Summation(a,b) " << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            cout << endl << "Enter " << ((choice-1) ? "a": "n") << ": ";
            cin >> firstElement;

            if(choice-1)
            {
                series.setFirstElement(firstElement);
                cout << "Enter b: ";
                cin >> n;
                cout << "   FibonacciSum(" << n << "): ";

                series.printFib(n-1);
                cout << " = " << series.fibSum(n-1) << endl;
            }
            else
                cout << "-->Fibonacci(" << firstElement << "): " << series.fib(firstElement-1) << endl;
            break;

        case 6:
            cout << "Find the sum of n elements for the harmonic series with prime denominators. " << endl;
            cout << "Enter index of first element: ";
            cin >> firstElement;
            series.setFirstElement(firstElement);
            cout << "Enter index of last element: ";
            cin >> n;
            cout << endl;
            cout << "HarmonicSeries_Prime(" << firstElement << "," << n << ") = ";
            series.printHarmonic_primeDecimal(n);
            cout << " = ";
            series.printHarmonic_primeFraction(n);
            cout << " = " << series.harmonicSum_prime(n) << endl;
            break;

       case 7:
            cout << "Find the sum of n elements for the Squared series. " << endl;
            cout << "Enter first element: ";
            cin >> firstElement;
            series.setFirstElement(firstElement);
            cout << "Enter last element: ";
            cin >> n;
            cout << endl;
            cout << "SumOfSquares(" << firstElement << "," << n << ") = ";
            series.printSumOfSquares(n);
            cout << " = " << series.sumOfSquares(n) << endl;
            break;

       case 8:
            cout << "Enter first element: ";
            cin >> firstElement;
            series.setFirstElement(firstElement);
            cout << "Enter last element: ";
            cin >> n;
            cout << endl;
            cout << "Sum of primes within this range: ";
            sum = series.primeSeries(firstElement, n);
            cout << " = " << sum << endl;

            break;

        default:
            cout << "Sorry! There is an error in your choice of input. " << endl;
    }
}
