class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // graph problem.
        const int SIZE = prerequisites.size();
        vector<vector<int>> adjacents(numCourses,vector<int>());
        vector<int> indegree(numCourses,0);
        deque<int> q;
        int taken = 0;
        
        for(vector<int>& p : prerequisites){
            adjacents[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        
        for(int i = 0;i < numCourses;i++)
            if(indegree[i] == 0)
                q.push_back(i);
        
        while(!q.empty()){
            taken+= q.size();
            for(int i = q.size();i > 0;i--){
                int node = q.front();
                q.pop_front();
                for(int nei : adjacents[node]){
                    indegree[nei]--;
                    if(indegree[nei] == 0)
                        q.push_back(nei);
                }
            }
        }
        
        return taken == numCourses;
    }
};
/*
pre = [a,b] means take b first, than a.
prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
method 1: topological sort.

we take the courses with no prerequisites.
Input: numCourses = 2, prerequisites = [[1,0]]
0 -> 1
courses with no pre : 0
courses with no pre : 
*/

// https://tinyurl.com/p38vuhzx