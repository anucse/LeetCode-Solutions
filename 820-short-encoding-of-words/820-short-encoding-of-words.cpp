struct Trie {
    Trie *children[26];
};

class Solution {
private:
    Trie *root = new Trie();
    bool checkWord(string w) {
        bool res = false;
        Trie *curr = root;
        for (int i = w.size() - 1, c; i >= 0; i--) {
            c = w[i] - 'a';
            if (!curr->children[c]) {
                res = true;
                curr->children[c] = new Trie();
            }
            curr = curr->children[c];
        }
        return res;
    }
public:
    int minimumLengthEncoding(vector<string>& words) {
        // support variables
        int res = 0;
        // sorting by decreasing length
        sort(begin(words), end(words), [](string a, string b){return b.size() < a.size();});
        // parsing all the words
        for (string w: words) {
            if (checkWord(w)) res += w.size() + 1;
        }
        return res;
    }
};