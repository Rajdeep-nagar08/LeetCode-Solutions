/*

jab koi naya pair aye too usse linked list ke last m add kardo

jab kisi pair key value mange too uski value return kardo aur usse linked list m se dlt karke linked list ke last m add kardo

jab linked list ka size full ho jaye aur naya pair add karna ho too linked list ka starting se pair remove kardo (jo ko least recently used pair h)


*/

class LRUCache {
public:
    
    int n;
    
    struct ListNode{
       
        int key;
        
        int val;
        
        ListNode* next=NULL;
        
        ListNode* prev=NULL;
     
    };
    
    unordered_map<int,ListNode*>mp;
    
    ListNode* start=NULL;
    
    ListNode* last=NULL;
    
    
    LRUCache(int capacity) {
        
    n=capacity;    
        
    }
    
    
    
    
    int get(int key) {
        
        // return -1, if key not exist
        
        
       if(mp.count(key)==1){
           
           // return mp[key]->val;
           
           // dlt node from the linkedlist and add it to the last of linked list
           
           ListNode* t=mp[key];
            
            // t->val=vl;
            
            if(last!=t){
                
                if(start==t){  // it is the first node of the linked list
                    
                    start=start->next;
                    
                    start->prev=NULL;
                    
                    last->next=t;
                    
                    t->next=NULL;
                    
                    t->prev=last;
                    
                    last=t;
                    
                }
                
                else{  // any middle node,  dlt it and add to the last
                    
                    
                    t->prev->next=t->next;
                    
                    t->next->prev=t->prev;
                    
                    last->next=t;
                    
                    t->prev=last;
                    
                    t->next=NULL;
                    
                    last=t;
                    
                }
                
            }
            
        
           return t->val;
           
       
       }
        
        return -1;
        
    }
    
    
    
    void put(int ky, int vl) {
        
      
        // key already present in the linked list, just update its value, dlt it from middle and put it to the last of linked list
        
        if(mp.count(ky)==1){
            
            ListNode* t=mp[ky];
            
            t->val=vl;
            
            if(last!=t){
                
                if(start==t){  // it is the first node of the linked list
                    
                    start=start->next;
                    
                    last->next=t;
                    
                    t->next=NULL;
                    
                    t->prev=last;
                    
                    last=t;
                    
                }
                
                else{  // any middle node,  dlt it and add to the last
                    
                    
                    t->prev->next=t->next;
                    
                    t->next->prev=t->prev;
                    
                    last->next=t;
                    
                    t->prev=last;
                    
                    t->next=NULL;
                    
                    last=t;
                    
                }
                
            }
            
            
        }
        
        // add node to the end of the linked list
        
        else{
            
            
              
        if(mp.size()==n){   //size is full,  dlt node from starting
            
            int ky1;
            
            ky1=start->key;
            
            mp.erase(ky1);
            
            if(n==1){
            
                start=NULL;
                last=NULL;
            }
            
            else{
                start=start->next;
                start->prev=NULL;
            }
            
                      
        }
        
        // now add node
            
            ListNode* t=new ListNode();
            t->key=ky;
            t->val=vl;
            
            if(last==NULL){
                last=t;
                start=t;
            }
            else{
               last->next=t;
               t->prev=last;
               last=last->next;
            }
            
            mp[ky]=t;
            
        }
        
        
        
    }
};

