/*****************************************************
// Author: Spencer Collins
// Date : 10/16/2025 
// This is the header file for Problem 1 Assignment 9.
//***************************************************/

#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <string>

class Song {
public:
    std::string title;
    std::string artist;
    double duration;
    Song* next;
    Song* prev;

    Song(std::string t, std::string a, double d)
        : title(t), artist(a), duration(d), next(nullptr), prev(nullptr) {
    }
};

class Playlist {
private:
    Song* current;

public:
    Playlist() : current(nullptr) {}

    ~Playlist() {
        clear();
    }

    bool isEmpty() const {
        return current == nullptr;
    }

    void addSong(const std::string& title, const std::string& artist, double duration) {
        Song* newSong = new Song(title, artist, duration);
        if (isEmpty()) {
            newSong->next = newSong;
            newSong->prev = newSong;
            current = newSong;
        }
        else {

            Song* last = current->prev;
            // add code to add node to the end of the list
            newSong->next = current;
            newSong->prev = last;
            last->next = newSong;
            current->prev = newSong;
        }
    }

    void removeSong(const std::string& title) {
        if (isEmpty()) {
            std::cout << "Playlist is empty.\n";
            return;
        }

        Song* temp = current;
        bool found = false;

        do {
            // add code to find a node by title. last node points to the first node
            
            temp = current->next;
            if(temp->title == title) {
                found = true;
                break;
            }
        } while (temp != current);

        if (!found) {
            std::cout << "Song not found.\n";
            return;
        }

        // last node in the list
        if (temp->next == temp) {
            delete temp;
            current = nullptr;
        }
        else {
            // add code to delete the found node
            

            if (temp == current) current = temp->next;
            delete temp;
        }
    }

    void skipForward(int n) {
        if (isEmpty()) return;
        for (int i = 0; i < n; ++i) {
           // add code 
            current = current->next; 
        }
    }

    void skipBackward(int n) {
        if (isEmpty()) return;
        for (int i = 0; i < n; ++i) {
            // add code
            current = current->prev;
        }
    }

    void displayCurrent() const {
        if (isEmpty()) {
            std::cout << "No song is currently playing.\n";
        }
        else {
            std::cout << "Now playing: " << current->title << " by " << current->artist
                << " (" << current->duration << " mins)\n";
        }
    }

    void clear() {
        if (isEmpty()) return;

        Song* temp = current->next;
        while (temp != current) {
            Song* next = temp->next;
            delete temp;
            temp = next;
        }
        delete current;
        current = nullptr;
    }
};

#endif // PLAYLIST_COMBINED_H

