#include <iostream>
#include <cmath>
#include <complex>
#include <vector>

typedef std::complex<double> cn;

std::vector<cn> FFT(std::vector<cn>& a)
{
    int size = a.size();
    if (size == 1) {
        return std::vector<cn>(1, a[0]);
    }

    std::vector<cn> w(size);
    for (int i = 0; i < size; i++) {
        double alpha = 2 * M_PI * i / size;
        w[i] = cn(cos(alpha), sin(alpha));
    }

    std::vector<cn> A0(size / 2), A1(size / 2);
    for (int i = 0; i < size / 2; i++) {
        A0[i] = a[i * 2];
        A1[i] = a[i * 2 + 1];
    }

    std::vector<cn> y0 = FFT(A0);
    std::vector<cn> y1 = FFT(A1);

    std::vector<cn> y(size);

    for (int k = 0; k < size / 2; k++) {
        y[k] = y0[k] + w[k] * y1[k];
        y[k + size / 2] = y0[k] - w[k] * y1[k];
    }

    return y;
}

int main()
{
    std::vector<cn> a{1, 2, 3, 4}; 
    std::vector<cn> b = FFT(a); 
    for (int i = 0; i < 4; i++) 
        std::cout << b[i] << std::endl; 
  
    return 0; 
}