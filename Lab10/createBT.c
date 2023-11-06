Node* CreateBT(Node* head){
    printf(" Value Node");
    int Data;
    scanf("%d",&Data);
    Node* newNode=CreateNode(data);
    if(Data==-1){
        return NULL;
    }
    printf("For left subtree");
    newNode->left= CreateBT(newNode->left);
    printf("For Right subtree");
    newNode->right= CreateBT(newNOde->right);
    
    return newNode;
    
    
}
