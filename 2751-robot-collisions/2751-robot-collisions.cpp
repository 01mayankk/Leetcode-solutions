class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, 
                                      vector<int>& healths, 
                                      string directions) {
        
        int n = positions.size();
        
        // Step 1: Store robots with their original index
        vector<tuple<int,int,char,int>> robots;
        
        for(int i = 0; i < n; i++) {
            robots.push_back({positions[i], healths[i], directions[i], i});
        }
        
        // Step 2: Sort robots based on position
        sort(robots.begin(), robots.end());
        
        // Stack to keep indices of robots moving right
        stack<int> st;
        
        // Result array (initialize with original healths)
        vector<int> result(n);
        for(int i = 0; i < n; i++) {
            result[i] = healths[i];
        }
        
        // Step 3: Traverse robots
        for(int i = 0; i < n; i++) {
            auto [pos, health, dir, idx] = robots[i];
            
            // Case 1: If robot moving right → push into stack
            if(dir == 'R') {
                st.push(i);
            }
            // Case 2: If robot moving left → collision possible
            else {
                while(!st.empty()) {
                    int topIdx = st.top();
                    auto &[p2, h2, d2, idx2] = robots[topIdx];
                    
                    // If top robot already dead → pop
                    if(result[idx2] == 0) {
                        st.pop();
                        continue;
                    }
                    
                    // Collision happens
                    if(result[idx2] < result[idx]) {
                        // Right robot dies
                        result[idx2] = 0;
                        st.pop();
                        
                        // Left robot loses 1 health
                        result[idx]--;
                    }
                    else if(result[idx2] > result[idx]) {
                        // Left robot dies
                        result[idx] = 0;
                        
                        // Right robot loses 1 health
                        result[idx2]--;
                        break;
                    }
                    else {
                        // Both die
                        result[idx] = 0;
                        result[idx2] = 0;
                        st.pop();
                        break;
                    }
                }
            }
        }
        
        // Step 4: Collect surviving robots in original order
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(result[i] > 0) {
                ans.push_back(result[i]);
            }
        }
        
        return ans;
    }
};