class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        for(auto num: nums){
            mpp[num]++;
        }
        vector<pair<int, int>> arr;
        for(auto& it:mpp){
            arr.push_back({it.first, it.second});
        }
        sort(arr.begin(), arr.end(), [](pair<int, int>&a, pair<int,int>&b){
            return a.second > b.second;
        });

        vector<int>res;
        for(int i = 0; i<k; i++){
            res.push_back(arr[i].first);
        }
        return res;
    }
};
