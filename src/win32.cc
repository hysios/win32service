#include <v8.h>
#include <node.h>
#ifdef WINDOWS
  #include <windows.h> 
#endif
#include <string>
#include "ntservmsg.h"
#include "win32.h"
#include "win32service.h"
#include "service_status.h"

Handle<Value> CreateFunctionObject(const Arguments& args) {
	HandleScope scope;
	Local<Object> obj = args[0]->ToObject();
	return scope.Close(obj);
}

Handle<Value> CreateService(const Arguments& args) {
	HandleScope scope;
	
	Local<FunctionTemplate> tpl = Local<FunctionTemplate>::New(Win32Service::win32service_template);

	return scope.Close(tpl->GetFunction());
}

void Win32::Init(Handle<Object> target) {
	HandleScope scope;

	target->Set(String::NewSymbol("createService"), 
		FunctionTemplate::New(CreateService)->GetFunction());
	// target->Set(String::NewSymbol("SERVICE_FILE_SYSTEM_DRIVER"), Uint32::New(SERVICE_FILE_SYSTEM_DRIVER));
}

extern "C" {
  static void Init(Handle<Object> target) {
    ServiceStatus::Init();
    Win32Service::Init(target);
    Win32::Init(target);
  }
  // @see http://github.com/ry/node/blob/v0.2.0/src/node.h#L101
  NODE_MODULE(win32service, Init);
}
