class Solution {
public:

    int calculateAvg(vector<vector<int>>& img, int i, int j, int row, int col)
    {
        int sum = 0;
        int count = 0;

        
        for(int r = i - 1; r <= i + 1; r++)
        {
            for(int c = j - 1; c <= j + 1; c++)
            {
                
                if(r >= 0 && r < row && c >= 0 && c < col)
                {
                    sum += img[r][c];
                    count++;
                }
            }
        }

        
        return sum / count;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        
        int n = img.size();
        int m = img[0].size();

        vector<vector<int>>result(n, vector<int>(m));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int val ;
                val = calculateAvg(img, i, j, n, m );

                result[i][j] = val;
            }
        }


        return result;



    }
};