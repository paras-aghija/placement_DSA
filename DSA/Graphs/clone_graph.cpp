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
    
    map<Node*, Node*> m;
    set<int> vis;
    void dfs(Node *root){
        vis.insert(root->val);
        Node *x = new Node(root->val);
        m[root] = x;
        for(auto nbr : root->neighbors){
            if(vis.find(nbr->val)==vis.end()) dfs(nbr);
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        dfs(node);
        Node *root = m[node];
        for(auto p : m){
            for(auto nbr : p.first->neighbors){
                p.second->neighbors.push_back(m[nbr]);
            }
        }
        return root;
    }
};