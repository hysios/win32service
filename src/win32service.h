#include <node.h>

#include <string>


using namespace v8;
using namespace std;

class Win32Service : node::ObjectWrap {
  public:
    string serviceName;

    static Persistent<Function> constructor;
    static Persistent<FunctionTemplate> win32service_template;

    static void Init(Handle<Object> target);

    static Handle<Value> New(const Arguments& args);
	static Handle<Value> CreateStatusObject();
	static Handle<Value> ConstructorFunction(const Arguments& args);
};
