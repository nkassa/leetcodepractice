class MedianFinder {
public:
    vector<int> list;
    MedianFinder() {
    }
    
    void addNum(int num) {
        list.push_back(num);
    }
    
    double findMedian() 
    {
        sort(list.begin(), list.end());
        if(list.size() % 2 != 0)
        {
            int n = list.size()/2;
            return list[n];
        }
        int n = list.size()/2;
        return (double)(list[n]+list[n-1])/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */