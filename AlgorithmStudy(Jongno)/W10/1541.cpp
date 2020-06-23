#include <iostream>

int main(int argc, const char* argv[])
{
    char str[51];
    std::scanf("%s", str);
    
    int ret;
    {
        ret = 0;
        
        int i = 0;
        int c = str[0];
        
        int num = 0;
        int weight = 1e+5;
        const int max_weight = 1e+5;
        bool accum_minus = false;
        
        while(c)
        {
            if('0' <= c && c <= '9')
            {
                weight /= 1e+1;
                num += ((c - '0') * weight);
            }
            else
            {
                ret += ((num / weight) * (accum_minus? -1 : 1));
                
                num = 0;
                weight = max_weight;
                
                if(c == '-')
                    accum_minus = true;
            }
            
            c = str[++i];
        }
        
        ret += ((num / weight) * (accum_minus? -1 : 1));
    }
    std::printf("%d", ret);
    
    return 0;
}
