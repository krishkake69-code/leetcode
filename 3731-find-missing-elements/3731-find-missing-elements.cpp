class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
       vector<int> ans;
       int mn = nums[0] , mx = nums[0];
       unordered_set<int> s;

       for(int x: nums){
        mn = min(mn, x);
        mx = max(mx, x);
        s.insert(x);
       }
    for(int i = mn; i <= mx; i++){
        if (s.find(i) ==s.end()){
            ans.push_back(i);
        }
    }
    return ans;
    }
};