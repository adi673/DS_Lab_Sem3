int depth(Node* head){
    if(head==NULL){
        return 0;
    }
    
    int leftD=depth(head->left);
    int rightD=depth(head->right);
    if(leftD>rightD){
        return leftD+1;
    }
    return rightD+1;
}
