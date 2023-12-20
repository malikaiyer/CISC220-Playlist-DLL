#ifndef DNODE_HPP_
#define DNODE_HPP_
#include <stdlib.h>
using namespace std;
#include "Song.hpp"

class DNode {
	friend class DLL;
	Song *song;  //data type of the nodes in the list (data type of DNode). Holds the address of the song. But isn't DNode it's own data type? 
	DNode *prev;
	DNode *next;
public:
	DNode();
	DNode(string s, string a, int lenmin, int lensec);
};


#endif /* DNODE_HPP_ */
