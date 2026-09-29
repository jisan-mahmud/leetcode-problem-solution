class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> graph(n);

        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double rate = succProb[i];

            graph[u].push_back({v, rate});
            graph[v].push_back({u, rate});
        }

        vector<double> prob(n, 0);
        prob[start_node] = 1;

        priority_queue<pair<double, int>> pq;
        pq.push({1, start_node});

        while(!pq.empty()){
            auto [rate, node] = pq.top();
            pq.pop();


            for(auto childPair : graph[node]){
                auto [childNode, childRate] = childPair;

                double currentProb = rate * childRate;
                if(prob[childNode] < currentProb){
                    prob[childNode] = currentProb;
                    pq.push({currentProb, childNode});
                }
            }

        }

        return prob[end_node];
    }
};