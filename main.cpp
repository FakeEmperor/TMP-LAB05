/**
* @file main.cpp
* @author FakeEmperor <fake_empire@mail.ru>
* @version 1.0
* <http://github.com/fakeemperor/TMP-LAB05/>
*
* @section LICENSE
*
* GNU GPL LICENSE
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License as
* published by the Free Software Foundation; either version 2 of
* the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
* General Public License for more details at
* http://www.gnu.org/copyleft/gpl.html
*
* @section DESCRIPTION
*
* This is test code for basic learning of template functions,
* classes and new feature in C++0x - lambda functions.
*
*/

#pragma warning(disable:4996)
#include <iostream>
#include <conio.h>


template <typename T>
using SwappingFunction = bool(*)(T&a, T&b);

template <typename T>
void sort(T* array, size_t size, SwappingFunction<T> sf){
	size_t i, u;
	for (i = 0; i < size; i++){
		for (u = i+1; u < size; u++){
			sf(array[i], array[u]);

		}
	}
}
class A{
	int value;
public:
	A(int a = 0):value(a){
	
	};
	static bool swap(A& a, A& b){
		if (a.value > b.value){
			int temp = a.value;
			a.value = b.value;
			b.value = temp;
			return true;
		}
		return false;
	};
	friend std::ostream& operator << (std::ostream& os,const A& a){
		os << a.value;
		return os;
	};
};

class B{
	double value;
	
public:
	B(double b = 0) :value(b){

	};
	static bool swap(B& a, B& b){
		if (a.value > b.value){
			double temp = a.value;
			a.value = b.value;
			b.value = temp;
			return true;
		}
		return false;
	};
	friend std::ostream& operator << (std::ostream& os, const B& b){
		os << b.value;
		return os;
	};
};
void printArrays(A *arrA,const size_t sa, B *arrB,const size_t sb){
	size_t i;
	std::cout << "Array A:=[";
	for (i = 0; i < sa; i++)
		std::cout << arrA[i] << (i < (sa-1) ? ", " : "");
	std::cout << "]" << std::endl;
	std::cout << "Array B:=[";
	for (i = 0; i < sb; i++)
		std::cout << arrB[i] << (i < (sb-1) ? ", " : "");
	std::cout << "]" << std::endl;
}
int main(){
	
	A arrA[5] = { 5, 0, 4, 2, 5};
	B arrB[6] = { 3.0, 2.9, 1.1, 0.5, 4.4, 10.1 };
	std::cout << "Hello, this is TMP-LAB05: \'Template Functions\'. Testing started..." << std::endl
		<< "Input arrays:" << std::endl;
	printArrays(arrA, 5, arrB, 6);
	sort(arrA, 5, A::swap);
	sort(arrB, 6, B::swap);
	std::cout << "Ouput arrays: " << std::endl;

	printArrays(arrA, 5, arrB, 6);
	std::cout << "To continue, press any key...";
	getch();
	return 0;
}