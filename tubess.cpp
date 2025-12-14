#include <iostream>
#include "tubess.h"
using namespace std;

int totalLibrarySong = 0;

//BST LIBRARY
adrSong addSongToLibrary(adrSong root, infotypeSong data) {
    if (!root) {
        adrSong p = new SongNode;
        p->info = data;
        p->left = p->right = NULL;
        return p;
    }

    if (data.id < root->info.id)
        root->left = addSongToLibrary(root->left, data);
    else if (data.id > root->info.id)
        root->right = addSongToLibrary(root->right, data);
    else
        cout << "ID sudah ada!\n";

    return root;
}

void printLibraryHeader() {
    printf("%-5s %-20s %-20s %-15s %-10s\n",
           "ID", "Title", "Singer", "Genre", "Duration");
    printf("-------------------------------------------------------------------------\n");
}

void viewLibrarySong(adrSong root) {
    if (root != NULL) {
        viewLibrarySong(root->left);

        printf("%-5d %-20s %-20s %-15s %-10d\n",
               root->info.id,
               root->info.title.c_str(),
               root->info.singer.c_str(),
               root->info.genre.c_str(),
               root->info.duration);

        viewLibrarySong(root->right);
    }
}


adrSong searchSong(adrSong root, string title) {
    if (!root) return NULL;

    if (root->info.title == title)
        return root;

    adrSong left = searchSong(root->left, title);
    if (left) return left;

    return searchSong(root->right, title);
}

void updateSong(adrSong root, int id) {
    if (root == NULL) return;
    updateSong(root->left, id);
    if (root->info.id == id) {
        cout << "Ubah judul baru: ";
        cin.ignore();
        getline(cin, root->info.title);
    }
    updateSong(root->right, id);
}

adrSong deleteSong(adrSong root, int id) {
    if (!root) return root;
    if (id < root->info.id) root->left = deleteSong(root->left, id);
    else if (id > root->info.id) root->right = deleteSong(root->right, id);
    else {
        if (!root->left) {
            adrSong r = root->right;
            delete root;
            return r;
        } else if (!root->right) {
            adrSong l = root->left;
            delete root;
            return l;
        }
        adrSong temp = root->right;
        while (temp->left) temp = temp->left;
        root->info = temp->info;
        root->right = deleteSong(root->right, temp->info.id);
    }
    return root;
}

// DLL PLAYLIST SONG
adrPlaylistSong createPlaylistSong(infoPlaylistSong x) {
    adrPlaylistSong p = new playlistSongNode;
    p->info = x;
    p->prev = p->next = NULL;
    return p;
}

void addSongToPlaylist(adrPlaylist p, infoPlaylistSong x) {
    adrPlaylistSong s = createPlaylistSong(x);
    if (p->firstSong == NULL) {
        p->firstSong = s;
    } else {
        adrPlaylistSong q = p->firstSong;
        while (q->next) q = q->next;
        q->next = s;
        s->prev = q;
    }
}

void viewPlaylistSongs(adrPlaylist p) {
    adrPlaylistSong s = p->firstSong;
    while (s != NULL) {
        cout << "- " << s->info.data.title << endl;
        s = s->next;
    }
}

//MLL PLAYLIST
adrPlaylist createPlaylist(infoPlaylist x) {
    adrPlaylist p = new playlistNode;
    p->info = x;
    p->firstSong = NULL;
    p->next = NULL;
    return p;
}

void addPlaylist(adrPlaylist &first, adrPlaylist p) {
    if (!first) first = p;
    else {
        adrPlaylist q = first;
        while (q->next) q = q->next;
        q->next = p;
    }
}

adrPlaylist searchPlaylist(adrPlaylist first, string playlistName) {
    while (first != NULL) {
        if (first->info.playlistName == playlistName) return first;
        first = first->next;
    }
    return NULL;
}

void deletePlaylist(adrPlaylist &first, string playlistName) {
    adrPlaylist prev = NULL, p = first;
    while (p && p->info.playlistName != playlistName) {
        prev = p;
        p = p->next;
    }
    if (!p) return;

    if (!prev) first = p->next;
    else prev->next = p->next;

    // Hapus child
    adrPlaylistSong s = p->firstSong;
    while (s) {
        adrPlaylistSong del = s;
        s = s->next;
        delete del;
    }

    delete p;
}

void viewAllPlaylist(adrPlaylist first) {
    if (first == NULL) {
        cout << "Tidak ada playlist\n";
        return;
    }
    while (first) {
        cout << "[" << first->info.playlistName << "]\n";
        viewPlaylistSongs(first);
        cout << endl;
        first = first->next;
    }
}

//FAVORITE LIST (SLL)
void addFavoriteSong(adrFavSong &f, infotypeSong x) {
    adrFavSong p = new favSongNode;
    p->info = x;
    p->next = f;
    f = p;
}

void addFavoritePlaylist(adrFavPlaylist &f, infoPlaylist x) {
    adrFavPlaylist p = new favPlaylistNode;
    p->info = x;
    p->next = f;
    f = p;
}

void viewFavoriteSongs(adrFavSong f) {
    while (f) {
        cout << f->info.title << endl;
        f = f->next;
    }
}

void viewFavoritePlaylists(adrFavPlaylist f) {
    while (f) {
        cout << f->info.playlistName << endl;
        f = f->next;
    }
}

// QUEUE
void createQueue(Queue &q) {
    q.head = q.tail = NULL;
}

bool isEmptyQueue(Queue q) {
    return q.head == NULL;
}

void enqueue(Queue &q, infotypeSong x) {
    adrQNode p = new QNode;
    p->info = x;
    p->next = NULL;
    if (isEmptyQueue(q)) q.head = q.tail = p;
    else {
        q.tail->next = p;
        q.tail = p;
    }
}

infotypeSong dequeue(Queue &q) {
    infotypeSong dummy = {0, "", "", "", 0};

    if (isEmptyQueue(q)) return dummy;

    adrQNode p = q.head;
    q.head = p->next;
    if (!q.head) q.tail = NULL;

    infotypeSong x = p->info;
    delete p;
    return x;
}


// ACTIVE SONG
void playSong(infotypeSong x) {
    cout << "Playing: " << x.title << endl;
}

void stopSong() {
    cout << "Pause.\n";
}

void nextSong() { cout << "Next...\n"; }
void prevSong() { cout << "Prev...\n"; }

// MERGE SORT
adrPlaylistSong mergeDuration(adrPlaylistSong a, adrPlaylistSong b) {
    if (!a) return b;
    if (!b) return a;

    if (a->info.data.duration <= b->info.data.duration) {
        a->next = mergeDuration(a->next, b);
        return a;
    } else {
        b->next = mergeDuration(a, b->next);
        return b;
    }
}

adrPlaylistSong sortSongByDuration(adrPlaylistSong head) {
    if (!head || !head->next) return head;

    adrPlaylistSong slow = head, fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    adrPlaylistSong mid = slow->next;
    slow->next = NULL;

    adrPlaylistSong left = sortSongByDuration(head);
    adrPlaylistSong right = sortSongByDuration(mid);

    return mergeDuration(left, right);
}

adrPlaylistSong sortPlaylistByTitle(adrPlaylist head) {
    return sortSongByDuration(head->firstSong);
}

// RECOMMEND
infotypeSong recommendBySinger(adrSong root, string favSinger) {
    if (!root) return SongInfo{0,"","","",0};
    if (root->info.singer == favSinger)
        return root->info;

    infotypeSong L = recommendBySinger(root->left, favSinger);
    if (L.id != 0)
        return L;

    return recommendBySinger(root->right, favSinger);
}

infotypeSong recommendByGenre(adrSong root, string favGenre) {
    if (!root) return SongInfo{0,"","","",0};

    if (root->info.genre == favGenre)
        return root->info;

    infotypeSong L = recommendByGenre(root->left, favGenre);
    if (L.id != 0) return L;

    return recommendByGenre(root->right, favGenre);
}

// REMIX MOOD
string remixByYourMood(string mood) {
    if (mood == "happy") return " Pop ";
    if (mood == "sad") return " Indie ";
    if (mood == "focus") return " Lo-fi ";
    if (mood == "angry") return " Rock ";
    return "Random ";
}
