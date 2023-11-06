void iterativePreorder(Node* head){
    Node* root;
    st.push(head);
    while(!st.empty()){
        root=st.top();
        printf("%d",root->data);
        st.pop();
        if(root->right!=NULL){
            st.push(root->right);
        }
        if(root->left!=NULL){
            st.push(root->left);
        }
    }
}
