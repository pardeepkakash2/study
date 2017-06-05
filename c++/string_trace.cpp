#include <iostream>
#include <string>

using namespace std;

int main ()
{
	string str = "040b";

	#if 0
	string str1 = "something";
	str1[0] = toupper(str1[0]);
	cout << str1 << '\n';
	#endif	
	
	cout << str.length() << '\n';
	for (int i=0; i<str.length() ; i++)
	{
		str[i] = toupper(str[i]);
	}
	cout << str << '\n';
	return 0;
}
