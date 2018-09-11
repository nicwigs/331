#ifndef PROJECT_BST_SET_H
#define PROJECT_BST_SET_H
#include "BinarySearchTree.h"
/** DO NOT MODIFY THE LINE BELOW THIS. IT WILL BE USED FOR TESTING. */
#define UNIT_TEST

//#include "Exceptions.h"
#include <vector>
using std::vector;

template<typename T>
class Set {

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
  Set() = default;
  Set(vector<T> values);
  ~Set() = default;
  bool contains(T value) const;
  int size() const;
  void add(T value);
  void remove(T value);
  void clear();
  vector<T> getValues() const;
  bool isDisjoint(const Set<T> &other) const;
  bool isSubset(const Set<T> &other) const;
  bool isSuperset(const Set<T> &other) const;
  Set<T> unionWith(const Set<T> &other) const;
  Set<T> intersection(const Set<T> &other) const;
  Set<T> difference(const Set<T> &other) const;
  Set<T> symmetricDifference(const Set<T> &other) const;
 private:
  BinarySearchTree<T> tree;
};

template<typename T>
Set<T>::Set(vector<T> values) {
	for (T value : values)
		tree.add(value);										//add elements to existing tree
}
template<typename T>
bool Set<T>::contains(T value) const {
	return (tree.search(value) != nullptr);						//contains if search does not return nullptr
}

template<typename T>
int Set<T>::size() const {
	return tree.size();											//call tree size
}

template<typename T>
void Set<T>::add(T value) {
	tree.add(value);											//calls tree add
}

template<typename T>
void Set<T>::remove(T value) {
	tree.remove(value);											//calls tree remove
}

template<typename T>
void Set<T>::clear() {
	BinarySearchTree<T> old = tree;								//delete old
	tree = BinarySearchTree<T>();								//make new empty
}

template<typename T>
vector<T> Set<T>::getValues() const {
	return tree.getValues();									//calls tree getValues
}

template<typename T>
bool Set<T>::isDisjoint(const Set<T> &other) const {
	vector<T> elements = other.tree.getValues();				//grab contents of other set
	for (T element : elements) {
		if (tree.search(element) != nullptr)
			return false;										//false if found
	}
	return true;												//true if none in common
}

template<typename T>
bool Set<T>::isSubset(const Set<T> &other) const {
	vector<T> elements = tree.getValues();						//grab this sets values
	for (T element : elements) {
		if (other.tree.search(element) == nullptr)
			return false;										//false if not found in other set
	}
	return true;												//true if all elements found in other set
}

template<typename T>
bool Set<T>::isSuperset(const Set<T> &other) const {
	return other.isSubset(*this);								//calls isSubset with sets flipped
}

template<typename T>
Set<T> Set<T>::unionWith(const Set<T> &other) const {
	vector<T> set1 = tree.getValues();							
	vector<T> set2 = other.tree.getValues();
	Set<T> new_set = Set<T>(set1);								//create copy of current set
	for (T element : set2)										//add other set
		new_set.tree.add(element);
	return new_set;
}

template<typename T>
Set<T> Set<T>::intersection(const Set<T> &other) const {
	vector<T> elements = tree.getValues();						//get elements
	vector<T> new_elements;	
	for (T element : elements)		
		if (other.tree.search(element) != nullptr)				//store if other set shares element in common
			new_elements.push_back(element);
	Set<T> new_set = Set<T>(new_elements);						//create new set
	return new_set;
}

template<typename T>
Set<T> Set<T>::difference(const Set<T> &other) const {
	vector<T> elements = tree.getValues();						//get elements
	vector<T> new_elements;
	for (T element : elements)
		if (other.tree.search(element) == nullptr)				//store if other set does not share the element in common
			new_elements.push_back(element);
	Set<T> new_set = Set<T>(new_elements);						//create new set
	return new_set;
}

template<typename T>
Set<T> Set<T>::symmetricDifference(const Set<T> &other) const {
	vector<T> elements = tree.getValues();						//get elements of this set
	vector<T> new_elements;
	for (T element : elements)
		if (other.tree.search(element) == nullptr)				//store if other set does not have the element
			new_elements.push_back(element);

	Set<T> new_set = Set<T>(new_elements);						//create new set

	elements = other.tree.getValues();							//get elements of other set
	for (T element : elements)
		if (tree.search(element) == nullptr)					//add to new set if this set does not have the element
			new_set.add(element);		

	return new_set;
}

#endif //PROJECT_BST_SET_H
