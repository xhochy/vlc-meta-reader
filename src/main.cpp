#include <iostream>

#include <vlc/libvlc.h>
#include <vlc/libvlc_media.h>

void vlcMetaPrint(const char* prefix, libvlc_media_t* media, libvlc_meta_t meta) {
    libvlc_media_parse(media);
    char *str = libvlc_media_get_meta(media, meta);
    if (str) {
        std::cout << prefix << ": " << str << std::endl;
        free(str);
    }
}

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

    libvlc_time_t duration = libvlc_media_get_duration(media);
    if (duration > 0) {
        std::cout << "Duration: "
                  << duration / 1000.0
                  << "s" << std::endl;
    }

    vlcMetaPrint("Artist", media, libvlc_meta_Artist);
    vlcMetaPrint("Title", media, libvlc_meta_Title);
    vlcMetaPrint("Genre", media, libvlc_meta_Genre);
    vlcMetaPrint("Copyright", media, libvlc_meta_Copyright);
    vlcMetaPrint("Album", media, libvlc_meta_Album);
    vlcMetaPrint("Track no:", media, libvlc_meta_TrackNumber);
    vlcMetaPrint("Description", media, libvlc_meta_Description);
    vlcMetaPrint("Rating", media, libvlc_meta_Rating);
    vlcMetaPrint("Date", media, libvlc_meta_Date);
    vlcMetaPrint("Setting", media, libvlc_meta_Setting);
    vlcMetaPrint("URL", media, libvlc_meta_URL);
    vlcMetaPrint("Language", media, libvlc_meta_Language);
    // FIXME: Is this present on any file metadata?
    // vlcMetaPrint("", media, libvlc_meta_NowPlaying);
    vlcMetaPrint("Publisher", media, libvlc_meta_Publisher);
    vlcMetaPrint("EncodedBy", media, libvlc_meta_EncodedBy);
    vlcMetaPrint("Artwork URL", media, libvlc_meta_ArtworkURL);
    vlcMetaPrint("Track ID", media, libvlc_meta_TrackID);
    vlcMetaPrint("Track total", media, libvlc_meta_TrackTotal);
    vlcMetaPrint("Director", media, libvlc_meta_Director);
    vlcMetaPrint("Season", media, libvlc_meta_Season);
    vlcMetaPrint("Episode", media, libvlc_meta_Episode);
    vlcMetaPrint("ShowName", media, libvlc_meta_ShowName);
    vlcMetaPrint("Actors", media, libvlc_meta_Actors);
#ifdef HAVE_VLC_ALBUMARTIST
    vlcMetaPrint("AlbumArtist", media, libvlc_meta_AlbumArtist);
#endif

    libvlc_media_track_t **tracks;
    uint track_count;
    if ((track_count = libvlc_media_tracks_get(media, &tracks)) > 0) {
        for (uint i = 0; i < track_count; i++) {
            std::cout << "Bitrate (track #" << (i + 1)
                      << "): " << tracks[i]->i_bitrate
                      << std::endl;
        }
        libvlc_media_tracks_release(tracks, track_count);
    }

    libvlc_media_release(media);
    libvlc_release(vlcInstance);
}
