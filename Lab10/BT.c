#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

typedef struct Node Node;

Node* CreateNode(int data){
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
}

void iterativeInorder(Node* head){
    Node* root=head;
    struct Node* st[50];
    int top=-1;
    while(1){
        if(root!=NULL){
            st[++top]=root;//st.push(root);
            root=root->left;
        }else{
            if(top==-1)  {     //(st.empty()){
                break;
            }
            root=st[top--];//root=st.top();
            //st.pop();
            printf(" %d ",root->data);
            root=root->right;
        }
    }
}

void iterativePreorder(Node* head){
    Node* root;
    struct Node* st[50];
    int top=-1;
    st[++top]=head;              //st.push(head);
    while(top!=-1){      //(!st.empty()){
        root=st[top--]  ;   //st.top();
        printf(" %d ",root->data);
        //st.pop();
        if(root->right!=NULL){
          st[++top]=root->right;   //st.push(root->right);
        }
        if(root->left!=NULL){
            st[++top]=root->left;   ////st.push(root->left);
        }
    }
}

void postOrderIterative(Node* root) {
    if (root == NULL) return;
    // Create two stacks
    struct Node* s1[50];
    int top1 = -1;
    struct Node* s2[50];
    int top2 = -1;
    // push root to the first stack
    s1[++top1] = root;
    struct Node* Node;
    // Run while the first stack is not empty
    while (top1 >= 0) {
        // Pop an item from s1 and push it to s2
        Node = s1[top1--];
        s2[++top2] = Node;
        // Push left and right children of the removed item to s1
        if (Node->left) s1[++top1] = Node->left;
        if (Node->right) s1[++top1] = Node->right;
    }
    // Print all elements of the second stack
    while (top2 >= 0) {
        Node = s2[top2--];
        printf(" %d ", Node->data);
    }
}

void printParent(Node* head,int key){

    if(head->left->data==key || head->right->data==key){
        printf("%d", head->data);
        return;
    }
    printParent(head->left,key);
    printParent(head->right,key);
    return;
    
}

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

int LeaftNode(Node* head){
    if(head==NULL){
        return 0;
    }
    if(head->left==NULL&& head->right==NULL){
        return 1;
    }
    
    int LeftLeaf=LeaftNode(head->left);
    int RightLeaf=LeaftNode(head->right);;
    
    return LeftLeaf+RightLeaf;
}

Node* CreateBT(Node* head){
    printf(" Value Node");
    int data;
    scanf("%d ",&data);
    Node* newNode=CreateNode(data);
    if(data==-1){
        return NULL;
    }
    printf("For left subtree of ");
    newNode->left= CreateBT(newNode->left);
    printf("For Right subtree of ");
    newNode->right= CreateBT(newNode->right);
    return newNode;
}

void printBT(Node* root){
    if(root==NULL){
        return;
    }
    
    printBT(root->left);
    printf(" %d ",root->data);
    printBT(root->right);
}

int identicalTrees(Node* a, Node* b)
{
    /*1. both empty */
    if (a == NULL && b == NULL)
        return 1;
 
    /* 2. both non-empty -> compare them */
    if (a != NULL && b != NULL) {
        return (a->data == b->data
                && identicalTrees(a->left, b->left)
                && identicalTrees(a->right, b->right));
    }
 
    /* 3. one empty, one not -> false */
    return 0;
}

int main(){
    Node* temp=NULL;
    Node* temp2=CreateBT(temp);
    iterativeInorder(temp2);
    printf("\n");
    iterativePreorder(temp2);
    printf("\n");
    postOrderIterative(temp2);
    printf("\n");
    int leafNodes=LeaftNode(temp2);
    printf("Give key to find ancestors");
    int key;
    scanf("%d",&key);
    printf("\n");
    ancestors(temp2,key);
    int depthh=depth(temp2);
    printf("Depth is :%d",depthh);
    printf("\n");
    printf("Parent of key is :");
    printParent(temp2,key);
    
}
