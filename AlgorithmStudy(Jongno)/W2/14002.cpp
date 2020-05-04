#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, const char* argv[])
{
    int n;
    std::scanf("%d", &n);
    
    int set[1'000];
    {
        for(int i = n - 1; i >= 0; --i)
            std::scanf("%d", set + i);
    }
    
    int opt[1'000];
    int trace[1'000];
    
    int r_idx = 1;

    for(int i = 0; i < n; ++i)
    {
        opt[i] = 1;
        int opt_index = -1;
        
        for(int j = 0; j < i; ++j)
        {
            if(set[j] > set[i])
            {
                if(opt[j] + 1 > opt[i])
                {
                    opt[i] = opt[j] + 1;
                    opt_index = j;
                }
            }
        }
        
        trace[i] = opt_index;
        
        if(opt[i] > opt[r_idx])
            r_idx = i;
    }
    
    const int r = opt[r_idx];
    std::printf("%d\n", r);
    
    int it = r_idx;
    
    while(it != -1)
    {
        std::printf("%d ", set[it]);
        
        it = trace[it];
    }
    
    return 0;
}
