#include <iostream>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;
#define PI 3.14159265

// Function to calculate power
double power(double base, int exponent) {
    double result = 1.0;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

// Function to calculate factorial
int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Function to calculate sine
double sine(double angle) {
    angle *= PI / 180.0; // Convert angle to radians
    double result = 0;
    for (int i = 0; i < 10; ++i) {
        result += power(-1, i) * power(angle, 2 * i + 1) / factorial(2 * i + 1);
    }
    return result;
}

// Function to calculate cosine
double cosine(double angle) {
    angle *= PI / 180.0; // Convert angle to radians
    double result = 0;
    for (int i = 0; i < 10; ++i) {
        result += power(-1, i) * power(angle, 2 * i) / factorial(2 * i);
    }
    return result;
}

// Function to calculate tangent
double tangent(double angle) {
    return sine(angle) / cosine(angle);
}

// Function to calculate cotangent
double cotangent(double angle) {
    return 1 / tangent(angle);
}

// Function to calculate secant
double secant(double angle) {
    return 1 / cosine(angle);
}

// Function to calculate cosecant
double cosecant(double angle) {
    return 1 / sine(angle);
}

// Function to calculate inverse sine (arcsin)
double arcsin(double value) {
    return asin(value) * 180.0 / PI; // Convert radians to degrees
}

// Function to calculate inverse cosine (arccos)
double arccos(double value) {
    return acos(value) * 180.0 / PI; // Convert radians to degrees
}

// Function to calculate inverse tangent (arctan)
double arctan(double value) {
    return atan(value) * 180.0 / PI; // Convert radians to degrees
}

// Function to calculate inverse cotangent (arccot)
double arccot(double value) {
    return atan(1 / value) * 180.0 / PI; // Convert radians to degrees
}

// Function to calculate inverse secant (arcsec)
double arcsec(double value) {
    return acos(1 / value) * 180.0 / PI; // Convert radians to degrees
}

// Function to calculate inverse cosecant (arccsc)
double arccsc(double value) {
    return asin(1 / value) * 180.0 / PI; // Convert radians to degrees
}

// Function to calculate logarithm with a custom base
double customLog(double base, double number) {
    if (base <= 0 || number <= 0) {
        cout << "Invalid input for logarithm!\n";
        return NAN;
    }
    return log(number) / log(base);
}

double customPower(double base, int exponent) {
    if (exponent == 0) {
        return 1.0;
    } else if (exponent > 0) {
        return base * customPower(base, exponent - 1);
    } else {
        return 1.0 / (base * customPower(base, -exponent - 1));
    }
}

struct node {
    int coeffx, powerx;
    node* link;
};

class clist {
    node* head = NULL;

public:
    clist() { head = NULL; }
    void create(int n);
    void display();
    clist addtopoly(clist ob2);
    int Evaluate(int x);
};

// a) Create polynomial
void clist::create(int n) {
    node* nn, * last = NULL;

    for (int i = 0; i < n; i++) {
        nn = new node;
        if (nn == NULL) {
            cout << "memory is full";
        }
        cout << "Enter coefficient of x" << endl;
        cin >> nn->coeffx;
        cout << "Enter power of x" << endl;
        cin >> nn->powerx;
        if (head == NULL)
        {
            last = nn;
            head=nn;
        }
        else
        {
            last->link=nn;
            last=nn;
        }
    }

      if (last!= NULL) 
      {
          last->link=head;

      }
}

// b) Display a polynomial
void clist::display() {
    node* temp = head;
    do {
        cout << temp->coeffx <<"x^"<< temp->powerx;
        temp = temp->link;
        if (temp != head) 
        {
            cout << "+";
        }
    } while(temp != head);
      cout<<endl;
}


// c) Add two polynomials

clist clist::addtopoly(clist ob2) 

{
    clist result, noresult;
    node* t1 = head;
    node* t2 = ob2.head;

    if (t1 == NULL && t2 == NULL) {
        cout << "Both polynomials are empty" << endl;
        return noresult;
    } 
    else {
        
        do {
            
            if (t1->powerx == t2->powerx) 
            {
                node* nn = new node;
                int sumofcoeff = t1->coeffx + t2->coeffx;
                nn->coeffx = sumofcoeff;
                nn->powerx = t1->powerx;
                nn->link = NULL;

                if (result.head == NULL) 
                {
                    result.head = nn;
                    nn->link = result.head;
                } 
                else {
                    node* temp = result.head;
                    
                    do {
                        temp = temp->link;
                    } while (temp->link != result.head);

                    temp->link = nn;
                    nn->link = result.head;
                }

                t1 = t1->link;
                t2 = t2->link;
            } 
            else if (t1->powerx > t2->powerx) 
            {
                node* nn = new node;
                nn->coeffx = t1->coeffx;
                nn->powerx = t1->powerx;
                nn->link = NULL;

                if (result.head == NULL) 
                {
                    result.head = nn;
                    nn->link = result.head;
                } else {
                    node* temp = result.head;
                    
                    do {
                        temp = temp->link;
                    } while (temp->link != result.head);

                    temp->link = nn;
                    nn->link = result.head;
                }

                t1 = t1->link;
            } else {
                node* nn = new node;
                nn->coeffx = t2->coeffx;
                nn->powerx = t2->powerx;
                nn->link = NULL;

                if (result.head == NULL) {
                    result.head = nn;
                    nn->link = result.head;
                } else {
                    node* temp = result.head;
                    do {
                        temp = temp->link;
                    } while (temp->link != result.head);

                    temp->link = nn;
                    nn->link = result.head;
                }

                t2 = t2->link;
            }
            
        } while ((t1 != head || t2 != ob2.head) && t1 != NULL && t2 != NULL);
    }
    
    
    
        while(t1!=head)
        {
              node* nn = new node;
                nn->coeffx = t1->coeffx;
                nn->powerx = t1->powerx;
                nn->link = NULL;

                if (result.head == NULL) 
                {
                    result.head = nn;
                    nn->link = result.head;
                } 
                else {
                    node* temp = result.head;
                    
                    do 
                    {
                        temp = temp->link;
                    } while (temp->link != result.head);

                    temp->link = nn;
                    nn->link = result.head;
                }

                t1 = t1->link;
        }
        
        while
        (t2!=ob2.head)
        { 
            node* nn = new node;
                nn->coeffx = t2->coeffx;
                nn->powerx = t2->powerx;
                nn->link = NULL;

                if (result.head == NULL) {
                    result.head = nn;
                    nn->link = result.head;
                } else {
                    node* temp = result.head;
                    do {
                        temp = temp->link;
                    } while (temp->link != result.head);

                    temp->link = nn;
                    nn->link = result.head;
                }

                t2 = t2->link;
            
        }

        return result;
    }

// d) Evaluate a given polynomial 

int clist::Evaluate(int x){
    node*temp=head;
    int cal=0;
    
    
    do {
        int y=temp->powerx;
    cal=temp->coeffx*pow(x,y)+cal;
    
    temp=temp->link;
    }
    while(temp!=head);
    
    return cal;
}

double degreesToRadians(double degrees) {
    return degrees * (PI / 180.0);
}

double radiansToDegrees(double radians) {
    return radians * (180.0 / PI);
}

string decimalToBinary(int decimal) {
    stringstream ss;
    while (decimal > 0) {
        ss << (decimal % 2);
        decimal /= 2;
    }
    string binary = ss.str();
    reverse(binary.begin(), binary.end());
    return binary;
}

// Function to convert binary to decimal
int binaryToDecimal(const string &binary) {
    int decimal = 0;
    int power = 1;
    for (int i = binary.length() - 1; i >= 0; --i) {
        if (binary[i] == '1') {
            decimal += power;
        }
        power *= 2;
    }
    return decimal;
}

// Function to convert decimal to octal
string decimalToOctal(int decimal) {
    stringstream ss;
    while (decimal > 0) {
        ss << (decimal % 8);
        decimal /= 8;
    }
    string octal = ss.str();
    reverse(octal.begin(), octal.end());
    return octal;
}

// Function to convert octal to decimal
int octalToDecimal(const string &octal) {
    int decimal = 0;
    int power = 1;
    for (int i = octal.length() - 1; i >= 0; --i) {
        decimal += (octal[i] - '0') * power;
        power *= 8;
    }
    return decimal;
}

// Function to convert decimal to hexadecimal
string decimalToHexadecimal(int decimal) {
    stringstream ss;
    ss << hex << uppercase << decimal;
    return ss.str();
}

// Function to convert hexadecimal to decimal
int hexadecimalToDecimal(const string &hexadecimal) {
    int decimal;
    stringstream ss;
    ss << hex << hexadecimal;
    ss >> decimal;
    return decimal;
}

// Structure to represent a complex number
struct Complex {
    double real;
    double imaginary;
};

// Function to add two complex numbers
Complex addComplex(const Complex& a, const Complex& b) {
    Complex result;
    result.real = a.real + b.real;
    result.imaginary = a.imaginary + b.imaginary;
    return result;
}

// Function to subtract two complex numbers
Complex subtractComplex(const Complex& a, const Complex& b) {
    Complex result;
    result.real = a.real - b.real;
    result.imaginary = a.imaginary - b.imaginary;
    return result;
}

// Function to multiply two complex numbers
Complex multiplyComplex(const Complex& a, const Complex& b) {
    Complex result;
    result.real = (a.real * b.real) - (a.imaginary * b.imaginary);
    result.imaginary = (a.real * b.imaginary) + (a.imaginary * b.real);
    return result;
}

// Function to divide two complex numbers
Complex divideComplex(const Complex& a, const Complex& b) {
    Complex result;
    double denominator = (b.real * b.real) + (b.imaginary * b.imaginary);
    result.real = ((a.real * b.real) + (a.imaginary * b.imaginary)) / denominator;
    result.imaginary = ((a.imaginary * b.real) - (a.real * b.imaginary)) / denominator;
    return result;
}

// Function to display complex number
void displayComplex(const Complex& num) {
    cout << num.real << " + " << num.imaginary << "i" << std::endl;
}

// Function to display a matrix
void displayMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

// Function to add two matrices
std::vector<std::vector<int>> addMatrix(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2) {
    int rows = matrix1.size();
    int cols = matrix1[0].size();

    std::vector<std::vector<int>> result(rows, std::vector<int>(cols, 0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return result;
}

// Function to subtract two matrices
std::vector<std::vector<int>> subtractMatrix(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2) {
    int rows = matrix1.size();
    int cols = matrix1[0].size();

    std::vector<std::vector<int>> result(rows, std::vector<int>(cols, 0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    return result;
}

// Function to multiply two matrices
std::vector<std::vector<int>> multiplyMatrix(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2) {
    int rows1 = matrix1.size();
    int cols1 = matrix1[0].size();
    int rows2 = matrix2.size();
    int cols2 = matrix2[0].size();

    if (cols1 != rows2) {
        std::cout << "Cannot multiply these matrices.\n";
        return std::vector<std::vector<int>>();
    }

    std::vector<std::vector<int>> result(rows1, std::vector<int>(cols2, 0));

    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

// Function to input matrix values
std::vector<std::vector<int>> inputMatrix(int rows, int cols) {
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols, 0));
    std::cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> matrix[i][j];
        }
    }
    return matrix;
}

// Function to find the transpose of a matrix
std::vector<std::vector<int>> transposeMatrix(const std::vector<std::vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    std::vector<std::vector<int>> result(cols, std::vector<int>(rows, 0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[j][i] = matrix[i][j];
        }
    }

    return result;
}

// Function to calculate GCD
int gcd(int a, int b) {
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}

// Function to calculate LCM
int lcm(int a, int b) {
    int hcf;
    float x = a, y = b;

    while (a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }
    if (a == 0) {
        hcf = b;
    } else {
        hcf = a;
    }

    return (x * y) / hcf;
}

// Function to calculate factorial
unsigned long long factorial1(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial1(n - 1);
    }
}

// Function to calculate nPr (permutations)
unsigned long long permutations(int n, int r) {
    return factorial1(n) / factorial1(n - r);
}

// Function to calculate nCr (combinations)
unsigned long long combinations(int n, int r) {
    return factorial1(n) / (factorial1(r) * factorial1(n - r));
}

// Function to display a vector
void displayVector(const std::vector<double>& vec) {
    std::cout << "Vector: ";
    for (double val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

// Function to calculate magnitude of a vector
double magnitude(const std::vector<double>& vec) {
    double mag = 0.0;
    for (double val : vec) {
        mag += val * val;
    }
    return sqrt(mag);
}

// Function to calculate the resultant addition of vectors
std::vector<double> resultantAddition(const std::vector<double>& vec1, const std::vector<double>& vec2, double angle) {
    double mag1 = magnitude(vec1);
    double mag2 = magnitude(vec2);

    std::vector<double> result;
    for (size_t i = 0; i < vec1.size(); ++i) {
        result.push_back(vec1[i] + vec2[i]);
    }

    double resultMag = sqrt(mag1 * mag1 + mag2 * mag2 + 2 * mag1 * mag2 * cos(angle * M_PI / 180.0));
    for (size_t i = 0; i < result.size(); ++i) {
        result[i] *= resultMag / magnitude(result);
    }

    return result;
}

// Function to calculate the resultant subtraction of vectors
std::vector<double> resultantSubtraction(const std::vector<double>& vec1, const std::vector<double>& vec2, double angle) {
    double mag1 = magnitude(vec1);
    double mag2 = magnitude(vec2);

    std::vector<double> result;
    for (size_t i = 0; i < vec1.size(); ++i) {
        result.push_back(vec1[i] - vec2[i]);
    }

    double resultMag = sqrt(mag1 * mag1 + mag2 * mag2 - 2 * mag1 * mag2 * cos(angle * M_PI / 180.0));
    for (size_t i = 0; i < result.size(); ++i) {
        result[i] *= resultMag / magnitude(result);
    }

    return result;
}

int main() {
    double operand1, operand2;
    int operation,opr;
do{
    cout << "Enter operation:\n";
    cout << "  1. Arithmetic                    2. Trigonometric\n";
    cout << "  3. Factorial                    4. Logarithm\n";
    cout << "  5. Power                         6. Polynomial\n";
    cout << "  7. Radians & Degree Conversion  8. Number System Conversion\n";
    cout << "  9. Complex numbers              10. Matrix\n";
    cout << "  11. LCM & GCD                   12. Permutation & Combination\n";
    cout << "  13. Vector                      14. Exit\n";
    cin >> operation;


    switch (operation) {
        case 1:{
            cout << "Enter operation:\n";
            cout << "  1. Addition        2. Subtraction\n";
            cout << "  3. Multiplication  4. Quotient\n";
            cout << "  5. Remainder\n";
            cin >> opr;
            
            cout << "Enter two operands: ";
            cin >> operand1 >> operand2;

            switch (opr) {
                case 1:
                    cout << "Result: " << operand1 + operand2 << endl;
                    break;
                case 2:
                    cout << "Result: " << operand1 - operand2 << endl;
                    break;
                case 3:
                    cout << "Result: " << operand1 * operand2 << endl;
                    break;
                case 4:
                    if (operand2 != 0) {
                        cout << "Result: " << operand1 / operand2 << endl;
                    } else {
                        cout << "Cannot divide by zero!\n";
                    }
                    break;
                case 5:
                    cout << "Result: " << int(operand1) % int(operand2) << endl;
                    break;
                default:
                    cout << "Invalid operation!\n";
            }
            break;
        }
        case 2:{
            cout << "Enter operation:\n";
            cout << "  1. Sine                2. Cosine\n";
            cout << "  3. Tangent             4. Cotangent\n";
            cout << "  5. Secant              6. Cosecant\n";
            cout << "  7. Inverse Sine       8. Inverse Cosine\n";
            cout << "  9. Inverse Tangent   10. Inverse Cotangent\n";
            cout << "  11. Inverse Secant    12. Inverse Cosecant\n";
            cin >> opr;
            switch (opr) {
                case 1:
                    cout << "Enter the angle in degrees: ";
                    cin >> operand1;
                    cout << "Sine: " << sine(operand1) << endl;
                    break;
                case 2:
                    cout << "Enter the angle in degrees: ";
                    cin >> operand1;
                    cout << "Cosine: " << cosine(operand1) << endl;
                    break;
                case 3:
                    cout << "Enter the angle in degrees: ";
                    cin >> operand1;
                    cout << "Tangent: " << tangent(operand1) << endl;
                    break;
                case 4:
                    cout << "Enter the angle in degrees: ";
                    cin >> operand1;
                    cout << "Cotangent: " << cotangent(operand1) << endl;
                    break;
                case 5:
                    cout << "Enter the angle in degrees: ";
                    cin >> operand1;
                    cout << "Secant: " << secant(operand1) << endl;
                    break;
                case 6:
                    cout << "Enter the angle in degrees: ";
                    cin >> operand1;
                    cout << "Cosecant: " << cosecant(operand1) << endl;
                    break;
                case 7:
                    cout << "Enter a value: ";
                    cin >> operand1;
                    cout << "Inverse Sine: " << arcsin(operand1) << endl;
                    break;
                case 8:
                    cout << "Enter a value: ";
                    cin >> operand1;
                    cout << "Inverse Cosine: " << arccos(operand1) << endl;
                    break;
                case 9:
                    cout << "Enter a value: ";
                    cin >> operand1;
                    cout << "Inverse Tangent: " << arctan(operand1) << endl;
                    break;
                case 10:
                    cout << "Enter a value: ";
                    cin >> operand1;
                    cout << "Inverse Cotangent: " << arccot(operand1) << endl;
                    break;
                case 11:
                    cout << "Enter a value: ";
                    cin >> operand1;
                    cout << "Inverse Secant: " << arcsec(operand1) << endl;
                    break;
                case 12:
                    cout << "Enter a value: ";
                    cin >> operand1;
                    cout << "Inverse Cosecant: " << arccsc(operand1) << endl;
                    break;
                default:
                    cout << "Invalid operation!\n";
            }
            break;
        }
        case 3:{
            cout << "Enter the number for factorial : ";
            int n;
            cin >> n;
            cout << factorial(n) << endl;
            break;
        }
        case 4: {
            double base, number;

            cout << "Enter the base of the logarithm: ";
            cin >> base;

            cout << "Enter the number: ";
            cin >> number;

            double result = customLog(base, number);

            cout << "Logarithm base " << base << " of " << number << " is: " << result << endl;
            break;
        }
        case 5:{
            double base;
            int exponent;
            cout << "Enter the base: ";
            cin >> base;
            cout << "Enter the exponent: ";
            cin >> exponent;
            double result = customPower(base, exponent);
            cout << base << " raised to the power of " << exponent << " is: " << result << endl;
            break;
        }
        case 6:{
            clist ob1, ob2, result;
            int choice, n, m,x,ans;
        
            do {
                cout << "Menu:\n";
                cout << "1. Create Polynomial 1\n";
                cout << "2. Create Polynomial 2\n";
                cout << "3. Display Polynomial 1\n";
                cout << "4. Display Polynomial 2\n";
                cout << "5. Add Polynomials\n";
                cout << "6. Display Resultant Polynomial\n";
                cout << "7. Quit\n";
                cout << "Enter your choice: ";
                cin >> choice;
        
                switch (choice) {
                    case 1:
                        cout << "Enter number of terms for Polynomial 1: ";
                        cin >> n;
                        ob1.create(n);
                        break;
        
                    case 2:
                        cout << "Enter number of terms for Polynomial 2: ";
                        cin >> m;
                        ob2.create(m);
                        break;
        
                    case 3:
                        cout << "Polynomial 1: ";
                        ob1.display();
                        break;
        
                    case 4:
                        cout << "Polynomial 2: ";
                        ob2.display();
                        break;
        
                    case 5:
                        result = ob1.addtopoly(ob2);
                        result.display();
                        cout << "Polynomials added successfully.\n";
                        break;
        
                    case 6:
                        cout << "Enter X value to Evaluate";
                        cin>>x;
                        ans=ob1.Evaluate(x);
                        cout<<"After Evaluate polynomial"<<ans<<endl;
                        break;
        
                    case 7:
                        cout << "Exiting program.\n";
                        break;
        
                    default:
                        cout << "Invalid choice. Please try again.\n";
                }
            } while (choice != 7);
            break;
        
        }
        case 7:{
            cout << "Enter operation:\n";
            cout << "  1. Radian to Degree   2. Degree to Radian\n";
            cin>>opr;
            double degrees, radians;
            switch(opr){
                case 1:
                    // Convert degrees to radians
                    cout << "Enter degrees to convert to radians: ";
                    cin >> degrees;
                    radians = degreesToRadians(degrees);
                    cout << degrees << " degrees = " << radians << " radians\n";
                    break;
                    
                case 2:
                    // Convert radians to degrees
                    cout << "Enter radians to convert to degrees: ";
                    cin >> radians;
                    degrees = radiansToDegrees(radians);
                    cout << radians << " radians = " << degrees << " degrees\n";
                    break;
            }
            break;
        }
        case 8:{
            int choice;
            int decimalNumber;
            string binaryNumber, octalNumber, hexadecimalNumber;
        
            cout << "Choose conversion type:\n";
            cout << "1. Decimal to Binary\n";
            cout << "2. Binary to Decimal\n";
            cout << "3. Decimal to Octal\n";
            cout << "4. Octal to Decimal\n";
            cout << "5. Decimal to Hexadecimal\n";
            cout << "6. Hexadecimal to Decimal\n";
            cout << "Enter your choice (1-6): ";
            cin >> choice;
        
            switch (choice) {
                case 1:
                    cout << "Enter a decimal number: ";
                    cin >> decimalNumber;
                    binaryNumber = decimalToBinary(decimalNumber);
                    cout << "Binary equivalent: " << binaryNumber << endl;
                    break;
        
                case 2:
                    cout << "Enter a binary number: ";
                    cin >> binaryNumber;
                    cout << "Decimal equivalent: " << binaryToDecimal(binaryNumber) << endl;
                    break;
        
                case 3:
                    cout << "Enter a decimal number: ";
                    cin >> decimalNumber;
                    octalNumber = decimalToOctal(decimalNumber);
                    cout << "Octal equivalent: " << octalNumber << endl;
                    break;
        
                case 4:
                    cout << "Enter an octal number: ";
                    cin >> octalNumber;
                    cout << "Decimal equivalent: " << octalToDecimal(octalNumber) << endl;
                    break;
        
                case 5:
                    cout << "Enter a decimal number: ";
                    cin >> decimalNumber;
                    hexadecimalNumber = decimalToHexadecimal(decimalNumber);
                    cout << "Hexadecimal equivalent: " << hexadecimalNumber << endl;
                    break;
        
                case 6:
                    cout << "Enter a hexadecimal number: ";
                    cin >> hexadecimalNumber;
                    cout << "Decimal equivalent: " << hexadecimalToDecimal(hexadecimalNumber) << endl;
                    break;
        
                default:
                    cout << "Invalid choice!\n";
            }
            break;
        }
        case 9:{
            Complex num1, num2, result;

            int operation;
            cout << "Choose operation:\n";
            cout << "1. Addition\n";
            cout << "2. Subtraction\n";
            cout << "3. Multiplication\n";
            cout << "4. Division\n";
            cout << "Enter your choice (1-4): ";
            cin >> operation;
        
            cout << "Enter real and imaginary parts of first complex number: ";
            cin >> num1.real >> num1.imaginary;
        
            cout << "Enter real and imaginary parts of second complex number: ";
            cin >> num2.real >> num2.imaginary;
        
            switch (operation) {
                case 1:
                    result = addComplex(num1, num2);
                    break;
                case 2:
                    result = subtractComplex(num1, num2);
                    break;
                case 3:
                    result = multiplyComplex(num1, num2);
                    break;
                case 4:
                    result = divideComplex(num1, num2);
                    break;
                default:
                    std::cout << "Invalid operation!\n";
            }
        
            cout << "Result: ";
            displayComplex(result);
            break;
        }
        case 10:{
            int rows, cols;
            int operation;
        
            cout << "Choose operation:\n";
            cout << "1. Matrix Addition\n";
            cout << "2. Matrix Subtraction\n";
            cout << "3. Matrix Multiplication\n";
            cout << "4. Transpose of a Matrix\n";
            cout << "Enter your choice (1-4): ";
            cin >> operation;
        
            switch (operation) {
                case 1:{
                    cout << "Enter the number of rows for Matrix 1: ";
                    cin >> rows;
                    cout << "Enter the number of columns for Matrix 1: ";
                    cin >> cols;
                    vector<std::vector<int>> matrix1 = inputMatrix(rows, cols);
                    cout << "Enter the number of rows for Matrix 2: ";
                    cin >> rows;
                    cout << "Enter the number of columns for Matrix 2: ";
                    cin >> cols;
                    vector<std::vector<int>> matrix2 = inputMatrix(rows, cols);
        
                    cout << "Matrix 1:\n";
                    displayMatrix(matrix1);
        
                    cout << "Matrix 2:\n";
                    displayMatrix(matrix2);
        
                    vector<std::vector<int>> addition = addMatrix(matrix1, matrix2);
                    cout << "Matrix Addition:\n";
                    displayMatrix(addition);
                    break;
                }
                case 2:{
                    // Matrix Subtraction
                    cout << "Enter the number of rows for Matrix 1: ";
                    cin >> rows;
                    cout << "Enter the number of columns for Matrix 1: ";
                    cin >> cols;
        
                    vector<std::vector<int>> matrix1 = inputMatrix(rows, cols);
        
                    cout << "Enter the number of rows for Matrix 2: ";
                    cin >> rows;
                    cout << "Enter the number of columns for Matrix 2: ";
                    cin >> cols;
        
                    vector<std::vector<int>> matrix2 = inputMatrix(rows, cols);
        
                    cout << "Matrix 1:\n";
                    displayMatrix(matrix1);
        
                    cout << "Matrix 2:\n";
                    displayMatrix(matrix2);
        
                    vector<std::vector<int>> subtraction = subtractMatrix(matrix1, matrix2);
                    cout << "Matrix Subtraction:\n";
                    displayMatrix(subtraction);
                    break;
                }
                case 3:{
                    // Matrix Multiplication
                    cout << "Enter the number of rows for Matrix 1: ";
                    cin >> rows;
                    cout << "Enter the number of columns for Matrix 1: ";
                    cin >> cols;
        
                    vector<std::vector<int>> matrix1 = inputMatrix(rows, cols);
        
                    cout << "Enter the number of rows for Matrix 2: ";
                    cin >> rows;
                    cout << "Enter the number of columns for Matrix 2: ";
                    cin >> cols;
        
                    vector<std::vector<int>> matrix2 = inputMatrix(rows, cols);
        
                    cout << "Matrix 1:\n";
                    displayMatrix(matrix1);
        
                    cout << "Matrix 2:\n";
                    displayMatrix(matrix2);
        
                    vector<std::vector<int>> multiplication = multiplyMatrix(matrix1, matrix2);
                    cout << "Matrix Multiplication:\n";
                    displayMatrix(multiplication);
                    break;
                }
                case 4:{
                    // Transpose of a Matrix
                    cout << "Enter the number of rows for the matrix: ";
                    cin >> rows;
                    cout << "Enter the number of columns for the matrix: ";
                    cin >> cols;
        
                    vector<std::vector<int>> matrix = inputMatrix(rows, cols);
        
                    cout << "Original Matrix:\n";
                    displayMatrix(matrix);
        
                    vector<std::vector<int>> transpose = transposeMatrix(matrix);
                    cout << "Transpose of Matrix:\n";
                    displayMatrix(transpose);
                    break;
                }
                default:{
                    cout << "Invalid operation!\n";
                }
            }
            break;
        }
        case 11:{
            int choice, num1, num2;

            std::cout << "Choose operation:\n";
            std::cout << "1. Calculate GCD\n";
            std::cout << "2. Calculate LCM\n";
            std::cout << "Enter your choice (1-2): ";
            std::cin >> choice;
        
            switch (choice) {
                case 1:
                    std::cout << "Enter first number: ";
                    std::cin >> num1;
        
                    std::cout << "Enter second number: ";
                    std::cin >> num2;
        
                    std::cout << "GCD is: " << gcd(num1, num2) << std::endl;
                    break;
        
                case 2:
                    std::cout << "Enter first number: ";
                    std::cin >> num1;
        
                    std::cout << "Enter second number: ";
                    std::cin >> num2;
        
                    std::cout << "LCM is: " << lcm(num1, num2) << std::endl;
                    break;
        
                default:
                    std::cout << "Invalid operation!\n";
            }
            break;
        }
        case 12:{
            int choice, n, r;

            std::cout << "Choose operation:\n";
            std::cout << "1. Permutations (nPr)\n";
            std::cout << "2. Combinations (nCr)\n";
            std::cout << "Enter your choice (1 or 2): ";
            std::cin >> choice;
        
            switch (choice) {
                case 1:
                    // Calculate nPr
                    std::cout << "Enter the value of n: ";
                    std::cin >> n;
                    std::cout << "Enter the value of r: ";
                    std::cin >> r;
                    std::cout << "Permutations (nPr) of " << n << " objects taken " << r << " at a time: "
                              << permutations(n, r) << std::endl;
                    break;
                case 2:
                    // Calculate nCr
                    std::cout << "Enter the value of n: ";
                    std::cin >> n;
                    std::cout << "Enter the value of r: ";
                    std::cin >> r;
                    std::cout << "Combinations (nCr) of " << n << " objects taken " << r << " at a time: "
                              << combinations(n, r) << std::endl;
                    break;
                default:
                    std::cout << "Invalid choice!\n";
            }
            break;
        }

        case 13:{
            int size;
            std::cout << "Enter the size of vectors: ";
            std::cin >> size;
        
            std::vector<double> vector1, vector2;
            std::cout << "Enter elements for vector 1:\n";
            for (int i = 0; i < size; ++i) {
                double val;
                std::cin >> val;
                vector1.push_back(val);
            }
        
            std::cout << "Enter elements for vector 2:\n";
            for (int i = 0; i < size; ++i) {
                double val;
                std::cin >> val;
                vector2.push_back(val);
            }
        
            double angle;
            std::cout << "Enter the angle between the vectors in degrees: ";
            std::cin >> angle;
        
            int operation;
            std::cout << "Choose operation:\n";
            std::cout << "1. Resultant Addition\n";
            std::cout << "2. Resultant Subtraction\n";
            std::cout << "Enter your choice (1 or 2): ";
            std::cin >> operation;
        
            switch (operation) {
                case 1: {
                    std::vector<double> addition = resultantAddition(vector1, vector2, angle);
                    std::cout << "Resultant Addition:\n";
                    displayVector(addition);
                    break;
                }
                case 2: {
                    std::vector<double> subtraction = resultantSubtraction(vector1, vector2, angle);
                    std::cout << "Resultant Subtraction:\n";
                    displayVector(subtraction);
                    break;
                }
                default:
                    std::cout << "Invalid operation!\n";
            }
            break;
        }
        case 14:
            exit(0);
        
        default:
            cout << "Invalid operation!\n";
    }
}while(operation!=14);
    return 0;
}
