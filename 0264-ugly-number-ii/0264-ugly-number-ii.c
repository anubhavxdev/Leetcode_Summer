int nthUglyNumber(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;

    int ugly[n];
    ugly[0] = 1;
    int count = 1;

    int i2 = 0, i3 = 0, i5 = 0;

    while (count < n) {
        int next2 = ugly[i2] * 2;
        int next3 = ugly[i3] * 3;
        int next5 = ugly[i5] * 5;

        int next_ugly = next2;
        if (next3 < next_ugly) next_ugly = next3;
        if (next5 < next_ugly) next_ugly = next5;

        ugly[count] = next_ugly;

        if (next_ugly == next2) i2++;
        if (next_ugly == next3) i3++;
        if (next_ugly == next5) i5++;

        count++;
    }

    return ugly[n - 1];
}
