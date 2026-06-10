/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;
        unordered_set<int> seen;
        Node* root = new Node(node->val);
        unordered_map<int, Node*> ump;
        ump[node->val] = root;
        seen.insert(node->val);
        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node* s = q.front();
            Node* par = ump[s->val];
            q.pop();
            for (auto it : s->neighbors) {
                if (!seen.count(it->val)) {
                    seen.insert(it->val);
                    Node* temp = new Node(it->val);
                    q.push(it);
                    ump[it->val] = temp;
                }

                par->neighbors.push_back(ump[it->val]);
            }
        }
        return root;
    }
};