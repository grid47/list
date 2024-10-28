class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        Node* nextptr = NULL;
        while(!q.empty()) {
            int sz = q.size();
            nextptr = NULL;
            while(sz--) {
                Node* tmp = q.front();
                q.pop();
                tmp->next = nextptr;
                nextptr = tmp;
                if(tmp->right)  q.push(tmp->right),
                                q.push(tmp->left);
            }
         }
        return root;
    }
};