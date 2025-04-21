class Solution {
public:
    #define ll long long
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        ll l = lower, r = upper, n = differences.size();
        ll templ = lower + differences[n - 1],
                  tempr = upper + differences[n - 1];
        if((templ<lower || templ>upper) && (tempr<lower || tempr>upper)) return 0;
        l = max(l, templ), r = min(r, tempr);
        for (int i = n - 1; i >= 0; i--) {
            if ((r - differences[i] > upper || r - differences[i] < lower) &&
                (l - differences[i] < lower || l - differences[i] > upper))
                return 0;
            l = max(l - differences[i], (ll)lower);
            r = min(r - differences[i], (ll)upper);
        }
        return r - l + 1;
    }
};