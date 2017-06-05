#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char str[100];
    cin>>str;
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]>='a'&&str[i]<='z')
        {
            str[i]=str[i] - 32;
        }
    }
    cout<<str<<endl;
    return 0;
}
