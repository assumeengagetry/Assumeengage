#include<iostream>
using namespace std;
void simon(int);
int main()

{
	using namespace std;
	simon(3);
	cout<<"paint a integer";
	int count ;
	cin>> count;
	simon(count);
	cout<<"Done";
	return 0;
}
void simon(int n)
{
	using namespace std;
	cout<<"simon says touch your toes "<<n<<"times"<<endl;
}
