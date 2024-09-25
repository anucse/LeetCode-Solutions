struct TrieNode{
    TrieNode* children[26]={};
    int score=0;
};

class Trie{
public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }

    void insert(const string& word){
        TrieNode* node=root;
        for(const char& ch:word){
            int index=ch-'a';
            if(!node->children[index]){
                node->children[index]=new TrieNode();
            }
            node=node->children[index];
            node->score++;
        }
    }

    int getScore(const string& word){
        TrieNode* node=root;
        int total=0;
        for(const char& ch:word){
            int index=ch-'a';
            node=node->children[index];
            total+=node->score;
        }
        return total;
    }

    int CommonPrefixLength(string& word){
        TrieNode* node=root;
        int ans=0;
        for(char& ch:word){
            int index=ch-'a';
            if(node->children[index]){
                node=node->children[index];
                ans++;
            }
            else
                break;
        }
        return ans;
    }
};


class Solution {
public:
    string longestCommonPrefix(vector<string>& words) {
        Trie trie;
        trie.insert(words[0]);
        int ans=INT_MAX;
        for(auto& word: words){
            ans=min(ans,trie.CommonPrefixLength(word));
        }

        return words[0].substr(0,ans);

    }
};