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
            opt[i] = 1;
            
            for(int j = 0; j < i; ++j)
            {
                if(set[i] < set[j])
                    opt[i] = std::max(opt[i], opt[j] + 1);
            }
        }
    }
    
    int r;
    {
        r = 1;
        
        for(int i = 0; i < n; ++i)
            r = std::max(r, opt[i]);
    }
    std::printf("%d", r);
    
    return 0;
}
