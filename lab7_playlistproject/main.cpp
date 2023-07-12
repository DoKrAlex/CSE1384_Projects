/*
Name: Alex Do                       NetID: akd306
Date: 4/18/2022                   Due Date: 4/18/2022
Description: This program will center around handling a playlist of songs
*/
// main.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

#include "song.h"

using namespace std;

// given to you
void processFile(vector<Song> &playlist);

// you should create
void shuffle(vector<Song> &playlist);
void bubbleSort(vector<Song> &playlist);
void displayPlaylist(vector<Song> &playlist);

// add your own sort function
int binarySearch(vector<Song> playlist, string title);

int main() {
    vector<Song> playlist;

    // sets up playlist
    processFile(playlist);

    cout << "\nInitial playlist: " << endl;
    displayPlaylist(playlist);

    cout <<"Welcome to the playlist display manager." << endl << endl;
    int choice;
    int index;
    string title;
    
    // loop that continues till the user wants
    do {
        // display the menu
        cout<<"0. Exit"<<endl;
        cout<<"1. Sort Playlist"<<endl;
        cout<<"2. Shuffle Playlist"<<endl;
        cout<<"3. Search Playlist"<<endl;
        cout<<"Which option would you like? ";
        cin>>choice; // input of choice

    // based on choice perform the operation
        if(choice == 1) {
            cout<<endl;
            bubbleSort(playlist);
            displayPlaylist(playlist);
        }
        else if(choice == 2) {
            cout<<endl;
            shuffle(playlist);
            displayPlaylist(playlist);
        }
        else if(choice == 3) {
            cin.ignore(100,'\n');
            cout<<endl<<"Enter the title of song to search: ";
            getline(cin,title);
            bubbleSort(playlist);
            index = binarySearch(playlist, title);
            
            if(index != -1) {
                cout<<playlist[index].getTitle()<<" - "<<playlist[index].getArtist()<<endl;
            }
            else {
                cout<<"No song with title: "<<title<<" found"<<endl;
            }
        }
        else if(choice != 0) {
            cout<<endl<<"Invalid choice"<<endl;
        }
    cout<<endl;
    }

    while(choice != 0);
        cout<<"Good Bye!"<<endl;
    return 0;
}

// function to load song details from file to vector of Song
    void processFile(vector<Song> &playlist) {
        ifstream infile;
        string line;

        infile.open("songs.txt");

        if(infile.is_open()) {
            cout << "Successful songs opening." << endl;
        }

        else {
            cout << "Couldn't locate file. Program closing." << endl;
            exit(EXIT_FAILURE);
        }

        while(getline(infile, line)) {
        // first line --> song
        // second line --> artist
            if(line != "") {
                string song, artist;
                song = line;
                getline(infile, artist);
                Song temp(song, artist);
                playlist.push_back(temp);
            }
        }
    }

    // function to shuffle the playlist
    void shuffle(vector<Song> &playlist) {
        // loop that continues half of size times
        for(size_t i=0;i<playlist.size()/2;i++) {
        // generate 2 random indices of the vector
            int idx1 = rand()%playlist.size();
            int idx2 = rand()%playlist.size();
            // loop that continues till idx1 and idx2 are same
            while(idx1 == idx2) {
                idx2 = rand()%playlist.size();
            }

            // swap the songs at idx1 and idx2
            Song temp = playlist[idx1];
            playlist[idx1] = playlist[idx2];
            playlist[idx2] = temp;
        }
    }

// function to sort the playlist using bubble sort
    void bubbleSort(vector<Song> &playlist) {
        for(size_t i=0;i<playlist.size()-1;i++) {
            for(size_t j=0;j<playlist.size()-1-i;j++) {
                if(playlist[j].getTitle() > playlist[j+1].getTitle()) {
                    Song temp = playlist[j];
                    playlist[j] = playlist[j+1];
                    playlist[j+1] = temp;
                }
            }
        }
    }

// function to display the playlist
    void displayPlaylist(vector<Song> &playlist) {
        for(size_t i=0;i<playlist.size();i++) {
            cout<<playlist[i].getTitle()<<" - "<<playlist[i].getArtist()<<endl;
        }
        cout<<endl;
    }

    // function to search for a title in the playlist and returns the index of the song if found else returns -1
    // It assumes that the list is sorted in ascending order by title
    int binarySearch(vector<Song> playlist, string title) {
        int low = 0;
        int high = playlist.size()-1;
        int mid;
    // loop that continues till low <= high
        while(low <= high) {
            mid = (low+high)/2; // get the mid index
    // if song title at mid = title, return mid
            if(playlist[mid].getTitle() == title) {
                return mid;
            }
            else if(playlist[mid].getTitle() > title) { // if song title at mid > title, search for title in left subarray
                high = mid-1;
            }
            else {// if song title at mid < title, search for title in right subarray
                low = mid+1;
            }
        }
    return -1; // song not found
}

//end of main.cpp

