#include <iostream>

int main(int argc, const char* argv[])
{
    int n;
    std::scanf("%d", &n);
    
    int opt[1000];
    {
        int set[1000];
        {
            for(int i = 0; i < n; ++i)
                std::scanf("%d", set + i);
        }
        
        for(int i = 0; i < n; ++i)
        {
            opt[i] = set[i];
            
            for(int j = 0; j < i; ++j)
            {
                if(set[j] < set[i])
                    opt[i] = std::max(opt[i], opt[j] + set[i]);
            }
        }
    }
    
    int r;
    {
        r = 0;
        
        for(int i = 0; i < n; ++i)
            r = std::max(r, opt[i]);
    }
    std::printf("%d", r);
    
    return 0;
}
