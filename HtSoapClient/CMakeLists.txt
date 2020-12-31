

if(CMAKE_SYSTEM MATCHES "Linux")
    set(CMAKE_C_FLAGS "-fPIC -rdynamic")
    set(CMAKE_CXX_FLAGS "-fpermissive -fPIC -rdynamic")
endif()

aux_source_directory(. SRC_LIST)
    
INCLUDE_DIRECTORIES(.)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/Source/KOSA/inc)
get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
foreach(dir ${dirs})
  message(STATUS "Include dir='${dir}'")
endforeach()

LINK_DIRECTORIES(${PROJECT_BINARY_DIR}/lib)
if(PLATFORM STREQUAL KYLIN3)
    LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/Source/kylin3/KLDemo/lib)
endif()
if(PLATFORM STREQUAL CHEETAH1)
    LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/Source/Cheetah1/LinuxVersion/ctdemo_linux/bin)
endif()
get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY LINK_DIRECTORIES)
foreach(dir ${dirs})
  message(STATUS "Link dir='${dir}'")
endforeach()


add_library(ifChengDao_shared SHARED ${SRC_LIST})
SET_TARGET_PROPERTIES(ifChengDao_shared PROPERTIES OUTPUT_NAME "ifChengDao")
