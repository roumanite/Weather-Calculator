/**
*****************************************************************************
*
* @class nodeBST
* @file  nodeBST.h
* @brief A Binary Search Tree class
* @details Binary Search Tree class for Assignment 2
* @version 1 
* @date 06/04/2018
* @author Madyarini Grace Ariel
*
*
*
*****************************************************************************
*/

#ifndef H_nodeBST
#define H_nodeBST

#include <iostream>

using namespace std;

template<class elemType>
struct nodeType
{
	elemType info;
	nodeType<elemType> *lLink;
	nodeType<elemType> *rLink;
};

template<class elemType>
class nodeBST
{
	typedef void (*flTyp)(elemType&);
public:
	/**
	* @brief Default Constructor
	* @date 06/04/2018
	* @author Madyarini Grace Ariel
	*/
	nodeBST();

	/**
	* @brief Default Destructor
	* @date 06/04/2018
	* @author Madyarini Grace Ariel
	*/
	~nodeBST();
	
	/**
	* @brief Copy Constructor
	* @param otherTree - BST to be copied from 
	* @date 06/04/2018
	* @author Madyarini Grace Ariel
	*/
	nodeBST(const nodeBST<elemType>& otherTree);

	/**
	* @brief Search and get item in the BST
	* @param searchItem - item to be searched
	* @return pointer to the item searched if found, null if not found
	* @date 06/04/2018
	* @author Madyarini Grace Ariel
	*/
	elemType* getSearch(const elemType& searchItem) const;

	/**
	* @brief Search item in the BST
	* @param searchItem - item to be searched
	* @return true if found, false if not found
	* @date 06/04/2018
	* @author Madyarini Grace Ariel
	*/
	bool search(const elemType& searchItem) const;

	/**
	* @brief Insert item in the BST
	* @param insertItem - item to be inserted
	* @post nodes increased to 1 if insertItem is unique. nodes stay the same if insertItem has existed in the BST.
	* @date 06/04/2018
	* @author Madyarini Grace Ariel
	*/
	void insert(const elemType& insertItem);
	
	/**
	* @brief Check if BST is empty
	* @return true if empty, false if not empty
	* @date 06/04/2018
	* @author Madyarini Grace Ariel
	*/
	bool isEmpty() const;

	/**
	* @brief Do something to every node in the BST with inorder traversal
	* @param fl - Function pointer to know what to do to every node traversed
	* @date 06/04/2018
	* @author Madyarini Grace Ariel
	*/
	void inorderTraversal(flTyp) const;

	/**
	* @brief Do something to every node in the BST with preorder traversal
	* @param fl - Function pointer to know what to do to every node traversed
	* @date 06/04/2018
	* @author Madyarini Grace Ariel
	*/
	void preorderTraversal(flTyp) const;

	/**
	* @brief Do something to every node in the BST with postorder traversal
	* @param fl - Function pointer to know what to do to every node traversed
	* @date 06/04/2018
	* @author Madyarini Grace Ariel
	*/
	void postorderTraversal(flTyp) const;

	/**
	* @brief Destruct BST
	* @param p - Node to be destroyed
	* @post Node destroyed
	* @date 06/04/2018
	* @author Madyarini Grace Ariel
	*/
	void destroy(nodeType<elemType>* &p);

	/**
	* @brief Get number of nodes in the BST
	* @return size in integer format
	* @date 06/04/2018
	* @author Madyarini Grace Ariel
	*/
	int size();

	/**
	* @brief Get maximum value from all node values
	* @return pointer to the item whose value is maximum, null if BST is empty
	* @date 06/04/2018
	* @author Madyarini Grace Ariel
	*/
	elemType* getMax();

	const nodeBST<elemType>& operator=(const nodeBST<elemType>&);
private:
	/**
	* @brief Helper method for inorderTraversal
	* @param p - Node, fl - Function pointer to know what to do to every node traversed
	* @date 06/04/2018
	* @author Madyarini Grace Ariel
	*/
	void inorder(nodeType<elemType> *p, flTyp) const;
	/**
	* @brief Helper method for preorderTraversal
	* @param p - Node, fl - Function pointer to know what to do to every node traversed
	* @date 06/04/2018
	* @author Madyarini Grace Ariel
	*/
	void preorder(nodeType<elemType> *p, flTyp) const;

	/**
	* @brief Helper method for postorderTraversal
	* @param p - Node, fl - Function pointer to know what to do to every node traversed
	* @date 06/04/2018
	* @author Madyarini Grace Ariel
	*/
	void postorder(nodeType<elemType> *p, flTyp) const;

	/**
	* @brief Helper method for getMax()
	* @param p - Node to be checked
	* @date 06/04/2018
	* @author Madyarini Grace Ariel
	*/
	void max(nodeType<elemType>* p);

	/**
	* @brief Helper method for copy constructor and = overloading 
	* @param &copiedTreeRoot - node to be filled, otherTreeRoot - node to be copied
	* @date 06/04/2018
	* @author Madyarini Grace Ariel
	*/
	void copyTree(nodeType<elemType>* &copiedTreeRoot, nodeType<elemType>* otherTreeRoot);

	/**
	* @brief Helper method for size()
	* @param p - Node 
	* @date 06/04/2018
	* @author Madyarini Grace Ariel
	*/
	int size(nodeType<elemType>* p);
	nodeType<elemType> *root;
	elemType maximum;
};

