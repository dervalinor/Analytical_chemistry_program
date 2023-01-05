#include <vector>
#include <numeric>
#include <math.h>

/*function statistical - calculate standard deviation, relative standard deviation, 
standard error of the mean, coefficient of variation, variance and sensitivity */

double statistical_data(){

  double result;


  return result;
}

/*Equation of the curve of data (store in vectors) */
//This code creates a calibration curve of form y = ax + b using two given vectors x and y. It first calculates the sum of x*y and x^2 and then calculates the coefficients a and b using the given formula. Finally it returns the value of y for the last x value in the vector.
void calibration_curve(vector<int> x, vector<int> y){
    double sum_xy = 0; 
    double sum_x = 0;
    double sum_x2 = 0;
    double sum_y = 0;
    double n = x.size();
    
    for(int i=0; i<n; i++){
        sum_xy += (x[i] * y[i]);
        sum_x += x[i];
        sum_y += y[i];
        sum_x2 += (x[i] * x[i]);
    }
    
    double a_num = (n * sum_xy) - (sum_x * sum_y);
    double a_denom = (n * sum_x2) - (sum_x * sum_x);
    double a = a_num / a_denom;
    
    double b_num = (sum_y * sum_x2) - (sum_x * sum_xy);
    double b_denom = (n * sum_x2) - (sum_x * sum_x);
    double b = b_num / b_denom;
    
    return a*x[n] + b;
}
