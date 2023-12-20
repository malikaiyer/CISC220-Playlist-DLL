#include <iostream>
#include <stdlib.h>
#include "Playlist.cpp" //i need to include all these files because i am using vscode and the code won't recognize the other files 
#include "DLL.cpp"      //and won't compile unless the cpp version of each file is included
#include "Song.cpp"
#include "DNode.cpp"
#include <time.h>
using namespace std;

int main() {
	srand(time(NULL));
	Playlist *list = new Playlist;
	// Playlist *list = new Playlist("ShortListofSongs.txt");
}

