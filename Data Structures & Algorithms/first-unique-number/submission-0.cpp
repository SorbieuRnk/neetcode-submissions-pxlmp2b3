class FirstUnique {
public:
queue<int>q;
unordered_map<int,int>freq;
    FirstUnique(vector<int>& nums) {
     for(int i=0;i<nums.size();i++){
        freq[nums[i]]++;
        if(freq[nums[i]]>1) continue;
        else{
            q.push(nums[i]);
        }
     }
    }
    
    int showFirstUnique() {
      while(!q.empty()&&freq[q.front()]>1){
        q.pop();
      }  
      if(q.empty()) return -1;
      return q.front();
    }
    
    void add(int value) {
        freq[value]++;
        if(freq[value]==1){
            q.push(value);
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
