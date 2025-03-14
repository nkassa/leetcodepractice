class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> store;
    TimeMap() {  
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back(pair(timestamp,value));
    }
    
    string get(string key, int timestamp) 
    {
        vector<pair<int, string>>& numStr = store[key];
        string ans;
        int left = 0;
        int right = numStr.size()-1;
        while(left <= right)
        {
            int mid = left + ((right-left)/2);
            if(numStr[mid].first <= timestamp)
            {
                ans = numStr[mid].second;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */