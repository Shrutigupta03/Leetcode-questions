/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
    if(!root) return nullptr;

        queue<Node*> q;
        q.push(root);
    
        while(!q.empty()){
            int x = q.size();
            int n = 0;
            while(n<x){
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                q.pop();
                n++;
            }
            if(q.size()>1){
                vector<Node*> v;
                while(!q.empty()){
                    v.push_back(q.front());
                    q.pop();
                }
                int z = v.size();
                for(int i=0; i<z-1; i++){
                    v[i]->next = v[i+1];
                    q.push(v[i]);
                }
                q.push(v[z-1]);
            }
        }
    
      return root;
    }
};