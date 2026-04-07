class Robot {
private:
    int w, h;          // width and height of the grid
    int perimeter;     // total number of cells on the boundary path
    int pos;           // current position index along the boundary (0 to perimeter-1)
    bool moved;        // tracks whether robot has moved at least once

public:
    Robot(int width, int height) {
        w = width;
        h = height;

        // Total boundary length (excluding repeated corner cells)
        perimeter = 2 * (w + h) - 4;

        pos = 0;       // start at bottom-left corner (0,0)
        moved = false; // robot hasn't moved yet
    }
    
    void step(int num) {
        // Move robot forward along boundary using modulo
        // This avoids unnecessary simulation for large steps
        pos = (pos + num) % perimeter;

        // Mark that robot has moved at least once
        if (num > 0) moved = true;
    }
    
    vector<int> getPos() {
        int x, y;

        // The boundary is divided into 4 segments:
        // 1. Bottom edge → moving right
        // 2. Right edge → moving up
        // 3. Top edge → moving left
        // 4. Left edge → moving down

        // Case 1: Bottom edge (0,0) → (w-1,0)
        if (pos < w) {
            x = pos;
            y = 0;
        }
        // Case 2: Right edge (w-1,1) → (w-1,h-1)
        else if (pos < w + h - 1) {
            x = w - 1;
            y = pos - (w - 1);
        }
        // Case 3: Top edge (w-2,h-1) → (0,h-1)
        else if (pos < 2 * w + h - 2) {
            x = (w - 1) - (pos - (w + h - 2));
            y = h - 1;
        }
        // Case 4: Left edge (0,h-2) → (0,1)
        else {
            x = 0;
            y = (h - 1) - (pos - (2 * w + h - 3));
        }

        return {x, y};
    }
    
    string getDir() {

        // Special edge case:
        // If position is 0:
        // - Before any movement → direction is "East"
        // - After completing a full cycle → direction becomes "South"
        if (pos == 0) {
            return moved ? "South" : "East";
        }

        // Direction depends on which boundary segment we are on

        // Bottom edge → moving right
        if (pos < w)
            return "East";

        // Right edge → moving up
        else if (pos < w + h - 1)
            return "North";

        // Top edge → moving left
        else if (pos < 2 * w + h - 2)
            return "West";

        // Left edge → moving down
        else
            return "South";
    }
};