#include <iostream>

int n, s;
int set[100'000];
int ret;

void solve(int i, int accum)
{
    if(i != -1 && s == accum)
        ++ret;
    
    for(++i; i < n; ++i)
        solve(i, accum + set[i]);
}

int main(int argc, const char* argv[])
{
    std::scanf("%d %d", &n, &s);

    for(int i = 0; i < n; ++i)
        std::scanf("%d", set + i);
       
    ret = 0;
    
    solve(-1, 0);
    
    std::printf("%d", ret);
    
    return 0;
}
