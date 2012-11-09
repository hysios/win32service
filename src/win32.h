#include <node.h>

#include <string>

using namespace v8;

class Win32 : node::ObjectWrap {
  public:
    static void Init(Handle<Object> target);

};
