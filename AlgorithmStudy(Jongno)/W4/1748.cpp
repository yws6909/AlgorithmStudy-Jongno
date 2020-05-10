#include <iostream>

int main(int argc, const char* argv[])
{
    int n;
    std::scanf("%d", &n);
    
    int r;
    {
        r = 0;
        int weight = 1;
        int unit = 1;
        
        while(true)
        {
            if(n < unit * 10)
            {
                r += (n - unit + 1) * (weight);
                    
                break;
            }
            
            r += (9 * unit) * weight;
            
            ++weight;
            unit *= 10;
        }
    }
    std::printf("%d", r);
    
    return 0;
}
