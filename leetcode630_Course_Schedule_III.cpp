class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        const int SIZE = courses.size();
        priority_queue<int> pq;
        int curTime = 0;
        
        sort(courses.begin(),courses.end(),[](auto& lhs,auto& rhs){
            return lhs[1] < rhs[1];
        });
        
        for(vector<int>& c : courses){
            if(c[0] > c[1]) continue;
            curTime+= c[0];
            pq.push(c[0]);
            if(curTime > c[1]){
                curTime-= pq.top();
                pq.pop();
            }
        }
        
        return pq.size();
    }
};

// https://tinyurl.com/tvuasn5e