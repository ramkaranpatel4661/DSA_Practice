class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int ans=-1;
        priority_queue<int>pq;
        for(auto i:nums){
            pq.push(i);
        }
        while(!pq.empty() && k!=0){
               ans=pq.top();
               pq.pop();
               k--;
        }
        return ans;
    }
};