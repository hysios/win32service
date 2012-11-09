var util = require('util');
exports = modeule.exports
__ = CONSTANTIZES = {
SERVICE_KERNEL_DRIVER       : 1
SERVICE_FILE_SYSTEM_DRIVER  : 2
SERVICE_ADAPTER             : 4
SERVICE_RECOGNIZER_DRIVER   : 8
SERVICE_DRIVER              : (SERVICE_KERNEL_DRIVER|SERVICE_FILE_SYSTEM_DRIVER|SERVICE_RECOGNIZER_DRIVER)
SERVICE_WIN32_OWN_PROCESS   : 16
SERVICE_WIN32_SHARE_PROCESS : 32
SERVICE_WIN32               : (SERVICE_WIN32_OWN_PROCESS|SERVICE_WIN32_SHARE_PROCESS)
SERVICE_INTERACTIVE_PROCESS : 256
SERVICE_TYPE_ALL            : (SERVICE_WIN32|SERVICE_ADAPTER|SERVICE_DRIVER|SERVICE_INTERACTIVE_PROCESS)
SERVICE_BOOT_START          : 0
SERVICE_SYSTEM_START        : 1
SERVICE_AUTO_START          : 2
SERVICE_DEMAND_START        : 3
SERVICE_DISABLED            : 4
SERVICE_ERROR_IGNORE        : 0
SERVICE_ERROR_NORMAL        : 1
SERVICE_ERROR_SEVERE        : 2
SERVICE_ERROR_CRITICAL      : 3
}

exports['define'] = {
	SERVICE_WIN32_OWN_PROCESS :
}
var Win32Service = function(options){
	if (options === undefined)
		optinos = {};

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
