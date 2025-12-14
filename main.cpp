#include <iostream>
#include "tubess.h"
#include <limits>
using namespace std;

int main() {
    adrSong library = NULL;
    adrPlaylist firstPlaylist = NULL;
    adrFavSong favSong = NULL;
    adrFavPlaylist favPlaylist = NULL;

    Queue q;
    createQueue(q);

    infotypeSong data, currentSong;
    int choice, id;
    bool isPlaying = false;

    //  DUMMY
        library = addSongToLibrary(library, {0,"Sakura Trees","Saib","Lo-fi",90});
        library = addSongToLibrary(library, {1,"Reflection","Nerd Odyssey","Lo-fi",159});
        library = addSongToLibrary(library, {2,"Snowman","lofi girl","Lo-fi",195});
        library = addSongToLibrary(library, {3,"Toxic","Britney Spears","Pop",200});
        library = addSongToLibrary(library, {4,"Levitating","Dua Lipa","Pop",203});
        library = addSongToLibrary(library, {5,"Bad Guy","Billie Eilish","Pop",194});
        library = addSongToLibrary(library, {6,"As It Was","Harry Styles","Pop",161});
        library = addSongToLibrary(library, {7,"Bohemian Rhapsody","Queen","Rock",354});
        library = addSongToLibrary(library, {8,"Hotel California","Eagles","Rock",301});
        library = addSongToLibrary(library, {9,"We Will Rock You","Queen","Rock",123});
        library = addSongToLibrary(library, {10,"Zombie","The Cranberries","Rock",309});
        library = addSongToLibrary(library, {11,"Monokrom","Tulus","Indie",219});
        library = addSongToLibrary(library, {12,"Bertaut","Nadin Amizah","Indie",320});
        library = addSongToLibrary(library, {13,"Satu Bulan","Bernadya","Indie",230});
        library = addSongToLibrary(library, {14,"Rehat","Kunto Aji","Indie",361});

        // Tambahkan ke queue
        enqueue(q, {0,"Sakura Trees","Saib","Lofi",90});
        enqueue(q, {1,"Reflection","Nerd Odyssey","Lofi",159});
        enqueue(q, {2,"Snowman","lofi girl","Lofi",195});
        enqueue(q, {3,"Toxic","Britney Spears","Pop",200});
        enqueue(q, {4,"Levitating","Dua Lipa","Pop",203});
        enqueue(q, {5,"Bad Guy","Billie Eilish","Pop",194});
        enqueue(q, {6,"As It Was","Harry Styles","Pop",161});
        enqueue(q, {7,"Bohemian Rhapsody","Queen","Rock",354});
        enqueue(q, {8,"Hotel California","Eagles","Rock",301});
        enqueue(q, {9,"We Will Rock You","Queen","Rock",123});
        enqueue(q, {10,"Zombie","The Cranberries","Rock",309});
        enqueue(q, {11,"Monokrom","Tulus","Indie",219});
        enqueue(q, {12,"Rayuan Perempuan Gila","Nadin Amizah","Indie",320});
        enqueue(q, {13,"Satu Bulan","Bernadya","Indie",230});
        enqueue(q, {14,"Rehat","Kunto Aji","Indie",361});


    // ROLE
    string role;
    do {
        printf("\n+-------------------------------+\n");
        printf("|        LOGIN SISTEM           |\n");
        printf("+-------------------------------+\n");
        printf("| Login sebagai:                |\n");
        printf("|  admin / user / exit          |\n");
        printf("+-------------------------------+\n");
        printf(" Pilihan: ");
        cin >> role;
        cout << " " << endl;

        /* MENU ADMIN */
        if (role == "admin") {
            do {
                printf("\n+--------------------------------+\n");
                printf("|          MENU ADMIN            |\n");
                printf("+--------------------------------+\n");
                printf("| 1. Tambah Lagu Baru ke Library |\n");
                printf("| 2. Hapus Lagu di Library       |\n");
                printf("| 3. Update Lagu di Library      |\n");
                printf("| 4. Lihat Daftar Lagu           |\n");
                printf("| 0. Logout                      |\n");
                printf("+--------------------------------+\n");
                printf(" Pilih menu: ");
                scanf("%d", &choice);
                printf("\n");


                switch (choice) {
                    case 1:
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "ID Lagu      : "; cin >> data.id;
                    cin.ignore();
                    cout << "Judul Lagu   : "; getline(cin, data.title);
                    cout << "Singer       : "; getline(cin, data.singer);
                    cout << "Genre        : "; getline(cin, data.genre);
                    cout << "Durasi       : "; cin >> data.duration;

                    library = addSongToLibrary(library, data);
                    cout << "Lagu berhasil ditambahkan\n";
                    break;


                    case 2:
                        cout << "ID Lagu: ";
                        cin >> id;
                        library = deleteSong(library, id);
                        cout << "Lagu dihapus\n";
                        break;

                    case 3:
                        cout << "ID Lagu: ";
                        cin >> id;
                        updateSong(library, id);
                        cout << "Lagu diupdate\n";
                        break;

                    case 4:
                        printLibraryHeader();
                        viewLibrarySong(library);
                        break;

                    case 0:
                        cout << "Anda telah logout sebagai Admin.\n";
                        break;

                    default:
                        cout << "Menu tidak valid\n";
                }
            } while (choice != 0);
        }

        /* MENU USER */
        else if (role == "user") {
            int userMenu;
            do {
                printf("\n+--------------------------------+\n");
                printf("|           MENU USER            |\n");
                printf("+--------------------------------+\n");
                printf("| 1. Library                     |\n");
                printf("| 2. Playlist                    |\n");
                printf("| 3. Active Song / Player        |\n");
                printf("| 0. Logout                      |\n");
                printf("+--------------------------------+\n");
                printf(" Pilih menu: ");
                scanf("%d", &userMenu);
                printf("\n");

                switch (userMenu) {

                // ================== LIBRARY ==================
                case 1: {
                    int libMenu;
                    do {
                        printf("\n+-----------------------------------------------+\n");
                        printf("|                MENU LIBRARY                   |\n");
                        printf("+-----------------------------------------------+\n");
                        printf("| 1. Lihat Semua Lagu di Library                |\n");
                        printf("| 2. Rekomendasi Lagu (Genre)                   |\n");
                        printf("| 3. Rekomendasi Lagu (Singer)                  |\n");
                        printf("| 4. Remix by Mood                              |\n");
                        printf("| 5. Tambah Lagu ke Favorit                     |\n");
                        printf("| 0. Kembali                                    |\n");
                        printf("+-----------------------------------------------+\n");
                        printf(" Pilih menu: ");
                        scanf("%d", &libMenu);
                        printf("\n");

                        switch (libMenu) {
                            case 1: {
                                printLibraryHeader();
                                viewLibrarySong(library);
                                break;
                            }
                            case 2: {
                                cin.ignore();
                                string g;
                                cout << "Genre: ";
                                getline(cin, g);
                                infotypeSong r = recommendByGenre(library, g);
                                if (r.id) cout << "Rekomendasi: " << r.title << endl;
                                else cout << "Tidak ada rekomendasi\n";
                                break;
                            }

                            case 3: {
                                cin.ignore();
                                string s;
                                cout << "Singer: ";
                                getline(cin, s);
                                infotypeSong r = recommendBySinger(library, s);
                                if (r.id) cout << "Rekomendasi: " << r.title << endl;
                                else cout << "Tidak ada rekomendasi\n";
                                break;
                            }

                            case 4: {
                                cin.ignore();
                                string mood;
                                cout << "Mood: ";
                                getline(cin, mood);
                                cout << "Genre cocok: " << remixByYourMood(mood) << endl;
                                break;
                            }

                            case 5: {
                                int pilih;
                                cout << "Tambah favorit:\n";
                                cout << "1. Lagu\n";
                                cout << "2. Playlist\n";
                                cout << "Pilihan: ";
                                cin >> pilih;

                                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                // ================= FAVORIT LAGU =================
                                if (pilih == 1) {
                                    string judul;
                                    cout << "Judul lagu: ";
                                    getline(cin, judul);

                                    adrSong s = searchSong(library, judul);
                                    if (!s) {
                                        cout << "Lagu tidak ditemukan di library\n";
                                        break;
                                    }

                                    addFavoriteSong(favSong, s->info);
                                    cout << "Lagu berhasil ditambahkan ke favorit\n";
                                }

                                // ================= FAVORIT PLAYLIST =================
                                else if (pilih == 2) {
                                    string pl;
                                    cout << "Nama playlist: ";
                                    getline(cin, pl);

                                    adrPlaylist p = searchPlaylist(firstPlaylist, pl);
                                    if (!p) {
                                        cout << "Playlist tidak ditemukan\n";
                                        break;
                                    }

                                    addFavoritePlaylist(favPlaylist, p->info);
                                    cout << "Playlist berhasil ditambahkan ke favorit\n";
                                }
                                else {
                                    cout << "Pilihan tidak valid\n";
                                    break;
                                }

                                // ================= TAMPILKAN FAVORIT =================
                                cout << "\n===== FAVORIT LAGU =====\n";
                                if (!favSong) cout << "Belum ada lagu favorit\n";
                                else viewFavoriteSongs(favSong);

                                cout << "\n===== FAVORIT PLAYLIST =====\n";
                                if (!favPlaylist) cout << "Belum ada playlist favorit\n";
                                else viewFavoritePlaylists(favPlaylist);

                                break;
                            }
                        }
                    } while (libMenu != 0);
                    break;
                }

                // ================== PLAYLIST ==================
                case 2: {
                    int plMenu;
                    do {
                        printf("\n+-----------------------------------------------+\n");
                        printf("|               MENU PLAYLIST                  |\n");
                        printf("+-----------------------------------------------+\n");
                        printf("| 1. Lihat Semua Playlist                      |\n");
                        printf("| 2. Cari Playlist                             |\n");
                        printf("| 3. Buat Playlist Baru                        |\n");
                        printf("| 4. Hapus Playlist                            |\n");
                        printf("| 5. Tambah Lagu ke Playlist                   |\n");
                        printf("| 6. Hapus Lagu dari Playlist                  |\n");
                        printf("| 7. Cari Lagu di Playlist                     |\n");
                        printf("| 8. Sort Lagu Playlist (Durasi)               |\n");
                        printf("| 9. Tambah Playlist ke Favorit                |\n");
                        printf("| 0. Kembali                                   |\n");
                        printf("+-----------------------------------------------+\n");
                        printf(" Pilih menu: ");
                        scanf("%d", &plMenu);
                        printf("\n");

                        switch (plMenu){
                            case 1:
                                viewAllPlaylist(firstPlaylist);
                                break;
                            case 2:{
                                string plName;
                                cout << "Cari playlist: ";
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                getline(cin, plName);

                                adrPlaylist p = searchPlaylist(firstPlaylist, plName);
                                if (!p) {
                                    cout << "Playlist tidak ditemukan\n";
                                    break;
                                }

                                cout << "\nPlaylist ditemukan!\n";
                                cout << "Nama Playlist : " << p->info.playlistName << endl;

                                if (!p->firstSong) {
                                    cout << "Playlist kosong\n";
                                } else {
                                    cout << "\nDaftar Lagu:\n";
                                    viewPlaylistSongs(p);
                                }
                                break;
                            }
                            case 3:{
                                string plName;
                                cout << "Nama playlist baru: ";
                                cin.ignore();
                                getline(cin, plName);
                                if (searchPlaylist(firstPlaylist, plName)) cout << "Playlist sudah ada\n";
                                else {
                                    infoPlaylist info;
                                    info.playlistId = 1;
                                    info.playlistName = plName;
                                    adrPlaylist p = createPlaylist(info);
                                    addPlaylist(firstPlaylist, p);
                                    cout << "Playlist berhasil dibuat\n";
                                }
                                break;
                            }
                            case 4:{
                                string pl;
                                cout << "Nama playlist: ";
                                cin.ignore();
                                getline(cin, pl);
                                deletePlaylist(firstPlaylist, pl);
                                cout << "Playlist dihapus\n";
                                break;
                            }
                            case 5:{
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                string pl, title;
                                cout << "Nama playlist: "; getline(cin, pl);
                                cout << "Judul lagu   : "; getline(cin, title);

                                adrPlaylist p = searchPlaylist(firstPlaylist, pl);
                                adrSong s = searchSong(library, title);

                                if (p && s) {
                                    infoPlaylistSong x;
                                    x.data = s->info;
                                    addSongToPlaylist(p, x);
                                    cout << "Lagu ditambahkan ke playlist\n";
                                } else cout << "Playlist / Lagu tidak ditemukan\n";
                                break;
                            }
                            case 6:{
                                string playlistName, title;

                                cout << "Nama playlist: ";
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                getline(cin, playlistName);

                                adrPlaylist p = searchPlaylist(firstPlaylist, playlistName);
                                if (!p) {
                                    cout << "Playlist tidak ditemukan\n";
                                    break;
                                }

                                cout << "Judul lagu yang akan dihapus: ";
                                getline(cin, title);

                                adrPlaylistSong cur = p->firstSong;

                                while (cur && cur->info.data.title != title)
                                    cur = cur->next;

                                if (!cur) {
                                    cout << "Lagu tidak ditemukan di playlist\n";
                                    break;
                                }

                                // unlink node
                                if (cur->prev)
                                    cur->prev->next = cur->next;
                                else
                                    p->firstSong = cur->next;

                                if (cur->next)
                                    cur->next->prev = cur->prev;

                                delete cur;
                                cout << "Lagu berhasil dihapus dari playlist\n";
                                break;
                            }
                            case 7: {
                                string title;
                                cout << "Judul lagu: ";
                                cin.ignore();
                                getline(cin, title);
                                adrSong s = searchSong(library, title);
                                if (s) cout << "Ditemukan: " << s->info.title << endl;
                                else cout << "Lagu tidak ditemukan\n";
                                break;
                            }
                            case 8:{
                                string pl;
                                cout << "Nama playlist: ";
                                cin.ignore();
                                getline(cin, pl);

                                adrPlaylist p = searchPlaylist(firstPlaylist, pl);
                                if(p) {

                                    p->firstSong = sortSongByDuration(p->firstSong);


                                    cout << "Playlist '" << pl << "' setelah di-sort berdasarkan durasi:\n";
                                    adrPlaylistSong cur = p->firstSong;
                                    while(cur) {
                                        cout << "- " << cur->info.data.title
                                            << " (" << cur->info.data.duration << "s)\n";
                                        cur = cur->next;
                                    }
                                }
                                else cout << "Playlist tidak ditemukan\n";
                                break;
                            }
                            case 9:{
                                int pilih;
                                cout << "Tambah favorit:\n";
                                cout << "1. Lagu\n";
                                cout << "2. Playlist\n";
                                cout << "Pilihan: ";
                                cin >> pilih;

                                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                // ================= FAVORIT LAGU =================
                                if (pilih == 1) {
                                    string judul;
                                    cout << "Judul lagu: ";
                                    getline(cin, judul);

                                    adrSong s = searchSong(library, judul);
                                    if (!s) {
                                        cout << "Lagu tidak ditemukan di library\n";
                                        break;
                                    }

                                    addFavoriteSong(favSong, s->info);
                                    cout << "Lagu berhasil ditambahkan ke favorit\n";
                                }

                                // ================= FAVORIT PLAYLIST =================
                                else if (pilih == 2) {
                                    string pl;
                                    cout << "Nama playlist: ";
                                    getline(cin, pl);

                                    adrPlaylist p = searchPlaylist(firstPlaylist, pl);
                                    if (!p) {
                                        cout << "Playlist tidak ditemukan\n";
                                        break;
                                    }

                                    addFavoritePlaylist(favPlaylist, p->info);
                                    cout << "Playlist berhasil ditambahkan ke favorit\n";
                                }
                                else {
                                    cout << "Pilihan tidak valid\n";
                                    break;
                                }

                                // ================= TAMPILKAN FAVORIT =================
                                cout << "\n===== FAVORIT LAGU =====\n";
                                if (!favSong) cout << "Belum ada lagu favorit\n";
                                else viewFavoriteSongs(favSong);

                                cout << "\n===== FAVORIT PLAYLIST =====\n";
                                if (!favPlaylist) cout << "Belum ada playlist favorit\n";
                                else viewFavoritePlaylists(favPlaylist);

                                break;
                            }
                        }

                    } while (plMenu != 0);
                    break;
                }

                // ================== PLAYER ==================
                case 3: {
                    int p;
                    bool isPlaying = false;

                    infotypeSong currentSong;
                    adrPlaylistSong currentPlaylistSong = NULL;
                    bool fromPlaylist = false;

                        do {
                            printf("\n+--------------------------------+\n");
                            printf("|        ACTIVE SONG PLAYER      |\n");
                            printf("+--------------------------------+\n");
                            printf("| 1. Play                        |\n");
                            printf("| 2. Pause                       |\n");
                            printf("| 3. Previous                    |\n");
                            printf("| 4. Next                        |\n");
                            printf("| 0. Kembali                     |\n");
                            printf("+--------------------------------+\n");
                            printf(" Pilih menu: ");
                            scanf("%d", &p);
                            printf("\n");

                            switch (p) {

                            // ================= PLAY =================
                            case 1: {
                                int playOpt;
                                cout << "\nPlay dari:\n";
                                cout << "1. Playlist\n";
                                cout << "2. Song (Library)\n";
                                cout << "0. Batal\n";
                                cout << "Pilihan: ";
                                cin >> playOpt;

                                // ===== PLAY DARI PLAYLIST =====
                                if (playOpt == 1) {
                                    string plName;
                                    cout << "Nama playlist: ";
                                    cin.ignore();
                                    getline(cin, plName);

                                    adrPlaylist pList = searchPlaylist(firstPlaylist, plName);
                                    if (!pList) {
                                        cout << "Playlist tidak ditemukan\n";
                                        break;
                                    }

                                    if (!pList->firstSong) {
                                        cout << "Playlist kosong\n";
                                        break;
                                    }

                                    currentPlaylistSong = pList->firstSong;
                                    currentSong = currentPlaylistSong->info.data;
                                    fromPlaylist = true;
                                    isPlaying = true;

                                    cout << "Now playing from playlist [" << plName << "]: "
                                        << currentSong.title
                                        << " (" << currentSong.duration << "s)\n";
                                }

                                // ===== PLAY DARI LIBRARY =====
                                else if (playOpt == 2) {
                                    cout << "\nDaftar Lagu di Library:\n";
                                    viewLibrarySong(library);

                                    string title;
                                    cout << "\nPilih judul lagu: ";
                                    cin.ignore();
                                    getline(cin, title);

                                    adrSong s = searchSong(library, title);
                                    if (s) {
                                        currentSong = s->info;
                                        fromPlaylist = false;
                                        currentPlaylistSong = NULL;
                                        isPlaying = true;

                                        cout << "Now playing: "
                                            << currentSong.title
                                            << " (" << currentSong.duration << "s)\n";
                                    } else {
                                        cout << "Lagu tidak ditemukan\n";
                                    }
                                }
                                break;
                            }

                            // ================= PAUSE =================
                            case 2:
                                if (isPlaying) {
                                    cout << "Paused: " << currentSong.title << endl;
                                    isPlaying = false;
                                } else {
                                    cout << "Tidak ada lagu yang diputar\n";
                                }
                                break;

                            // ================= PREVIOUS =================
                            case 3:
                                if (fromPlaylist) {
                                    if (currentPlaylistSong && currentPlaylistSong->prev) {
                                        currentPlaylistSong = currentPlaylistSong->prev;
                                        currentSong = currentPlaylistSong->info.data;

                                        cout << "Now playing previous: "
                                            << currentSong.title
                                            << " (" << currentSong.duration << "s)\n";
                                        isPlaying = true;
                                    } else {
                                        cout << "Tidak ada lagu sebelumnya di playlist\n";
                                    }
                                } else {
                                    cout << "Previous song tidak tersedia untuk library\n";
                                }
                                break;


                            // ================= NEXT =================
                            case 4:
                                if (fromPlaylist) {
                                    if (currentPlaylistSong &&
                                        currentPlaylistSong->next) {

                                        currentPlaylistSong = currentPlaylistSong->next;
                                        currentSong = currentPlaylistSong->info.data;

                                        cout << "Now playing next: "
                                            << currentSong.title
                                            << " (" << currentSong.duration << "s)\n";
                                        isPlaying = true;
                                    } else {
                                        cout << "Playlist sudah habis\n";
                                        isPlaying = false;
                                    }
                                }
                                else {
                                    if (!isEmptyQueue(q)) {
                                        currentSong = dequeue(q);
                                        cout << "Now playing next: "
                                            << currentSong.title
                                            << " (" << currentSong.duration << "s)\n";
                                        isPlaying = true;
                                    } else {
                                        cout << "Queue kosong\n";
                                        isPlaying = false;
                                    }
                                }
                                break;

                            case 0:
                                cout << "Kembali ke menu user\n";
                                break;

                            default:
                                cout << "Pilihan tidak valid\n";
                            }

                        } while (p != 0);

                        break;
                }

                case 0:
                    cout << "Logout user\n";
                    break;
                }

            } while (userMenu != 0);
        }

    } while (role != "exit");

    cout << "\nPROGRAM SELESAI\n";
    return 0;
}
