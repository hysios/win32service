#include <node.h>
#include <v8.h>

using namespace v8;

typedef unsigned long DWORD;

typedef struct _SERVICE_STATUS {
	DWORD dwServiceType;
	DWORD dwCurrentState;
	DWORD dwControlsAccepted;
	DWORD dwWin32ExitCode;
	DWORD dwServiceSpecificExitCode;
	DWORD dwCheckPoint;
	DWORD dwWaitHint;
} SERVICE_STATUS,*LPSERVICE_STATUS;


class ServiceStatus : node::ObjectWrap {
	public:
		static void Init();
		static Handle<Value> NewInstance();
		static ServiceStatus* New();
		static Handle<Value> PlusOne(const Arguments& args);
		static Handle<Value> GetServiceType(Local<String> property, const AccessorInfo& info);
		static void SetServiceType(Local<String> property, Local<Value> value, const AccessorInfo& info);
		static Handle<Value> GetCurrentState(Local<String> property, const AccessorInfo& info);
		static void SetCurrentState(Local<String> property, Local<Value> value, const AccessorInfo& info);
		static Handle<Value> GetControlsAccepted(Local<String> property, const AccessorInfo& info);
		static void SetControlsAccepted(Local<String> property, Local<Value> value, const AccessorInfo& info);
		static Handle<Value> GetWin32ExitCode(Local<String> property, const AccessorInfo& info);
		static void SetWin32ExitCode(Local<String> property, Local<Value> value, const AccessorInfo& info);
		static Handle<Value> GetServiceSpecificExitCode(Local<String> property, const AccessorInfo& info);
		static void SetServiceSpecificExitCode(Local<String> property, Local<Value> value, const AccessorInfo& info);
		static Handle<Value> GetCheckPoint(Local<String> property, const AccessorInfo& info);
		static void SetCheckPoint(Local<String> property, Local<Value> value, const AccessorInfo& info);
		static Handle<Value> GetWaitHint(Local<String> property, const AccessorInfo& info);
		static void SetWaitHint(Local<String> property, Local<Value> value, const AccessorInfo& info);
		static Handle<ObjectTemplate> status_template;

	private:
		ServiceStatus();
		~ServiceStatus();

		double counter_;

		SERVICE_STATUS status;


};
