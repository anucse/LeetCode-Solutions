class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int p=1;
        int s=f.size();
        if(n==0)
            return true;
        for(int i=0;i<s;i++){
            if(f[i]==0){
                p+=1;
            }
            else{
                p=0;
            }
            if(p==3){
                n--;
                p=1;
            }
            if(i==s-1 && p==2){
                n--;
            }
            if(n==0)
                return true;
        }

        return n==0;
    }
};