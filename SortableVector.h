// Description: Lab 7B - Sortable Vector
// Author: Katherine-Marie Gonzales
// COMSC200 - 5001
// April 1, 2019
// Status: Complete

//SortableVector.h
#ifndef SORTABLEVECTOR_H
#define SORTABLEVECTOR_H
#include <iostream>
#include <new>       
#include <cstdlib>  
using namespace std;

template <class T>
class SortableVector
{
private:
   T *aptr;          
   int arraySize;    
   void memError();  
   void subError();  


public:
   SortableVector()
      { aptr = 0; arraySize = 0;}
      
   SortableVector(int);
   
   SortableVector(const SortableVector &);
   
   ~SortableVector();
   
   int size() const
      { return arraySize; }

   T getElementAt(int position);

   T &operator[](const int &);
   
   void sort();
};


template <class T>
SortableVector<T>::SortableVector(int s)
{
   arraySize = s;

   try
   {
      aptr = new T [s];
   }
   catch (bad_alloc)
   {
      memError();
   }


   for (int count = 0; count < arraySize; count++)
      *(aptr + count) = 0;
}



template <class T>
SortableVector<T>::SortableVector(const SortableVector &obj)
{

   arraySize = obj.arraySize;
   
 
   aptr = new T [arraySize];
   if (aptr == 0)
      memError();
      
 
   for(int count = 0; count < arraySize; count++)
      *(aptr + count) = *(obj.aptr + count);
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SortableVector<T>::~SortableVector()
{
   if (arraySize > 0)
      delete [] aptr;
}



template <class T>
void SortableVector<T>::memError()
{
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}


template <class T>
void SortableVector<T>::subError()
{
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}



template <class T>
T SortableVector<T>::getElementAt(int sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}


template <class T>
T &SortableVector<T>::operator[](const int &sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
};


template <class T> // to sort the content 
void SortableVector<T>::sort() 
{
	
	for(int i = 1; i < arraySize; i++)  // ar[i] is element to insert
    {
        for(int j = i; j > 0; j--)
            if(aptr[j] < aptr[j - 1])
               swap(aptr[j], aptr[j - 1]);
            else break;
    }    
    
}

#endif 