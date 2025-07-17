class Solution {
public:
    // Binary search to count number of 1s in a row
    int binarySearch(const vector<int>& row, int rowSize) {
        int start = 0;
        int end = rowSize - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (row[mid] == 1) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return start; // Number of 1s
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        // Min-heap using pair: {soldier_count, row_index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
        
        int rowSize = mat[0].size();  // number of columns in each row
        for (int i = 0; i < mat.size(); i++) {
            int count = binarySearch(mat[i], rowSize);
            minheap.push({count, i}); // push into min-heap
        }

        vector<int> result;
        while (k-- && !minheap.empty()) {
            result.push_back(minheap.top().second);
            minheap.pop();
        }

        return result;
    }
};
