void traverse(Node* root){
    if(root==NULL){
        return;
    }
    traverse(root->left);
    int data=root->data;
    printf("%d",data);
    traverse(root->right);
    return;
}
