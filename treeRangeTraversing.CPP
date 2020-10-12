/*

Given the root node of a binary search tree, return the sum
of values of all nodes with value between L and R(inclusive).
The binary search tree is guaranteed to have unique values.

input: root = [10, 5, 15, 3, 7, null, 18], L = 7, R = 15

output: 32

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

void traverseTree(struct Node* temp, long int L, long int R) {
	if (temp->left != NULL) {
		traverseTree(temp->left, L, R);
	}
	if (temp->right != NULL) {
		traverseTree(temp->right, L, R);
	}
	if (temp->data >= L && temp->data <= R) {
		sumOfRange = sumOfRange + temp->data;
	}
}

int main() {
	long int num, L, R;
	cin>>num>>L>>R;

	struct Node* root = NULL;
	struct Node* temp;

	for(long int i = 0; i < num; i++ ) {
		
		long int value;
		cin>>value;
		if (value != 0 ) {
			if (root == NULL) {
				root = new Node(value);
			}
			temp = root;
			while(temp->data != value) {
				if (temp->data >= value) {
					if (temp->left == NULL) {
						temp->left = new Node(value);
					}
					temp = temp->left;
				} else if (temp->data < value) {
					if (temp->right == NULL) {
						temp->right = new Node(value);
					}
					temp = temp->right;
				}
			}
		}
		
		
	}
	traverseTree(root, L, R);
	cout<<sumOfRange<<endl;

	return 0;
}

