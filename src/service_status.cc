#include <node.h>
#include "service_status.h"

#define SERVICE_WIN32_OWN_PROCESS	0x00000010
#define SERVICE_STOPPED				0x00000001
#define SERVICE_ACCEPT_STOP			0x00000001


using namespace v8;

ServiceStatus::ServiceStatus() {};
ServiceStatus::~ServiceStatus() {};

// m_Status.dwCurrentState = SERVICE_STOPPED;
// m_Status.dwControlsAccepted = SERVICE_ACCEPT_STOP;
// m_Status.dwWin32ExitCode = 0;
// m_Status.dwServiceSpecificExitCode = 0;
// m_Status.dwCheckPoint = 0;
// m_Status.dwWaitHint = 0;

Handle<ObjectTemplate> ServiceStatus::status_template;

void ServiceStatus::Init(){
	status_template = ObjectTemplate::New();
	status_template->SetInternalFieldCount(1);

	status_template->SetAccessor(String::New("ServiceType"), GetServiceType, SetServiceType);
	status_template->SetAccessor(String::New("CurrentState"), GetCurrentState, SetCurrentState);
	status_template->SetAccessor(String::New("ControlsAccepted"), GetControlsAccepted, SetControlsAccepted);
	status_template->SetAccessor(String::New("Win32ExitCode"), GetWin32ExitCode, SetWin32ExitCode);
	status_template->SetAccessor(String::New("ServiceSpecificExitCode"), GetServiceSpecificExitCode, SetServiceSpecificExitCode);
	status_template->SetAccessor(String::New("CheckPoint"), GetCheckPoint, SetCheckPoint);
	status_template->SetAccessor(String::New("WaitHint"), GetWaitHint, SetWaitHint);

	// constructor = Persistent<Function>::New(tpl->GetFunction());
}



ServiceStatus* ServiceStatus::New(){
	HandleScope scope;

	ServiceStatus* obj = new ServiceStatus();
	SERVICE_STATUS& status = obj->status;
	status.dwServiceType             = SERVICE_WIN32_OWN_PROCESS;
	status.dwCurrentState            = SERVICE_STOPPED;
	status.dwControlsAccepted        = SERVICE_ACCEPT_STOP;
	status.dwWin32ExitCode           = 0;
	status.dwServiceSpecificExitCode = 0;
	status.dwCheckPoint              = 0;
	status.dwWaitHint                = 0;

	// obj->Wrap(args.This());

	return obj;
}

Handle<Value> ServiceStatus::NewInstance() {
	HandleScope scope;
	// ServiceStatus* status_obj = ObjectWrap::Unwrap<ServiceStatus>(args.This());
	ServiceStatus* status_obj = New();
	Local<Object> obj = status_template->NewInstance();
	obj->SetInternalField(0, External::New(status_obj));

	return scope.Close(obj);
}

Handle<Value> ServiceStatus::PlusOne(const Arguments& args) {
  HandleScope scope;

  ServiceStatus* obj = ObjectWrap::Unwrap<ServiceStatus>(args.This());
  obj->counter_ += 1;

  return scope.Close(Number::New(obj->counter_));
}

Handle<Value> ServiceStatus::GetServiceType(Local<String> property, const AccessorInfo& info){
	ServiceStatus* instance = node::ObjectWrap::Unwrap<ServiceStatus>(info.Holder());
	return Uint32::New(instance->status.dwServiceType);
}

void ServiceStatus::SetServiceType(Local<String> property, Local<Value> value, const AccessorInfo& info){
	ServiceStatus* instance = node::ObjectWrap::Unwrap<ServiceStatus>(info.Holder());
	instance->status.dwServiceType = value->ToUint32()->Value();
}

Handle<Value> ServiceStatus::GetCurrentState(Local<String> property, const AccessorInfo& info){
	ServiceStatus* instance = node::ObjectWrap::Unwrap<ServiceStatus>(info.Holder());
	return Uint32::New(instance->status.dwCurrentState);
}

void ServiceStatus::SetCurrentState(Local<String> property, Local<Value> value, const AccessorInfo& info){
	ServiceStatus* instance = node::ObjectWrap::Unwrap<ServiceStatus>(info.Holder());
	// Uint32 v8dbl(value);
	instance->status.dwCurrentState = value->ToUint32()->Value();
}

Handle<Value> ServiceStatus::GetControlsAccepted(Local<String> property, const AccessorInfo& info){
	ServiceStatus* instance = node::ObjectWrap::Unwrap<ServiceStatus>(info.Holder());
	return Uint32::New(instance->status.dwControlsAccepted);	
}

void ServiceStatus::SetControlsAccepted(Local<String> property, Local<Value> value, const AccessorInfo& info){
	ServiceStatus* instance = node::ObjectWrap::Unwrap<ServiceStatus>(info.Holder());
	instance->status.dwControlsAccepted = value->ToUint32()->Value();	
}

Handle<Value> ServiceStatus::GetWin32ExitCode(Local<String> property, const AccessorInfo& info){
	ServiceStatus* instance = node::ObjectWrap::Unwrap<ServiceStatus>(info.Holder());
	return Uint32::New(instance->status.dwControlsAccepted);	
}

void ServiceStatus::SetWin32ExitCode(Local<String> property, Local<Value> value, const AccessorInfo& info){
	ServiceStatus* instance = node::ObjectWrap::Unwrap<ServiceStatus>(info.Holder());
	instance->status.dwControlsAccepted = value->ToUint32()->Value();	
}

Handle<Value> ServiceStatus::GetServiceSpecificExitCode(Local<String> property, const AccessorInfo& info){
	ServiceStatus* instance = node::ObjectWrap::Unwrap<ServiceStatus>(info.Holder());
	return Uint32::New(instance->status.dwServiceSpecificExitCode);	
}

void ServiceStatus::SetServiceSpecificExitCode(Local<String> property, Local<Value> value, const AccessorInfo& info){
	ServiceStatus* instance = node::ObjectWrap::Unwrap<ServiceStatus>(info.Holder());
	instance->status.dwServiceSpecificExitCode = value->ToUint32()->Value();	
}

Handle<Value> ServiceStatus::GetCheckPoint(Local<String> property, const AccessorInfo& info){
	ServiceStatus* instance = node::ObjectWrap::Unwrap<ServiceStatus>(info.Holder());
	return Uint32::New(instance->status.dwCheckPoint);	
}

void ServiceStatus::SetCheckPoint(Local<String> property, Local<Value> value, const AccessorInfo& info){
	ServiceStatus* instance = node::ObjectWrap::Unwrap<ServiceStatus>(info.Holder());
	instance->status.dwCheckPoint = value->ToUint32()->Value();	
}

Handle<Value> ServiceStatus::GetWaitHint(Local<String> property, const AccessorInfo& info){
	ServiceStatus* instance = node::ObjectWrap::Unwrap<ServiceStatus>(info.Holder());
	return Uint32::New(instance->status.dwWaitHint);	
}

void ServiceStatus::SetWaitHint(Local<String> property, Local<Value> value, const AccessorInfo& info){
	ServiceStatus* instance = node::ObjectWrap::Unwrap<ServiceStatus>(info.Holder());
	instance->status.dwWaitHint = value->ToUint32()->Value();	
}

