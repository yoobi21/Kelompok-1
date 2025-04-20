#include <iostream>
#include <cmath>
#include <limits>
#include <string>
#include <iomanip>

using namespace std;

// Fungsi Iterasi Tetap
double g(double x) {
    return - (pow(x, 3) + 1) / 2;
}

// Fungsi Newton-Raphson
double f(double x) {
    return pow(x, 3) + pow(x, 2) - 3 * x - 3;
}
double f_turunan(double x) {
    return 3 * pow(x, 2) + 2 * x - 3;
}

// Fungsi Secant
double f_secant(double x) {
    return x - pow(x, 3) + pow(x, 2) - 3 * x - 3;
}

int main() {
    string pilihan;
    char ulang;

    do {
        cout << "\n==============================\n";
        cout << "   MENU METODE NUMERIK\n";
        cout << "==============================\n";
        cout << "1. Metode Iterasi Tetap\n";
        cout << "2. Metode Newton-Raphson\n";
        cout << "3. Metode Secant\n";
        cout << "Pilih metode (1 / 2 / 3): ";
        cin >> pilihan;

        if (pilihan == "1") {
            double x0, x1, toleransi;
            int iter = 0, maxIter;

            cout << "\n=== METODE ITERASI TETAP ===\n";
            while (true) {
                cout << "Masukkan tebakan awal x0 : ";
                cin >> x0;
                if (cin.fail()) {
                    cout << "Eror: Masukan angka yang valid!\n";
                    cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else break;
            }

            while (true) {
                cout << "Masukkan toleransi        : ";
                cin >> toleransi;
                if (cin.fail() || toleransi <= 0) {
                    cout << "Eror: Toleransi harus angka > 0!\n";
                    cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else break;
            }

            while (true) {
                cout << "Masukkan batas iterasi    : ";
                cin >> maxIter;
                if (cin.fail() || maxIter <= 0) {
                    cout << "Eror: Iterasi harus angka > 0!\n";
                    cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else break;
            }

            do {
                x1 = g(x0);
                double error = fabs(x1 - x0);
                cout << "Iterasi " << iter + 1 << ": x = " << fixed << setprecision(6) << x1
                     << "  Error: " << fixed << setprecision(6) << error << endl;
                if (error < toleransi) break;
                x0 = x1;
                iter++;
            } while (iter < maxIter);

            cout << "\nAkar hampiran: " << x1 << endl;
            cout << "f(x) = " << f(x1) << endl;

        } else if (pilihan == "2") {
            double x0, x1, toleransi;
            int iter = 0, maxIter;

            cout << "\n=== METODE NEWTON-RAPHSON ===\n";
            while (true) {
                cout << "Masukkan tebakan awal x0 : ";
                cin >> x0;
                if (cin.fail()) {
                    cout << "Eror: Masukan angka yang valid!\n";
                    cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else break;
            }

            while (true) {
                cout << "Masukkan toleransi        : ";
                cin >> toleransi;
                if (cin.fail() || toleransi <= 0) {
                    cout << "Eror: Toleransi harus angka > 0!\n";
                    cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else break;
            }

            while (true) {
                cout << "Masukkan batas iterasi    : ";
                cin >> maxIter;
                if (cin.fail() || maxIter <= 0) {
                    cout << "Eror: Iterasi harus angka > 0!\n";
                    cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else break;
            }

            do {
                x1 = x0 - f(x0) / f_turunan(x0);
                double error = fabs(x1 - x0);
                cout << "Iterasi " << iter + 1 << ": x = " << fixed << setprecision(6) << x1
                     << "  Error: " << fixed << setprecision(6) << error << endl;
                if (error < toleransi) break;
                x0 = x1;
                iter++;
            } while (iter < maxIter);

            cout << "\nAkar hampiran: " << x1 << endl;
            cout << "f(x) = " << f(x1) << endl;

        } else if (pilihan == "3") {
            double x0, x1, x2, toleransi;
            int iter = 0, maxIter;

            cout << "\n=== METODE SECANT ===\n";
            while (true) {
                cout << "Masukkan nilai awal x0 : ";
                cin >> x0;
                if (cin.fail()) {
                    cout << "Eror: Masukan angka yang valid!\n";
                    cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else break;
            }

            while (true) {
                cout << "Masukkan nilai kedua x1 : ";
                cin >> x1;
                if (cin.fail()) {
                    cout << "Eror: Masukan angka yang valid!\n";
                    cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else break;
            }

            while (true) {
                cout << "Masukkan toleransi        : ";
                cin >> toleransi;
                if (cin.fail() || toleransi <= 0) {
                    cout << "Eror: Toleransi harus angka > 0!\n";
                    cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else break;
            }

            while (true) {
                cout << "Masukkan batas iterasi    : ";
                cin >> maxIter;
                if (cin.fail() || maxIter <= 0) {
                    cout << "Eror: Iterasi harus angka > 0!\n";
                    cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else break;
            }

            do {
                if (f_secant(x1) - f_secant(x0) == 0) {
                    cout << "Terjadi pembagian dengan nol!\n";
                    break;
                }

                x2 = x1 - f_secant(x1) * (x1 - x0) / (f_secant(x1) - f_secant(x0));
                double error = fabs(x2 - x1);
                cout << "Iterasi " << iter + 1 << ": x = " << fixed << setprecision(6) << x2
                     << "  Error: " << fixed << setprecision(6) << error << endl;
                if (error < toleransi) break;
                x0 = x1;
                x1 = x2;
                iter++;
            } while (iter < maxIter);

            cout << "\nAkar hampiran: " << x2 << endl;
            cout << "f(x) = " << f(x2) << endl;

        } else {
            cout << "\nPilihan tidak valid! Silakan pilih 1, 2, atau 3.\n";
        }

        cout << "\nIngin kembali ke menu? (Y/T): ";
        cin >> ulang;

    } while (ulang == 'Y' || ulang == 'y');

    cout << "\nProgram selesai. Terima kasih!\n";
    return 0;
}
