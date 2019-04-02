// Description: Lab 7B - Sortable Vector
// Author: Katherine-Marie Gonzales
// COMSC200 - 5001
// April 1, 2019
// Status: Complete

//testSortableVector.cpp
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include "SortableVector.h"
using namespace std;


int main() {
	const int SIZE = 5;  

	SortableVector<int> intTable(SIZE); 
	SortableVector<double> doubleTable(SIZE); 


	for (int x = 0; x < SIZE ; x++) {
		intTable[x] = SIZE - x;
		doubleTable[x]= SIZE - (x * 1.1f);
	}

	cout << "Before sorting, these values are in intTable:\n";
	for (int x = 0; x < SIZE; x++)
		cout << intTable[x] << "  ";
	cout << "\nBefore sorting, these values are in doubleTable:\n";
	for (int x = 0; x < SIZE; x++)
		cout << doubleTable[x] << "  ";
	
	intTable.sort();
	doubleTable.sort();

	cout << "\nAfter sorting, these values are in intTable:\n";
	for (int x = 0; x < SIZE; x++)
		cout << intTable[x] << "  ";
	cout << "\nAfter sorting, these values are in doubleTable:\n";
	for (int x = 0; x < SIZE; x++)
		cout << doubleTable[x] << "  ";
		
	return 0;
}