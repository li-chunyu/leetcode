class Trie {
public:
    struct TrieNode {
    bool is_word;
    TrieNode **children;
    TrieNode() {
      is_word = false;
      children = (TrieNode**) malloc(sizeof(TrieNode*)*26);
      memset(children, 0, 26*sizeof(TrieNode*));
    }
  };

    /** Initialize your data structure here. */
    Trie():root(new TrieNode()) {        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
      TrieNode *r = root;
      for (auto c: word) {
        if (r->children[c-'a'] == NULL) {
          TrieNode *n = new TrieNode();
          r->children[c-'a'] = n;
        }
        r = r->children[c-'a'];
      }
      r->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
      TrieNode *r = root;
      for (auto c: word) {
        if (r->children[c-'a'] == NULL) {
          return false;
        }
        r = r->children[c-'a'];
      }
      return r->is_word?true:false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
      TrieNode *r = root;
      for (auto c: prefix) {
        if (r->children[c-'a'] == NULL) {
          return false;
        }
        r = r->children[c-'a'];
      }
      return true;
    }
private:
  
  TrieNode * const root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */