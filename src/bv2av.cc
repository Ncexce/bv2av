//bv2av, a av and bv converter for bilibili
//Code based on mcfx's python code,and algorithm by mcfx
//Original: https://www.zhihu.com/question/381784377/answer/1099438784
//This transferred version is still buggy and unusable, and I have no idea why that will happen.
//All functions are available now!
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
//ull dec(string todec);

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

//decode bv->av is available now.
//the comments beneath is deprecated now. I will research them again.
//annotation.usage: indexing a map: map_name.find(key)->second, returning a value the key holds.
//annotation.continue: Not necessary. Can be accessed by array directly.
//annotation.QReference: context: typedef unsigned long long ull;
ull dec(string todec, ull arg1, ull arg2)
{
	ull r=0;
	for(int i=0;i<6;i++)
	{
		if(i==0)
		{
			r+=(tr[todec[s[i]]])*((ull)pow(58,i));
			//cout<<r<<"    "<<(tr[todec[s[i]]])<<"    "<<(tr[todec[s[i]]])*((ull)pow(58,i)+1)<<endl;
			continue;
		}
		r+=(tr[todec[s[i]]])*((ull)pow(58,i)+1);
		//cout<<r<<"    "<<(tr[todec[s[i]]])<<"    "<<(tr[todec[s[i]]])*((ull)pow(58,i))<<endl;
	}
	//cout<<r<<endl;
	return ((r-arg2)^arg1);
}

/*//annotation.debug:Dictionary [OK]
//annotation.debug:pow() [OK]
//annotation.debug:Multiply [STRANGE] (But OK)
//annotation.debug Others [OK]
//bv -> av is available now!
ull dec(string todec)
{
	ull vxor=177451812;
	ull vadd=100618342136696320;
	ull r=0;
	int deptable[10]={11,10,3,8,4,6,2,9,5,7};
	int tabl[10]={2,3,4,5,6,7,8,9,10,11};
	int topow[10]={6,2,4,8,5,9,3,7,1,0};
	for(int i=0;i<10;i++)
	{
		//Why strange: According to my debug, when i=5,7,9,
		//I must add the number of the character that represents 
		//itself in the dictionary to the multiplier, or I will get an error output.
		//p.s. the '//' is widely used to debug.
		if(i==5||i==7||i==9)
		{
			r+=((ull)tr[todec[tabl[i]]])*(((ull)pow(58,topow[i])));
			//cout<<r<<"    "<<((ull)tr[todec[tabl[i]]])*((ull)pow(58,topow[i]))<<endl;
		}else
		{
			r+=((ull)tr[todec[tabl[i]]])*(((ull)pow(58,topow[i]))+1);
			//cout<<r<<"    "<<((ull)tr[todec[tabl[i]]])*(((ull)pow(58,topow[i]))+1)<<endl;
		}
		//cout<<r<<"    "<<((ull)tr[todec[tabl[i]]])*(((ull)pow(58,topow[i]))+1)<<endl;
		//if(i==9) r+=(ull)tr[todec[tabl[i]]];
	}
	//cout<<r<<endl;
	return (r-vadd)^vxor;
}*/
