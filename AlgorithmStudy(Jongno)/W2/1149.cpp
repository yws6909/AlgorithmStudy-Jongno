#include <iostream>
#include <algorithm>

int main(int argc, const char* argv[])
{
    int n;
    std::scanf("%d", &n);
    
    int r, g, b;
    std::scanf("%d %d %d", &r, &g, &b);
    
    for(int i = 1; i < n; ++i)
    {
        int optr = std::min(g, b);
        int optg = std::min(r, b);
        int optb = std::min(r, g);
        
        std::scanf("%d %d %d", &r, &g, &b);

        r += optr;
        g += optg;
        b += optb;
    }
    
    const int ret = std::min({r, g, b});
    std::printf("%d", ret);
    
    return 0;
}
