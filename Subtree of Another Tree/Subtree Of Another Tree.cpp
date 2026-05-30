#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

bool isInclude(TreeNode* current, TreeNode* subRoot) {
	if (current == nullptr && subRoot != nullptr) {
		return false;
	}

	if (current != nullptr && subRoot == nullptr) {
		return false;
	}

	if (current == nullptr && subRoot == nullptr) {
		return true;
	}

	if (current->val == subRoot->val) {
		return isInclude(current->left, subRoot->left) && isInclude(current->right, subRoot->right);
	}
	return false;
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
	if (root == nullptr) {
		return false;
	}

	if (subRoot == nullptr) {
		return false;
	}

	if (isInclude(root, subRoot)) {
		return true;
	}

	return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

int main() {
	TreeNode rootNode = TreeNode(3);
	rootNode.left = new TreeNode(4);
	rootNode.right = new TreeNode(5);
	rootNode.left->left = new TreeNode(1);
	rootNode.left->right = new TreeNode(2);
	rootNode.left->right->left = new TreeNode(0);

	TreeNode subNode = TreeNode(4);
	subNode.left = new TreeNode(1);
	subNode.right = new TreeNode(2);

	cout << isSubtree(&rootNode, &subNode);
}