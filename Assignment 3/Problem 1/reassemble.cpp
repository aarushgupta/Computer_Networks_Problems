#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ii insert

string int2hex_padded(int x)
{
	stringstream sstream;
	sstream << hex << x;
	string result = sstream.str();

	if(result.length()<4)
	{
		string res = "";

		for(int i=0;i<4-result.length();i++)
			res += '0';

		res += result;
		return res;
	}

	return result;
}


int main()
{

	freopen("fragmented.txt","r",stdin);
	freopen("reassembled.txt","w",stdout);

	int no_fragments;
	cin>>no_fragments;

	string res = "";
	string s;

	for(int i=0;i<no_fragments;i++)
	{
		cin>>s;
		string y = s.substr(40,s.length()-40);

		res += y;
	}

	int x = res.length();
	x += 40;

	x /=2;

	string len = int2hex_padded(x);

	string ans = "";

	for(int j=0;j<4;j++)
		ans += s[j];

	ans += len;

	for(int j=8;j<12;j++)
		ans += s[j];

	for(int j=12;j<16;j++)
		ans += '0';

	
	for(int j=16;j<40;j++)
		ans += s[j];

	ans += res;

	cout<<ans<<endl;



	return 0;
}