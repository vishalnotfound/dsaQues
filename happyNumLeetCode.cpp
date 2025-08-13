class Solution {
public:
    bool isHappy(int n) {
    unordered_set<int> seen;

    while (n != 1 && !seen.count(n)) {
        seen.insert(n);

        int next = 0, temp = n;
        while (temp) {
            int d = temp % 10;
            next += d * d;
            temp /= 10;
        }

        n = next;
    }

    return n == 1;
}

};
