cmake_minimum_required(VERSION 3.16)
project(EasyAlgAE)
set(CMAKE_CXX_STANDARD 14)
# demos

set(VC_PKG_PATH__ "C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Professional\\VC\\Auxiliary\\VS")
set(CGET_PKG_PATH__ ./cget)

set(LIB__ spdlog)

include_directories(include ${VC_PKG_PATH__}\\include ${CGET_PKG_PATH__}/include)
link_directories(${VC_PKG_PATH__}\\lib\\x64 ${CGET_PKG_PATH}/lib)

add_subdirectory(tests)

add_executable(demo_1 demos/demo_1.cc)
target_link_libraries(demo_1 ${LIB__})

