class Solution {
public:
    bool isValidSerialization(string preorder) {
        int slots = 1;  // Start with one slot for the root
        stringstream ss(preorder);
        string node;

        while (getline(ss, node, ',')) {
            // Use one slot for current node
            slots--;

            // If slots become negative → invalid
            if (slots < 0) return false;

            // Non-null nodes add two child slots
            if (node != "#")
                slots += 2;
        }

        // All slots should be used up
        return slots == 0;
    }
};
