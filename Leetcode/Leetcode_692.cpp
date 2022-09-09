// 前K个高频单词
struct Compare {
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
    return (a.first > b.first || (a.first == b.first && a.second < b.second));
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        unordered_map<string, int> wordFrequent;
        for (auto& word: words) ++wordFrequent[word];
        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> q;
        for (auto& word: wordFrequent) 
        {
            pair<int, string> temp(word.second, word.first);
            q.push(temp);
            if (q.size() > k) {
                q.pop();
            }
        }
        while (!q.empty()) {
            res.emplace_back(q.top().second);
            q.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};