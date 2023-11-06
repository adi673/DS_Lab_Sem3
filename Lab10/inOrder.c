void iterativeInorder(Node* head){
    Node* root=head;
    
    while(true){
        if(root!=NULL){
            st.push(root);
            root=root->left;
        }else{
            if(st.empty()){
                break;
            }
            root=st.top();
            st.pop();
            printf("%d",root->data);
            root=root->right;
        }
    }
}
