//bv2av, a av and bv converter for bilibili
//Code based on mcfx's python code,and algorithm by mcfx
//Original: https://www.zhihu.com/question/381784377/answer/1099438784
//This transferred version is still buggy and unusable, and I have no idea why that will happen.
//encode av -> bv is available now, but decoding bv -> av is still unavailable.
//pull-requests is STRONGLY WELCOMED if you know how to fix that.
#include <iostream>
#include <cmath>
#include <map>
#include <string>
#include <cstdlib>
using namespace std;

//typedefs
typedef map<char,int> indexer;
typedef unsigned long long ull;

//function prototypes -- arg1=vxor, arg2=vadd
// encode av -> bv available now!
string enc(ull toenc, ull arg1, ull arg2);
ull dec(string todec,ull arg1, ull arg2);

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
	ull vxor=177451812;
	ull vadd=8728348608;
	//ull vadd=100618342136696320;
	if(ag1=="enc")
	{
		ull param=stoll(ag2);
		cout<<enc(param,vxor,vadd);
		return 0;
	}
	if(ag1=="dec")
	{
		cout<<"av"<<dec(ag2,vxor,vadd);
		return 0;
	}

}

//av->bv is available now!
string enc(ull toenc, ull arg1, ull arg2)
{
	ull temp1 = (toenc^arg1)+arg2;
	string tstr="BV1  4 1 7  ";
	for(int i=0;i<6;i++)
	{
		tstr[s[i]]=table[static_cast<ull>(floor(temp1/(pow(58,i))))%58ull];
		//cout<<(static_cast<ull>(floor(temp1/(pow(58,i))))%58ull)<<endl;
	}
	return tstr;
}

//decode bv->av is still not available.
//annotation: indexing a map: usage: map_name.find(key)->second, returning a value the key holds.
//annotation: Not necessary. Can be accessed by array directly.
//annotation: context: typedef unsigned long long ull;
ull dec(string todec, ull arg1, ull arg2)
{
	ull r=0;
	for(int i=0;i<6;i++)
	{
		r+=(tr[todec[s[i]]])*(pow(58,i));
		cout<<((tr[todec[s[i]]])*(pow(58,i)))<<endl;
	}
	return ((r-arg2)^arg1);
}
