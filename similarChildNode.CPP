/*

Consider all the leaves of a binary tree, from left to right order, the values
of those leaves from a leaf value sequence.
for example, in the given tree above, the leaf value sequence is (6,7,4,9,8).
Two binary trees are considered leaf-similar if their leaf value sequence is
the same. return true if and only if the two given trees with head nodes root1
and root2 are leaf-similar.

input: size of root1 = 11, size of root2 = 15
root1 = [3, 5, 1, 6, 2, 9, 8, null, null, 7, 4],
root2 = [3, 5, 1, 6, 7, 4, 2, null, null, null, null, null, null, 9, 8]


output: true

NOTE: Use 0 instead of null in input.
*/

#include<bits/stdc++.h>
#define li long int
using namespace std;

li pivot = 0;
li checkPivot = 0;

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

void treeTraverse(struct Node*, li*);
void checkTree(struct Node*, li*);

int main() {
	li M, N;
	cin>>M>>N;
	li* root1 = (li*) malloc(M * sizeof(li));
	li* root2 = (li*) malloc(N * sizeof(li));
	li size = (M>N) ? M : N;
	li* childNode = (li*) malloc(size * sizeof(li));

	for(li i = 0; i < M; ++i ) {
		cin>>root1[i];
	}
	
	for(li i = 0; i < N; ++i ) {
		cin>>root2[i];
	}
	
	struct Node* tree1 = insertLevelOrder(root1, tree1, 0 ,M);
	struct Node* tree2 = insertLevelOrder(root2, tree2, 0 ,N);
	treeTraverse(tree1, childNode);
	checkTree(tree2, childNode);
	return 0;
}

void treeTraverse(struct Node* root, li* childNode) {
	
	if (root->left != NULL) {
		treeTraverse(root->left, childNode);
	}
	if (root->left == NULL && root->right == NULL || root->left->data == 0 && root->right->data == 0 || root->left->data == 0 && root->right == NULL || root->left == NULL && root->right->data == 0) {
		if (root->data != 0) {
			childNode[pivot] = root->data;
			++pivot;
			return;
		} else {
			return;
		}
	}
	if (root->right != NULL) {
		treeTraverse(root->right, childNode);
	}
}

void checkTree(struct Node* root, li* childNode) {
	if (root->left != NULL) {
		checkTree(root->left, childNode);
	}
	if (root->left == NULL && root->right == NULL || root->left->data == 0 && root->right->data == 0 || root->left->data == 0 && root->right == NULL || root->left == NULL && root->right->data == 0) {
		if (pivot != -1) {
			if (root->data != 0) {
				if (root->data == childNode[checkPivot]) {
					++checkPivot;
					if (checkPivot == pivot) {
						cout<<"true"<<endl;
						return;
					} else {
						return;
					}
				} else {
					cout<<"false"<<endl;
					pivot = -1;
				}
			}
		}
	}
	if (root->right != NULL) {
		checkTree(root->right, childNode);
	}
}