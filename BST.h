//BST.h file
//Description: This program implements a binary tree using an array
//Author: Aaryan Gupta
//Creation Date: June 10, 2021


#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include<iostream>
#include<cmath>
#include<climits>

using namespace std;

class BST{

public:

	//constructor
	BST(){
		size = 0;
	}

	//overloaded constructor
	BST(int s, int h){
		size = s;
		height = h;
		array = new int[size];
	}

	//destructor
	~BST();

	void insertTree(int data[], int n);
	void sortTree(int data[], int n);




	int *array;
	int size;
	int height;

};

//destructor
BST::~BST(){
	delete[] array;
}


//populates the remaining nodes with the min value of the two children.
void BST::sortTree(int data[], int n){

	int l = 0;


	while(l < n){


		int i = pow(2, height-1) -2;

		while(i >= 0){

			int left = (2 * i) + 1;
			int right = (2 * i) + 2;

			if(array[left] < array[right]){
				array[i] = array[left];
			}
			else{
				array[i] = array[right];
			}
			i--;
		}

		data[l] = array[0];
		

		for(int a = 0; a < size; a++){
			if(array[a] == data[l]){
				array[a] = INT_MAX;
			}
		}
		l++;

	}




}



//inserts the values from data array into leaf nodes of the binary tree.
void BST::insertTree(int data[], int n){

	//keeps track of the indeces of the data array
	int j = 0;

	int i = pow(2, height-1);
	i = i - 1;

	while(j < n){
		array[i] = data[j];
		i++;
		j++;
		
	}

	while(i < size){
		array[i] = INT_MAX;
		i++;
	}
}

#endif
