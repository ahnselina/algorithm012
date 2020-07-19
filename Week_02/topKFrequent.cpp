/*347. 前 K 个高频元素*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {  
        unordered_map<int, int> freq;
        for(int num : nums) {
            freq[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto kv : freq ) {
            pq.push({kv.second, kv.first});
            while(pq.size() > k) pq.pop();
        }

        vector<int> res;
        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};