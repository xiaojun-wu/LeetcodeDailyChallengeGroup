class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        heap[start]++;
        heap[end]--;
        int k = 0,cur = 0;
        for(auto it = heap.begin();it != heap.end();it++){
            cur+= it->second;
            k = max(k,cur);
        }
        
        return k;
    }
private:
    map<int,int> heap;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */