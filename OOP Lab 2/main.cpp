//Exercitiul 1
/*
#include <iostream>
#include <cstring>

using namespace std;

class String {
private:
    char* data;
    int length;

public:
    // Constructor implicit
    String() {
        length = 0;
        data = new char[1];
        data[0] = '\0';
        cout<<"Acesta este un constructor implicit"<<endl;
    }

    // Constructor cu un parametru
    String(const char* str) {
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
    }

    // Constructor de copiere
    String(const String& other) {
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
    }

    // Destructor
    ~String() {
        if(data != nullptr)
        delete[] data;
    }

    // Funcție de atribuire
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] data;
            length = other.length;
            data = new char[length + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    // Funcție pentru comparare
    bool operator==(const String& other) const {
        return (strcmp(data, other.data) == 0);
    }

    // Funcție pentru a căuta un subșir în șirul curent
    bool contains(const char* substr) const {
        return (strstr(data, substr) != nullptr);
    }

    // Funcție pentru a număra aparițiile unui caracter în șir
    int count(char ch) const {
        int count = 0;
        for (int i = 0; i < length; ++i) {
            if (data[i] == ch) {
                count++;
            }
        }
        return count;
    }

    // Funcție pentru a afișa șirul
    void print() const {
        cout << data;
    }
};

int main() {
    char string[255];
    cout<<"Introdu un sir de caractere:"<<endl;
    cin>>string;
    String str1(string);
    String str2 = str1; // Constructorul de copiere
    cout<<"Introdu al doilea sir"<<endl;
    char string2[255];
    cin>>string2;
    String str3 = string2;

    cout << "string1: ";
    str1.print();
    cout << endl;

    cout << "string2: ";
    str2.print();
    cout << endl;

    cout << "string3: ";
    str3.print();
    cout << endl;

    if (str1 == str2) {
        cout << "str1 si str2 sunt identice." << endl;
    } else {
        cout << "str1 si str2 nu sunt identice." << endl;
    }

    if (str1.contains("ar")) {
        cout << "str1 contine subsirul 'ar'." << endl;
    } else {
        cout << "str1 nu contine subsirul 'ar'." << endl;
    }

    cout << "Numarul de 'l' in str1: " << str1.count('l') << endl;

    return 0;
}
*/
//Exercitiul 2
/*
#include <iostream>

class Matrix {
private:
    double* data;  // Pointer spre matrice
    int rows;      // Numărul de rânduri
    int cols;      // Numărul de coloane
    int errorCode; // Codul erorii (0 - fără eroare, 1 - insuficiență de memorie, 2 - depășire limită matrice)

public:
    // Constructor fără parametri (constructorul implicit)
    Matrix() : data(nullptr), rows(0), cols(0), errorCode(0) {}

    // Constructor cu un parametru - matrice pătrată
    Matrix(int size) : rows(size), cols(size), errorCode(0) {
        data = new double[size * size];
        if (!data) {
            errorCode = 1; // Cod de eroare pentru insuficienţă de memorie
        }
    }

    // Constructor cu doi parametri - matrice dreptunghiulară
    Matrix(int numRows, int numCols) : rows(numRows), cols(numCols), errorCode(0) {
        data = new double[numRows * numCols];
        if (!data) {
            errorCode = 1; // Cod de eroare pentru insuficienţă de memorie
        }
    }

    // Destructor pentru eliberarea memoriei
    ~Matrix() {
        delete[] data;
    }

    // Funcţie membru pentru returnarea valorii elementului (i, j)
    double get(int i, int j) {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            errorCode = 2; // Cod de eroare pentru depăşirea limitelor matricei
            return 0.0;
        }
        return data[i * cols + j];
    }

    // Funcţie membru pentru setarea valorii elementului (i, j)
    void set(int i, int j, double value) {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            errorCode = 2; // Cod de eroare pentru depăşirea limitelor matricei
            return;
        }
        data[i * cols + j] = value;
    }

    // Funcţie membru pentru adunarea a două matrice
    Matrix add(const Matrix& other) {
        if (rows != other.rows || cols != other.cols) {
            errorCode = 3; // Cod de eroare pentru necorespondenţa dimensiunilor matricelor
            return Matrix();
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows * cols; ++i) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }

    // Funcţie membru pentru scăderea a două matrice
    Matrix subtract(const Matrix& other) {
        if (rows != other.rows || cols != other.cols) {
            errorCode = 3; // Cod de eroare pentru necorespondenţa dimensiunilor matricelor
            return Matrix();
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows * cols; ++i) {
            result.data[i] = data[i] - other.data[i];
        }
        return result;
    }

    // Funcţie membru pentru înmulţirea cu o matrice
    Matrix multiply(const Matrix& other) {
        if (cols != other.rows) {
            errorCode = 3; // Cod de eroare pentru necorespondenţa dimensiunilor matricelor
            return Matrix();
        }

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                double sum = 0.0;
                for (int k = 0; k < cols; ++k) {
                    sum += data[i * cols + k] * other.data[k * other.cols + j];
                }
                result.data[i * other.cols + j] = sum;
            }
        }
        return result;
    }

    // Funcţie membru pentru afişarea matricei
    void display() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << get(i, j) << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    // Testarea funcţionării clasei
    Matrix a(2, 2);
    a.set(0, 0, 1.0);
    a.set(0, 1, 2.0);
    a.set(1, 0, 3.0);
    a.set(1, 1, 4.0);

    Matrix b(2, 2);
    b.set(0, 0, 5.0);
    b.set(0, 1, 6.0);
    b.set(1, 0, 7.0);
    b.set(1, 1, 8.0);

    Matrix c = a.add(b);
    Matrix d = a.subtract(b);
    Matrix e = a.multiply(b);
    Matrix f = a.multiply(2.0);

    std::cout << "Matrix A:" << std::endl;
    a.display();

    std::cout << "Matrix B:" << std::endl;
    b.display();

    std::cout << "Matrix C (A + B):" << std::endl;
    c.display();

    std::cout << "Matrix D (A - B):" << std::endl;
    d.display();

    std::cout << "Matrix E (A * B):" << std::endl;
    e.display();

    std::cout << "Matrix F (A * 2.0):" << std::endl;
    f.display();

    return 0;
}
*/