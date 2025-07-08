#include<iostream>
using namespace std;

const int MAX = 10;

void inputMatrix(int a[MAX][MAX], int &n, int &m) {
    cout << "Enter rows and columns: ";
    cin >> n >> m;
    cout << "Enter matrix elements:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
}

void printMatrix(int a[MAX][MAX], int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

bool isZeroMatrix(int a[MAX][MAX], int n, int m) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j] != 0)
                return false;
    return true;
}

bool isIdentityMatrix(int a[MAX][MAX], int n) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            if(i == j && a[i][j] != 1)
                return false;
            else if(i != j && a[i][j] != 0)
                return false;
        }
    return true;
}

bool isDiagonalMatrix(int a[MAX][MAX], int n) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(i != j && a[i][j] != 0)
                return false;
    return true;
}

bool isScalarMatrix(int a[MAX][MAX], int n) {
    if(!isDiagonalMatrix(a, n)) return false;
    int value = a[0][0];
    for(int i = 0; i < n; i++)
        if(a[i][i] != value)
            return false;
    return true;
}

bool isSymmetric(int a[MAX][MAX], int n) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(a[i][j] != a[j][i])
                return false;
    return true;
}

bool isSkewSymmetric(int a[MAX][MAX], int n) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(a[i][j] != -a[j][i])
                return false;
    return true;
}

bool isUpperTriangular(int a[MAX][MAX], int n) {
    for(int i = 1; i < n; i++)
        for(int j = 0; j < i; j++)
            if(a[i][j] != 0)
                return false;
    return true;
}

bool isLowerTriangular(int a[MAX][MAX], int n) {
    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
            if(a[i][j] != 0)
                return false;
    return true;
}

int determinant2x2(int a[MAX][MAX]) {
    return a[0][0]*a[1][1] - a[0][1]*a[1][0];
}

void transpose(int a[MAX][MAX], int b[MAX][MAX], int n, int m) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            b[j][i] = a[i][j];
}

int main() {
    int a[MAX][MAX], t[MAX][MAX];
    int n, m;

    inputMatrix(a, n, m);

    cout << "\nMatrix Type: ";
    if(n == 1 && m != 1) cout << "Row Matrix\n";
    else if(m == 1 && n != 1) cout << "Column Matrix\n";
    else if(n == m) cout << "Square Matrix\n";
    else cout << "Rectangular Matrix\n";

    if(isZeroMatrix(a, n, m))
        cout << "-> Zero Matrix\n";

    if(n == m) {
        if(isIdentityMatrix(a, n))
            cout << "-> Identity Matrix\n";

        if(isDiagonalMatrix(a, n))
            cout << "-> Diagonal Matrix\n";

        if(isScalarMatrix(a, n))
            cout << "-> Scalar Matrix\n";

        if(isSymmetric(a, n))
            cout << "-> Symmetric Matrix\n";

        if(isSkewSymmetric(a, n))
            cout << "-> Skew-Symmetric Matrix\n";

        if(isUpperTriangular(a, n))
            cout << "-> Upper Triangular\n";

        if(isLowerTriangular(a, n))
            cout << "-> Lower Triangular\n";

        if(n == 2) {
            int det = determinant2x2(a);
            cout << "-> Determinant: " << det << endl;
            if(det == 0) cout << "-> Singular Matrix\n";
            else cout << "-> Non-Singular Matrix\n";
        }
    }

    // Transpose
    transpose(a, t, n, m);
    cout << "\nTranspose of the matrix:\n";
    printMatrix(t, m, n);

    return 0;
}
