/*
 * Честно решал не сам. Не смог понять, что от меня хотел автор задачи.
 * Сумел понять в каких случаях Yes и No, но не понял, что именно
 * нужно было писать во второй строке =(
 */
#include <iostream>

int main() {
    using std::cin;
    using std::cout;
    using std::endl;

    std::uint32_t a, b;
    cin >> a >> b;

    if ((a % 2) || (!a && b % 2)) { cout << "No" << endl; }
    else {
        auto s = (a + 2*b) / 2;
        auto ans2 = std::min(s / 2, b);
        auto ans1 = s - 2 * ans2;
        cout << "Yes" << endl << ans1 << " " << ans2 << endl;
    }

    return 0;
}