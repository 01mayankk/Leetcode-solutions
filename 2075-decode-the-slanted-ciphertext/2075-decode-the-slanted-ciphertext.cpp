class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {

        // If rows = 0, nothing to decode
        if (rows == 0) return "";

        // Total length of encoded string
        int n = encodedText.size();

        // Number of columns in the matrix
        // Since string is formed row-wise → total elements = rows * cols
        int cols = n / rows;

        // Final decoded string
        string result = "";

        // We start diagonal traversal from each column of first row
        for (int startCol = 0; startCol < cols; startCol++) {

            int i = 0;          // Start from first row
            int j = startCol;   // Start from current column

            // Traverse diagonally (down-right direction)
            while (i < rows && j < cols) {

                // Convert 2D index → 1D index
                // encodedText is stored row-wise
                // so index = row * cols + column
                result += encodedText[i * cols + j];

                // Move diagonally
                i++;
                j++;
            }
        }

        // Remove trailing spaces (important step)
        // Because extra spaces may be added while decoding
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }

        // Return final decoded message
        return result;
    }
};