class SegmentTree {
public:

    // Maximum coordinate limit
    int size;

    // Segment Tree
    // Stores maximum gap value in a range
    vector<int> segmentTree;

    SegmentTree(int n) {
        size = n;
        segmentTree.resize(4 * size, 0);
    }

    //------------------------------------------------------------------
    // Update the value at a specific index
    //------------------------------------------------------------------
    void update(int node,
                int start,
                int end,
                int index,
                int value) {

        // Leaf node reached
        // Update the gap value
        if (start == end) {
            segmentTree[node] = value;
            return;
        }

        int mid = (start + end) / 2;

        // If target index lies in left half
        if (index <= mid) {
            update(
                node * 2,
                start,
                mid,
                index,
                value
            );
        }
        // Otherwise go to right half
        else {
            update(
                node * 2 + 1,
                mid + 1,
                end,
                index,
                value
            );
        }

        // Recompute maximum value for current segment
        segmentTree[node] =
            max(
                segmentTree[node * 2],
                segmentTree[node * 2 + 1]
            );
    }

    //------------------------------------------------------------------
    // Return maximum gap in range [left, right]
    //------------------------------------------------------------------
    int query(int node,
              int start,
              int end,
              int left,
              int right) {

        // No overlap
        //
        // Current segment:
        // start -------- end
        //
        // Query segment:
        // left ----- right
        if (right < start || end < left) {
            return 0;
        }

        // Complete overlap
        //
        // Current segment completely lies
        // inside query range
        if (left <= start && end <= right) {
            return segmentTree[node];
        }

        int mid = (start + end) / 2;

        // Search both halves and return maximum
        return max(
            query(
                node * 2,
                start,
                mid,
                left,
                right
            ),
            query(
                node * 2 + 1,
                mid + 1,
                end,
                left,
                right
            )
        );
    }
};

class Solution {
public:

    vector<bool> getResults(vector<vector<int>>& queries) {

        //--------------------------------------------------------------
        // Maximum coordinate value according to constraints
        //--------------------------------------------------------------
        int maximumCoordinate = 50000;

        //--------------------------------------------------------------
        // Stores all obstacle positions in sorted order
        //
        // Example:
        // {0, 4, 10, 20, 50000}
        //--------------------------------------------------------------
        set<int> obstaclePositions;

        // Add left boundary obstacle
        obstaclePositions.insert(0);

        // Add right boundary obstacle
        obstaclePositions.insert(maximumCoordinate);

        //--------------------------------------------------------------
        // Segment Tree Idea:
        //
        // For every obstacle position X,
        // store:
        //
        // X - previousObstacle
        //
        // Meaning:
        // Length of free interval ending at X.
        //
        // Example:
        //
        // Obstacles:
        // 0 ---- 4 ---- 10 ---- 20
        //
        // Stored values:
        // index 4  -> 4
        // index 10 -> 6
        // index 20 -> 10
        //
        //--------------------------------------------------------------
        SegmentTree segmentTree(maximumCoordinate + 1);

        //--------------------------------------------------------------
        // Initially obstacles are:
        //
        // 0 ----------------------- 50000
        //
        // One giant free gap exists.
        //
        // Gap ending at 50000 = 50000
        //--------------------------------------------------------------
        segmentTree.update(
            1,
            0,
            maximumCoordinate,
            maximumCoordinate,
            maximumCoordinate
        );

        vector<bool> result;

        //------------------------------------------------------------------
        // Process every query
        //------------------------------------------------------------------
        for (auto& query : queries) {

            //--------------------------------------------------------------
            // TYPE 1 QUERY
            //
            // [1, x]
            //
            // Add obstacle at position x
            //--------------------------------------------------------------
            if (query[0] == 1) {

                int obstaclePosition = query[1];

                //----------------------------------------------------------
                // Find obstacle immediately on the right
                //
                // Example:
                // Obstacles:
                // {0,4,10,20}
                //
                // Insert 7
                //
                // nextObstacle = 10
                //----------------------------------------------------------
                auto rightObstacleIterator =
                    obstaclePositions.lower_bound(obstaclePosition);

                int nextObstacle = *rightObstacleIterator;

                //----------------------------------------------------------
                // Find obstacle immediately on the left
                //
                // previousObstacle = 4
                //----------------------------------------------------------
                int previousObstacle =
                    *prev(rightObstacleIterator);

                //----------------------------------------------------------
                // Insert new obstacle
                //----------------------------------------------------------
                obstaclePositions.insert(obstaclePosition);

                //----------------------------------------------------------
                // Before insertion:
                //
                // previousObstacle -------- nextObstacle
                //
                // Example:
                // 4 ----------------------- 10
                //
                // Gap length = 6
                //
                //----------------------------------------------------------

                //----------------------------------------------------------
                // After insertion:
                //
                // 4 -------- 7 -------- 10
                //
                // Left gap = 3
                // Right gap = 3
                //
                // Store left gap at index 7
                //----------------------------------------------------------
                segmentTree.update(
                    1,
                    0,
                    maximumCoordinate,
                    obstaclePosition,
                    obstaclePosition - previousObstacle
                );

                //----------------------------------------------------------
                // Store right gap at index nextObstacle
                //----------------------------------------------------------
                segmentTree.update(
                    1,
                    0,
                    maximumCoordinate,
                    nextObstacle,
                    nextObstacle - obstaclePosition
                );
            }

            //--------------------------------------------------------------
            // TYPE 2 QUERY
            //
            // [2, x, size]
            //
            // Check if a block of length "size"
            // can fit completely inside [0, x]
            //--------------------------------------------------------------
            else {

                int position = query[1];
                int requiredSize = query[2];

                //----------------------------------------------------------
                // Find first obstacle strictly greater than x
                //
                // Example:
                // Obstacles:
                // {0,4,10,20}
                //
                // x = 15
                //
                // upper_bound(15) -> 20
                //----------------------------------------------------------
                auto iterator =
                    obstaclePositions.upper_bound(position);

                //----------------------------------------------------------
                // Obstacle immediately before x
                //
                // previousObstacle = 10
                //----------------------------------------------------------
                int previousObstacle =
                    *prev(iterator);

                //----------------------------------------------------------
                // Query maximum complete gap that ends
                // at or before previousObstacle
                //
                // Example:
                //
                // 0 --- 4 ----- 10 ---------- 20
                //
                // Maximum full gap before 10
                //----------------------------------------------------------
                int maximumGap =
                    segmentTree.query(
                        1,
                        0,
                        maximumCoordinate,
                        0,
                        previousObstacle
                    );

                //----------------------------------------------------------
                // There may be a partially usable gap:
                //
                // previousObstacle -------- position
                //
                // Example:
                // 10 ----------- 15
                //
                // Length = 5
                //
                // Since position may lie inside a gap,
                // we must also consider this segment.
                //----------------------------------------------------------
                maximumGap =
                    max(
                        maximumGap,
                        position - previousObstacle
                    );

                //----------------------------------------------------------
                // If any available gap is at least requiredSize,
                // answer is true.
                //----------------------------------------------------------
                result.push_back(
                    maximumGap >= requiredSize
                );
            }
        }

        return result;
    }
};