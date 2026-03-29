class ZigzagIterator {
public:
bool turn;
vector<int>first;
vector<int>second;
int i,j,n,m;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        turn=true;
        first=v1,second=v2;
        i=0,j=0,n=v1.size(),m=v2.size();
    }

    int next() {
        if(i<n&&j<m){
            if(turn){
                i++;
                turn=false;
                return first[i-1];                
            }
            else{
                turn=true;
                return second[j++];
            }
        }
        if(i<n){
            return first[i++];
        }
        return second[j++];
    }

    bool hasNext() {
        if(i<n||j<m) return true;
        return false;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
