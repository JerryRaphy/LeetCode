class Solution {
public:
    int findDelayedArrivalTime(int A, int D) {
        return (A + D) % 24;
    }
};