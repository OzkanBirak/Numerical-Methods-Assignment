#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double myFunction(double x) {
    return pow(x, 3) - x - 2;
}

double secantMethod(double x0, double x1, double tol, int max_iter) {
    double x2;

    cout << fixed << setprecision(6);
    cout << "------------------------------------------------------------\n";
    cout << "Iter\t" << "x0\t\t" << "x1\t\t" << "x2\t\t" << "f(x2)\n";
    cout << "------------------------------------------------------------\n";

    for (int i = 1; i <= max_iter; ++i) {
        double f0 = myFunction(x0);
        double f1 = myFunction(x1);

        if (fabs(f1 - f0) < 1e-12) {
            cerr << "Division by zero risk (f(x1) - f(x0) too small) at iteration " << i << ".\n";
            return NAN;
        }

        x2 = x1 - f1 * (x1 - x0) / (f1 - f0);
        double f2 = myFunction(x2);

        cout << i << "\t" << x0 << "\t" << x1 << "\t" << x2 << "\t" << f2 << endl;

        if (fabs(x2 - x1) < tol) {
            cout << "\nConverged to a root after " << i << " iterations.\n";
            return x2;
        }

        x0 = x1;
        x1 = x2;
    }

    cerr << "\nMaximum iterations reached without convergence.\n";
    return x2;
}

int main() {
    cout << "===============================================\n";
    cout << "   Welcome to Your Custom Secant Root Solver!\n";
    cout << "===============================================\n\n";

    double x0 = 1.0;
    double x1 = 2.0;
    double tolerance = 1e-6;
    int maxIterations = 100;

    double root = secantMethod(x0, x1, tolerance, maxIterations);

    if (!isnan(root)) {
        cout << "\nFinal estimated root: " << root << endl;
    }

    cout << "\nThank you for using this special solver made just for you!\n";
    return 0;
}
