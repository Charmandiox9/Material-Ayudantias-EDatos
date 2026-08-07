#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    ~TreeNode() {
        delete left;
        delete right;
    }
};


TreeNode* generateBinaryTree(std::vector<int> inorder, std::vector<int> postorder) {
    if (inorder.empty()) return nullptr;

    int rootVal = postorder.back();
    TreeNode* root = new TreeNode(rootVal);

    int mid = 0;
    for (int i = 0; i < inorder.size(); ++i) {
        if (inorder[i] == rootVal) {
            mid = i;
            break;
        }
    }

    vector<int> leftInorder(inorder.begin(), inorder.begin() + mid);
    vector<int> rightInorder(inorder.begin() + mid + 1, inorder.end());

    vector<int> leftPostorder(postorder.begin(), postorder.begin() + mid);
    vector<int> rightPostorder(postorder.begin() + mid, postorder.end() - 1);

    root->left = generateBinaryTree(leftInorder, leftPostorder);
    root->right = generateBinaryTree(rightInorder, rightPostorder);

    return root;
}


void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

void printPreorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printPostorder(TreeNode* root) {
    if (!root) return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->val << " ";
}

int main() {
    vector<int> inorder   = {4, 2, 5, 1, 6, 3, 7};
    vector<int> postorder = {4, 5, 2, 6, 7, 3, 1};

    TreeNode* root = generateBinaryTree(inorder, postorder);

    cout << "Preorder:  ";
    printPreorder(root);
    cout << endl;

    cout << "Inorder:   ";
    printInorder(root);
    cout << endl;

    cout << "Postorder: ";
    printPostorder(root);
    cout << endl;

    delete root;

    return 0;
}