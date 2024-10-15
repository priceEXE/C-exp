#include "../../include/ch4_homework/MyArray.hpp"
#include <iostream>
using namespace std;
MyArray::MyArray(int size) : size(size), p(new int[size])
{
    cout << "MyArrayconstructor " << endl; }
MyArray::MyArray(const MyArray &old) : size(old.size),p(new int[size])
{
    for (int i = 0; i < size; i++)
    {
            p[i] = old.p[i];
    }
    cout << "MyArray copy constructor" << endl;
}