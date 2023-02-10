/*The creation of a curve calibration for analytical 
chemistry, where we obtain the values of a and b 
in a linear function, y = ax + b, and 
calculate the concentration of a set of samples*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void linear_calibration_curve(const vector<double> &x, const vector<double> &y, double &a, double &b) {
  int n = x.size();
  
  double sum_x = 0, sum_y = 0, sum_xy = 0, sum_xx = 0;
  for (int i = 0; i < n; i++) {
    sum_x += x[i];
    sum_y += y[i];
    sum_xy += x[i] * y[i];
    sum_xx += x[i] * x[i];
  }
  //a is the slope of the linear function and b is the 
  //intercept
  a = (n * sum_xy - sum_x * sum_y) / (n * sum_xx - sum_x * sum_x);
  b = (sum_y - a * sum_x) / n;
}

int main() {
  vector<double> x = {1, 2, 3, 4, 5};
  vector<double> y = {2, 4, 6, 8, 10};

  double a, b;
  linear_calibration_curve(x, y, a, b);

  cout << "The calibration curve is: y = " << a << "x + " << b << endl;
  
  return 0;
}
