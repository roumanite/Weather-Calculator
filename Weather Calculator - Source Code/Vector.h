/**
*******************************************************
*
* @class Vector
* @file  Vector.h
* @brief A custom vector templated class
* @details Vector Template class for Assignment 2
* @version 1 
* @date 03/03/2018
* @author Madyarini Grace Ariel
*
*
* Remarks :
* - There is no function for getCapacity() because the user is 
*   not supposed to care about the size of the dynamic array,
*   but the number of items hold currently in the array (getSize).
* - There is no function for isFull() because the user is not
*   supposed to be concerned about this since it is a dynamic array,
*   the array will automatically resize when it is full.
* - There is no print function because a data structure's job is not I/O.
*
*******************************************************
*/
 
#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

template <class Type>
class Vector
{
public:
	/**
	* @brief Default Constructor
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	Vector();

	/**
	* @brief Default Destructor
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	~Vector();

	Vector(const Vector<Type>& otherVector);

	/**
	* @brief Push back item into the Vector
	* @param i - Item
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	void add(const Type& i);

	/**
	* @brief Resize the Vector
	* @param newSize - New size of Vector
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	void resize(int newSize); 

	/**
	* @brief Get number of items inside Vector
	* @return Number of items in integer format
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	int getSize();

	/**
	* @brief Check whether the Vector is empty or not
	* @return Boolean value - true means there are no items inside the Vector
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	bool isEmpty() const;
	Type& operator[] (int index);
	const Vector<Type>& operator= (const Vector<Type>&);
private: 
	int capacity; 
	Type *list;
	int length;
};

template <class Type>
Vector<Type>::Vector()
{
	length = 0;
	capacity = 200;
	list = new Type[capacity];
}

template <class Type>
Vector<Type>::~Vector()
{
	delete[] list;
}

template <class Type>
Vector<Type>::Vector(const Vector<Type>& otherVector)
{
	capacity = otherVector.capacity;
	length = otherVector.length;
	list = new Type[capacity];
	for(int i = 0; i < length; i++)
		list[i] = otherVector.list[i];
}

template <class Type>
void Vector<Type>::resize(int newSize)
{
	Type *newList = new Type[capacity];
	Type *newListP = newList;
	Type *oldListP = list;

	while(oldListP != (list+length))
	{
		*(newListP) = *(oldListP);
		newListP++;
		oldListP++;
	}

	capacity = newSize;
	delete[] list;
	list = newList;
}

template <class Type>
void Vector<Type>::add(const Type& i)
{
	if((capacity/2)==length)
	{
		Vector :: resize (capacity * 1.5);
	}
	list[length] = i;
	length++;
}

template <class Type>
int Vector<Type>::getSize()
{
	return length;
}

template <class Type>
bool Vector<Type>::isEmpty() const
{
	return (length == 0);
}

template <class Type>
Type& Vector<Type>::operator[] (int index)
{
	assert (index >= 0 && index < length);
	return list[index];
}

template <class Type>
const Vector<Type>& Vector<Type>::operator=(const Vector<Type>& otherVector)
{
	if(this != &otherVector)
	{
		delete[] list;
		capacity = otherVector.capacity;
		length = otherVector.length;

		list = new Type[capacity];

		for(int i = 0; i < length; i++)
			list[i] = otherVector.list[i];
	}
}
#endif //VECTOR_H
