class SnakeGame {
public:
struct PairHash {
    std::size_t operator()(const std::pair<int, int>& p) const {
        return std::hash<int>{}(p.first) ^ std::hash<int>{}(p.second);
    }
};
int food_no;
queue<pair<int,int>>path;
unordered_set<pair<int,int>,PairHash>st;
vector<vector<int>>location;
int n,m;
int row,col;
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        n=height,m=width;
        for(int i=0;i<food.size();i++){
            location.push_back(food[i]);
        }
        path.push({0,0});
        st.insert({0,0});
        food_no=0;
        row=0,col=0;
    }
    
    int move(string direction) {
        // up
        if(direction=="U") row--;
        // down
        else if(direction=="D")row++;
        // left
        else if(direction=="L")col--;
        // right
        else col++;

        bool food=false;
        if(row<0||row>=n||col<0||col>=m) return -1;

        if(food_no<location.size() &&location[food_no][0]==row&&location[food_no][1]==col)food=true;
        
      
          if (!food) {
        st.erase(path.front());
        path.pop();
    }
        if(st.count({row,col})!=0) return -1;
 st.insert({row,col});
 path.push({row,col});
 if(food) food_no++;
  return food_no;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
