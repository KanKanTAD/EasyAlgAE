
set(TEST_LIB__ UnitTest++)

#include_directories(include ${VC_PKG_PATH__}\\include ${CGET_PKG_PATH__}/include)
link_directories(${VC_PKG_PATH__}\\lib\\x64 ${CGET_PKG_PATH}/lib)

add_executable(RandomTest RandomTest.cc)
target_link_libraries(RandomTest PUBLIC ${TEST_LIB__})



