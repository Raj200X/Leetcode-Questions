class FoodRatings {
public:
    struct comp {
        bool operator()(pair<int,string>& a, pair<int,string>& b) {
            if(a.first == b.first)
                return a.second > b.second;
            return a.first < b.first; 
        }
    };
    unordered_map<string, pair<int,string>> foodInfo;

    unordered_map<string, priority_queue<pair<int,string>, vector<pair<int,string>>, comp>> cuisineMap;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0; i < n; i++) {
            foodInfo[foods[i]] = {ratings[i], cuisines[i]};
            cuisineMap[cuisines[i]].push({ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodInfo[food].second;
        foodInfo[food].first = newRating;
        cuisineMap[cuisine].push({newRating, food});
    }
    
    string highestRated(string cuisine) {
        auto &pq = cuisineMap[cuisine];

        while(true) {
            auto top = pq.top();
            if(foodInfo[top.second].first == top.first)
                return top.second;
            pq.pop();
        }
    }
};