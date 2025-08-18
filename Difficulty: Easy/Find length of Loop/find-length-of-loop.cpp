/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // Code here
        int c=0;
        if(head == NULL)return 0;
        
        Node* s = head;
        Node* f = head;
        
        while(f!= NULL && f->next != NULL){
            s= s->next;
            f = f->next->next;
            
            if(s == f){
                s=s->next;
                c++;
                while(s!= f){
                    s=s->next;
                    c++;
                }
                return c;
            }
            
        }
        return 0;
        
    }
};