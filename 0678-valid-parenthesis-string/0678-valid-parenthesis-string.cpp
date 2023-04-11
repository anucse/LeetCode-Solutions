class Solution {
public:
    bool checkValidString(string s) {
        
        int n=s.size();
        
        int l=0;
        int r=0;
        int star=0;
        
        for(int i=0;i<n;i++){
            if(s[i]=='(')
                l++;
            else if(s[i]==')'){
                r++;
            }
            else 
                star++;
            
            if(r>l+star)
                return false;
        }
        
        bool f1=(l+star>=r);
        
        l=0;
        r=0;
        star=0;
        
        for(int i=n-1;i>=0;i--){
            if(s[i]=='(')
                l++;
            else if(s[i]==')'){
                r++;
            }
            else 
                star++;
            
            if(l>r+star)
                return false;
        }
        
        bool f2=(r+star>=l);
        
        return f1  and f2;
        
    }
};