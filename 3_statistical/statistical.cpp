#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

// Function to calculate absolute standard deviation
double absStdDev(const vector<double> &values, double mean)
{
    double sum = 0;
    for (double x : values)
        sum += abs(x - mean);
    return sum / values.size();
}

// Function to calculate relative standard deviation
double relStdDev(const vector<double> &values, double mean)
{
    return absStdDev(values, mean) / mean;
}

// Function to calculate standard error of the mean
double stdErrorMean(const vector<double> &values)
{
    double mean = accumulate(values.begin(), values.end(), 0.0) / values.size();
    double sum = 0;
    for (double x : values)
        sum += (x - mean) * (x - mean);
    return sqrt(sum / (values.size() - 1)) / sqrt(values.size());
}

// Function to calculate coefficient of variation
double coeffVariation(const vector<double> &values)
{
    double mean = accumulate(values.begin(), values.end(), 0.0) / values.size();
    double sum = 0;
    for (double x : values)
        sum += (x - mean) * (x - mean);
    double std_dev = sqrt(sum / (values.size() - 1));
    return std_dev / mean;
}

int main()
{
    vector<double> values = { 1, 2, 3, 4, 5 };

    double mean = accumulate(values.begin(), values.end(), 0.0) / values.size();

    cout << "Absolute standard deviation: " << absStdDev(values, mean) << endl;
    cout << "Relative standard deviation: " << relStdDev(values, mean) << endl;
    cout << "Standard error of the mean: " << stdErrorMean(values) << endl;
    cout << "Coefficient of variation: " << coeffVariation(values) << endl;

    return 0;
}

