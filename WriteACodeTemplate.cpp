#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif

#include<string>
#include <iomanip>
#include<math.h>
#include<algorithm>
using namespace std;

int main()
{
    int W, H, i, j, k, distance[94][2], cost[3], maxIndex;
    string s, language[3];
    bool start;
    char lastChar;
    cin>>W>>H;
    for(i=0; i<H; i++)
    {
        cin>>s;
        for(j=0; j<W; j++)
        {
            distance[s[j]-33][0] = i;
            distance[s[j]-33][1] = j;
        }
    }
    cost[0] = cost[1] = cost[2] = 0;
    for(i=0; i<3; i++)
    {
        cin>>s;
        language[i] = s;
        cin>>s;
        while(1)
        {
            if (s=="%TEMPLATE-START%")
                start=true;
            else
                start=false;
            if(!start)
                lastChar = s[s.size()-1];
            cin>>s;
            if(s=="%TEMPLATE-END%")
                break;
            if(!start)
                cost[i] += max(abs(distance[s[0]-33][0]-distance[lastChar-33][0]),abs(distance[s[0]-33][1]-distance[lastChar-33][1]));
            for(j=1; j<s.size(); j++)
                cost[i] += max(abs(distance[s[j]-33][0]-distance[s[j-1]-33][0]),abs(distance[s[j]-33][1]-distance[s[j-1]-33][1]));
        }
    }
    if(cost[0]<=cost[1])
    {
        if(cost[0]<=cost[2])
            maxIndex = 0;
        else
            maxIndex = 2;
    }
    else
    {
        if(cost[1]<=cost[2])
            maxIndex = 1;
        else
            maxIndex = 2;
    }
    cout<<language[maxIndex]<<endl;
    cout<<cost[maxIndex];
    return 0;
}
