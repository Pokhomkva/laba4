#include <iostream>
#include <cassert>
using namespace std;

//Напечатать шестнадцатеричную цифру для значения от 0 до 15
char
nibble_to_hex(uint8_t i)
{
    char digits[]="0123456789abcdef";
    return digits[i];
}
//Указание компилятору, что значение одного типа нужно трактовать как значение другого, называется приведением типов
const uint8_t*
as_bytes(const void* data) {
   return reinterpret_cast<const uint8_t*>(data);
}
//Напечатать байт как два nibble
void
print_in_hex(uint8_t byte)
{
    cout << nibble_to_hex(byte >> 4)
         << nibble_to_hex(byte & 0x0f);
}
//Преобразовать void* в uint8_t* и напечатать массив этих байт
void
print_in_hex(const void* data, size_t size)
{
    const uint8_t* bytes = as_bytes(data);
    for (size_t i=0; i < size; i++) {
            print_in_hex(bytes[i]);
        if ((i+1) % 16 == 0){
                cout << '\n';
            }
            else {
                cout << ' ';
            }
    }
}
//Напечатать байт в двоичном виде
char
bit_digit(uint8_t byte, uint8_t bit){
if (byte & 0b00000001 << bit){
    return '1';
}
return '0';
}

//Сдвиги на 7, 6, …, 0 бит логично делать циклом
void
print_in_binary(uint8_t byte)
{
    for (uint8_t bit = 7; bit > 0; bit--)

    cout << bit_digit(byte, bit);
    cout << bit_digit(byte,0);

}
//Напечатать блок данных в двоичном виде
void
print_in_binary(const void* data, size_t size)
{
    const uint8_t* bytes = as_bytes(data);
    for (size_t i=0; i < size; i++) {
            print_in_binary(bytes[i]);
        if ((i+1) % 4 == 0){
                cout << '\n';
            }
            else {
                cout << ' ';
            }
    }
}

 void
 calc(uint16_t op1,char oper,uint16_t op2)
 {
     print_in_hex(&op1,sizeof op1);
     cout << oper << " ";
     print_in_hex(&op2,sizeof op2);
     cout << "= ";
     uint16_t result;
     if (oper == '&')
     result=op1 & op2;
     if (oper == '|')
     result=op1 | op2;
     if (oper == '^')
     result = op1 ^ op2;
     print_in_hex(&result,sizeof(result));
     cout << '\n';
     print_in_binary(&op1,sizeof op1);
     cout << oper << " ";
     print_in_binary(&op2,sizeof op2);
     cout << "= ";
     print_in_binary(&result,sizeof(result));
     cout << '\n';
 }
 int main()
 {
    /* int a,c;
     char b;
     cout << "Enter a =";
     cin >> a;
     cout << "\nEnter b =";
     cin >> b;
     cout << "\nEnter c =";
     cin >> c;
     calc (a, b ,c);
 }*/
   calc(1025, '&', 127);
 system ("pause");
 }

