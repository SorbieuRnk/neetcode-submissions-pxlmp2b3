class Leaderboard {
public:
unordered_map<int,int>records;
priority_queue<pair<int,int>>pq;
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        records[playerId]+=score;
        pq.push({records[playerId],playerId});
    }
    
    int top(int K) {
        vector<pair<int,int>>v;
        int total=0;
        while(K>0){
            auto [sc,id]=pq.top();
            pq.pop();
        if(records[id]==sc){
          total+=sc;
          v.push_back({sc,id});
          K--;
        }
        }
        for(auto &i:v){
            pq.push(i);
        }
        return total;
    }
    
    void reset(int playerId) {
         records[playerId]=0;
         pq.push({0,playerId});
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
