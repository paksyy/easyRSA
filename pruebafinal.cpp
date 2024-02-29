#include <iostream>
#include <math.h>

using namespace std;

long long int exp_mod(long long int base, long long int exp, long long int m) {
    if (exp == 0)
        return 1;
    long long int temp = exp_mod(base, exp / 2, m);
    temp = (temp * temp) % m;
    if (exp % 2 == 1)
        temp = (temp * base) % m;
    return temp;
}

int main() {
    string mensaje = "Hola mundo!";
    int e = 7;
    long long int p = 97;
    long long int q = 79;
    long long int n = p * q;
    long long int r = (p - 1) * (q - 1);
    cout << "Llave publica: " << n << endl;
    cout << "Llave privada: " << r << endl;
    
    // Calcular d utilizando el algoritmo de Euclides extendido
    long long int d = 1;
    while (((e * d) % r) != 1) {
        d++;
    }
    
    cout << "Llave privada: " << d << endl;

    int mensajeCifrado[100];
    int mensajeDescifrado[100];
    int i = 0;
    cout << "Mensaje Ascii: ";
    for (char c : mensaje) {
        mensajeCifrado[i] = static_cast<int>(c);
        cout << mensajeCifrado[i] << " ";
        i++;
    }
    cout << endl;
    
    // Cifrar mensaje
    cout << "Mensaje cifrado: ";
    for (int j = 0; j < i; j++) {
        mensajeCifrado[j] = exp_mod(mensajeCifrado[j], e, n);
        cout << mensajeCifrado[j] << " ";
    }
    cout << endl;
    
    // Descifrar mensaje
    cout << "Mensaje descifrado: ";
    for (int j = 0; j < i; j++) {
        mensajeDescifrado[j] = exp_mod(mensajeCifrado[j], d, n);
        cout << static_cast<char>(mensajeDescifrado[j]);
    }
    
    return 0;
}