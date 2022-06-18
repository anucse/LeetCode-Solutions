class WordFilter {
public:
    unordered_map<string,int> m;
    
    WordFilter(vector<string>& words) {
        int n=words.size();
        for(int i=0;i<n;i++){
            int wordsize=words[i].size();
            string word=words[i];
            for(int j=1;j<=wordsize;j++){
                string prefix=word.substr(0,j);
                for(int k=0;k<wordsize;k++){
                    string suffix=word.substr(k,wordsize);
                    m[prefix+':'+suffix]=i+1;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string s=prefix+':'+suffix;
        return m[s]-1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */