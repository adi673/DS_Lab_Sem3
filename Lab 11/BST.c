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

Node* insert(Node* head, int val){
    
    if(head==NULL){
        return CreateNode(val);
    }
    Node* root=head;
    if(val<head->data){
        root->left=insert(root->left,val);
    }
    
    if(val>head->data){
        root->right=insert(root->right,val);
    }
    
    return root;
}

int findmin(Node* root){
    int min=root->data;
    while(root->left!=NULL){
         min=root->left->data;
        root=root->left;
       
    }
    return min;
}

Node* deleteNode(Node* head, int val){
    if(head==NULL){
        return head;
    }
    Node* root=head;
    if(val<root->data){
        root->left=deleteNode(root->left,val);
    }else if(val>root->data){
        root->right=deleteNode(root->right,val);
    }else{
        if(root->left==NULL){
            return root->right;
        }else if(root->right==NULL){
            return root->left;
        } 
        root->data=findmin(root->right);
        root->right=deleteNode(root->right,root->data);
        
    }
    return head;
}

void traverse(Node* root){
    if(root==NULL){
        return;
    }
    traverse(root->left);
    int data=root->data;
    printf(" %d ",data);
    traverse(root->right);
    return;
}


Node* SearchEle(Node* root,int key){
    
    if(root->data==key|| root==NULL){
        return root;
    }
    
    if(key<root->data){
        return SearchEle(root->left,key);
    }
    
    return SearchEle(root->right,key);
}

int main(){
    
  Node* root=CreateNode(20);
  insert(root, 5);
  insert(root, 1);
  insert(root, 15);
  insert(root, 9);
  insert(root, 7);
  insert(root, 12);
  insert(root, 30);
  insert(root, 25);
  insert(root, 40);
  insert(root, 45);
  insert(root, 42);
  printf("\n");
  traverse(root);
  //deleteNode()
  root=deleteNode(root, 30);
  printf("\n");
  traverse(root);
  printf("\n");
  Node* val=SearchEle(root,40);
  printf("%d ",val->data);
}
