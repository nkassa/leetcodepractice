class TimeMap {
public:
    unordered_map<string, vector<pair<int,string>>> count;
    TimeMap() {  
    }
    
    void set(string key, string value, int timestamp) {
        count[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) 
    {
        int left = 0; 
        int right = count[key].size()-1;
        while(left <= right)
        {
            int mid = left + ((right-left)/2);
            if(count[key][mid].first == timestamp)
            {
                return count[key][mid].second;
            }
            else if(count[key][mid].first < timestamp)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        if(right >= 0)
        {
            return count[key][right].second;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */