#ifndef PROJECT_BST_BINARYSEARCHTREE_H
#define PROJECT_BST_BINARYSEARCHTREE_H
/** DO NOT MODIFY THE LINE BELOW THIS. IT WILL BE USED FOR TESTING. */
#define UNIT_TEST

//#include "Exceptions.h"
#include <vector>
using std::vector;

template<typename T>
struct Node {
  T value;
  Node *left;
  Node *right;
  Node(T val) : value(val), left(nullptr), right(nullptr) {};
};

template<typename T>
class BinarySearchTree {

    /** any friends for testing
     */
	/*
#if defined(UNIT_TEST)
    FRIEND_TEST(BSTProjectTests, TestBSTAdd);
    FRIEND_TEST(BSTProjectTests, TestBSTSearch);
    FRIEND_TEST(BSTProjectTests, TestBSTRemove);
    FRIEND_TEST(BSTProjectTests, TestBSTInstance);
    FRIEND_TEST(BSTProjectTests, TestSetInstance);
    FRIEND_TEST(BSTProjectTests, TestSetAdd);
    FRIEND_TEST(BSTProjectTests, TestSetRemove);
    FRIEND_TEST(BSTProjectTests, TestSetContains);
    FRIEND_TEST(BSTProjectTests, TestBSTInorderTraversal);
    FRIEND_TEST(BSTProjectTests, TestSetClear);
#endif
*/
 public:
	  BinarySearchTree();												
	  BinarySearchTree(vector<T> values);
	  ~BinarySearchTree();
	  void add(T val);
	  const T *search(T val) const;
	  void remove(T val);
	  vector<T> getValues() const;
	  int size() const;

 private:
	  Node<T> *root = nullptr;
	  void add(Node<T> *&root_node, Node<T> *&new_node);
	  Node<T> *remove(Node<T> *&root_node, T val);
	  void inOrderTraversal(Node<T> *node, vector<T> &values) const;
	  int size(Node<T> *node) const;
	  void destroy(Node<T> *&node);
	  const Node<T> *search(Node<T> *root_node, T val) const;
};

template<typename T>
BinarySearchTree<T>::BinarySearchTree() {}						//No arg constructor 

template<typename T>
BinarySearchTree<T>::BinarySearchTree(vector<T> values) {		//constructor
	for (T element : values)
		add(element);											//add element to the tree
}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree() {
	destroy(root);												//call recursive destroy
}

template<typename T>
void BinarySearchTree<T>::add(T val) {
	Node<T> * new_node = new Node<T>(val);						//create pointer to new node
	add(root, new_node);										//call the add method
}

template<typename T>
void BinarySearchTree<T>::add(Node<T> *&root_node, Node<T> *&new_node) {
	if (root_node == nullptr)									//sets child to new node once reaches nullptr
		root_node = new_node;
	else if (new_node->value < root_node->value)				//go left
		add(root_node->left, new_node);
	else if (new_node->value > root_node->value)				//go right
		add(root_node->right, new_node);						
	else
		delete new_node;										//if element is already in the tree, delete the new node made
}

template<typename T>
const T *BinarySearchTree<T>::search(T val) const {
	const Node<T>* found_node = search(root, val);				//call recursive search
	return (found_node == nullptr) ? nullptr : &(found_node->value);
}
template<typename T>
const Node<T> *BinarySearchTree<T>::search(Node<T> *root_node, T val) const {
	if (root_node == nullptr)
		return nullptr;											//not there, return nullptr
	else if (root_node->value == val)
		return root_node;										//found it!
	return (val > root_node->value) ?							//bigger, search right, smaller, left
		search(root_node->right, val) : search(root_node->left, val);
}

template<typename T>
void BinarySearchTree<T>::remove(T val) {
	remove(root, val);											//call recursive remove
}

template<typename T>
vector<T> BinarySearchTree<T>::getValues() const {
	vector<T> values;											//initiated 
	inOrderTraversal(root, values);								//call recursive traversal
	return values;												//return vec
}
template<typename T>
void BinarySearchTree<T>::inOrderTraversal(Node<T> *node, vector<T> &values) const {
	if (node == nullptr) return;								//nothing there
	inOrderTraversal(node->left, values);						//left
	values.push_back(node->value);								//add value to vector
	inOrderTraversal(node->right, values);						//right
}

template<typename T>
int BinarySearchTree<T>::size() const {
	return size(this->root);									//call size
}
template<typename T>
int BinarySearchTree<T>::size(Node<T> *node) const {			//1 + left size + right size
	return node == nullptr ? 0 : 1 + this->size(node->left) + this->size(node->right);
}

template<typename T>
Node<T> *BinarySearchTree<T>::remove(Node<T> *&root_node, T val) {
	if (root_node == nullptr) return nullptr;									//null!
	else if (root_node->value == val) {											//found desired val
		if (root_node->left == nullptr && root_node->right == nullptr) {		//leaf node
			Node<T>* current_node = &(*root_node);								//another pointer to node, cant delete root_node*
			root_node = nullptr;												//point to nullptr
			delete current_node;												//delete the node that was there
		}
		else if (root_node->left != nullptr && root_node->right != nullptr) {	//full node
			Node<T>* find_min = root_node->right;
			while (find_min->left != nullptr)
				find_min = find_min->left;
			root_node->value = find_min->value;									//find replacement
			remove(root_node->right, root_node->value);							//remove previous
		}
		else {
			Node<T>* current_node = &(*root_node);								//another pointer to current node
			root_node = (root_node->left != nullptr) ? root_node->left : root_node->right; //pass around node
			delete current_node;												//removes node
		}
		return root_node;
	}
	else {																		//havent found val yet
		return (val > root_node->value) ? remove(root_node->right, val) : remove(root_node->left, val);  //bigger->right, smaller->left
	}
}

template<typename T>
void BinarySearchTree<T>::destroy(Node<T> *&node) {
	if (node != nullptr) {
		destroy(node->left);									//left
		destroy(node->right);									//right
		delete node;											//own self 
	}	
}

#endif //PROJECT_BST_BINARYSEARCHTREE_H
