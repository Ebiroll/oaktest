# oaktest
Test of codespaces and docker with the OAK-D POE camera

Until a proper codespace it set up do,

Already  Installed by codespace 
> sudo apt-get install  libopencv-dev


Do this
 git clone https://github.com/luxonis/depthai-core
 git submodule update --init --recursive
 mkdir build
 cd build; cmake ..


 No need to build, 
# cmake -S. -Bbuild
# cmake  --build build
