#include <iostream>
#include <cmath>
#include <map>
#include <string>
#include <cstdlib>
using namespace std;

//typedefs
typedef map<char,int> indexer;

//function prototypes -- arg1=vxor, arg2=vadd
string enc(unsigned long long toenc, unsigned long long arg1, unsigned long long arg2);
unsigned long long dec(string todec,unsigned long long arg1, unsigned long long arg2, indexer dictio);

//global variables
indexer tr;
int s[6]={11,10,3,8,4,6};
string table = "fZodR9XQDSUm21yCkr6zBqiveYah8bt4xsWpHnJE7jL5VG3guMTKNPAwcF";
int main(int argc, char *argv[])
{
	if(argc!=3)
	{
		cout<<"Usage:bv2av (enc/dec) string"<<endl;
		return 1;
	}
	string ag1(argv[1]);
	string ag2(argv[2]);
	if(ag1!="enc"&&ag1!="dec")
	{
		cout<<"Usage:bv2av (enc/dec) string"<<endl;
		return 1;
	}
	for(int i=0;i<58;i++)
	{
		tr[table[i]]=i;
	}
	unsigned long long vxor=177451812;
	unsigned long long vadd=8728348608;
	//unsigned long long vadd=100618342136696320;
	if(ag1=="enc")
	{
		unsigned long long param=stoll(ag2);
		cout<<enc(param,vxor,vadd);
		return 0;
	}
	if(ag1=="dec")
	{
		cout<<dec(ag2,vxor,vadd,tr);
		return 0;
	}

}

string enc(unsigned long long toenc, unsigned long long arg1, unsigned long long arg2)
{
	unsigned long long temp1 = (toenc^arg1)+arg2;
	string tstr="BV1  4 1 7  ";
	for(int i=0;i<6;i++)
	{
		tstr[s[i]]=table[static_cast<unsigned long long>(floor(toenc/(pow(58,i))))%58];
		cout<<(static_cast<unsigned long long>(floor(toenc/(pow(58,i))))%58)<<endl;
	}
	return tstr;
}

//reference: indexing a map: usage: map_name.find(key)->second, returning a value the key holds.
unsigned long long dec(string todec, unsigned long long arg1, unsigned long long arg2, indexer dictio)
{
	unsigned long long r=0;
	for(int i=0;i<6;i++)
	{
		r+=(dictio.find(todec[s[i]])->second)*(pow(58,i));
		cout<<(dictio.find(todec[s[i]])->second)<<endl;
	}
	return (r-arg2)^arg1;
}
