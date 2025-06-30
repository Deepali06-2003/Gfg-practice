/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        struct Node* s = head;
        struct Node* f = head;
        int c=0;
        while(f!= NULL && f->next != NULL){
            s= s->next;
            f = f->next->next;
            if(s==f){
                c=1;
                s= s->next;
                while(s!= f){
                  
                    c++;
                    s = s->next;
                }
                return c;
            }
            
        }
        return 0;
    }
};