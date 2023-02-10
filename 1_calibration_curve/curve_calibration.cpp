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

int main() {

  //the user adds the data
  //Data number
  int n, m;

  cout << "Enter the number of data points: ";
  cin >> n;

  vector<double> x(n);
  vector<double> y(n);
  vector<double> samples(n);

  cout << "Enter the independent variable x data points: " << endl;
  for (int i = 0; i < n; i++) {
    cout << "x[" << i << "] = ";
    cin >> x[i];
  }

  cout << "\n";

  cout << "Enter the dependent variable y data points: " << endl;
  for (int i = 0; i < n; i++) {
    cout << "y[" << i << "] = ";
    cin >> y[i];
  }

  double a, b;
  linear_calibration_curve(x, y, a, b);

  cout << "The calibration curve is: y = " << a << "x + " << b << endl;
  
  double r_sq = r_squared(x, y, a, b);
  cout << "The R-squared value is: " << r_sq << endl;


  //use the calibration curve to calculate the independent
  //(like the concentration) variable in the samples 
  cout << "Number of samples: "; cin >> m;
  cout << "Enter the data of the samples: " << endl;
  for (int i = 0; i < m; i++) {
     cout << "y[" << i << "] = ";
     cin >> y[i];
  }

  return 0;
}
