Node* SearchEle(Node* root,int key){
    
    if(root->data==key|| root==NULL){
        return root;
    }
    
    if(key<root->data){
        return SearchEle(root->left,key);
    }
    
    return SearchEle(root->right,key);
}
