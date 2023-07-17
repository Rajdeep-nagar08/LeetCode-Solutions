class Solution {
public:
    
    ListNode* reverse(ListNode* head){
        ListNode *p, *q;
        p=head, q=NULL;
        
        while(p!=NULL){
            ListNode* on=p->next; // keep track of original next node
            p->next=q; // reversing links
            q=p;
            p=on;
        }
        return q;
    }
    
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        ListNode* p=reverse(head1);
        ListNode* q=reverse(head2);
        
        ListNode *head, *last;
        head=last=new ListNode(-1); // pointers to new list
        
        int carry=0;
        while(p!=NULL || q!=NULL){
            int d=(p!=NULL ? p->val:0) + (q!=NULL ? q->val:0) + carry;
            
            ListNode *temp=new ListNode(d%10);
            last->next=temp;
            last=temp;
            
            carry=d/10;
            
            if(p) p=p->next;
            if(q) q=q->next;
        }
        
        if(carry!=0){
            ListNode *temp=new ListNode(carry);
            last->next=temp;
            last=temp;
        }
        
        head=head->next; // since head was pointing to dummy node
        head=reverse(head);
        
        return head;
    }
};