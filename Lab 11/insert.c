Node* insertNode(Node* head, int data){
    
    if(head==NULL){
        return newNode(data);
    }
    
    if(val<head->data){
        root->left=insertNode(root->left,data);
    }
    
    if(val>head->data){
        root->right=insertNode(root->right,data);
    }
    
    return root;
}
