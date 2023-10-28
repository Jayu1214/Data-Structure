#include <iostream>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to insert a new node into the binary tree.
TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }

    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

// Inorder traversal using a stack (non-recursive)
void inorderTraversal(TreeNode* root) {
    stack<TreeNode*> s;
    TreeNode* current = root;

    while (current || !s.empty()) {
        while (current) {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();

        cout << current->val << " ";

        current = current->right;
    }
}

// Preorder traversal using a stack (non-recursive)
void preorderTraversal(TreeNode* root) {
    stack<TreeNode*> s;
    if (root) s.push(root);

    while (!s.empty()) {
        TreeNode* current = s.top();
        s.pop();

        cout << current->val << " ";

        if (current->right) s.push(current->right);
        if (current->left) s.push(current->left);
    }
}

// Postorder traversal using two stacks (non-recursive)
void postorderTraversal(TreeNode* root) {
    stack<TreeNode*> s1, s2;
    if (root) s1.push(root);

    while (!s1.empty()) {
        TreeNode* current = s1.top();
        s1.pop();
        s2.push(current);

        if (current->left) s1.push(current->left);
        if (current->right) s1.push(current->right);
    }

    while (!s2.empty()) {
        cout << s2.top()->val << " ";
        s2.pop();
    }
}

int main() {
    TreeNode* root = nullptr;
    int n, val;

    cout << "Enter the number of elements in the tree: ";
    cin >> n;

    cout << "Enter the elements one by one:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        root = insert(root, val);
    }

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << "\n";

    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << "\n";

    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << "\n";

    return 0;
}
