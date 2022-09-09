#ifndef LAB17_MATRIX_H
#define LAB17_MATRIX_H


class Matrix {
private:
    double ** matrix{};

    int width{};
    int height{};

    void generateMatrix();
public:
    Matrix(const Matrix &);
    explicit Matrix(int size);

    ~Matrix();

    Matrix operator=(const Matrix&) const;
    bool operator==(const Matrix&);
    bool operator!=(const Matrix&);
    void operator+=(const double&);
    void operator+=(const Matrix&);
    void operator*=(const double&);
    void operator*=(const Matrix&);

    double ** getMatrix();
    int getWidth() const;
    int getHeight() const;

    double getElementFromMatrix(int col, int row);

    void fillMatrix(double number);
};


#endif //LAB17_MATRIX_H
