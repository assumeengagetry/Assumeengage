#include<iostream>
#include<climits>
#define ZERO 0
using namespace std;
int main()
{
	short sam = SHRT_MAX;
	unsigned short sure= sam;
	cout<<"Sam has "<<sam<<"dollers , sure has "<<sure<<"dolloers"<<endl;
	sam=sam+1;sure=sure+1;
	cout<<"every one get $1,and now each has"<<sam<<"  "<<sure<<"$"<<endl;
	sam=ZERO;
	sure=ZERO;
	sam=sam-1;sure=sure-1;
	cout<<"Now sam and sure have"<<sam <<"  "<<sure<<"$";
}
