
bool ancestors(Node* head, int key){
    if(head==NULL){
        return  false;
    }
    if(head->data==key){
        return true;
    }
    
    if(ancestors(head->left)||ancestors(head->right)){
        printf("%d",head->data);
        return true;
    }
    return false;
}
