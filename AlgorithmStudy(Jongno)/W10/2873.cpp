#include <iostream>
#include <limits>
#include <string>

int main(int argc, const char* argv[])
{
    int r, c;
    std::scanf("%d %d", &r, &c);
    
    int map[1'000][1'000];
    {
        for(int i = 0; i < r; ++i)
        {
            for(int j = 0; j < c; ++j)
                std::scanf("%d", &map[i][j]);
        }
    }
    
    std::string ret;
    {
        if((r & 0b1) || (c & 0b1))
        {
            if(r & 0b1)
            {
                const int row_divided_by_two = r / 2;
                
                for(int i = 0; i < row_divided_by_two; ++i)
                    ret += (std::string(c - 1, 'R') + "D" + std::string(c - 1, 'L') + "D");
                
                ret += std::string(c - 1, 'R');
            }
            else
            {
                const int col_divided_by_two = c / 2;
                
                for(int i = 0; i < col_divided_by_two; ++i)
                    ret += (std::string(r - 1, 'D') + "R" + std::string(r - 1, 'U') + "R");
                
                ret += std::string(r - 1, 'D');
            }
        }
        else
        {
            int min_r;
            int min_c;
            {
                min_r = -1;
                min_c = -1;
                int min_value = std::numeric_limits<int>::max();
                
                for(int i = 0; i < r; ++i)
                {
                    for(int j = (i & 0b1) ^ 0b1; j < c; j += 2)
                    {
                        if(min_value > map[i][j])
                        {
                            min_value = map[i][j];
                            min_r = i;
                            min_c = j;
                        }
                    }
                }
            }
            
            {
                const int row_integrate = min_r / 2;
                const int row_divided_by_two = r / 2;
                
                for(int i = 0; i < row_integrate; ++i)
                    ret += (std::string(c - 1, 'R') + "D" + std::string(c - 1, 'L') + "D");
                
                {
                    const int col_integrate = min_c / 2;
                    const int col_divided_by_two = c / 2;
                    
                    for(int i = 0; i < col_integrate; ++i)
                        ret += "DRUR";
                    
                    {
                        if(min_c & 0b1)
                            ret += "DR";
                        else
                            ret += "RD";
                    }
                    
                    for(int i = col_integrate + 1; i < col_divided_by_two; ++i)
                        ret += "RURD";
                }
                
                for(int i = row_integrate + 1; i < row_divided_by_two; ++i)
                    ret += ("D" + std::string(c - 1, 'L') + "D" + std::string(c - 1, 'R'));
            }
        }
    }
    std::printf("%s", ret.c_str());
    
    return 0;
}
