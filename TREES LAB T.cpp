#include<iostream>
using namespace std;

struct TreeNode {

	int value;

	TreeNode* left;

	TreeNode* right;

	//TreeNode() {}

	//TreeNode(int val) : val(val) {}

};

class BST {

public:
	BST();
	~BST();

	void swapSubTrees(TreeNode *root, int key);

	void Insert(int key);

	TreeNode* Search(int key);

	void destroy_tree();

	void printInorder();

	void printPostorder();

	void printPreorder();

	void display(int x, int y, TreeNode* root);

	void display(int x, int y);

	TreeNode* root;

	



private:

	void destroy_tree(TreeNode* node);

	void Insert(int key, TreeNode* node);

	TreeNode* Search(int key, TreeNode* node);

	void printInorder(TreeNode* node);

	void printPostorder(TreeNode* node);

	void printPreorder(TreeNode* node);





};


int main() {

	int n;

	int* arr;

	BST* tree = new BST();

	tree->Insert(6);

	tree->Insert(4);

	tree->Insert(8);

	tree->Insert(3);

	tree->Insert(5);
	tree->display(13, 0);
	tree->printInorder();

	tree->printPreorder();

	tree->printPostorder();
	tree->swapSubTrees(tree->root, 6);
	//cout << "\n\n\n\n\n\n\n\n";
	tree->display(13, 0);

	tree->printInorder();

	tree->printPreorder();

	tree->printPostorder();
	cout << endl << endl;
	tree->swapSubTrees(tree->root, 6);
	tree->printInorder();

	tree->printPreorder();

	tree->printPostorder();
	tree->display(13, 0);
	delete tree;

	system("PAUSE");
}


BST::BST() {
	root = NULL;

}

BST::~BST() {

	destroy_tree();

}

void BST::destroy_tree(TreeNode* node) {

	if (node != NULL) {

		destroy_tree(node->left);

		destroy_tree(node->right);

		delete node;

	}

}


void BST::swapSubTrees(TreeNode*root, int key) {
	//find node with data==val
	//swap left and right for all its subtrees
	if (root->left == NULL && root->right == NULL)
		return;
	TreeNode*temp = root->right;

	if (root->value == key) {
		root->right = root->left;
		root->left = temp;

		if (root->left != NULL) {
			key = root->left->value;
			swapSubTrees(root->left, key);
		}
		if (root->right != NULL) {
			key = root->right->value;
			swapSubTrees(root->right, key);
		}
		return;
	}
	else if (root->value > key) {
		root = root->left;
		swapSubTrees(root, key);
	}
	else {
		root = root->right;
		swapSubTrees(root, key);
	}
}



void BST::Insert(int key) {

	if (root != NULL) {

		Insert(key, root);

	}

	else {

		root = new TreeNode;

		root->value = key;

		root->left = NULL;

		root->right = NULL;

	}

}

void BST::Insert(int key, TreeNode* node) {

	if (key < node->value) {

		if (node->left != NULL) {

			Insert(key, node->left);

		}

		else {

			node->left = new TreeNode;

			node->left->value = key;

			node->left->left = NULL;

			node->left->right = NULL;

		}

	}

	else if (key >= node->value) {

		if (node->right != NULL) {

			Insert(key, node->right);

		}

		else {


			node->right = new TreeNode;

			node->right->value = key;

			node->right->right = NULL;

			node->right->left = NULL;

		}

	}

}


TreeNode* BST::Search(int key, TreeNode* node) {

	if (node != NULL) {

		if (key == node->value) {

			return node;

		}

		if (key < node->value) {

			return Search(key, node->left);

		}

		else {

			return Search(key, node->right);

		}

	}

	else {

		return NULL;

	}

}

TreeNode* BST::Search(int key) {

	return Search(key, root);

}

void BST::destroy_tree() {

	destroy_tree(root);
}

void BST::printInorder() {

	cout << "Print Inorder : ";

	printInorder(root);

	cout << endl;

}

void BST::printInorder(TreeNode* node) {

	if (node != NULL) {

		printInorder(node->left);

		cout << node->value << ",";

		printInorder(node->right);

	}

}


void BST::printPreorder() {

	cout << "Preorder : ";

	printPreorder(root);

	cout << endl;
}


void BST::printPreorder(TreeNode* node) {

	if (node != NULL) {

		cout << node->value << ",";

		printPreorder(node->left);

		printPreorder(node->right);


	}


}


void BST::printPostorder() {

	cout << "Print Postorder : ";

	printPostorder(root);

	cout << endl;

}

void BST::printPostorder(TreeNode* node) {

	if (node != NULL) {

		printPostorder(node->left);

		printPostorder(node->right);

		cout << node->value << ",";

	}

}

int x = 13;
int y = 0;
int treeArray[10][27] = { 0 };
void BST::display(int x, int y) {
	treeArray[10][27] = { 0 };
	if (root != NULL)
		treeArray[y][x] = root->value;
	display((x - 1) / 2, y + 1, root->left);
	display((x - 1) / 2 + (x + 1), y + 1, root->right);


	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 27; j++) {
			if (treeArray[i][j] == 0) {
				cout << ' ';
			}
			else {
				cout << treeArray[i][j];
			}

		}
		cout << endl;
	}
}

void BST::display(int x, int y, TreeNode* root) {

	if (root != NULL) {
		treeArray[y][x] = root->value;
		display((x - 1) / 2, y + 1, root->left);
		display((x - 1) / 2 + (x + 1), y + 1, root->right);
	}


}