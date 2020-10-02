/*
Комплексное число в алгебраической форме представляются парой действительных чисел (a, b), где a – действительная часть, b – мнимая часть. Реализовать класс Complex для работы с комплексными числами. Обязательно должны быть присутствовать операции
сложения add, (a, b) + (c, d) = (a + c, b + d);
вычитания sub, (a, b) – (c, d) = (a – c, b – d);
умножения mul, (a, b)  (c, d) = (ac – bd, ad + bc);
деления div, (a, b) / (c, d) = (ac + bd, bc – ad) / (c2 + d2);
сравнение equ, (a, b) = (c, d), если (a = c) и (b = d);
сопряженное число conj, conj(a, b) = (a, –b).
Реализовать операции сравнения модулей.

Операции сложения, вычитания, умножения, деления, сравнения на равенство должны быть выполнены в виде перегрузки операторов.
Необходимо реализовать пользовательский литерал для работы с константами типа Complex.
*/

#include<iostream>
#include<cmath>


using namespace std;

class Complex {
public:
    Complex() {
        this->real = 0;
        this->img = 0;
    }

    void setRealImg(double first, double second) {
        this->real = first;
        this->img = second;
    }
    void getData();
    void display();

    Complex operator+ (Complex c1);
    Complex operator- (Complex c1);
    Complex operator* (Complex c1);
    Complex operator/ (Complex c1);
    bool operator== (Complex c1);
    bool operator^ (Complex c1);
    float abs();

private:
    float real;
    float img;
};


void Complex::display() {
   cout << "(" << this->real << ")" << " + " << "(" << this->img << ")" << "i";
}

void Complex::getData() {
    cout << "Enter the real and img of complex no.\n";
    cout << "Real : ";
    cin >> this->real;
    cout << "Img : ";
    cin >> this->img;
}

Complex Complex::operator/ (Complex c1) {
    Complex div;
    div.real = ( (this->real * c1.real) + (this->img * c1.img) ) / ( pow(c1.real, 2) + pow(c1.img, 2) );
    div.img = ( (this->img * c1.real) - (this->real * c1.img) ) / ( pow(c1.real, 2) + pow(c1.img, 2) );
    return div;
}

Complex Complex::operator* (Complex c1) {
    Complex mul;
    mul.real = ( (this->real * c1.real) - (this->img * c1.img) );
    mul.img = ( (this->real * c1.img) + (this->img * c1.real) );
    return mul;
}

Complex Complex::operator- (Complex c1) {
    Complex sub;
    sub.real = this->real - c1.real;
    sub.img = this->img - c1.img;
    return sub;
}

Complex Complex::operator+ (Complex c1) {
    Complex add;
    add.real = this->real + c1.real;
    add.img = this->img + c1.img;
    return add;
}

bool Complex::operator== (Complex c1) {
    if (this->real == c1.real && this->img == c1.img){
        return true;
    }
    return false;
}

bool Complex::operator^ (Complex c1) {
    if (this->real == c1.real && this->img == -1 * c1.img) {
        return true;
    }
    return false;
}

float Complex::abs() {
    float max_part = max(this->real, this->img);
    float min_part = min(this->real, this->img);
    return max_part * sqrt(1 + min_part * min_part / max_part / max_part);
}

class Part {
public:
    Part() {
        this->part = 0;
    }
    Part(long double part){
        this->part = part;
    }
    double part;
};

Part operator ""_REAL(long double part) {
    Part lit(part);
    return lit;
}

Part operator ""_IMG(long double part) {
    Part lit(part);
    return lit;
}

int main() {
    Complex a, b, c;
    Complex example;
    Part part_real, part_img;

    int opt, opt_exit = 1;

    while(opt_exit == 1) {
        a.getData();
        b.getData();

        cout << "\n\t ---Main Menu--";
        cout << "\n\t 1.Addition";
        cout << "\n\t 2.Subtraction";
        cout << "\n\t 3.Multiplication";
        cout << "\n\t 4.Division";
        cout << "\n\t 5.Equal";
        cout << "\n\t 6.Conjugate";
        cout << "\n\t 7.Show number with\n\t   Users literals\n\t   in Complex define";
        cout << "\n\t 8.Exit";
        cout << "\n\t---Enter your choice--> ";

        cin >> opt;

        switch(opt) {
        case 1:
            c = a + b;
            cout << "\n\n";

            a.display();
            cout << " + ";
            b.display();
            cout << " = ";
            c.display();
            break;

        case 2:
            c = a - b;
            cout << "\n\n";
            a.display();
            cout << " - ";
            b.display();
            cout << " = ";
            c.display();
            break;

        case 3:
            c = a * b;
            cout << "\n\n";
            a.display();
            cout << " * ";
            b.display();
            cout << " = ";
            c.display();
            break;

        case 4:
            c = a / b;
            cout << "\n\n";
            a.display();
            cout << " / ";
            b.display();
            cout << " = ";
            c.display();
            break;

        case 5:
            cout << "\n\t   Numbers are absolutes? (1 is yes) --> ";
            cin >> opt;
            cout << "\n\n";
            if (opt == 1){
                cout << a.abs();
                if (a.abs() == b.abs())
                    cout << " == ";
                else
                    cout << " != ";
                cout << b.abs();
            } else {
                a.display();
                if (a == b)
                    cout << " == ";
                else
                    cout << " != ";
                b.display();
            }
            break;

        case 6:
            cout << "\n\n";
            a.display();
            if (a ^ b)
                cout << "  =  ";
            else
                cout << " =\\= ";
            b.display();
            break;

        case 7:
            part_real = 4.74_REAL;
            part_img = 5.46_IMG;
            example.setRealImg(part_real.part, part_img.part);
            example.display();
            break;

        case 8:
            return 0;

        default:
            cout << "\n\n\t---Invalid choice....... try again\n";
            break;
        }
        cout << "\n\n\t---Press 1 to continue--> ";
        cin >> opt_exit;
    }
   return 0;
}