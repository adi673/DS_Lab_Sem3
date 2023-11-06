int LeaftNode(Node* head){
    if(head->left==NULL && head->right==NULL){
        return 1;
    }
    
    int LeftLeaf=LeaftNode(head-left);
    int RightLeaf=LeaftNode(head-right);;
    
    return LeftLeaf+RightLeaf;
}
