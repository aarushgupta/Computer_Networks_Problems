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


string make_flag_offset(int flag, int offset)
{
	ll o = offset + flag*pow(2,13);

	string a = int2hex_padded(o);
	return a;
}

int main()
{
	freopen("input.txt","r",stdin);

	freopen("fragmented.txt","w",stdout);

	string data;
	int inp_packet_length;
	cin>>data;

	inp_packet_length = data.length();

	inp_packet_length/=2;

	int mtu;
	cin>>mtu;

	int no_fragments = ceil(1.0*(inp_packet_length*1.0-20.0)/(mtu*1.0 - 20.0));

	cout<<no_fragments<<endl;

	int packet_data_size = 0,transmitted_data_size=0;

	inp_packet_length -= 20;

	for(int i=0;i<no_fragments;i++)
	{
		int size = mtu-20;

		size -= size%8;

		if(size<=inp_packet_length)
			inp_packet_length -= size;
		else
			size = inp_packet_length;

		string ans = "";

		for(int j=0;j<4;j++)
			ans += data[j];

		ans += int2hex_padded(size+20);

		for(int j=8;j<12;j++)
			ans += data[j];

		if(i!=no_fragments-1)
		{
			ans += make_flag_offset(1,transmitted_data_size/8);
		}
		else
		{
			ans += make_flag_offset(0,transmitted_data_size/8);
		}

		
		for(int j=16;j<40;j++)
			ans += data[j];

		int y = data.length();
		for(int j = 2*transmitted_data_size + 40; j< min(2*transmitted_data_size + 40 + 2*size,y );j++)
		{
			ans+=data[j];
		}

		cout<<ans<<endl;
		packet_data_size = size;
		transmitted_data_size+=packet_data_size;
		//cout<<packet_data_size<<endl;
	}

	return 0;
}