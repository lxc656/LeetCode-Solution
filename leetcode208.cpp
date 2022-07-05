class Trie {
public:
    struct Node{
        bool is_end;
        Node *son[26];
        Node() {
            is_end = false;
            for(int i=0; i<26; i++) {
                son[i] = nullptr;
            }
        }
    } *root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* tmp = root;
        for(auto x:word) {
            int index = x-'a';
            if(tmp->son[index]==nullptr) {
                Node* new_node = new Node();
                tmp->son[index] = new_node;
            }
            tmp = tmp->son[index];
        }
        tmp->is_end = true;
    }
    
    bool search(string word) {
        Node* temp = root;
        for(auto x:word) {
            int index = x-'a';
            if(temp->son[index]==nullptr) {
                return false;
            }
            else {
                temp = temp->son[index];
            }
        }
        if(temp->is_end) {
            return true;
        }
        else {
            return false;
        }
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
        for(auto x:prefix) {
            int index = x-'a';
            if(temp->son[index]==nullptr) {
                return false;
            }
            else {
                temp = temp->son[index];
            }
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