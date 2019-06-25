// -----------------------------------------------------------
//
//	Test file of nodeBST class for Assignment 2
//	Version 1 : 6 April 2018
//	Author    : Madyarini Grace Ariel	
//
//	Testing Notes : Uncomment to test nodeBST class
//	 
// -----------------------------------------------------------

#include <iostream>
#include "Weather.h"
#include "nodeBST.h"
#include <string>

using namespace std;

void print(int& x)
{
	cout << x << " ";
}

void print(string& x)
{
	cout << x << " ";
}
/*
int main()
{
	cout << " -- Testing BST of integers --\n";
	nodeBST<int> iList;
	iList.insert(3);
	iList.insert(5);
	iList.insert(1);
	iList.insert(4);
	cout << "Testing inorder\n";
	iList.inorderTraversal(print);
	cout << "\nTesting preorder\n";
	iList.preorderTraversal(print);
	cout << "\nTesting postorder\n";
	iList.postorderTraversal(print);
	cout << "\nTesting isEmpty function\n";
	cout << "isEmpty returns : " << iList.isEmpty() << endl;
	cout << "Testing size function\n";
	cout << "size returns : " << iList.size() << endl;
	cout << "Testing getMax function\n";
	int* num3 = iList.getMax();
	cout << "getMax returns : " << *num3 << endl;

	cout << "Testing isEmpty and getMax functions of an empty BST\n";
	nodeBST<int> iList2;
	cout << "isEmpty returns : " << iList2.isEmpty() << endl;
	int* w3 = iList2.getMax();
	
	cout << "getMax returns pointer that is : ";
	if(w3 == NULL)
		cout << "Null\n";
	else
		cout << "Not null\n";

	cout << "Testing overloading of assignment operator\n";
	iList2 = iList;
	cout << "iList2 = iList, inorder traversal of iList2 : ";
	iList2.inorderTraversal(print);

	cout << "\n\n -- Testing BST of string --\n";
	cout << "Testing copy constructor\n";
	nodeBST<string> s1;
	s1.insert("pineapple");
	s1.insert("apple");
	s1.insert("banana");
	cout << "Inserted pineapple, apple, and banana to s1.\n";
	nodeBST<string> s2(s1);
	cout << "Inorder traversal of s2 which is copied from s1 : "; 
	s2.inorderTraversal(print);
	cout << "\nTesting search and getSearch function\n";
	cout << "s1.search(\"apple\") returns : " << s1.search("apple") << endl;
	cout << "s1.search(\"lemon\") returns : " << s1.search("lemon") << endl;
	cout << "s1.getSearch(\"apple\") returns : ";
	if(s1.getSearch("apple") != NULL)
		cout << *(s1.getSearch("apple")) << endl;
	else
		cout << "NULL\n";
	cout << "s1.getSearch(\"lemon\") returns : ";
	if(s1.getSearch("lemon") != NULL)
		cout << *(s1.getSearch("lemon")) << endl;
	else
		cout << "NULL\n";

	system("PAUSE");
	return 0;
}
*/