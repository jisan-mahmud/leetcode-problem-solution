
class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if(parent[x] == x) return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if(rootA == rootB) return;

        if(rank[rootA] < rank[rootB]) {
            parent[rootA] = rootB;
        }
        else if(rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA;
        }
        else {
            parent[rootB] = rootA;
            rank[rootA]++;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> emailToId;
        unordered_map<string, string> emailToName;

        int id = 0;

        for(auto &account:accounts){
            string name = account[0];
            for(int i = 1; i < account.size(); i++){
                emailToId[account[i]] = id++;
                emailToName[account[i]] = name;
            }
        }

        parent.resize(id);
        rank.assign(id, 0);

        for(int i = 0; i < id; i++){
            parent[i] = i;
        }

        for(auto &account : accounts){
            int firstEmailId = emailToId[account[1]];
            
            for(int i = 2; i < account.size(); i++){
                int currentEmailId = emailToId[account[i]];

                unite(firstEmailId, currentEmailId);
            }

        }

        unordered_map<int, vector<string>> groups;

        for(auto &[email, id] : emailToId){
            int root = find(id);
            groups[root].push_back(email);
        }

        vector<vector<string>> ans;

        for(auto &[root, emails] : groups){
            sort(emails.begin(), emails.end());

            vector<string> mergedAccount;

            string name = emailToName[emails[0]];
            mergedAccount.push_back(name);
            mergedAccount.insert(mergedAccount.end(), emails.begin(), emails.end());

            ans.push_back(mergedAccount);
        }

        return ans;

    }
};
