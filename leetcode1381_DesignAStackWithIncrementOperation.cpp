class CustomStack {
public:
    CustomStack(int maxSize) {
        capacity = maxSize;
        arr = vector<int>(maxSize,0);
    }
    
    void push(int x) {
        if(stack.size() < capacity)
            stack.push_back(x);
    }
    
    int pop() {
        if(stack.empty())
            return -1;
        int inc = arr[stack.size() - 1];
        arr[stack.size() - 1] = 0;
        int val = stack.back() + inc;
        stack.pop_back();
        if(!stack.empty())
            arr[stack.size() - 1]+= inc;
        return val;
    }
    
    void increment(int k, int val) {
        if(stack.empty()) return;
        if(k > stack.size())
            k = stack.size();
        arr[k - 1]+= val;
    }
private:
    int capacity;
    vector<int> stack;
    vector<int> arr;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */