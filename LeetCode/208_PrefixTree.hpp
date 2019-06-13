#include<vector>
#include <unordered_map>
using namespace std;
class Trie
{
public:
    Trie(/* args */):_root(new TrieNode()){}

    //insert a word into the trie
    void insert(const string& word){
        TrieNode* p = _root.get();
        for(const char c : word){
            if(!p->children[c-'a'])
                p->children[c-'a'] = new TrieNode();
            p = p->children[c-'a'];
        }
        p->is_word = true;
    }

    //return i fthr word is in the tire
    bool search(const string& word)const{
        const TrieNode* p = find(word);
        return p && p->is_word;
    }

    bool startsWith(const string& prefix)const{
        return  find(prefix) != nullptr;
    }
private:
    struct TrieNode
    {
        TrieNode():is_word(false),children(26,nullptr){}

        //must delete TrieNode* in destructor
        ~TrieNode(){
            for(auto child : children)
                if(child)
                    delete child;
        }
        bool is_word;
        vector<TrieNode*> children;
    };

    std::unique_ptr<TrieNode> _root;

    const TrieNode* find(const string& prefix) const{
        const TrieNode* p = _root.get();
        for(const char c:prefix){
            p = p->children[c-'a'];
            if(p == nullptr) break;
        }
        return p;
    }
    
};

///////////////////////////
/* Solution with map
class Trie {
public:
    /** Initialize your data structure here. */
    Trie(): root_(new TrieNode()) {}
    
    /** Inserts a word into the trie. */
    void insert(const string& word) {
        TrieNode* p = root_.get();
        for (const char c : word) {
            if (!p->children.count(c))
                p->children[c] = new TrieNode();
            p = p->children[c];
        }
        p->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(const string& word) const {
        const TrieNode* p = find(word);
        return p && p->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string& prefix) const {
        return find(prefix) != nullptr;
    }
private:
    struct TrieNode {
        TrieNode():is_word(false){}
        
        ~TrieNode() {
            for (auto& kv : children)
                if (kv.second) delete kv.second;
        }
        
        bool is_word;
        unordered_map<char, TrieNode*> children;
    };
    
    const TrieNode* find(const string& prefix) const {
        const TrieNode* p = root_.get();
        for (const char c : prefix) {
            if (!p->children.count(c)) return nullptr;
            p = p->children.at(c);
        }
        return p;
    }
    
    std::unique_ptr<TrieNode> root_;
};
*/