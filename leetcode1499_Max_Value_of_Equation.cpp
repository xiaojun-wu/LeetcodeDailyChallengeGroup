class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        const int SIZE = points.size();
        int res = INT_MIN;
        deque<pair<int,int>> q;
        q.emplace_back(points[0][0],points[0][1]);
        
        for(int i = 1;i < SIZE;i++){
            while(!q.empty() && points[i][0] - q.front().first > k)
                q.pop_front();
            if(!q.empty())
                res = max(res,points[i][0] + points[i][1] + q.front().second - q.front().first);
            while(!q.empty() && points[i][1] - q.back().second >= points[i][0] - q.back().first)
                q.pop_back();
            q.emplace_back(points[i][0],points[i][1]);
        }
        
        return res;
    }
};
/*
if |xi - xj| <= yj - yi, pop the i-th element from queue.
Why it works?
Because if there is a element k, and |xi - xk| == k, than |xj - xk| < k,
both pair {i,k} and {j,k} are valid candinates.
and (yi + yk + |xi - xk|) < (yj + yk + |xj - xk|).
xk > xj > xi, so |xi - xk| - |xj - xk| == xk - xi - xk + xj == xj - xi
and we know yj - yi >= |xi - xj| == xj - xi.
So the pair{i,k} isn't larger than pair{j,k}.
In all valid elment k in this array, pair{j,k} will not less than pair{i,k}.
We can keep element j instead of i.
So pop i.
*/

// https://tinyurl.com/hh2jxp9m