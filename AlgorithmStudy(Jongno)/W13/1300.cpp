#include <iostream>
#include <algorithm>

int n, k;

int calc(int num)
{
    int ret = 0;
    
    for(int i = 1; i <= n; ++i)
        ret += std::min(num / i, n);
    
    return ret;
}

int main(int argc, const char* argv[])
{
    std::scanf("%d %d", &n, &k);
    
    int l = 1, r = k;
    
    int ret = 0;
    
    while(l <= r)
    {
        int m = (l + r) / 2;
        
        if(calc(m) < k)
        {
            l = m + 1;
        }
        else
        {
            ret = m;
            r = m - 1;
        }
    }
    
    std::printf("%d", ret);
    
    return 0;
}

