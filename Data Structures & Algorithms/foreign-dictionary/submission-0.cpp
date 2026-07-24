class Solution {
public:
    string foreignDictionary(vector<string>& words) {

        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> indegree;

        // Initialize all characters
        for (string &word : words) {
            for (char c : word) {
                indegree[c] = 0;
            }
        }

        // Build graph
        for (int i = 0; i < words.size() - 1; i++) {

            string &w1 = words[i];
            string &w2 = words[i + 1];

            int len = min(w1.size(), w2.size());
            int j = 0;

            while (j < len && w1[j] == w2[j])
                j++;

            // Invalid case
            if (j == len) {
                if (w1.size() > w2.size())
                    return "";
                continue;
            }

            char u = w1[j];
            char v = w2[j];

            if (!graph[u].count(v)) {
                graph[u].insert(v);
                indegree[v]++;
            }
        }

        queue<char> q;

        for (auto &it : indegree) {
            if (it.second == 0)
                q.push(it.first);
        }

        string ans;

        while (!q.empty()) {

            char node = q.front();
            q.pop();

            ans += node;

            for (char nei : graph[node]) {

                indegree[nei]--;

                if (indegree[nei] == 0)
                    q.push(nei);
            }
        }

        if (ans.size() != indegree.size())
            return "";

        return ans;
    }
};
