class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        int n = prerequisites.size();
        vector<int> in_degree(numCourses, 0);
        for(int i = 0; i < n; i++)
        {
            in_degree[prerequisites[i][0]]++;
        }
        queue<int> queue;
        for(int i = 0; i < numCourses; i++)
        {
            if(in_degree[i] == 0)
            {
                queue.push(i);
            }
        }
        int idx = 0;
        while(!queue.empty())
        {
            idx++;
            int in = queue.front();
            queue.pop();
            for(int i = 0; i < n; i++)
            {
                if(prerequisites[i][1] == in)
                {
                    in_degree[prerequisites[i][0]]--;
                    if(in_degree[prerequisites[i][0]] == 0)
                    {
                        queue.push(prerequisites[i][0]);
                    }
                }
            }
        }
        if(idx  != numCourses)
        {
            return false;
        }
        return true;
    }
};