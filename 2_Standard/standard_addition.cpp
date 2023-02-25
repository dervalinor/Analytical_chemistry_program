/*we have to calculate y = 0 and a function of dissolutions*/

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

double r_squared(const vector<double> &x, const vector<double> &y, double a, double b) {
  int n = x.size();

  double sum_y = 0, sum_yy = 0, sum_residual = 0;
  for (int i = 0; i < n; i++) {
    sum_y += y[i];
    sum_yy += y[i] * y[i];
    double y_pred = a * x[i] + b;
    sum_residual += (y[i] - y_pred) * (y[i] - y_pred);
  }

  double y_mean = sum_y / n;
  double ss_total = sum_yy - n * y_mean * y_mean;
  double ss_residual = sum_residual;
  double r_squared = 1 - ss_residual / ss_total;

  return r_squared;
}


//Extrapolation y = 0
double calculate_x(double a, double b) {
    double cx = -b/a;
    return cx;
}



int main() {

  //the user adds the data
  //Data number
  int n;

  cout << "Enter the number of data points: ";
  cin >> n;

  vector<double> x(n);
  vector<double> y(n);
  vector<double> samples(n);

  //remember that several dilutions of the standard were made by taking
  //n volumenes and create function dilutions c1v1 = c2v2
  cout << "Volumen standard: " << endl;
  for (int i = 0; i < n; i++) {
    cout << "x[" << i << "] = ";
    cin >> x[i];
  }

  cout << "\n";

  cout << "Absorbance values: " << endl;
  for (int i = 0; i < n; i++) {
    cout << "y[" << i << "] = ";
    cin >> y[i];
  }

  double a, b;
  linear_calibration_curve(x, y, a, b);

  cout << "The calibration curve is: y = " << a << "x + " << b << endl;
  
  double r_sq = r_squared(x, y, a, b);
  cout << "The R-squared value is: " << r_sq << endl;

  //create a function where extrapolation y = 0 then x = - b/a

  double x_extrapolation = calculate_x(a, b);

  return 0;
}
