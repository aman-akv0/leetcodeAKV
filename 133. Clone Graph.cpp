unordered_map<Node*,Node*> mp;
    void dfs (Node* node,Node* clone){
        for(Node* n : node->neighbors){
            if(mp.find(n)==mp.end()){
                Node *clonne = new Node(n->val);
                mp[n]=clonne;
                clone->neighbors.push_back(clonne);
                dfs(n,clonne);
            }else{
                clone->neighbors.push_back(mp[n]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        Node *clone=new Node(node->val);
        mp[node]=clone;
        dfs(node,clone);
        return clone;
    }
