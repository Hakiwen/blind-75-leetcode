class Solution {
public:
    using twoVec = vector<vector<int> >;
    
    
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        size_t numEdges = prerequisites.size();
        
        pair<twoVec, vector<int> > graph = this->convertEdge2AdjList(numCourses, prerequisites);
        
        twoVec adjList = graph.first;
        vector<int> degree = graph.second;
        
        queue<int> zeroInDegree;
        
        for(int i =0; i< numCourses;++i){
            if (!degree[i]) 
                zeroInDegree.push(i);
        }
        
        size_t nodesUnPealed = numCourses;
        while(!zeroInDegree.empty()){
            int currentRoot = zeroInDegree.front();
            zeroInDegree.pop();
            --nodesUnPealed;
            
            for(auto next : adjList[currentRoot]){
                if(--degree[next] == 0){
                    zeroInDegree.push(next);
                }
            }
            
        }
        return nodesUnPealed == 0;
        
        
    }
private:
    pair<twoVec, vector<int>> convertEdge2AdjList(int vertices, twoVec& edges){
        twoVec ret (vertices);
        vector<int> deg (vertices);
        for(int i = 0;i<edges.size();++i){
            int outNode = edges[i][0];
            int inNode = edges[i][1];
            ret[inNode].push_back(outNode);
            ++deg[outNode];
        }
        return pair<twoVec, vector<int> > (ret, deg);
    }
};
