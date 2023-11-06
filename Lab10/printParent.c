void printParent(Node* head,int key){

    if(head->left->data==key || head->right->data==key){
        printf("%d", head->data);
        return;
    }
    printParent(head->left,key);
    printParent(head->right,key);
    return;
    
}
