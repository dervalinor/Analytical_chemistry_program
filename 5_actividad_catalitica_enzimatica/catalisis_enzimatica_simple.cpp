/* Programa para calcular Vm y Km apartir de un curva de calibracion de la actividad catalitica
de un enzima por medio de la ecuacion de ecuacion de Lineweaved-Bard*/

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

    double intercept = 0.0; // Definition intercept - calculation of Vmax
    double slope = 0.0; //definition of slope - calculation km


    try {
        //Para este caso se realizara la curva de calibracion
        //de 1/V y 1/[S] de acuerdo a la ecuacion de Lineweaved-Bard
        double n;

        std::cout << "Amount of data: ";
        std::cin >> n;

        std::vector<double> v1(n); //vector de concentraccion mantener con eje x
        std::vector<double> v2(n); //vector de la velocidad de la reaccion

        std::cout << "substrate concentration: " << std::endl;
        for (int i = 0; i < n; ++i) {
            std::cout << "Concentration " << i + 1 <<" :"; std::cin >> v1[i];
        }

       std::cout << "reaction velocity: " << std::endl;
        for(int i = 0; i < n; ++i){
            std::cout << "Velocity " << i + 1  <<" :"; std::cin >> v2[i];
        }

        // Verificar que los vectores sean del mismo tamaño
        if (v1.size() != v2.size()) {
            throw std::invalid_argument("Los vectores deben ser del mismo tamaño");
        }

        // Calcular los inversos de los vectores
        std::vector<double> inv_v1 = inverse(v1);
        std::vector<double> inv_v2 = inverse(v2);

        // Calcular la regresión lineal
        std::pair<double, double> result = linear_regression(inv_v1, inv_v2);
        slope = result.first;
        intercept = result.second; // Asignar valor a intercept aquí

        // Calcular R²
        double r2 = r_squared(inv_v1, inv_v2, slope, intercept);

        // Mostrar la función lineal y R²
        std::cout << "Función lineal: y = " << slope << "x + " << intercept << std::endl;
        std::cout << "R² = " << r2 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout<< "Determination of Michaelis constant (Km) and maximum rate of reaction (Vmax)" << std::endl;

    if (intercept != 0 && slope != 0) {
    double Vmax = 1 / intercept;
    std::cout << "Maximum rate of reaction (Vmax): " << Vmax << std::endl;
    std::cout << "Michaelis constant (Km): " << slope*Vmax << std::endl;
    } else {
    std::cout << "Error, intercept or slope is zero" << std::endl;
    }


    return 0;
}
