#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <stdexcept>

/* 
calculo de la Km y Vmax para enzima en un proceso catalitico sin inhibidor

*/

// Función para calcular el inverso de un vector
std::vector<double> inverse(const std::vector<double>& v) {
    std::vector<double> result(v.size());
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] == 0) {
            throw std::invalid_argument("División por cero");
        }
        result[i] = 1 / v[i];
    }
    return result;
}

// Función para calcular la regresión lineal
std::pair<double, double> linear_regression(const std::vector<double>& x, const std::vector<double>& y) {
    double n = x.size();
    double sum_x = std::accumulate(x.begin(), x.end(), 0.0);
    double sum_y = std::accumulate(y.begin(), y.end(), 0.0);
    double sum_xy = std::inner_product(x.begin(), x.end(), y.begin(), 0.0);
    double sum_xx = std::inner_product(x.begin(), x.end(), x.begin(), 0.0);
    double slope = (n * sum_xy - sum_x * sum_y) / (n * sum_xx - sum_x * sum_x);
    double intercept = (sum_y - slope * sum_x) / n;
    return std::make_pair(slope, intercept);
}

// Función para calcular R²
double r_squared(const std::vector<double>& x, const std::vector<double>& y, double slope, double intercept) {
    double ss_tot = 0.0;
    double ss_res = 0.0;
    double y_mean = std::accumulate(y.begin(), y.end(), 0.0) / y.size();
    for (size_t i = 0; i < x.size(); ++i) {
        double y_pred = slope * x[i] + intercept;
        ss_tot += std::pow(y[i] - y_mean, 2);
        ss_res += std::pow(y[i] - y_pred, 2);
    }
    return 1 - ss_res / ss_tot;
}

int main() {
    try {
        // Vectores de entrada
        std::vector<double> v1 = {1, 2, 3, 4, 5}; //vector de concentraccion mantener con eje x
        std::vector<double> v2 = {2, 3, 4, 5, 6}; //vector de la velocidad de la reaccion

        // Verificar que los vectores sean del mismo tamaño
        if (v1.size() != v2.size()) {
            throw std::invalid_argument("Los vectores deben ser del mismo tamaño");
        }

        // Calcular los inversos de los vectores
        std::vector<double> inv_v1 = inverse(v1);
        std::vector<double> inv_v2 = inverse(v2);

        // Calcular la regresión lineal
        auto [slope, intercept] = linear_regression(inv_v1, inv_v2);

        // Calcular R²
        double r2 = r_squared(inv_v1, inv_v2, slope, intercept);

        // Mostrar la función lineal y R²
        std::cout << "Función lineal: y = " << slope << "x + " << intercept << std::endl;
        std::cout << "R² = " << r2 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
