#ifdef LIBBVAVC_H
#else
#define LIBBVAVC_H __declspec(dllimport) //当编译时，头文件不参加编译，所以.cpp文件中先定义，后头文件被包含进来，因此外部使用时，为dllexport，而在内部编译时，则为dllimport
#endif


typedef unsigned long long ull;
class LIBBVAVC_H Converter
{
public:
  Converter();
  Converter(string codec);
  bool setcodec(string codec);
  string getcodec(string codec);
  bool formatidentify();
  bool formatidentify(string codec);
  bool initialconvert();
  string enc(ull toenc);
  ull dec(string todec);
private:
  string codecs;
  int flag;
  ull vxor=177451812;
  ull vadd=8728348608;

};
