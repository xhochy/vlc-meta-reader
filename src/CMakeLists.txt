include_directories(
    ${LIBVLC_INCLUDE_DIR}
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

