#include <iostream>

#include <vlc/libvlc.h>
#include <vlc/libvlc_media.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Please specify exactly a single file." << std::endl;
        exit(EXIT_FAILURE);
    }

    libvlc_instance_t *vlcInstance = libvlc_new(0, nullptr);
    if (!vlcInstance) {
        std::cerr << "Could not initialise VLC" << std::endl;
        exit(EXIT_FAILURE);
    }

    libvlc_media_t* media = libvlc_media_new_path(vlcInstance, argv[1]);
    if (!media) {
        std::cerr << "Could not initialise media" << std::endl;
        exit(EXIT_FAILURE);
    }

    libvlc_media_parse(media);
    char *artist = libvlc_media_get_meta(media, libvlc_meta_Artist);
    if (artist) {
        std::cout << "Artist: " << artist << std::endl;
        free(artist);
    }

    libvlc_media_release(media);
    libvlc_release(vlcInstance);
}
