/*

Given a binary tree, return the sum of values of nodes with even-valued grandparent.
(A grandparent of a node is the parent of its parent, if it exists.)
If there are no nodes with an even valued grandparent, return 0.

input: root = [6, 7, 8, 2, 7, 1, 3, 9, null, 1, 4, null, null, null, 5]

output: 18

*/
#include<iostream>
using namespace std;

long int sumOfRange = 0;

struct Node {
	struct Node* left;
	long int data;
	struct Node* right;
	
	Node(long int value) {
		data = value;
		left = NULL;
		right = NULL;
	}
};

Node* insertLevelOrder(long int arr[], struct Node* root, long int i, long int n) {
	if (i < n) {
		Node* temp = new Node(arr[i]);
		root = temp;
		root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);
		root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
	}
	return root;
}

void treeTraverse(struct Node* root) {
	if ((root->data % 2) == 0) {
		if (root->left != NULL) {
			if (root->left->left != NULL) {
				sumOfRange += root->left->left->data;
			}
			if (root->left->right != NULL) {
				sumOfRange += root->left->right->data;
			}
		}
		if (root->right != NULL) {
			if (root->right->left != NULL) {
				sumOfRange += root->right->left->data;
			}
			if (root->right->right != NULL) {
				sumOfRange += root->right->right->data;
			}
		}
	}
	if (root->left != NULL) {
		treeTraverse(root->left);
	}
	if (root->right != NULL) {
		treeTraverse(root->right);
	}
}

int main() {
	long int num;
	cin>>num;
	long int arr[num];

	for(long int i = 0; i < num; i++ ) {
		cin>>arr[i];
	}
	
	struct Node* root = insertLevelOrder(arr, root, 0 ,num);
	treeTraverse(root);
	cout<<sumOfRange<<endl;
	return 0;
}

