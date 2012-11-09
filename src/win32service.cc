#include <v8.h>
#include <node.h>
#ifdef WINDOWS
  #include <windows.h> 
#endif
#include <string>
#include "ntservmsg.h"
#include "win32service.h"
#include "service_status.h"

#define SERVICE_FILE_SYSTEM_DRIVER    0x00000002

using namespace v8;
using namespace std;

Persistent<FunctionTemplate> Win32Service::win32service_template;

void Win32Service::Init(Handle<Object> target){
  HandleScope scope;

  Local<FunctionTemplate> ltpl = FunctionTemplate::New(New);
  win32service_template = Persistent<FunctionTemplate>::New(ltpl);

  // definition Win32Service Class template
  win32service_template->SetClassName(String::NewSymbol("Win32Service"));
  win32service_template->InstanceTemplate()->SetInternalFieldCount(1); // 1 since this is a constructor function
  // get constructor function
  win32service_template->InstanceTemplate()->Set(String::NewSymbol("status"), CreateStatusObject());
  // tpl->GetFunction();
  target->Set(String::NewSymbol("Win32Service"), win32service_template->GetFunction());
  target->Set(String::NewSymbol("SERVICE_FILE_SYSTEM_DRIVER"), Uint32::New(SERVICE_FILE_SYSTEM_DRIVER));

  // SERVICE_FILE_SYSTEM_DRIVER
  // 0x00000002
  // The service is a file system driver.}
  // SERVICE_KERNEL_DRIVER
  // 0x00000001
  // The service is a device driver.
  // 
}

Handle<Value> Win32Service::CreateStatusObject(){
  HandleScope scope;
  return scope.Close(ServiceStatus::NewInstance());
}

Handle<Value> Win32Service::ConstructorFunction(const Arguments& args){
  HandleScope scope;
  Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
  tpl->Set(String::NewSymbol("status"), CreateStatusObject());
  return scope.Close(tpl->GetFunction());
}

Handle<Value> Win32Service::New(const Arguments& args){
  HandleScope scope;
  Win32Service* obj = new Win32Service();
  
  obj->Wrap(args.This());
  return args.This();
}

Handle<Value> CreateObject(const Arguments& args) {
  HandleScope scope;

  Local<Object> obj = Object::New();
  obj->Set(String::NewSymbol("msg"), args[0]->ToString());

  return scope.Close(obj);
}


