class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        queue<int> queue;
        for(vector<int> pre: prerequisites)
        {
            indegree[pre[0]]++;
            adj[pre[1]].push_back(pre[0]);
        }
        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0)
            {
                queue.push(i);
            }
        }
        int count = 0;
        while(!queue.empty())
        {
            int course = queue.front();
            queue.pop();
            count++;
            for(int newCourse: adj[course])
            {
                indegree[newCourse]--;
                if(indegree[newCourse] == 0)
                {
                    queue.push(newCourse);
                }
            }
        }
        return count == numCourses;
    }
};