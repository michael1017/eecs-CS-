#include <stdio.h>
#include <stdlib.h>
typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

Node* Create_List(Node* in, int data){
    Node* n = (Node* )malloc(sizeof(Node* ));
    //printf("%p",n);
    n->data = data;
    n->next = in;
    return n;
}
Node* Reverse_List(Node* in){
    return in;
}
void Print_List(Node* in){
	printf("%d", in->data);
    if(in->next == NULL){
        printf("\n");
        return ;
    }
    else {
        printf("->");
        Print_List(in->next);
        return ;
        
    }

}
void Free_List(Node* in){
    if(in->next == NULL){
        free(in);
        return ;
    }
    else {
        free(in->next);
        free(in);
        return ;
        
    }
}
int main() {
    Node *head = NULL;
    int n, data, i;
    
    scanf("%d", &n);
    for( i=0; i<n; i++ ) {
        scanf("%d", &data);
        head = Create_List( head, data );
    }
    
    head = Reverse_List( head );
    
    Print_List( head );
    Free_List( head );
    
    return 0;
}