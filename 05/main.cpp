#include <iostream>

int main() {
    using std::cin;
    using std::cout;
    using std::endl;

    std::uint64_t n;
    cin >> n;

    while (n % 2 && n % 3 && n % 5) { n--; }

    cout << n << endl;

    return 0;
}