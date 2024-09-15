class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int count=0;
        int res=0;
        for(int i=0;i<n;){
            char letter=chars[i];
            count=0;
            while(i<n && chars[i]==letter){
                i++;
                count++;
            }
            chars[res]=letter;
            res++;
            if(count>1){
                for(char c:to_string(count)){
                    chars[res++]=c;
                }
            }

        }
        return res;
    }
};