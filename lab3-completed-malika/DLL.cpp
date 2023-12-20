
#include "DNode.hpp"
#include "DLL.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

//Check Playlist.cpp for instructions of what to write here and how to test it


	DLL::DLL(){  // constructor - initializes an empty list
		last = NULL;
		first = NULL;
		numSongs = 0;
	}
	DLL::DLL(string t, string l, int m, int s){  // constructor, initializes a list with one new node with data x
		DNode *n = new DNode (t,l,m,s);
		first = n;
		last = n;
		numSongs=1;
	}
	void DLL::push(string n, string a, int m, int s) {  // does what you'd think
		//adds a new node with the data in the input to the end of the playlist
		DNode *newNode = new DNode(n,a,m,s); //new node to be added to the end of the list

		//what does this mean? The push method must include a case for creating the very first node in the list.

		//execute this case only if there is no nodes in the list
		if(first==NULL){
			first = last = newNode;
			first->prev=NULL;
			last->next = NULL;
		}

		else{
			//while loop to find the last node 
			DNode *tmp = first;
			while(tmp->next != NULL){  //need tmp->next here instead of tmp because it will not execute tmp=tmp->next for the last node and will stop when tmp = last
				tmp = tmp->next;
			}	
				tmp->next = newNode;
				last = newNode;
				last->prev = tmp;
				newNode->next = NULL;
				numSongs++;
		}
	}
	
	Song *DLL::pop() { //removes the last element from the list and returns it's data
		DNode *tmp = last;
		Song *data = tmp->song;  //data holds the data of the last element

		last = last->prev;  //makes the previous one the last element
		delete tmp;

		last->next = NULL; //makes the next of the last NULL
		numSongs--;

		return data;
	}

	void DLL::printList() {
		DNode *tmp = first;
		while(tmp!=NULL){   //need tmp instead of tmp->next!=NULL here because this will make it go through the last node and execute it
			tmp->song->printSong();
			tmp = tmp->next;
		}
	}

	void DLL::moveUp(string s) {
		/*This method goes through the list, finds
		 *the node with the title, and moves it up one place in the list. If it is the first
		 *song in the list, it moves it to the end of the list.*/
		DNode *swapSong = first;
		while(swapSong->song->title != s && swapSong!=NULL){
				swapSong = swapSong->next;
			}  //makes swapSong be equal to the song to be swapped


			if(swapSong == first){ //all the songs move up one - remove first, add one to the last. 
				//remove first and add it to the last
				first = swapSong->next;
				first->prev = NULL;

				last->next = swapSong;
				swapSong->prev = last;
				swapSong->next = NULL;
				last = swapSong;
			}


			else if(swapSong != first){   //swap the two - just swapping their data, or memory location too?
				//switching their memory location
				DNode *prevNode = swapSong->prev;
				DNode *prevprevNode = swapSong ->prev->prev;
				DNode *nextNode = swapSong->next;

				if (swapSong == first->next){
					swapSong->next = prevNode;
					swapSong->prev = NULL; 

					prevNode->next = nextNode; 
					prevNode->prev = swapSong; 

					nextNode->prev = prevNode; 

					first = swapSong;
				}

				else if (swapSong==last){
					swapSong->next = prevNode;
					swapSong->prev = prevprevNode; 

					prevNode->next = NULL; 
					prevNode->prev = swapSong; 

					last = prevNode;

					prevprevNode->next = swapSong;
				}

				else{
					swapSong->next = prevNode;
					swapSong->prev = prevprevNode; 

					prevNode->next = nextNode; 
					prevNode->prev = swapSong; 

					nextNode->prev = prevNode; 

					prevprevNode->next = swapSong;

					// if (swapSong==last){
					// 	last = prevNode;
					// }
				}
			}
		}
	

	void DLL::listDuration(int *tm, int *ts) {
		//* Note that this method takes as input two pointers to integers.  It is using call by
		//* pointer (largely so you get to practice call by pointer).  The method sums the minutes
		//* and the seconds of each song in the playlist to determine the total number of minutes and
		//* seconds.  It retursn nothing (void) but the input parameters are modified to hold these totals.

		DNode *tmp = first;
		while(tmp!=NULL){
			*tm += tmp->song->min;
			*ts += tmp->song->sec;
			tmp = tmp->next;
		}
	}

	void DLL::moveDown(string s) {
	//This method goes through the list, finds the node with the title, and moves it down one place in the list.  If it is the last
	//song in the list, it moves it to the front of the list
		DNode *swapSong = first;
		while(swapSong->song->title != s && swapSong!=NULL){
				swapSong = swapSong->next;
			}  //makes swapSong be equal to the song to be swapped


			if(swapSong == last){ //all the songs move down one - remove last, add one to the first. 
				last = swapSong->prev;
				last->next = NULL;

				first->prev = swapSong;
				swapSong->next = first;
				swapSong->prev = NULL;
				first = swapSong;
			}

			else if(swapSong != last){  //switching their memory location
				DNode *prevNode = swapSong->prev;
				DNode *nextnextNode = swapSong->next->next;
				DNode *nextNode = swapSong->next;

				if (swapSong == last->prev){ //if this is second to last 
					swapSong->next = NULL;
					swapSong->prev = nextNode; 

					prevNode->next = nextNode; 

					nextNode->prev = prevNode; 
					nextNode->next = swapSong;

					last = swapSong;
				}

				else if(swapSong==first){
					swapSong->next = nextnextNode;
					swapSong->prev = nextNode; 

					nextNode->prev = NULL; 
					nextNode->next = swapSong;

					nextnextNode->prev = swapSong;

					first = nextNode;
				}

				else{ //correct
					swapSong->next = nextnextNode;
					swapSong->prev = nextNode; 

					prevNode->next = nextNode; 

					nextNode->prev = prevNode; 
					nextNode->next = swapSong;

					nextnextNode->prev = swapSong;

					// if (swapSong==first){
					// 	first = nextNode;
					// }
				}
			}
	}

	void DLL::makeRandom() {
		//There are many, many ways to write this method, and each is fine (unless it doesn't result
		// in a random list.
		// The method should randomly rearrange your play list so that the nodes are reordered in a new,
		// random order.
		for(int i=0;i<numSongs; i++){
			int x = rand()%(numSongs-2);
			int num=0;

			DNode *tmp = first;
			while(num!=x){
				tmp = tmp->next;  //tmp now is at the random node assigned
				num++;
			}

			if (tmp!= first && tmp!=last){
				//add tmp to the end of the doubly linked list and delete it from the middle
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;

				last->next = tmp;
				tmp->prev = last;
				last = tmp;
				last->next = NULL;
			}

			else if (tmp==first){
				tmp->next->prev = NULL;
				first = tmp->next;

				last->next = tmp;
				tmp->prev = last;
				last = tmp;
				last->next = NULL;
			}
		}
	}

	int DLL::remove(string s) {  
		// note that the int returned is the index - this is standard for a remove, but we won't be using it.
		// This Method goes through your list, finds a title, and removes that node from the list.  It
		// must work for the first node and the last node, as well as any node in  the list.
		DNode *tmp = first;
		int index = 0;

		//finding index of node to be deleted
		while(tmp->song->title != s && tmp!=NULL){
			tmp= tmp->next; 
			index+=1;
		} //now tmp is the node to be deleted

		cout << "Removing " << s << endl;

		//case if tmp is head
		if (tmp==first){
			first = tmp->next;
			tmp->next->prev = NULL;
			delete tmp;
		}

		//case if tmp is last node
		else if(tmp==last){
			last = tmp->prev;
			last->next = NULL;
			delete tmp;
		}

		//tmp in the middle
		else{
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			delete tmp; 
		}
		return index;		

	}


	DLL::~DLL(){
		DNode *tmp = new DNode();
		delete tmp;
	}
