class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector <int> freq(20001,0);
        for (int i = 0;i<nums.size();i++){
            freq[nums[i]+10000]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for(int i=0;i<freq.size();i++){
            pq.push({freq[i],i-10000});
            while(pq.size()>k && !pq.empty() ) {pq.pop();}
        }

        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
