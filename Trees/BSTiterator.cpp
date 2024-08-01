/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {

    
public:
    vector<TreeNode*>  vec;
    int curr=0 ;
    void inorder(TreeNode* root,vector<TreeNode*> &vec)
    {
        if(root == NULL) return;

        inorder(root->left, vec);
        vec.push_back(root);
        inorder(root->right, vec);
    }
    BSTIterator(TreeNode* root) {
        inorder(root, vec);
        curr =0 ;
    }
    
    int next() {
        int value = vec[curr]->val;
        curr++;
        return value;
    }
    
    bool hasNext() {
        if(curr < vec.size()) return true;
        else return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
