/*
store each nodes value in a string in inorder fashion along with storing length of node value at its corresponding index in a vector (initially whole vector is initialize to -1) -> do this process using inorder traversal

After this , make binary tree using that string, note if for ith node(in inorder fashion) if v[i]=-1 , it mean its null node, otherwise length of this node is v[i]
and its value is stored in substring at index j of length v[i]
*/


vector<int>v;

class Codec {

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        v = vector<int>(10020, -1);

        int i = 0;
        string tree = "";
        if (!root)
            return tree;

        // memset(v,-1,sizeof(v));

        queue<TreeNode*>q;

        q.push(root);
        string st = to_string(root->val);
        tree = tree + st;
        v[i++] = st.length();

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left) {
                    q.push(node->left);
                    string str = to_string(node->left->val);
                    tree = tree + str;
                    v[i++] = str.length();
                }
                else
                    i++;


                if (node->right) {
                    q.push(node->right);
                    string str = to_string(node->right->val);
                    tree = tree + str;
                    v[i++] = str.length();
                }
                else
                    i++;

            }
        }

        return tree;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string str) {
        TreeNode* root = nullptr;


        if (str.length() == 0 || v[0] == -1)
            return root;

        int i = 0;
        int j = 0;
        string rt = str.substr(j, v[i]);
        root = new TreeNode(stoi(rt));
        j = j + v[i];
        i++;
        queue<TreeNode*>q;
        q.push(root);
        while (!q.empty() && i < v.size() && j < str.length()) {
            int sz = q.size();
            while (sz-- && i < v.size() && j < str.length()) {
                TreeNode* node = q.front();
                q.pop();
                if (v[i] != -1) {
                    string l = str.substr(j, v[i]);
                    TreeNode* nodel = new TreeNode(stoi(l));
                    node->left = nodel;
                    j = j + v[i];
                    q.push(nodel);
                }
                i++;
                if (v[i] != -1) {
                    string r = str.substr(j, v[i]);
                    TreeNode* noder = new TreeNode(stoi(r));
                    node->right = noder;
                    j = j + v[i];
                    q.push(noder);
                }
                i++;
            }
        }
        return root;
    }


};
