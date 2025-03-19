//weighted undirected graph having n vertices numbered from 1 to n and m edges
//edges[i]=[ai,bi,wi], represents an edge from vertex ai to bi with weight wi.
//Src=1 & Dest=n
//Return the shortest path between the vertex 1 and the vertex n and if path does not exist then return a list consisting of only -1. If there exists a path, then return a list whose first element is the weight of the path and the remaining elements represent the shortest path.

#define PII pair<int, int>
class Solution {
   public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges) {
        int dist[n + 1];
        int parent[n + 1];
        vector<PII> adj[n+1];
        vector<int> ans;
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        int x, node, wgt, adjNode, adjWgt, minDist;
        minDist=-1;

        for (x = 0; x <= n; ++x) {
          dist[x]=1e9;
          parent[x]=x;
        }
        for (x = 0; x < m; ++x) {
          adj[edges[x][0]].push_back({edges[x][2], edges[x][1]});
          adj[edges[x][1]].push_back({edges[x][2], edges[x][0]});
        }

        pq.push({0,1});
        dist[1]=0;

        while(!pq.empty()){
          node = pq.top().second;
          wgt=pq.top().first;
          pq.pop();

          if(node==n){
            minDist=wgt;
            break;
          }

          for(auto it:adj[node]){
            adjNode=it.second;
            adjWgt=it.first;
            if(dist[adjNode]>wgt+adjWgt){
              dist[adjNode]=wgt+adjWgt;
              pq.push({dist[adjNode], adjNode});
              parent[adjNode]=node;
            }
          }
        }

        if(minDist==-1){
          return {-1};
        }

        node=n;
        while(parent[node]!=node){
          ans.push_back(node);
          node=parent[node];
        }

        ans.push_back(1);
        ans.push_back(minDist);

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
