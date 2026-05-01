#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = INT_MAX / 2;  // 避免加法溢出，用半无穷大

int main() {
    int V, n;
    cout << "请输入总容量 V 和饮料种类数 n: ";
    cin >> V >> n;

    vector<pair<int, int>> items;  // (容量, 满意度)

    for (int i = 0; i < n; ++i) {
        int vol, sat, cnt;
        cout << "请输入第" << i+1 << "种饮料的容量、满意度、最大数量: ";
        cin >> vol >> sat >> cnt;

        // 二进制拆分
        for (int k = 1; k <= cnt; k <<= 1) {
            items.emplace_back(k * vol, k * sat);
            cnt -= k;
        }
        if (cnt > 0) {
            items.emplace_back(cnt * vol, cnt * sat);
        }
    }

    // dp[j] 表示恰好装满容量 j 时的最大满意度
    vector<int> dp(V + 1, -INF);
    dp[0] = 0;   // 容量0时，满意度为0

    // 对每个拆分出的物品做 01 背包（倒序更新）
    for (auto [w, val] : items) {
        for (int j = V; j >= w; --j) {
            if (dp[j - w] != -INF) {
                dp[j] = max(dp[j], dp[j - w] + val);
            }
        }
    }

    if (dp[V] == -INF) {
        cout << "无解（无法恰好装满 " << V << " 单位容量）" << endl;
    } else {
        cout << "最大满意度为：" << dp[V] << endl;
    }

    return 0;
}