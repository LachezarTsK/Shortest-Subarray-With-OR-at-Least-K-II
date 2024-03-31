
public class Solution {

    private static final int NOT_POSSIBLE_TO_CREATE_SUBARRAY = -1;
    private static final int TOTAL_BITS = 32;
    private final int[] bits = new int[TOTAL_BITS];
    private int valueBitwiseOR;

    public int minimumSubarrayLength(int[] input, int target) {
        int left = 0;
        int right = 0;
        int minLengthSubarray = Integer.MAX_VALUE;

        while (right < input.length) {
            countBits(input[right]);

            while (left <= right && valueBitwiseOR >= target) {
                minLengthSubarray = Math.min(minLengthSubarray, right - left + 1);
                discountBits(input[left]);
                ++left;
            }
            ++right;
        }
        return (minLengthSubarray != Integer.MAX_VALUE)
                ? minLengthSubarray
                : NOT_POSSIBLE_TO_CREATE_SUBARRAY;
    }

    private void countBits(int value) {
        valueBitwiseOR = (valueBitwiseOR | value);
        for (int bitPosition = 0; bitPosition < TOTAL_BITS; ++bitPosition) {
            bits[bitPosition] += ((value & (1 << bitPosition)) != 0) ? 1 : 0;
        }
    }

    private void discountBits(int value) {
        for (int bitPosition = 0; bitPosition < TOTAL_BITS; ++bitPosition) {
            bits[bitPosition] -= ((value & (1 << bitPosition)) != 0) ? 1 : 0;
            if (bits[bitPosition] == 0) {
                valueBitwiseOR = (valueBitwiseOR & (~(1 << bitPosition)));
            }
        }
    }
}
