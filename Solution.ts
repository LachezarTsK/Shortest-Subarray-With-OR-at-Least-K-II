
function minimumSubarrayLength(input: number[], target: number): number {
    const NOT_POSSIBLE_TO_CREATE_SUBARRAY = -1;
    this.TOTAL_BITS = 32;
    this.bits = new Array<number>(this.TOTAL_BITS).fill(0);
    this.valueBitwiseOR = 0;

    let left = 0;
    let right = 0;
    let minLengthSubarray = Number.MAX_SAFE_INTEGER;

    while (right < input.length) {
        countBits(input[right]);

        while (left <= right && this.valueBitwiseOR >= target) {
            minLengthSubarray = Math.min(minLengthSubarray, right - left + 1);
            discountBits(input[left]);
            ++left;
        }
        ++right;
    }
    return (minLengthSubarray !== Number.MAX_SAFE_INTEGER)
        ? minLengthSubarray
        : NOT_POSSIBLE_TO_CREATE_SUBARRAY;
};

function countBits(value: number): void {
    this.valueBitwiseOR = (this.valueBitwiseOR | value);
    for (let bitPosition = 0; bitPosition < this.TOTAL_BITS; ++bitPosition) {
        this.bits[bitPosition] += ((value & (1 << bitPosition)) !== 0) ? 1 : 0;
    }
}

function discountBits(value: number): void {
    for (let bitPosition = 0; bitPosition < this.TOTAL_BITS; ++bitPosition) {
        this.bits[bitPosition] -= ((value & (1 << bitPosition)) !== 0) ? 1 : 0;
        if (this.bits[bitPosition] === 0) {
            this.valueBitwiseOR = (this.valueBitwiseOR & (~(1 << bitPosition)));
        }
    }
}
