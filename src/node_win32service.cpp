#include <v8.h>
#include <node.h>
#ifdef WINDOWS
  #include <windows.h> 
#endif
#include <string>

/* 

= V8 recap =

More detailed info at http://code.google.com/apis/v8/embed.html

== Context ==

A context is an execution environment that allows separate, unrelated, JavaScript applications to run in a single instance of V8. 
Must be explicitly declared.

== Handles ==

Defines the lifetime of an object.

Local (deleted when scope deleted), 
Persistent (deleted manually), 
Handle (parent class)

== Handle scope == 

A container that holds lots of handles.  
When handle scope's destructor is called (implicitly called when ~ called) all handles created within that scope are removed

== Templates ==

A template is a blueprint for JavaScript functions and objects in a context. You can use a template to wrap C++ functions and data structures within JavaScript objects so that they can be manipulated by JavaScript scripts. (i.e. a browser's DOM aka 'document')

Function template: A function template is the blueprint for a single function. 
Object templates: Each function template has an associated object template. accessors/interceptor C++ callbacks

*/

//using namespace node;
using namespace v8;

class Win32service : node::ObjectWrap {
  private:
  public:
    Win32service() {}
    ~Win32service() {}
    
    // Win32service serviceName
    std::string serviceName;

    
    // Holds our constructor function
    static v8::Persistent<FunctionTemplate> persistent_function_template;

    static void Init(Handle<Object> target) {
      v8::HandleScope scope;

      v8::Local<FunctionTemplate> local_function_template = v8::FunctionTemplate::New(New);
      
      Win32service::persistent_function_template = v8::Persistent<FunctionTemplate>::New(local_function_template);
      Win32service::persistent_function_template->InstanceTemplate()->SetInternalFieldCount(1); // 1 since this is a constructor function
      Win32service::persistent_function_template->SetClassName(v8::String::NewSymbol("Win32service"));
      
      Win32service::persistent_function_template->InstanceTemplate()->SetAccessor(String::New("serviceName"), GetServiceName, SetServiceName);
      Win32service::persistent_function_template->InstanceTemplate()->SetAccessor(String::New("status"), GetStatus, SetStatus);

      // Win32service::persistent_function_template->InstanceTemplate()->SetAccessor(String::New("status"), GetStatus, SetStatus);
      // 
      
      NODE_SET_PROTOTYPE_METHOD(Win32service::persistent_function_template, "send", Send);
      // target->Set(String::NewSymbol("status"), Win32Service::service_status_template->GetFunction());
      target->Set(String::NewSymbol("Win32Service"), Win32service::persistent_function_template->GetFunction());
    }

    // constructor function
    static Handle<Value> New(const Arguments& args) {
      HandleScope scope;
      Win32service* instance = new Win32service();
      // Set some default values
      if (instance->serviceName.empty()){
        return ThrowException(Exception::Error(String::New("No set serviceName")));
      }

      instance->statusObj = ServiceStatus::NewInstance();

      instance->Wrap(args.This());

      return args.This();
    }

    static v8::Handle<Value> Send(const Arguments& args) {
      v8::HandleScope scope;
      // Extract C++ object reference from "this" aka args.This() argument
      Win32service* Win32service_instance = node::ObjectWrap::Unwrap<Win32service>(args.This());
      
      // Convert first argument to V8 String
      v8::String::Utf8Value v8str(args[0]);
      
      // // see http://library.gnome.org/devel/libnotify/0.7/NotifyWin32service.html 
      // Notify::init("Basic");
      // // Args: title, content, icon
      // Notify::Win32service n(Win32service_instance->title.c_str(), *v8str, Win32service_instance->icon.c_str()); // *v8str points to the C string
      // // Display win32service
      // n.show();
      // // Return value
      return v8::Boolean::New(true);
    }
    
    static v8::Handle<Value> GetServiceName(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
      // Extract the C++ request object from the JavaScript wrapper.
      Win32service* Win32service_instance = node::ObjectWrap::Unwrap<Win32service>(info.Holder());
      return v8::String::New(Win32service_instance->serviceName.c_str());
    }

    static void SetServiceName(Local<String> property, Local<Value> value, const AccessorInfo& info) {
      Win32service* Win32service_instance = node::ObjectWrap::Unwrap<Win32service>(info.Holder());
      v8::String::Utf8Value v8str(value);
      Win32service_instance->serviceName = *v8str;
    }

    static v8::Handle<Value> GetStatus(v8:local<v8::String> property, const v8::AccessorInfo& info) {
      Win32service* Win32service_instance = node::ObjectWrap::Unwrap<Win32service>(info.Holder());
      Win32service_instance->statusObj 
      return Win32service_instance->statusObj
    }
};

// class Win32service : node::ObjectWrap {
//   public:
//     Win32service() {}
//     ~Win32service() {}

//     std::string service_name;

//     static v8::Persistent<FunctionTemplate> persistent_function_template;

//     static void Init(Handle<Object> target) {
//       v8::HandleScope scope;
//       // Wrap our New() method so that it's accessible from Javascript
//       v8::Local<FunctionTemplate> local_function_template = v8::FunctionTemplate::New(New);
      
//       // Make it persistent and assign it to our object's persistent_function_template attribute
//       Win32service::persistent_function_template = v8::Persistent<FunctionTemplate>::New(local_function_template);

//       Win32service::persistent_function_template->InstanceTemplate()->SetInternalFieldCount(1); // 1 since this is a constructor function
//       // Set a class name for objects created with our constructor
//       Win32service::persistent_function_template->SetClassName(v8::String::NewSymbol("Win32service"));

//       target->Set(String::NewSymbol("win32service"), Win32service::persistent_function_template->GetFunction());
//     }

//     static Handle<Value> New(const Arguments& args) {
//       HandleScope scope;
//       Win32service* Win32service_instance = new Win32service();
//       // Set some default values
//       Win32service_instance->title = "Node.js";
//       Win32service_instance->icon = "terminal";
      
//       // Wrap our C++ object as a Javascript object
//       Win32service_instance->Wrap(args.This());
      
      
//       // Our constructor function returns a Javascript object which is a wrapper for our C++ object, 
//       // This is the expected behavior when calling a constructor function with the new operator in Javascript.
//       return args.This();
//     }    
// };

v8::Persistent<FunctionTemplate> Win32service::persistent_function_template;
extern "C" {
  static void init(Handle<Object> target) {
    Win32service::Init(target);
  }
  // @see http://github.com/ry/node/blob/v0.2.0/src/node.h#L101
  NODE_MODULE(win32service, init);
}