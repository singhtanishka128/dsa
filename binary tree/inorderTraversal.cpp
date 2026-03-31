/* IN-ORDER TRAVERSAL: LEFT, ROOT, RIGHT */

#include <vector>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:

    void Inorder(TreeNode* root, vector<int> &arr) {
        if (root == nullptr) {
            return;
        }
       
        Inorder(root->left, arr);
        arr.push_back(root->data);
        Inorder(root->right, arr);
    }
    
    vector<int> inorder(TreeNode* root) {
        vector<int> arr;
        Inorder(root, arr);
        return arr;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/