//
// This class is a native C++ Node.js extension for creating windows service application
//
#include <v8.h>
#include <node.h>
// We need those two libraries for the GTK+ notification 
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