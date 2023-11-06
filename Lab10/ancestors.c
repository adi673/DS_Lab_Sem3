
bool ancestors(Node* head, int key){
    if(head==NULL){
        return  false;
    }
    if(head->data==key){
        return true;
    }
    
    if(ancestors(head->left,key)||ancestors(head->right,key)){
        printf("%d",head->data);
        return true;
    }
    return false;
}
