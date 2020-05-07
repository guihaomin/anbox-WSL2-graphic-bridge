# anbox-WSL2-graphic-bridge
Implemented graphic bridging from anbox on WSL2 to render application on win10.
<br>
## Setup
The bridging process is from unix pipe(qemu_pipe) on WSL2 to a given WSL2 IP port using socat. Note that WSL2 uses dynamic IP address so the generated IP address needs to be wrote to configuration file.
<br>
Open sln file in visual studio and install all dependency using vcpkg.<br>
The graphic translator library is loaded at run time, you have to compile swiftshader egl library for this project.
## Issues
There are bugs in window connection part that graphic rendering result cannot be seen on window.
## Future
The input bridging is not implemented.
# Acknowledgement
This project is based on anbox: https://github.com/anbox/anbox
