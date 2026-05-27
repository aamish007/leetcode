class Trie{
    struct TrieNode{
        bool isEnd;
        TrieNode* children[26];
        TrieNode(){
            isEnd=false;
            for(int i=0;i<26;i++)children[i]=NULL;
        }
    };
    TrieNode* root;
    public:
    Trie(){
        root=new TrieNode();
    }
    void insert(string s){
        TrieNode* curr=root;
        for(char ch:s){
            int i=ch-'a';
            if(curr->children[i]==NULL)curr->children[i]=new TrieNode();
            curr=curr->children[i];
        }
        curr->isEnd=true;
    }
    string common(){
        string res="";
        TrieNode* curr=root;bool many=false;
        while(!many){
            int c=0;int k=0;
            for(int i=0;i<26;i++){
                if(curr->children[i]){c++;k=i;}
            }
            if(c>1){many=true;return res;}
            else if(c==0)return res;
            else{
                curr=curr->children[k];
                char ch='a'+k;
                res.push_back(ch);
            }
            if(curr->isEnd)return res;
        }
        return res;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie t;
        for(string s:strs){
            if(s=="")return "";
            t.insert(s);
        }
        return t.common();
    }
};