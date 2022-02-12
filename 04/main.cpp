#include <iostream>
#include <vector>

/* Типа макет доски
 *
 *    1 2 3 4 5 6 7 8
 *   +++++++++++++++++
 * 1 +x| | | | | |x| +
 * 2 + |x| | | |x| | +
 * 3 + | |x| |x| | | +
 * 4 + | | |x| | | | +
 * 5 + | | | | | | | +
 * 6 + | | | | | | | +
 * 7 + | | | | | | | +
 * 8 + | | | | | | | +
 *   +++++++++++++++++
 */

//const unsigned char MAX_STEPS = 100;

int main() {
    using std::cin;
    using std::cout;
    using std::endl;

    struct point {
        short x, y;

        public:
        bool operator != (const point &b) const noexcept
        {
            return b.x != x || b.y != y;
        }
    };

    point a{};
    point b{};
    cin >> a.x >> a.y >> b.x >> b.y;

    if (!((b.x - a.x - b.y - a.y) % 2))
    {
        cout << "Yes" << endl;
        std::vector<point> steps; // Шаги

        do {
            if (std::max(a.x, b.x) - std::min(a.x, b.x) > 1) {
                a.x += a.x < b.x ? 1 : -1;
                a.y += b.y == a.y ? (a.y < 4 ? 1 : -1) : (b.y > a.y ? 1 : -1);
            }
            else if (std::max(a.y, b.y) - std::min(a.y, b.y) > 1) {
                a.y += a.y < b.y ? 1 : -1;
                a.x += b.x == a.x ? (a.x < 4 ? 1 : -1) : (b.x > a.x ? 1 : -1);
            }
            else {
                steps.push_back(b);
                break;
            }


            steps.push_back(a);
        } while (a != b);

        cout << int(steps.size()) << endl;
        for (const auto& st : steps) {
            cout << st.x << " " << st.y << endl;
        }
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}