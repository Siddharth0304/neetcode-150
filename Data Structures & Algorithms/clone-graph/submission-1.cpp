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
    Node* clone(Node* node,map<Node*,Node*> &mp){
        if(node==NULL)
            return NULL;
        if(mp.find(node)!=mp.end())
            return mp[node];
        
        Node* n=new Node(node->val);
        mp[node]=n;

        for(auto &it:node->neighbors){
            n->neighbors.push_back(clone(it,mp));
        }
        return n;
    }
    Node* cloneGraph(Node* node) {
        map<Node*,Node*> mp;
        queue<Node*> q;
        return clone(node,mp);
    }
};
