### Compilation

```bash
g++ demo.cpp -L/Users/gregory1/Downloads/wxWidgets-3.1.4/build-cocoa-debug/lib   -framework IOKit -framework Carbon -framework Cocoa -framework AudioToolbox -framework System -framework OpenGL -lwx_osx_cocoau_xrc-3.1 -lwx_osx_cocoau_html-3.1 -lwx_osx_cocoau_qa-3.1 -lwx_osx_cocoau_core-3.1 -lwx_baseu_xml-3.1 -lwx_baseu_net-3.1 -lwx_baseu-3.1 -I/Users/gregory1/Downloads/wxWidgets-3.1.4/build-cocoa-debug/lib/wx/include/osx_cocoa-unicode-3.1 -I/Users/gregory1/Downloads/wxWidgets-3.1.4/include -D_FILE_OFFSET_BITS=64 -DWXUSINGDLL -D__WXMAC__ -D__WXOSX__ -D__WXOSX_COCOA__
```
