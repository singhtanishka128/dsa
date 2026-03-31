/* PRE-ORDER TRAVERSAL: ROOT, LEFT, RIGHT */

#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:

    void preorder(Node* root, vector<int> &arr) {
        if (root == nullptr) {
            return;
        }
        
        arr.push_back(root->data);
        preorder(root->left, arr);
        preorder(root->right, arr);
    }

    vector<int> preOrder(Node* root) {
        vector<int> arr;
        preorder(root, arr);
        return arr;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/