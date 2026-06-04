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
        Node* n;
        if(mp.find(node)!=mp.end())
            n=mp[node];
        else{
            n=new Node(node->val);
            mp[node]=n;
        }
        for(auto &it:node->neighbors){
            if(mp.find(it)!=mp.end())
                n->neighbors.push_back(mp[it]);
            else{
                Node* nei=new Node(it->val);
                mp[it]=nei;
                n->neighbors.push_back(nei);
                clone(it,mp);
            }
        }
        return n;
    }
    Node* cloneGraph(Node* node) {
        map<Node*,Node*> mp;
        queue<Node*> q;
        return clone(node,mp);
    }
};
