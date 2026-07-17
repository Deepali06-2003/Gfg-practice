/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
}; */

class Solution {
  public:
  
  Node* merge_sort(Node* t1 , Node* t2){
      if(t1==NULL && t2==NULL) return NULL;
      if(t1 == NULL) return t2;
      if(t2 == NULL) return t1;
      
      Node* n_head = new Node(0);
      Node* temp = n_head;
      while(t1!= NULL && t2 != NULL){
          if(t1->data <= t2->data){
              temp->bottom = t1;
              t1 = t1->bottom;
          }
          else{
              temp->bottom = t2;
              t2 = t2->bottom;
          }
          temp = temp->bottom;
          temp->next = NULL;
      }
      while(t1 != NULL){
          temp->bottom = t1;
          temp->next = NULL;
          
          t1 = t1->bottom;
        
          temp = temp->bottom;
      }
      while(t2 != NULL){
          temp->bottom = t2;
          temp->next = NULL;
          
          t2 = t2->bottom;
        
          temp = temp->bottom;
      }
      
      return n_head->bottom;
  }
    Node *flatten(Node *root) {
    if (root == NULL || root->next == NULL)
        return root;
    Node* temp = root;
    Node* ans = NULL;
    
    while (temp) {
        Node* nextCol = temp->next;
        ans = merge_sort(ans, temp);
        temp = nextCol;
    }
    
    return ans;
    }
};

