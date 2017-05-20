
project(zad4)

set(HEDEAR_FILES Zad4.h)
set(SOURCE_FILES Zad4.cpp)

add_library(libzad4 STATIC ${SOURCE_FILES})
target_include_directories(libzad4 PUBLIC .)

add_executable(zad4 ${SOURCE_FILES} main.cpp)

target_link_libraries(zad4 libzad4)
