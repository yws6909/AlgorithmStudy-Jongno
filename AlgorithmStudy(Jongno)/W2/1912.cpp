#include <iostream>
#include <limits>

int main (int argc, const char* argv[])
{
    int n;
    std::scanf("%d", &n);
    
    int sum = 0;
    int r = std::numeric_limits<int>::lowest();
    int min = 0;
    
    for (int i = 0; i < n; ++i)
    {
        int input;
        std::scanf("%d", &input);
        
        sum += input;
        r = std::max(r, sum - min);
        min = std::min(min, sum);
    }
    
    std::printf("%d", r);
    
    return 0;
}
