#include <iostream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <string>
#include "libbvavc.h"
using namespace std;

LIBBVAVC_H Converter::Converter()
{
  codecs="av170001";
}

LIBBVAVC_H Converter::Converter(string codec)
{
  codecs=codec;
}

bool LIBBVAVC_H Converter::setcodec(string codec)
{
  codecs=codec;
  return true;
}

string LIBBVAVC_H Converter::getcodec()
{
  return codecs;
}

bool LIBBVAVC_H Converter::formatidentify()
{
  if(codecs.substr(0,2)!="av" && codecs.substr(0,2)!="BV") return false;
  if(codecs.substr(0,2)=="av") flag=1;
  if(codecs.substr(0,2)=="BV") flag=2;
  return true;
}

bool LIBBVAVC_H Converter::formatidentify(string codec)
{
  if(codec.substr(0,2)!="av" && codec.substr(0,2)!="BV") return false;
  return true;
}

string LIBBVAVC_H initialconvert()
{
  if(flag==1) codecs=enc((ull)((codecs.substr(2,10)).stoll()));
  if(flag==2) codecs="av"+dec(codecs);
}
