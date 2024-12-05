#include <bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;

#define dbg printf("in\n")
#define nl printf("\n");
#define N 100010
#define inf 100000000000

using namespace std;

ll v[N], b[N], dist[N];
int main()
{
    ll i, j, k;
    ll n, m;
    ll high, low, mid;

    scanf("%I64d%I64d", &n, &m);

    set<ll> sb;
    set<ll>::iterator itr;

    for (i = 0; i < n; i++)
        scanf("%I64d", &v[i]);
    for (i = 0; i < m; i++)
        scanf("%I64d", &b[i]), sb.insert(b[i]);

    for (i = 0; i < n; i++)
    {
        itr = sb.lower_bound(v[i]);
        if (itr == sb.end())
            dist[i] = inf;
        else
            dist[i] = abs(*itr - v[i]);
    }

    for (i = 0; i < n; i++)
    {
        k = inf * 2;
        high = m - 1, low = 0;

        while (low <= high)
        {
            mid = (low + high) / 2;

            if (b[mid] == v[i]) {
                k = 0;
                break;
            }

            if (b[mid] > v[i])
                high = mid - 1;
            else
                k = min(k, abs(b[mid] - v[i])), low = mid + 1;
        }

        dist[i] = min(k, dist[i]);
    }

    m = 0;
    for (i = 0; i < n; i++)
        m = max(m, dist[i]);

    printf("%I64d\n", m);

    return 0;
}