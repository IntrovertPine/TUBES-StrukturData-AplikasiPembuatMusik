# TUBES-StrukturData-AplikasiPembuatMusik

A. ANGGOTA KELOMPOK : 
  1. Annisa Nasywa Nugroho	  103052400044
  2. Diatenta Br Sembiring		103052400073
  3. Nashwan Zaydan K.	 	    103052400076

B. DESKRIPSI APLIKASI :

  Aplikasi ini merupakan program manajemen musik berbasis C++ yang dirancang menggunakan berbagai struktur data seperti Binary Search Tree (BST), Multi Linked List (MLL), Double Linked List (DLL), Single Linked List (SLL), dan Queue.

  Aplikasi ini memungkinkan pengguna untuk:
  1. Mengelola library lagu.
  2. Membuat dan mengelola playlist.
  3. Menandai lagu dan playlist favorit.
  4. Mendapatkan rekomendasi lagu berdasarkan genre, singer, dan mood.

  Program berjalan melalui console/terminal dan memiliki dua peran pengguna, yaitu Admin dan User.

C. STRUKTUR DATA YANG DIGUNAKAN :
  - Binary Search Tree (BST) = Library lagu
  - Multi Linked List (MLL) = Playlist
  - Double Linked List (DLL) = Lagu dalam playlist
  - Single Linked List (SLL) = Lagu & playlist favorit
  - Queue = Antrian pemutaran lagu
  - Merge Sort = Pengurutan lagu berdasarkan durasi

D. FITUR APLIKASI:
  1. Fitur Admin:
     - Menambahkan lagu baru ke library
     - Menghapus lagu dari library
     - Mengupdate data lagu
     - Melihat seluruh daftar lagu di library
  3. Fitur User:
     - Melihat semua lagu di library
     - Mencari lagu berdasarkan judul
     - Melihat seluruh playlist
     - Menambahkan lagu ke playlist
     - Menghapus playlist
     - Menambahkan lagu atau playlist ke favorit
     - Melihat daftar favorit
     - Rekomendasi lagu berdasarkan: Genre, Singer
     - Remix by Mood (happy, sad, focus, angry)
     - Mengurutkan lagu berdasarkan durasi (ascending)
     - Pemutar lagu: Play, Pause, Stop, Next, Previous

E. CARA MENJALANKAN PROGRAM :
  1. Persiapan
     Pastikan sudah terinstall:
     - Compiler C++ (GCC / MinGW / g++)
     - Sistem operasi Windows / Linux / macOS
  2. Pastikan file berikut berada dalam satu folder:
     - main.cpp
     - tubess.cpp
     - tubess.h
  3. Buka terminal atau command prompt, lalu jalankan:   g++ maintubess.cpp tubess.cpp -o tubess
  4. Untuk mnjalankan Program, lalu jalankan:           ./tubess
  5. Saat Program dijalankan, pengguna diminta memilih peran user/admin. Ketik admin untuk masuk sebagai admin, Ketik user untuk masuk sebagai user.
