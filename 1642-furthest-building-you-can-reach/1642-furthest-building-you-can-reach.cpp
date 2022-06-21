class Solution {
public:
    // maintain a min heap and push jump heights equal to the number of ladders 
    // this signifies we can use only that much ladder
    
    // from next jumps , we compare jump heights to the top of the min heap
    // if top is less than current jump height , pop the heap and use that much bricks
    // and push the current jump height to the heap
    
    // else use current jump height number of bricks 
    
    // continue untill we exhaust all bricks or exhaust all buildings 
    
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int i=0;      // number of buildings
        int currHeight;
        int n=heights.size();
        
        while(i<n-1 && pq.size()<ladders){
            currHeight=heights[i+1]-heights[i];
            if(currHeight>0){
                pq.push(currHeight);
            }
            i++;
            
            
        }
        
        while(i<n-1){
            currHeight=heights[i+1]-heights[i];
            if(currHeight>0){
                if(!pq.empty() && currHeight>pq.top()){
                    bricks-=pq.top();
                    pq.pop();
                    pq.push(currHeight);
                }
                else{
                    bricks-=currHeight;
                }
            }
            if(bricks<0)
                return i;
            i++;
        }
        return i;
    }
};