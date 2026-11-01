
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

        for(auto &account : accounts) {
            string name = account[0];

            for(int i = 1; i < account.size(); i++) {

                if(!emailToId.count(account[i])) {
                    emailToId[account[i]] = id++;
                    emailToName[account[i]] = name;
                }
            }
        }

        parent.resize(id);
        rank.assign(id, 0);

        for(int i = 0; i < id; i++) {
            parent[i] = i;
        }

        // Step 3: Union emails
        for(auto &account : accounts) {

            int firstEmailId = emailToId[account[1]];

            for(int i = 2; i < account.size(); i++) {
                int currentEmailId = emailToId[account[i]];

                unite(firstEmailId, currentEmailId);
            }
        }

        // Step 4: Group emails
        unordered_map<int, vector<string>> groups;

        for(auto &[email, emailId] : emailToId) {
            int root = find(emailId);
            groups[root].push_back(email);
        }

        // Step 5: Build answer
        vector<vector<string>> ans;

        for(auto &[root, emails] : groups) {

            sort(emails.begin(), emails.end());

            vector<string> mergedAccount;

            mergedAccount.push_back(emailToName[emails[0]]);

            for(auto &email : emails) {
                mergedAccount.push_back(email);
            }

            ans.push_back(mergedAccount);
        }

        return ans;
    }
};
