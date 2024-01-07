/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
      if(!head)
        return head;
        
        /*
        
iterates through the original linked list, inserting a new node with the same value after each original node
        
        */
      Node* temp;
      Node* curr=head;
      while(curr){
        temp=curr->next;
        curr->next=new Node(curr->val);
        curr->next->next=temp;
        curr=temp;
      }
      
        /*
        
         sets the random pointer for each copied node.
        */
        
        
      curr=head;
      while(curr){
        curr->next->random=curr->random?curr->random->next:curr->random;
        curr=curr->next->next;
      }
        
        /*
        
separates the original and copied linked lists, restoring the original list and forming the copied list
        */
        
      Node* orignal=head;
      Node* copy=head->next;
      temp=copy;
      while(orignal && copy){
        orignal->next=orignal->next->next;
        copy->next=copy->next?copy->next->next:copy->next;
        orignal=orignal->next;
        copy=copy->next;
      }
      return temp;
      
    }
};