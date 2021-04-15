class SnapshotArray {
public:
    SnapshotArray(int length) {
        snapid = 0;
        arr = vector<vector<pair<int,int>>>(length,vector<pair<int,int>>(1,{0,0}));
    }
    
    void set(int index, int val) {
        if(arr[index].back().second != val){
            if(arr[index].back().first == snapid)
                arr[index].back().second = val;
            else
                arr[index].emplace_back(snapid,val);
        }
    }
    
    int snap() {
        return snapid++;
    }
    
    int get(int index, int snap_id) {
        int left = 0,right = arr[index].size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(arr[index][mid].first > snap_id)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return arr[index][right].second;
    }
private:
    int snapid;
    vector<vector<pair<int,int>>> arr;
};