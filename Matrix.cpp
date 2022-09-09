#include "Matrix.h"

Matrix::Matrix(int size) : width(size), height(size) {
    generateMatrix();
}

void Matrix::generateMatrix() {
    this->matrix = new double * [this->height];
    for (int i = 0; i < this->width; ++i) {
        this->matrix[i] = new double[this->width];
    }
}

void Matrix::fillMatrix(double number) {
    for (int i = 0; i < this->width; ++i) {
        for (int j = 0; j < this->height; ++j) {
            this->matrix[i][j] = number;
        }
    }
}

Matrix::Matrix(const Matrix &matrix) {
    this->width = matrix.width;
    this->height = matrix.height;

    generateMatrix();

    for (int i = 0; i < this->width; ++i) {
        for (int j = 0; j < this->height; ++j) {
            this->matrix[i][j] = matrix.matrix[i][j];
        }
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < this->getWidth(); ++i) {
        delete [] this->matrix[i];
    }
    delete [] this->matrix;
}

double **Matrix::getMatrix() {
    return this->matrix;
}

int Matrix::getWidth() const {
    return this->width;
}

int Matrix::getHeight() const {
    return this->height;
}

Matrix Matrix::operator=(const Matrix& m) const {

    Matrix n_matrix(this->getWidth());
    for (int i=0; i< this->getWidth(); i++){
        for (int j=0; j< this->getHeight(); j++){
            n_matrix.getMatrix()[i][j] = m.matrix[i][j];
        }
    }
    return n_matrix;
}


double Matrix::getElementFromMatrix(int col, int row) {
    return this->matrix[row][col];
}

bool Matrix::operator==(const Matrix &m) {
    for (int i=0; i< this->getWidth(); i++){
        for (int j=0; j< this->getHeight(); j++){
            if (this->getMatrix()[i][j] != m.matrix[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix &m) {
    return !operator==(m);
}

void Matrix::operator+=(const Matrix&n) {
    for (int i=0; i< this->getWidth(); i++){
        for (int j=0; j< this->getHeight(); j++){
            this->getMatrix()[i][j] += n.matrix[i][j];
        }
    }
}

void Matrix::operator*=(const double &n) {
    for (int i=0; i< this->getWidth(); i++){
        for (int j=0; j< this->getHeight(); j++){
            this->getMatrix()[i][j] *= n;
        }
    }
}

void Matrix::operator*=(const Matrix &n) {
    for (int i=0; i< this->getWidth(); i++){
        for (int j=0; j< this->getHeight(); j++){
            this->getMatrix()[i][j] *= n.matrix[i][j];
        }
    }
}

void Matrix::operator+=(const double &n) {
    for (int i=0; i< this->getWidth(); i++){
        for (int j=0; j< this->getHeight(); j++){
            this->getMatrix()[i][j] += n;
        }
    }
}



