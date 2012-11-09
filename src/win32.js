var util = require('util');
// var win32service = require('')
exports = module.exports;
__ = CONSTANTIZES = {
SERVICE_KERNEL_DRIVER                 : 1,
SERVICE_FILE_SYSTEM_DRIVER            : 2,
SERVICE_ADAPTER                       : 4,
SERVICE_RECOGNIZER_DRIVER             : 8,
SERVICE_WIN32_OWN_PROCESS             : 16,
SERVICE_WIN32_SHARE_PROCESS           : 32,
SERVICE_INTERACTIVE_PROCESS           : 256,
SERVICE_BOOT_START                    : 0,
SERVICE_SYSTEM_START                  : 1,
SERVICE_AUTO_START                    : 2,
SERVICE_DEMAND_START                  : 3,
SERVICE_DISABLED                      : 4,
SERVICE_ERROR_IGNORE                  : 0,
SERVICE_ERROR_NORMAL                  : 1,
SERVICE_ERROR_SEVERE                  : 2,
SERVICE_ERROR_CRITICAL                : 3,
SERVICE_NO_CHANGE                     :	-1,
SERVICE_STOPPED                       : 1,
SERVICE_START_PENDING                 : 2,
SERVICE_STOP_PENDING                  : 3,
SERVICE_RUNNING                       : 4,
SERVICE_CONTINUE_PENDING              : 5,
SERVICE_PAUSE_PENDING                 : 6,
SERVICE_PAUSED                        : 7,
SERVICE_ACCEPT_STOP                   : 1,
SERVICE_ACCEPT_PAUSE_CONTINUE         : 2,
SERVICE_ACCEPT_SHUTDOWN               : 4,
SERVICE_ACCEPT_PARAMCHANGE            : 8,
SERVICE_ACCEPT_NETBINDCHANGE          : 16,
SERVICE_ACCEPT_HARDWAREPROFILECHANGE  : 32,
SERVICE_ACCEPT_POWEREVENT             : 64,
SERVICE_ACCEPT_SESSIONCHANGE          : 128,
SERVICE_CONTROL_STOP                  : 1,
SERVICE_CONTROL_PAUSE                 : 2,
SERVICE_CONTROL_CONTINUE              : 3,
SERVICE_CONTROL_INTERROGATE           : 4,
SERVICE_CONTROL_SHUTDOWN              : 5,
SERVICE_CONTROL_PARAMCHANGE           : 6,
SERVICE_CONTROL_NETBINDADD            : 7,
SERVICE_CONTROL_NETBINDREMOVE         : 8,
SERVICE_CONTROL_NETBINDENABLE         : 9,
SERVICE_CONTROL_NETBINDDISABLE        : 10,
SERVICE_CONTROL_DEVICEEVENT           : 11,
SERVICE_CONTROL_HARDWAREPROFILECHANGE : 12,
SERVICE_CONTROL_POWEREVENT            : 13,
SERVICE_CONTROL_SESSIONCHANGE         : 14,
SERVICE_ACTIVE                        : 1,
SERVICE_INACTIVE                      : 2,
SERVICE_STATE_ALL                     : 3,
SERVICE_QUERY_CONFIG                  : 1,
SERVICE_CHANGE_CONFIG                 : 2,
SERVICE_QUERY_STATUS                  : 4,
SERVICE_ENUMERATE_DEPENDENTS          : 8,
SERVICE_START                         : 16,
SERVICE_STOP                          : 32,
SERVICE_PAUSE_CONTINUE                : 64,
SERVICE_INTERROGATE                   : 128,
SERVICE_USER_DEFINED_CONTROL          : 256,
SERVICE_RUNS_IN_SYSTEM_PROCESS        : 1,
SERVICE_CONFIG_DESCRIPTION            : 1,
SERVICE_CONFIG_FAILURE_ACTIONS        : 2
}

__['SERVICE_DRIVER']   = (__.SERVICE_KERNEL_DRIVER|__.SERVICE_FILE_SYSTEM_DRIVER|__.SERVICE_RECOGNIZER_DRIVER);
__['SERVICE_WIN32']    = (__.SERVICE_WIN32_OWN_PROCESS|__.SERVICE_WIN32_SHARE_PROCESS);
__['SERVICE_TYPE_ALL'] = (__.SERVICE_WIN32|__.SERVICE_ADAPTER|__.SERVICE_DRIVER|__.SERVICE_INTERACTIVE_PROCESS);
__['SERVICE_ALL_ACCESS'] = (__.STANDARD_RIGHTS_REQUIRED|__.SERVICE_QUERY_CONFIG|__.SERVICE_CHANGE_CONFIG|__.SERVICE_QUERY_STATUS|__.SERVICE_ENUMERATE_DEPENDENTS|__.SERVICE_START|__.SERVICE_STOP|__.SERVICE_PAUSE_CONTINUE|__.SERVICE_INTERROGATE|__.SERVICE_USER_DEFINED_CONTROL);


var Win32Service = function(options){
	if (options === undefined)
		options = {};

	if (this.serviceName === undefined && this.serviceName === null) this.serviceName = options.serviceName;

	if (this.serviceName === undefined && this.serviceName === null)
		throw "must set serviceName argument";

	// load default setting
	this.load_default_setting();

	// merge options setting
	var status = options.status;
	for(var key in status){
		var value = status[key];
		this.status[key] = value;
	}

	//	this.startService();
}


Win32Service.default_status = {
	ServiceType             : __.SERVICE_WIN32_OWN_PROCESS,
	CurrentState            : __.SERVICE_STOPPED,
	ControlsAccepted        : __.SERVICE_ACCEPT_STOP,
	Win32ExitCode           : 0,
	ServiceSpecificExitCode : 0,
	CheckPoint              : 0,
	WaitHint                : 0
};

Win32Service.prototype = {
	load_default_setting: function(){
		this.status = {};
		var default_status = Win32Service.default_status
		for (var key in default_status) {
			var value = default_status[key];
			this.status[key] = value;
		}
	},
	install: function() {
	// body...
	},
	uninstall: function(){

	},
	start: function(){

	},
	stop: function(){

	},
	pause: function(){

	}
}

exports['Win32Service'] = Win32Service;
for (var constant in __){
	exports[constant] = __[constant];
}