class TimeMap {
public:
    unorered_map<string, vector<pair<int,string>>> count;
    TimeMap() {  
    }
    
    void set(string key, string value, int timestamp) {
        count[key].push_back({timestanp, value}));
    }
    
    string get(string key, int timestamp) 
    {
        vector<pair<int,string>> list;
        list = count[key];
        int left = 0; 
        int right = list.size()-1;
        while(left <= right)
        {
            int mid = left + (right-left)/2;
            if(list[mid].second <= timestamp)
            [
                left = mid + 1;
            ]
            else
            {
                right = mid - 1;
            }
        }
        return count[key]
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */