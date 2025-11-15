#include <bits/stdc++.h>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // 🔹 SERIALIZE: Convert Tree -> String
    // We do a BFS (level-order traversal).
    // - If node exists, store its value.
    // - If node is NULL, store "#".
    // This ensures we can reconstruct tree structure uniquely.
    string serialize(TreeNode* root) {
        if (!root) return "";
        string data = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();

            if (node) {
                data += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                data += "#,";
            }
        }
        return data;
    }

    // 🔹 DESERIALIZE: Convert String -> Tree
    // We again use BFS.
    // - First value → root
    // - For each node, assign its left & right children using next values.
    // - If value is "#", it means NULL → skip child creation.
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;

        stringstream ss(data);
        string str;

        // Root value
        getline(ss, str, ',');
        if (str == "#") return NULL;

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();

            // Left child
            if (getline(ss, str, ',')) {
                if (str != "#") {
                    TreeNode* leftNode = new TreeNode(stoi(str));
                    node->left = leftNode;
                    q.push(leftNode);
                }
            }

            // Right child
            if (getline(ss, str, ',')) {
                if (str != "#") {
                    TreeNode* rightNode = new TreeNode(stoi(str));
                    node->right = rightNode;
                    q.push(rightNode);
                }
            }
        }

        return root;
    }
};

// 🔹 Helper function: Inorder traversal (for validation)
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    Codec codec;

    /*
            1
           / \
          2   3
             / \
            4   5
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    // 🔹 Serialize the tree
    string serialized = codec.serialize(root);
    cout << "Serialized Tree: " << serialized << "\n";

    // 🔹 Deserialize back to tree
    TreeNode* deserializedRoot = codec.deserialize(serialized);

    // 🔹 Check correctness by printing inorder traversal
    cout << "Inorder of Deserialized Tree: ";
    inorder(deserializedRoot);
    cout << "\n";

    // Another test case
    /*
            10
           /
          20
         /
        30
    */
    TreeNode* root2 = new TreeNode(10);
    root2->left = new TreeNode(20);
    root2->left->left = new TreeNode(30);

    string serialized2 = codec.serialize(root2);
    cout << "\nSerialized Tree 2: " << serialized2 << "\n";

    TreeNode* deserializedRoot2 = codec.deserialize(serialized2);
    cout << "Inorder of Deserialized Tree 2: ";
    inorder(deserializedRoot2);
    cout << "\n";

    return 0;
}
