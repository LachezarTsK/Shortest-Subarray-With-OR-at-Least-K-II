
#include <array>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

class Solution {

    static const int NOT_POSSIBLE_TO_CREATE_SUBARRAY = -1;
    static const int TOTAL_BITS = 32;
    array<int, TOTAL_BITS> bits{};
    int valueBitwiseOR = 0;

public:
    int minimumSubarrayLength(const vector<int>& input, int target) {
        int left = 0;
        int right = 0;
        int minLengthSubarray = numeric_limits<int>::max();

        while (right < input.size()) {
            countBits(input[right]);

            while (left <= right && valueBitwiseOR >= target) {
                minLengthSubarray = min(minLengthSubarray, right - left + 1);
                discountBits(input[left]);
                ++left;
            }
            ++right;
    }
        return (minLengthSubarray != numeric_limits<int>::max())
                ? minLengthSubarray
                : NOT_POSSIBLE_TO_CREATE_SUBARRAY;
    }

private:
    void countBits(int value) {
        valueBitwiseOR = (valueBitwiseOR | value);
        for (int bitPosition = 0; bitPosition < TOTAL_BITS; ++bitPosition) {
            bits[bitPosition] += ((value & (1 << bitPosition)) != 0) ? 1 : 0;
        }
    }

    void discountBits(int value) {
        for (int bitPosition = 0; bitPosition < TOTAL_BITS; ++bitPosition) {
            bits[bitPosition] -= ((value & (1 << bitPosition)) != 0) ? 1 : 0;
            if (bits[bitPosition] == 0) {
                valueBitwiseOR = (valueBitwiseOR & (~(1 << bitPosition)));
            }
        }
    }
};
