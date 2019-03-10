#include<stdio.h>
#include<set>
#include<algorithm>
using namespace std;
const int MAX_M = 100000;
int m, d, flag[MAX_M], cnt[MAX_M];
struct point {
    int x, y, idx;
    point() {}
    point(int _x, int _y, int _idx)
        :x(_x), y(_y), idx(_idx) {}
    bool operator<(point i) const {
        return y < i.y || y == i.y && x < i.x;
    }
}p[MAX_M];
bool compx(point i, point j) { return i.x < j.x || i.x == j.x&&i.y < j.y; }
int uf(int h) {
    if (h == flag[h]) return h;
    return flag[h] = uf(flag[h]);
}
set<point> st;
void act() {
    sort(p, p + m, compx);
    for (int i = 0, h = 0; i < m; i++) {
        while (p[i].x - p[h].x>d) st.erase(p[h++]);
        for (set<point>::iterator it = st.lower_bound(point(-1e9, p[i].y - d, -1));
        it != st.end() && it->y <= p[i].y;) {
            flag[uf(it->idx)] = uf(p[i].idx);
            st.erase(it++);
        }
        st.insert(p[i]);
    }
}
int main() {
    scanf("%d %d", &m, &d);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        p[i] = point(a + b, a - b, i);
        flag[i] = i;
    }
    act();
    for (int i = 0; i < m; i++) p[i].x *= -1;
    st.clear();
    act();
    int res1 = 0, res2 = 0;
    for (int i = 0; i < m; i++) {
        res1 += cnt[uf(i)]++ == 0;
        res2 = max(res2, cnt[uf(i)]);
    }
    printf("%d %d", res1, res2);
    return 0;
}
