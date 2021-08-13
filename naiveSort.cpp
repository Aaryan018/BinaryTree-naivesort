//naiveSort.cpp file
//Description: This program sorts an array using a binary tree
//Author: Aaryan Gupta
//Creation Date: June 10, 2021

#include "BST.h"
#include<iostream>
#include<cmath>
//#include<array>


//this function sorts the array using a Binary Tree.
void naiveSort(int data[], int n){

	
	int height = ceil(log2(n)) + 1;
	int size = pow(2, height) - 1;

	//find the size and height of the tree required and send into the constructor
	BST tree(size, height);

	//inserting the values into the leaf nodes of the tree.
	tree.insertTree(data, n);

	//sorting the tree.
	tree.sortTree(data, n);

}


//creating the array and calling other functions.
int main(){

	int data[5] = {8, 20, 0, 7, 2};


	//I found this method of finding size of array from the website www.educative.io
	int n = sizeof(data)/sizeof(data[0]);

	naiveSort(data, n);

	//printing the output
	for(int i = 0; i < n; i++){
		cout << data[i] << endl;
	}

}