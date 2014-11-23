configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/config.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/config.h
)

include_directories(
    ${LIBVLC_INCLUDE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)
add_executable( vlc_meta_reader_bin 
    main.cpp 
)
target_link_libraries( vlc_meta_reader_bin 
    ${LIBVLC_LIBRARY}
)
set_target_properties( vlc_meta_reader_bin
    PROPERTIES
        RUNTIME_OUTPUT_NAME vlc-meta-reader
)

