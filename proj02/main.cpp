#include <cstdio>

#include <iostream>
using std::cout; using std::endl;

#include "BinarySearchTree.h"
#include "Set.h"

#include <vector>
using std::vector;
#include <algorithm>
void print_vec(vector<int> values) {
	for (int val : values)
		cout << val << " ";
	cout << endl;

}
void test_add() {
	vector<int> in = { 5,3,7,2,8,9,1 };
	BinarySearchTree<int> t = BinarySearchTree<int>(in);
	t.add(10);
	t.add(0);
	vector<int> out = t.getValues();
	vector<int> correct = { 0, 1, 2, 3, 5, 7, 8, 9, 10 };
	if (out == correct)
		cout << "Good (adding)" << endl;
	else
		cout << "Failed (adding)" <<endl;
}

void test_trans() {
	vector<int> in = { 5,3,7,2,8,9,1 };
	BinarySearchTree<int> t = BinarySearchTree<int>(in);
	vector<int> out = t.getValues();
	vector<int> correct = { 1,2,3,5,7,8,9 };
	if (out == correct)
		cout << "Good (trans)" << endl;
	else
		cout << "Failed (trans)" << endl;


	vector<int> in2 = { 1,2,3,4,5,6,7,8,9,29 };
	BinarySearchTree<int> t2 = BinarySearchTree<int>(in2);
	vector<int> out2 = t2.getValues();
	

	if (out2 == in2)
		cout << "Good (trans)" << endl;
	else {
		cout << "Failed (trans)" << endl;
		print_vec(out2);
		print_vec(in2);
	}

	cout << ".......testing In order traversal........." << endl;
	vector<int> v = { 54,64,12,4,16,16,100,2,7,32,86,19 };
	BinarySearchTree<int> t3 = BinarySearchTree<int>(v);
	std::sort(v.begin(), v.end());
	vector<int> i = t3.getValues();
	for (int val : i)
		cout << val << " ";
	cout << endl;
	for (int val : v)
		cout << val << " ";
	cout << endl;

}
void test_search() {
	vector<int> in = { 6,2,18,43,72,4,23,46,12,14,1,98,76};
	BinarySearchTree<int> t = BinarySearchTree<int>(in);
	const int * ptr = t.search(98);
	if (*ptr == 98)
		cout << "Good (search)" << endl;
	else {
		cout << "Failed (seach)" << endl;
	}
	ptr = t.search(100);
	if (ptr == nullptr)
		cout << "Good (search)" << endl;
	else {
		cout << "Failed (seach)" << endl;
	}
}
void test_remove() {
	vector<int> in = { 5,3,7,0,4,6,100 };
	BinarySearchTree<int> t = BinarySearchTree<int>(in);
	t.remove(0);
	vector<int> out = t.getValues();
	vector<int> t1 = { 3,4,5,6,7,100 };
	if (out == t1)
		cout << "Good (remove leaf)" << endl;
	else {
		cout << "Failed (remove leaf)" << endl;
	}
	t.remove(3);
	vector<int> t2 = { 4,5,6,7,100 };
	out = t.getValues();
	if (out == t2)
		cout << "Good (remove 1 child)" << endl;
	else {
		cout << "Failed (remove 1 child)" << endl;
	}
	t.remove(7);
	vector<int> t3 = { 4,5,6,100};
	out = t.getValues();
	if (out == t3)
		cout << "Good (remove 2 child)" << endl;
	else {
		cout << "Failed (remove 2 child)" << endl;
	}



}
void test_remove_big() {
	vector<int> in = { 100,40,200,10,50,150,270,9,12,45,70,120,170,220,280 };
	BinarySearchTree<int> t = BinarySearchTree<int>(in);
	t.remove(9);
	vector<int> out = t.getValues();
	vector<int> t1 = {10,12,40,45,50,70,100,120,150,170,200,220,270,280};
	if (out == t1)
		cout << "Good (remove leaf)" << endl;
	else {
		cout << "Failed (remove leaf)" << endl;
	}
	t.remove(10);
	vector<int> t2 = { 12,40,45,50,70,100,120,150,170,200,220,270,280 };
	out = t.getValues();
	if (out == t2)
		cout << "Good (remove 1 child)" << endl;
	else {
		cout << "Failed (remove 1 child)" << endl;
	}
	t.remove(200);
	vector<int> t3 = { 12,40,45,50,70,100,120,150,170,220,270,280 };
	out = t.getValues();
	if (out == t3)
		cout << "Good (remove 2 child)" << endl;
	else {
		cout << "Failed (remove 2 child)" << endl;
	}
	t.remove(500);
	out = t.getValues();
	if (out == t3)
		cout << "Good (remove false val)" << endl;
	else {
		cout << "Failed (remove false val)" << endl;
	}

	BinarySearchTree<int> f = BinarySearchTree<int>();
	f.remove(10);
	vector<int> t4 = {};

	out = f.getValues();
	if (out == t4)
		cout << "Good (remove empty)" << endl;
	else {
		cout << "Failed (remove empty)" << endl;
	}
}
void test_size() {
	vector<int> in = { 100,40,200,10,50,150,270,9,12,45,70,120,170,220,280 };
	BinarySearchTree<int> t = BinarySearchTree<int>(in);
	int sz = t.size();
	if (sz == 15)
		cout << "Good (size)" << endl;
	else {
		cout << "Failed (size)" << endl;
	}
	BinarySearchTree<int> f = BinarySearchTree<int>();
	sz = f.size();
	if (sz == 0)
		cout << "Good (size empty)" << endl;
	else {
		cout << "Failed (size empty)" << endl;
	}
}
void test_contains() {
	vector<int> in = { 5,3,7,0,4,6,100 };
	Set<int> s1 = Set<int>(in);
	if (s1.contains(100))
		cout << "Good (contains)" << endl;
	else {
		cout << "Failed (conatains)" << endl;
	}
	if (!s1.contains(21))
		cout << "Good (contains)" << endl;
	else {
		cout << "Failed (conatains)" << endl;
	}
}
void test_set_size() {
	vector<int> in = { 100,40,200,10,50,150,270,9,12,45,70,120,170,220,280 };
	Set<int> t = Set<int>(in);
	int sz = t.size();
	if (sz == 15)
		cout << "Good (size set)" << endl;
	else {
		cout << "Failed (size set)" << endl;
	}
	Set<int> f = Set<int>();
	sz = f.size();
	if (sz == 0)
		cout << "Good (size empty set)" << endl;
	else {
		cout << "Failed (size empty set)" << endl;
	}
}
void test_set_add() {
	vector<int> in = { 5,3,7,2,8,9,1 };
	Set<int> t = Set<int>(in);
	t.add(10);
	t.add(0);
	vector<int> out = t.getValues();
	vector<int> correct = { 0, 1, 2, 3, 5, 7, 8, 9, 10 };
	if (out == correct)
		cout << "Good (adding set)" << endl;
	else
		cout << "Failed (adding set)" << endl;
	t.add(10);
	out = t.getValues();
	if (out == correct)
		cout << "Good (adding set already in)" << endl;
	else
		cout << "Failed (adding set already in)" << endl;
}
void test_set_remove_big() {
	vector<int> in = { 100,40,200,10,50,150,270,9,12,45,70,120,170,220,280 };
	Set<int> t = Set<int>(in);
	t.remove(9);
	vector<int> out = t.getValues();
	vector<int> t1 = { 10,12,40,45,50,70,100,120,150,170,200,220,270,280 };
	if (out == t1)
		cout << "Good (remove set leaf)" << endl;
	else {
		cout << "Failed (remove set leaf)" << endl;
	}
	t.remove(10);
	vector<int> t2 = { 12,40,45,50,70,100,120,150,170,200,220,270,280 };
	out = t.getValues();
	if (out == t2)
		cout << "Good (remove set 1 child)" << endl;
	else {
		cout << "Failed (remove set 1 child)" << endl;
	}
	t.remove(200);
	vector<int> t3 = { 12,40,45,50,70,100,120,150,170,220,270,280 };
	out = t.getValues();
	if (out == t3)
		cout << "Good (remove set 2 child)" << endl;
	else {
		cout << "Failed (remove set 2 child)" << endl;
	}
	t.remove(500);
	out = t.getValues();
	if (out == t3)
		cout << "Good (remove set false val)" << endl;
	else {
		cout << "Failed (remove set false val)" << endl;
	}

	Set<int> f = Set<int>();
	f.remove(10);
	vector<int> t4 = {};

	out = f.getValues();
	if (out == t4)
		cout << "Good (remove set empty)" << endl;
	else {
		cout << "Failed (remove set empty)" << endl;
	}
}
void test_set_clear() {
	vector<int> in = { 100,40,200,10,50,150,270,9,12,45,70,120,170,220,280 };
	Set<int> t = Set<int>(in);
	vector<int> t4 = {};
	t.clear();
	vector<int>out = t.getValues();
	if (out == t4)
		cout << "Good (set clear)" << endl;
	else {
		cout << "Failed (set clear)" << endl;
	}
}
void test_set_disjoint() {
	vector<int> in = { 100,40,200,10,50,150,270,9,12,45,70,120,170,220,280 };
	Set<int> s1 = Set<int>(in);
	vector<int> in2 = { 5,22,893 };
	Set<int> s2 = Set<int>(in2);
	vector<int> in3 = { 100,23,11 };
	Set<int> s3 = Set<int>(in3);
	if (s1.isDisjoint(s2))
		cout << "Good (set disjoint)" << endl;
	else {
		cout << "Failed (set disjoint)" << endl;
	}
	if (!s1.isDisjoint(s3))
		cout << "Good (set disjoint)" << endl;
	else {
		cout << "Failed (set disjoint)" << endl;
	}
}
void test_set_subset() {
	vector<int> in = { 100,40,200,10,50,150,270,9,12,45,70,120,170,220,280 };
	Set<int> s1 = Set<int>(in);
	vector<int> in2 = { 120,170,220};
	Set<int> s2 = Set<int>(in2);
	vector<int> in3 = { 100,23,11 };
	Set<int> s3 = Set<int>(in3);
	if (s2.isSubset(s1))
		cout << "Good (set subset)" << endl;
	else {
		cout << "Failed (set subset)" << endl;
	}
	if (!s3.isSubset(s1))
		cout << "Good (set sibset)" << endl;
	else {
		cout << "Failed (set subset)" << endl;
	}
}
void test_set_superset() {
	vector<int> in = { 100,40,200,10,50,150,270,9,12,45,70,120,170,220,280 };
	Set<int> s1 = Set<int>(in);
	vector<int> in2 = { 120,170,220 };
	Set<int> s2 = Set<int>(in2);
	vector<int> in3 = { 100,23,11 };
	Set<int> s3 = Set<int>(in3);
	if (s1.isSuperset(s2))
		cout << "Good (set super)" << endl;
	else {
		cout << "Failed (set super)" << endl;
	}
	if (!s1.isSuperset(s3))
		cout << "Good (set super)" << endl;
	else {
		cout << "Failed (set super)" << endl;
	}
}
void test_set_unionwith() {
	vector<int> in = { 4,2,6,1,7 };
	Set<int> s1 = Set<int>(in);
	vector<int> in2 = { 4,2,3,9};
	Set<int> s2 = Set<int>(in2);
	Set<int> s3 = s1.unionWith(s2);

	vector<int> t1 = { 1,2,3,4,6,7,9 };
	vector<int> out = s3.getValues();

	if (t1 == out)
		cout << "Good (set unionwith)" << endl;
	else {
		cout << "Failed (set unionwith)" << endl;
	}

}
void test_set_intersection() {
	vector<int> in = { 4,2,6,1,7,8,21 };
	Set<int> s1 = Set<int>(in);
	vector<int> in2 = { 4,2,3,9 };
	Set<int> s2 = Set<int>(in2);
	Set<int> s3 = s1.intersection(s2);

	vector<int> t1 = { 2,4 };
	vector<int> out = s3.getValues();

	if (t1 == out)
		cout << "Good (set intersection)" << endl;
	else {
		cout << "Failed (set intersection)" << endl;
	}


	vector<int> in3 = {};
	Set<int> s4 = Set<int>(in3);
	Set<int> s5 = s1.intersection(s4);

	vector<int> out2 = s5.getValues();
	if (in3 == out2)
		cout << "Good (set intersection empty)" << endl;
	else {
		cout << "Failed (set intersection empty)" << endl;
	}

}
void test_set_difference() {
	vector<int> in = { 4,2,6,1,7,8,21 };
	Set<int> s1 = Set<int>(in);
	vector<int> in2 = { 4,2,3,9 };
	Set<int> s2 = Set<int>(in2);
	Set<int> s3 = s1.difference(s2);

	vector<int> t1 = { 1,6,7,8,21 };
	vector<int> out = s3.getValues();

	if (t1 == out)
		cout << "Good (set differnce)" << endl;
	else {
		cout << "Failed (set differnce)" << endl;
	}

}
void test_set_sym() {
	vector<int> in = { 4,2,6,1,7,8,21 };
	Set<int> s1 = Set<int>(in);
	vector<int> in2 = { 4,2,3,9 };
	Set<int> s2 = Set<int>(in2);
	Set<int> s3 = s1.symmetricDifference(s2);

	vector<int> t1 = { 1,3,6,7,8,9,21 };
	vector<int> out = s3.getValues();

	if (t1 == out)
		cout << "Good (set sym)" << endl;
	else {
		cout << "Failed (set sym)" << endl;
	}

}
int main()
{
	vector<int> single = { 1 };
	//BinarySearchTree<int> t = BinarySearchTree<int>(single);

	//vector<int> intVecSample4{ 3,5,57,4,1,2,40, 70 };
	//BinarySearchTree<int> vecTree4(intVecSample4);
	//vecTree4.remove(5);
	//BinarySearchTree<int> t = BinarySearchTree<int>(single); 

	//Set<int> vecSet = Set<int>(single);


	

	///
	vector<int> setvec1 = { 4,5,3,2,6,7 };
	vector<int> setvec2 = {};

	Set<int> s1 = Set<int>(setvec1);
	Set<int> s2 = Set<int>(setvec2);
	

	
	Set<int> s3 = s1.unionWith(s2);
	vector<int> un = s3.getValues();
	for (int val : un)
		cout << val << " ";
	cout << endl;


	s1.remove(4);
	vector<int> s1_results = s1.getValues();
	for (int val : s1_results)
		cout << val << " ";
	cout << endl;

	s1.clear();

	test_add();
	test_trans();
	test_search();
	test_remove();
	test_remove_big();
	test_size();

	test_contains();
	test_set_size();
	test_set_add();
	test_set_remove_big();
	test_set_clear();
	test_set_disjoint();
	test_set_subset();
	test_set_superset();
	test_set_unionwith();
	test_set_intersection();
	test_set_difference();
	test_set_sym();


 	return 0;
}
