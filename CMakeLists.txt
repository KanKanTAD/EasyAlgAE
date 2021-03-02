cmake_minimum_required(VERSION 3.16)
project(EasyAlgAE)
set(CMAKE_CXX_STANDARD 17)
# demos

set(VC_PKG_PATH__ "C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Professional\\VC\\Auxiliary\\VS")

include_directories(include ${VC_PKG_PATH__}\\include)
link_directories(${VC_PKG_PATH__}\\lib\\x64)

add_executable(demo_1 demos/demo_1.cc)