template <class elemType>
void nodeBST<elemType>::copyTree(nodeType<elemType>* &copiedTreeRoot, nodeType<elemType>* otherTreeRoot)
{
	if(otherTreeRoot == NULL)
		copiedTreeRoot = NULL;
	else
	{
		copiedTreeRoot = new nodeType<elemType>;
		copiedTreeRoot->info = otherTreeRoot->info;
		copyTree(copiedTreeRoot->lLink, otherTreeRoot->lLink);
		copyTree(copiedTreeRoot->rLink, otherTreeRoot->rLink);
	}
}

template <class elemType>
elemType* nodeBST<elemType>::getMax()
{
	if( root == NULL )
		return NULL;
	max(root);
    return &maximum;
}

template <class elemType>
void nodeBST<elemType>::max(nodeType<elemType>* p)
{
    if(p->rLink == NULL)
        maximum = p->info;
    else
        max(p->rLink);
}

template<class elemType>
int nodeBST<elemType>::size() 
{
	return(size(root)); 
}

template<class elemType>
int nodeBST<elemType>::size(nodeType<elemType>* p) 
{ 
	if (p == NULL) 
	  return(0); 
	else  
		return(size(p->lLink) + 1 + size(p->rLink)); 
} 

template<class elemType>
nodeBST<elemType>::nodeBST()
{
	root = NULL;
}

template<class elemType>
nodeBST<elemType>::~nodeBST()
{
	destroy(root);
}

template<class elemType>
nodeBST<elemType>::nodeBST(const nodeBST<elemType>& otherTree)
{
	if(otherTree.root == NULL)
		root = NULL;
	else
		copyTree(root, otherTree.root);
}

template<class elemType>
void nodeBST<elemType>::insert(const elemType& insertItem)
{
	nodeType<elemType> *current;
	nodeType<elemType> *trailCurrent = NULL;
	nodeType<elemType> *newNode;

	newNode = new nodeType<elemType>;
	newNode->info = insertItem;
	newNode->lLink = NULL;
	newNode->rLink = NULL;

	if(root == NULL)
			root = newNode;
		else
		{
			current = root;
			while(current!= NULL)
			{
				trailCurrent = current;
				if(insertItem == current->info)
					return;
				else
					if(insertItem < current->info)
						current = current->lLink;
				else
					current = current->rLink;
			}

			if(insertItem < trailCurrent->info)
				trailCurrent->lLink = newNode;
			else
				trailCurrent->rLink = newNode;
		}
}


template<class elemType>
bool nodeBST<elemType>::isEmpty() const
{
	return (root == NULL);
}

template<class elemType>
void nodeBST<elemType>::preorderTraversal(flTyp fl) const
{
	preorder(root, fl);
}

template<class elemType>
void nodeBST<elemType>::inorderTraversal(flTyp fl) const
{
	inorder(root, fl);
}

template<class elemType>
void nodeBST<elemType>::postorderTraversal(flTyp fl) const
{
	postorder(root, fl);
}

template<class elemType>
void nodeBST<elemType>::preorder(nodeType<elemType> *p, flTyp fl) const
{
	if(p != NULL)
	{
		(*fl)(p->info);
		preorder(p->lLink, *fl);
		preorder(p->rLink, *fl);
	}
}

template<class elemType>
void nodeBST<elemType>::postorder(nodeType<elemType> *p, flTyp fl) const
{
	if(p != NULL)
	{
		postorder(p->lLink, *fl);
		postorder(p->rLink, *fl);
		(*fl)(p->info);
	}
}

template<class elemType>
void nodeBST<elemType>::inorder(nodeType<elemType> *p, flTyp fl) const
{
	if(p != NULL)
	{
		inorder(p->lLink, *fl);
		(*fl)(p->info);
		inorder(p->rLink, *fl);
	}
}


template<class elemType>
void nodeBST<elemType>::destroy(nodeType<elemType>* &p)
{
	if(p != NULL)
	{
		destroy(p->lLink);
		destroy(p->rLink);
		delete p;
		p = NULL;
	}
}

template<class elemType>
bool nodeBST<elemType>::search(const elemType& searchItem) const
{
	nodeType<elemType> *current;
	bool found = false;
	if(root == NULL)
	{
		return false;
	}
	else
	{
		current = root;
		while(current != NULL && !found)
		{
			if(searchItem == current->info)
				found = true;
			else if(searchItem < current->info)
				current = current->lLink;
			else
				current = current->rLink;
		}
	}

	return found;
}

template<class elemType>
elemType* nodeBST<elemType>::getSearch(const elemType& searchItem) const
{
	nodeType<elemType> *current;
	bool found = false;
	if(root == NULL)
	{
		return NULL;
	}
	else
	{
		current = root;
		while(current != NULL && !found)
		{
			if(searchItem == current->info)
				return &(current->info);
			else if(searchItem < current->info)
				current = current->lLink;
			else
				current = current->rLink;
		}
	}
	return NULL;
}

template<class elemType>
const nodeBST<elemType>& nodeBST<elemType>::operator=(const nodeBST<elemType>& otherTree)
{
	if(this != &otherTree)
	{
		if(root != NULL)
			destroy(root);
		if(otherTree.root == NULL)
			root = NULL;
		else
			copyTree(root, otherTree.root);
	}
	return *this;
}
#endif