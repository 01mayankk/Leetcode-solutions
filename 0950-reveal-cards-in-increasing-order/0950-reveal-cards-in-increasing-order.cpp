class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {

        deque<int>dq;

        sort(deck.begin(), deck.end());

        for(int i = deck.size() - 1; i >= 0; i--)
            {
                dq.push_front(deck[i]);
                if(i != 0 && !dq.empty())
                {
                    int hold = dq.back();
                    dq.pop_back();
                    dq.push_front(hold);
                }
            }
        return vector<int>(dq.begin(), dq.end());
    }
};