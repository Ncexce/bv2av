#ifndef LIBBVAVC_H
#define LIBBVAVC_H __declspec(dllexport)
#endif

extern "C"
{
  bool LIBBVAVC_H formatcheck(string codec);
  string LIBBVAVC_H bv2av(string todec);
  string LIBBVAVC_H av2bv(string toenc);

}
