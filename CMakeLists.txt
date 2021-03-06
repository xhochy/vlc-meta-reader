project( vlc_meta_reader )
cmake_minimum_required( VERSION 2.8.6 )
set( CMAKE_MODULE_PATH  "${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules" )

find_package(LIBVLC REQUIRED)

include(CheckCXXCompilerFlag)
check_cxx_compiler_flag( "-std=c++11" CXX11_FOUND )
check_cxx_compiler_flag( "-std=c++0x" CXX0X_FOUND )
check_cxx_compiler_flag( "-stdlib=libc++" LIBCPP_FOUND )
if(CXX11_FOUND)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(CXX0X_FOUND)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(FATAL_ERROR "${CMAKE_CXX_COMPILER} does not support C++11, please use a
    different compiler")
endif()
if(LIBCPP_FOUND AND APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
endif()

include(CheckCXXSourceCompiles)
check_cxx_source_compiles("
#include <vlc/libvlc.h>
#include <vlc/libvlc_media.h>

int main(int argc, char *argv[]) {
    libvlc_meta_t meta = libvlc_meta_AlbumArtist;
}"
HAVE_VLC_ALBUMARTIST)

add_subdirectory(src)

