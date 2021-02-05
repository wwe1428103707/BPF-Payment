
file(GLOB_RECURSE SRC_LIST "*.cpp")
file(GLOB_RECURSE HEADERS "*.h")
add_library(precompiled ${SRC_LIST} ${HEADERS})

find_library(NTL_LIB ntl)
if(NOT GIT_FOUND)
  message(FATAL_ERROR "No ntl")
endif()

find_library(M_LIB m)
if(NOT GIT_FOUND)
  message(FATAL_ERROR "No m")
endif()

find_library(GMP_LIB libgmp.a)
if(NOT GIT_FOUND)
  message(FATAL_ERROR "No gmp")
endif()

target_link_libraries(precompiled PRIVATE blockverifier ethcore)
target_link_libraries(precompiled PUBLIC storage devcore JsonCpp)
target_link_libraries(precompiled PRIVATE Paillier GroupSig VRF)
add_subdirectory(extension)
