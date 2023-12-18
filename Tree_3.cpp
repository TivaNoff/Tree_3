#include <iostream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    invertTree(root->left);
    invertTree(root->right);

    return root;
}

void printLevelOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        std::cout << current->val << " ";

        if (current->left) {
            q.push(current->left);
        }
        if (current->right) {
            q.push(current->right);
        }
    }
}

int main() {
    TreeNode* root1 = new TreeNode(4);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(7);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(3);
    root1->right->left = new TreeNode(6);
    root1->right->right = new TreeNode(9);

    std::cout << "Input 1: ";
    printLevelOrder(root1);
    std::cout << std::endl;

    TreeNode* invertedRoot1 = invertTree(root1);

    std::cout << "Output 1: ";
    printLevelOrder(invertedRoot1);
    std::cout << std::endl;

    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);

    std::cout << "Input 2: ";
    printLevelOrder(root2);
    std::cout << std::endl;

    TreeNode* invertedRoot2 = invertTree(root2);

    std::cout << "Output 2: ";
    printLevelOrder(invertedRoot2);
    std::cout << std::endl;

    TreeNode* root3 = nullptr;

    std::cout << "Input 3: ";
    printLevelOrder(root3);
    std::cout << std::endl;

    TreeNode* invertedRoot3 = invertTree(root3);

    std::cout << "Output 3: ";
    printLevelOrder(invertedRoot3);
    std::cout << std::endl;

    return 0;
}
