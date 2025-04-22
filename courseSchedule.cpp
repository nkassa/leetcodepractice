class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        int n = prerequisites.size();
        vector<vector<int>> list(numCourses);
        vector<int> indegree(numCourses, 0);
        for(vector<int> pre: prerequisites)
        {
            list[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        queue<int> queue;
        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0)
            {
                queue.push(i);
            }
        }
        int cnt = 0;
        while(!queue.empty())
        {
            int in = queue.front();
            queue.pop();
            cnt++;
            for(int course: list[in])
            {
                indegree[course]--;
                if(indegree[course] == 0)
                {
                    queue.push(course);
                }
            }
        }
        return cnt == numCourses;
    }
};