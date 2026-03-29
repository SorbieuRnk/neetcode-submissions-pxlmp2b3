class HitCounter {
public:
 unordered_map<int,int>hits;
    HitCounter() {
       
    }
    
    void hit(int timestamp) {
        hits[timestamp]++;
    }
    
    int getHits(int timestamp) {
        int total=0;
        for(int i=timestamp;i>=max(0,timestamp-299);i--){
            total+=hits[i];
        }
        return total;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
