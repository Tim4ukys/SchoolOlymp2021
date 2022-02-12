#include <iostream>

int main() {
    using std::cin;
    using std::cout;
    using std::endl;

    std::uint64_t n, ans = 1, x2 = 1, x3, x5;
    cin >> n;

    while (x2 <= n) {
        x3 = x2;
        while (x3 <= n) {
            x5 = x3;
            while (x5 <= n)
            {
                ans = std::max(ans, x5);
                x5 *= 5;
            }
            x3 *= 3;
        }
        x2 *= 2;
    }


    cout << ans << endl;

    return 0;
}