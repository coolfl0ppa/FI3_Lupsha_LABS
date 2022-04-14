#include <iostream>
#include "TComplex.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    TComplex com1(4, 5);
    TComplex com2(8, 15);
    cout <<"com1 = " << com1;
    TComplex com3 = com2;
    cout <<"com2 = " << com2 << "\n" << "Оператор присваивания: com3 = com2 >> "
         << "\n" << "com3 = " << com3 << endl;
    com3 = com1 + com2;
    cout << "Оператор сложения: com3 = com1 + com2 >> "
         << "\n" << "com3 = " << com3 << endl;
    com3 = com1 - com2;
    cout << "Оператор вычитания: com3 = com1 - com2 >> "
         << "\n" << "com3 = " << com3  << endl;
    com3 = com1 * com2;
    cout << "Оператор умножения: com3 = com1 * com2 >> "
        << "\n" << "com3 = " << com3 << endl;
    com3 = com1 / com2;
    cout << "Оператор деления: com3 = com1 / com2 >> "
        << "\n" << "com3 = " << com3 << endl;
    cout << "Cравнение: com1 = com2 ? >> " << endl;
    if (com1 == com2)
        cout << "True" << endl;
    else
        cout << "False" << endl;
    TComplex com(4, 5);
    cout << "\nМодуль комплексного числа com1 = " << com.ABS() << endl;
    com.Pow(2);
    cout << "\nВозведение com в степень 2\n" << com << endl;
    com.Pow(0.5);
    cout << "\nВозведение com в степень 0.5\n" << com << endl;
    cout << "\nТригонометрическая форма " << com1 << endl;
    com1.TrigForma();
}
