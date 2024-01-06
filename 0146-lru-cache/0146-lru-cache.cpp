class LRUCache {
public:
    
    struct ListNode{
        
        int val;
        
        ListNode* prev=NULL;
        
        ListNode* next=NULL;
        
    };
    
    

unordered_map<int,ListNode*>mp;  // key, Pointer to the linked list
    
unordered_map<ListNode*,int>mp1;   // pointer to the linked list, key

    
ListNode* last=NULL;
    
ListNode* first=NULL;
    
int sz;
    
int cnt=0;
    
    
LRUCache(int cap) {
        
    sz=cap;
    
    }
    
    int get(int key) {
        
        if(mp.count(key)){
            
          // bring this node to last
            
            
            if(last==mp[key])   // if already its the last node
            return mp[key]->val;
            
            if(first==mp[key]){  // if its the first node
                
                first=mp[key]->next;
                
                mp[key]->prev=last;
                
                last->next=mp[key];
                
                mp[key]->next=NULL;
                
                last=mp[key];
            }
            
            else{  // somewhere in middle
                
                mp[key]->prev->next=mp[key]->next;
                
                mp[key]->next->prev=mp[key]->prev;
                
                mp[key]->prev=last;
                
                mp[key]->next=NULL;
                
                last->next=mp[key];
                
                last=mp[key];
            }
            
            return mp[key]->val;
        
        }
        
        return -1;
        
    }
    
    void put(int key, int value) {
        
        // cout<<mp[key]<<endl;
        
        cout<<cnt<<endl;
    
        if(mp.count(key)){
            
            mp[key]->val=value;
            
            // Bring this node to last
            
           
             if(last==mp[key])   // if already its the last node
                 return ;
            
            if(first==mp[key]){  // if its the first node
                
                first=mp[key]->next;
                
                mp[key]->prev=last;
                
                last->next=mp[key];
                
                mp[key]->next=NULL;
                
                last=mp[key];
            }
            
            else{  // somewhere in middle
                
                mp[key]->prev->next=mp[key]->next;
                
                mp[key]->next->prev=mp[key]->prev;
                
                mp[key]->prev=last;
                
                mp[key]->next=NULL;
                
                last->next=mp[key];
                
                last=mp[key];
            }
    
            return;
            
        }
        
        
        
        
        else if(cnt==sz){  // size full, remove LRU
            
          // remove LRU
        
          int lruKey=mp1[first];
        
          mp.erase(lruKey);
            
          mp1.erase(first);
            
         first=first->next;
          
         if(first)
         first->prev=NULL;
        
            
        }
        
     // putting in last
            
            ListNode* temp= new ListNode();
        
        if(cnt<sz)
            cnt++;
            
            temp->val=value;
            
        if(!first){
            first=temp;
            last=temp;
        }
        else{
            last->next=temp;
            temp->prev=last;
            last=temp;
        }
            
            mp[key]=last;
        
            mp1[last]=key;
            
        
        return ;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */