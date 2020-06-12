class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie * node = this;
        for(char a : word){
            if(node->children[a] == nullptr){
                node->children[a] = new Trie();
            }
            node = node->children[a];
        }
        node->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie * node = this;
        for(char a : word){
            node = node->children[a];
            if(node == nullptr){
                return false;
            }
        }
        return node->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie * node = this;
        for(char a: prefix){
            node = node->children[a];
            if(node == nullptr){
                return false;
            }
        }
        return true;
    }
    
    ~Trie(){
        for (auto it : this->children){
            delete it.second;
        }
    }
    
private:
    unordered_map<char, Trie *> children;
    bool end = false;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
