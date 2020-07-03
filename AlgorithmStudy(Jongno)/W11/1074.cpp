#include <iostream>

int main(int argc, const char* argv[])
{
    int n, r, c;
    std::scanf("%d %d %d", &n, &r, &c);
    
    int ret;
    {
        ret = 0;
        
        int unit = 2;
        int div = unit / 2;
        
        for(int i = 0; i < n; ++i)
        {
            int suf = 0;
            
            if(r % unit >= div)
                suf += 2;
            
            if(c % unit >= div)
                suf += 1;

            ret += (suf * div * div);
            
            unit *= 2;
            div *= 2;
        }
    }
    std::printf("%d", ret);
    
    return 0;
}
