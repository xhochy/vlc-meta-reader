find_package(PkgConfig QUIET)
pkg_check_modules(PC_LIBVLC QUIET libvlc)
set(LIBVLC_DEFINITIONS ${PC_LIBVLC_CFLAGS_OTHER})

find_path(LIBVLC_INCLUDE_DIR vlc/libvlc.h
    HINTS
        ${PC_LIBVLC_INCLUDEDIR}
        ${PC_LIBVLC_INCLUDE_DIRS}
)

find_library(LIBVLC_LIBRARY NAMES vlc libvlc
    HINTS
        ${PC_LIBVLC_LIBDIR}
        ${PC_LIBVLC_LIBRARY_DIRS}
)

set(LIBVLC_VERSION ${PC_LIBVLC_VERSION})

find_package_handle_standard_args(LibVLC
    REQUIRED_VARS LIBVLC_LIBRARY LIBVLC_INCLUDE_DIR
    VERSION_VAR LIBVLC_VERSION
)

 
