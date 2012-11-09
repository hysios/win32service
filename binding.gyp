{
  'targets': [
    {
      'target_name': 'win32service',
      'sources': [ 'src/win32.cc', 'src/win32service.cc', 'src/service_status.cc' ]
    }
  ],
  'conditions': [
    ['OS=="win"', {
      'defines': ['WINDOWS']
    }], 
    ['OS=="linux"', {
      'defines': ['LINUX']
    }]
  ]
}