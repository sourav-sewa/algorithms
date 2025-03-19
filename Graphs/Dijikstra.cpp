//weighted, undirected graph of V vertices, numbered from 0 to V-1
//adj[i] = [node,weight]
//S = Source node
//Return a list of integers denoting shortest distance between each node and source vertex S. If a vertex is not reachable from source then its distance will be 1e9

#define PII pair<int, int>
class Solution {
   public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        vector<int> dist(V, 1e9);
        priority_queue<PII, vector<PII>, greater<PII>> pq;  //{dist, node} minheap
        int x, y, node, wgt, adjNode, adjWgt;

        dist[S] = 0;
        pq.emplace(0, S);

        while (!pq.empty()) {
            wgt = pq.top().first;
            node = pq.top().second;
            pq.pop();

            for (auto it : adj[node]) {
                adjWgt = it[1];
                adjNode = it[0];
                if (dist[adjNode] > wgt + adjWgt) {
                    dist[adjNode] = wgt + adjWgt;
                    pq.emplace(dist[adjNode], adjNode);
                }
            }
        }

        return dist;
    }
};
