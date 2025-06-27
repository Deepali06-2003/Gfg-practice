/* Link list node */
/*
struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
}; */

class Solution {
  public:
    // Function to count nodes of a linked list.
    int getCount(struct Node* head) {

        // Code here
        struct Node* curr = head;
        int c=0;
        while(curr!= nullptr){
            c++;
            curr = curr->next;
        }
        return c;
    }
};