class Trie {
  
    struct TrieNode{
      TrieNode *children[26];
      bool end;
    };
   TrieNode* root=new TrieNode();
public:
    Trie() {
       // root=new TrieNode;
    }
    
    void insert(string word) {
        TrieNode* node=root;
      for(int i=0;i<word.length();i++){
        int index=word[i]-'a';
        if(node->children[index]==NULL)
          node->children[index]=new TrieNode();
         node=node->children[index];
      }
        node->end=true;
    }
    
    bool search(string word) {
      TrieNode* node=root;
       for(int i=0;i<word.length();i++){
        int index=word[i]-'a';
        if(node->children[index]==NULL)
          return false;
         node=node->children[index];
       }
      if(node->end==true)
        return true;
      else
        return false;
    }
    
    bool startsWith(string prefix) {
              TrieNode* node=root;
       for(int i=0;i<prefix.length();i++){
        int index=prefix[i]-'a';
        if(node->children[index]==NULL)
          return false;
         node=node->children[index];
       }
      return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */