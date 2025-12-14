#ifndef TUBESS_H_INCLUDED
#define TUBESS_H_INCLUDED
using namespace std;

const int MAX_LIBRARY = 15;
extern int totalLibrarySong;
const int MAX_PLAYLIST = 5;
const int MAX_SONG_IN_PLAYLIST = 15;

struct SongInfo {
    int id;
    string title;
    string singer;
    string genre;
    int duration;
};
typedef SongInfo infotypeSong;

struct SongNode {
    infotypeSong info;
    SongNode *left;
    SongNode *right;
};
typedef SongNode* adrSong;

struct playlistSongInfo{
    infotypeSong data;
};
typedef playlistSongInfo infoPlaylistSong;

struct playlistSongNode {
    infoPlaylistSong info;
    playlistSongNode *prev;
    playlistSongNode *next;
};
typedef playlistSongNode* adrPlaylistSong;

struct playlistInfo{
    int playlistId;
    string playlistName;
};
typedef playlistInfo infoPlaylist;

struct playlistNode {
    infoPlaylist info;
    adrPlaylistSong firstSong;
    playlistNode *next;
};
typedef playlistNode* adrPlaylist;

struct favSongNode {
    infotypeSong info;
    favSongNode *next;
};
typedef favSongNode* adrFavSong;

struct favPlaylistNode {
    infoPlaylist info;
    favPlaylistNode *next;
};
typedef favPlaylistNode* adrFavPlaylist;

struct QNode {
    infotypeSong info;
    QNode *next;
};
typedef QNode* adrQNode;

struct Queue {
    adrQNode head;
    adrQNode tail;
};


adrSong addSongToLibrary(adrSong root, infotypeSong data);
void viewLibrarySong(adrSong root);
void updateSong(adrSong root, int id);
adrSong deleteSong(adrSong root, int id);
adrSong searchSong(adrSong root, string title);


adrPlaylistSong createPlaylistSong(infoPlaylistSong x);
void addSongToPlaylist(adrPlaylist p, infoPlaylistSong x);
void viewPlaylistSongs(adrPlaylist p);


adrPlaylist createPlaylist(infoPlaylist x);
void addPlaylist(adrPlaylist &first, adrPlaylist p);
void deletePlaylist(adrPlaylist &first, string playlistName);
adrPlaylist searchPlaylist(adrPlaylist first, string playlistName);
void viewAllPlaylist(adrPlaylist first);
void printLibraryHeader();


void addFavoriteSong(adrFavSong &f, infotypeSong x);
void addFavoritePlaylist(adrFavPlaylist &f, infoPlaylist x);
void viewFavoriteSongs(adrFavSong f);
void viewFavoritePlaylists(adrFavPlaylist f);


void createQueue(Queue &q);
void enqueue(Queue &q, infotypeSong x);
infotypeSong dequeue(Queue &q);
bool isEmptyQueue(Queue q);


void playSong(infotypeSong x);
void stopSong();
void nextSong();
void prevSong();


adrPlaylistSong sortSongByDuration(adrPlaylistSong head);
adrPlaylistSong sortPlaylistByTitle(adrPlaylist head);


infotypeSong recommendBySinger(adrSong root, string favSinger);
infotypeSong recommendByGenre(adrSong root, string favGenre);


string remixByYourMood(string mood);


#endif // TUBESS_H_INCLUDED
