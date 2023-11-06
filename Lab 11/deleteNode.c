int findmin(Node* root){
    int min=root->data;
    while(root->left!=NULL){
        root=root->left;
        min=root->data;
    }
    return min;
}

Node* deleteNode(Node* head, int key){
    if(head==NULL){
        return NULL;
    }
    
    if(val<head->data){
        root->left=deleteNode(root->left,key);
    }else if(val>head->data){
        root->right=deleteNode(root->right,key);
    }else{
        if(head->left==NULL){
            return head->right;
        }else if(head->right==NULL){
            return head->left;
        } 
        head->data=findmin(head->right);
        head->right=deleteNode(head->right,key);
        
    }
    return head;
}
