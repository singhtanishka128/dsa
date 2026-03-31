/* iterative preorder: ROOT, LEFT, RIGHT

struct TreeNode {
    int val;  
    TreeNode* left;  
    TreeNode* right;  
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} 
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;  
        
        if(root == nullptr) {
            return preorder;
        }
        
        stack<TreeNode*> st;  
        st.push(root);  
        
        while(!st.empty()) {
            root = st.top();  
            st.pop();  
            preorder.push_back(root->val);  
            
            if(root->right != nullptr) {   //first right 
                st.push(root->right);
            }
            
            if(root->left != nullptr) {   //then left
                st.push(root->left);
            }
        }
        
        return preorder;
    }
};

tc:O(n)
sc:O(n)

*/