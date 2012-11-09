var Win32Service = require('../build/Release/win32service.node').Win32Service;
var util = require("util");

function MyService(){
	this.className = "MyService";
	this.serviceName = "web_devcice_service";
}

util.inherits(MyService, Win32Service);

service = new MyService();

