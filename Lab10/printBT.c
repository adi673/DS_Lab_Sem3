void printBT(Node* root){
    if(root==NULL){
        return;
    }
    
    printBT(root->left);
    printf("%d",root->data);
    printBT(root->right);
}
