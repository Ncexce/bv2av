//Notice: This is a release version of source code which contains comments.
//Notice: The algorithm is from mcfx's Python code on zhihu.
//Visit the link in the readme file.
#include <iostream>
#include <map>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;

//typedefs(Important)
typedef map<char,int> indexer;
//Introduction:declare a map<char,int> type aliased indexer.
//used later in the dict library.
//lancer feels good.

typedef unsigned long long ull;
//Introduction: declare the unsigned long long type as ull(abbr. ver)
//aims to improve the readbility.
//aims to decrease the size of the code.

//Function prototypes
string enc(ull toenc, ull arg1, ull arg2);
//Introduction: encode av to bv.
//args accepted: (ull toenc)-av number to encode.
//               (ull arg1)-accept the vxor variable.
//               (ull arg2)-accept the vadd variable.
//returns: the encoded string(BV Prefix included).

ull dec(string todec, ull arg1, ull arg2);
//Introduction: decode bv to av.
//args accepted: (string todec)-the bv string to decode(BV Prefix included).
//               (ull arg1)-accept the vxor variable.
//               (ull arg2)-accept the vadd variable.
//returns: the decoded av number(av prefix is not included).

//global variables
indexer tr; //the dictionary.
int s[6]={11,10,3,8,4,6}; //the digits to be changed.

string table = "fZodR9XQDSUm21yCkr6zBqiveYah8bt4xsWpHnJE7jL5VG3guMTKNPAwcF";
//the modified Base58 Conversion Table.

//Function Main: Accept 2 arguments:
//The first argument should be "enc" or "dec" to specify the mode this software works.
//The second argument should be the string to process.
int main(int argc, char *argv[])
{
  if(argc!=3)
    {
      cout<<"Usage:bv2av (enc/dec) string"<<endl;
      return 1;
    }
  string ag1(argv[1]); //initialize first argument from argv[].
  string ag2(argv[2]); //initialize the second argument from argv[].
  if(ag1!="enc"&&ag1!="dec") //check the parameters
    {
      cout<<"Usage:bv2av (enc/dec) string"<<endl;
      return 1;
    }
  ull vxor=177451812; //Important: vxor
  ull vadd=8728348608; //Important: vadd
  if(ag1=="enc")
    {
      ull param=stoll(ag2); //type conversion
      cout<<enc(param,vxor,vadd);
      return 0;
    }
  if(ag1=="dec")
    {
      cout<<"av"<<dec(ag2,vxor,vadd);
      return 0;
    }
}

string enc(ull toenc, ull arg1, ull arg2)
{
  ull temp1 = (toenc^arg1)+arg2;
  string tstr="BV1  4 1 7  "; //the fixed digits
  for(int i=0; i<6; i++)
    {
      tstr[s[i]]=table[static_cast<ull>(floor(temp1/(pow(58,i))))%58ull]; //process the string
    }
  return tstr;
}

ull dec(string todec, ull arg1, ull arg2)
{
  ull r=0;
  for(int i=0; i<6; i++)
    {
      if(i==0)
	{
	  r+=(tr[todec[s[i]]])*((ull)pow(58,i)); //bug fixes: when i==0 the result will be wrong.
	  continue;
	}
      r+=(tr[todec[s[i]]])*((ull)pow(58,i)+1); //process the string
    }
  return ((r-arg2)^arg1); //return the post-process string.
}

