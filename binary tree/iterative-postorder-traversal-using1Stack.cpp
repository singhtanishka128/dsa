/* using 1 stack

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    if (!root) return result;

    stack<TreeNode*> st;
    TreeNode* curr = root;
    TreeNode* lastVisited = NULL;

    while (curr != NULL || !st.empty()) {

        // Step 1: Go left as much as possible
        if (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        } 
        else {
            TreeNode* temp = st.top();

            // Step 2: If right exists and not processed yet → go right
            if (temp->right != NULL && lastVisited != temp->right) {
                curr = temp->right;
            } 
            else {
                // Step 3: Process node
                result.push_back(temp->data);
                lastVisited = temp;
                st.pop();
            }
        }
    }

    return result;
}

tc: O(n)
sc: O(n)

*/