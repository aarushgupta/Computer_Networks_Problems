# include<iostream>
#include<vector>
#include <bits/stdc++.h>

using namespace std;

int main()
{
	string ip4;
	cout<<"Enter IPv4 Address: ";
	cin>>ip4;
	vector<int> ip4_split;
	string temp;
	for(char i:ip4)
	{
		if(i == '.')
		{
			ip4_split.push_back(stoi(temp));
			temp = "";
		}
		else
		{
			temp = temp + i;
		}
	}
	ip4_split.push_back(stoi(temp));

	string ip6;
	for(int i = 0; i < 4; i++)
	{
		// int temp1 = (int)ip4_split[i];
		stringstream ss;
		ss << setfill('0')<<setw(2)<<hex << ip4_split[i];
		ip6+=ss.str();
		if(i == 1)
			ip6+=':';
	}

	// for(auto i:ip4_split)
	// {
	// 	cout<<i<<endl;
	// }
	cout<<"IPv6 Address: "<<"0:0:0:0:0:ffff:"<<ip6;

	return 0;
}