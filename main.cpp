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
    question("������� ������ �������", N);
    Matrix matrix(N);
    // ����������� �����������
    Matrix matrix2(matrix);

    question("��� ��������� ������ �������?", M);
    matrix.fillMatrix(M);
    question("��� ��������� ������ �������?", M);
    matrix2.fillMatrix(M);

    cout << "������ �������: " << endl;
    printMatrix(matrix);
    cout << "������ �������: " << endl;
    printMatrix(matrix2);

    bool sumMatrix;
    double nx;
    question("�������?", sumMatrix);

    if (sumMatrix) {
        matrix += matrix2;
    } else {
        question("�������� ������� ���� �� �����?", sumMatrix);
        if (sumMatrix) {
            matrix *= matrix2;
        } else {
            question("������� ����� �� ������� ����� �������� �������", nx);
            matrix *= nx;
        }
    }

    cout << "���������: " << endl;

    printMatrix(matrix);
    system("pause");
    return 0;
}
