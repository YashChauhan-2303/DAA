#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *llink,*rlink;
};

typedef struct node * NODE;
NODE head = NULL;

void createList(int val){
    NODE new_node;
    if(head == NULL){
        new_node = (NODE)malloc(sizeof(struct node));
        new_node->llink = new_node->rlink = NULL;
        new_node->val = val;
        head = new_node;
    } else {
        printf("List is already created !");
    }
}

void insertIntoList(int before, int val){
    NODE nd, new_nd;
    nd = head;
    while(nd != NULL && nd->val != before)
        nd = nd->rlink;
    if (nd != NULL){
        new_nd = (NODE)malloc(sizeof(struct node));
       new_nd->llink = nd->rlink=NULL;
       new_nd->val=val;
       if(nd->llink!=NULL){
        nd->llink->rlink=new_nd;
        new_nd->llink=nd->llink;
        new_nd->rlink=nd;
        nd->llink=new_nd;
       } else {
        new_nd->rlink=nd;
        nd->llink=new_nd;
        head=new_nd;
       }
    } else {
        printf("Unable to insert, Node with value %d not found!!",val);
    }
}

void deleteAll(int delVal){
    NODE curr,nxtnode;
    curr = head;
    while(curr != NULL){
        if(curr->val == delVal){
            if (curr->llink!=NULL){
                curr->llink->rlink=curr->rlink;
                if(curr->rlink!=NULL){
                    curr->rlink->llink=curr->llink;
                    nxtnode=curr->rlink;
                    free(curr);
                    curr=nxtnode;
                } else {
                    curr->llink->rlink=NULL;
                    free(curr);
                    curr=NULL;
                }
            } else {
                if (curr->rlink != NULL){
                    curr->rlink->llink=NULL;
                    nxtnode=curr->rlink;
                    free(curr);
                    head=nxtnode;
                    curr=nxtnode;
                } else {
                    free(curr);
                    head = curr = NULL;
                }
            }
        } else {
            curr = curr->rlink;
        }
    }
}

void searchNode(int searchVal){
    NODE curr;
    curr = head;
    while (curr != NULL){
        if (curr->val == searchVal)
            printf("Node is found with key %d\n", searchVal);
        curr = curr->rlink;
    }
}

void displayAll(){
    NODE curr;
    curr = head;
    while(curr != NULL){
        printf("Node with val %d\n", curr->val); 
        curr = curr->rlink;
    }
}

int main(){
    int choice, val,before; 
    do { 
        printf("1. Create List\n"); 
        printf("2. Insert into List\n"); 
        printf("3. Delete all by value\n"); 
        printf("4. Search by value\n"); 
        printf("5. Display all\n"); 
        printf("6. Exit\n"); 
        printf("Enter your choice :"); 
        scanf("%d", &choice); 
        switch(choice) { 
            case 1: printf("Please enter the node value"); 
            scanf("%d", &val); 
            createList(val); 
            break; 
            case 2: printf("Please enter the node value to insert "); 
            scanf("%d", &val); printf("Please enter the node value before which new node has to be inserted "); 
            scanf("%d", &before); 
            insertIntoList(before, val); 
            break; 
            case 3:printf("Enter the node value to be deleted "); 
            scanf("%d", &val);
            deleteAll(val); 
            break; 
            case 4:printf("Enter the node value to be searched "); 
            scanf("%d", &val); 
            searchNode(val);
            break; 
            case 5:
            displayAll(); 
            break; 
            case 6: break; 
            default:printf("Invalid choice "); 
            break; 
        } 
    }while(choice != 6); 
    return 0;
}