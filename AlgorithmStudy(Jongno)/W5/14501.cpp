#include <iostream>

int n;
int t[16], p[16];
int ret;

void solve(int day, int sum)
{
    if (day > n)
    {
        ret = std::max(ret, sum);
        return;
    }
    
    for (int i = day + 1; i < day + t[day]; ++i)
        solve(i, sum);
    
    if (day + t[day] <= n + 1)
        solve(day + t[day], sum + p[day]);
}

int main(int argc, const char* argv[])
{
    scanf("%d", &n);
    
    ret = 0;
    
    for (int i = 1; i <= n; ++i)
        std::scanf("%d %d", t + i, p + i);
    
    solve(1, 0);
    
    std::printf("%d", ret);
    
    return 0;
}
