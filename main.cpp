#include <iostream>
#include "Matrix.h"

using namespace std;

// Questions for integer types
void question(const string& quest, int &answer) {
    cout << quest << " |int|: ";
    cin >> answer;
}

// Questions for doubles types
void question(const string& quest, double &answer) {
    cout << quest << " |double|: ";
    cin >> answer;
}

// Questions for bool types
void question(const string& quest, bool &answer) {
    cout << quest << " |bool|: ";
    cin >> answer;
}

void printMatrix(Matrix matrix) {
    for (int i = 0; i < matrix.getWidth(); i++)
        for (int j = 0; j < matrix.getHeight(); j++)
            cout << matrix.getMatrix()[i][j] << " \n"[j == matrix.getWidth()-1];
}

int main() {
    int N;
    double M;
    setlocale(LC_ALL, "");
    question("Введите размер матрицы", N);
    Matrix matrix(N);
    // Конструктор копирования
    Matrix matrix2(matrix);

    question("Чем заполнить первую матрицу?", M);
    matrix.fillMatrix(M);
    question("Чем заполнить вторую матрицу?", M);
    matrix2.fillMatrix(M);

    cout << "Первая матрица: " << endl;
    printMatrix(matrix);
    cout << "Вторая матрица: " << endl;
    printMatrix(matrix2);

    bool sumMatrix;
    double nx;
    question("Сложить?", sumMatrix);

    if (sumMatrix) {
        matrix += matrix2;
    } else {
        question("Умножить матрицы друг на друга?", sumMatrix);
        if (sumMatrix) {
            matrix *= matrix2;
        } else {
            question("Введите число на которое нужно умножить матрицу", nx);
            matrix *= nx;
        }
    }

    cout << "Результат: " << endl;

    printMatrix(matrix);
    system("pause");
    return 0;
}
