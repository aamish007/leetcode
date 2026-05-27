class Trie {
    struct node{
        node* children[26];
        bool isEnd;
        node(){
            isEnd=false;
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
        }
    };
    node* root;
public:
    Trie() {
        root=new node();
    }
    
    void insert(string word) {
        node* curr=root;
        for(char ch:word){
            int idx=ch-'a';
            if(curr->children[idx]==NULL){
                curr->children[idx]=new node();
            }
            curr=curr->children[idx];
        }
        curr->isEnd=true;
    }
    
    bool search(string word) {
        node* curr=root;
        for(char ch:word){
            int idx=ch-'a';
            if(curr->children[idx]==NULL){
                return false;
            }
            curr=curr->children[idx];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string word) {
        node* curr=root;
        for(char ch:word){
            int idx=ch-'a';
            if(curr->children[idx]==NULL){
                return false;
            }
            curr=curr->children[idx];
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