class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char, int> freqMap;

        
        for (char ch : s) {
            freqMap[ch]++;
        }

        
        priority_queue<pair<int, char>> pq;

        for (auto& entry : freqMap) {
            pq.push({entry.second, entry.first});  
        }

        
        string result = "";
        while (!pq.empty()) {
            auto [freq, ch] = pq.top();
            pq.pop();
            result += string(freq, ch);  
        }

        return result;
    }
};