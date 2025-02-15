#include <iostream>
#include <string>
using namespace std;

class MusicPlayer {
private:
    string playlist[50];
    string currentlyPlayingSong;
    int count;

public:
	// defult constructor
    MusicPlayer() {
        count = 0;
        currentlyPlayingSong = "No song is playing";
    }

    void addSong(string song) {
        if (count < 50) {
            playlist[count] = song;
            count++;
            cout<<song<<" added to the playlist."<<endl;
        } else {
            cout<<"Playlist is full !!\n";
            }
    }

    void removeSong(string song) {
        for (int i = 0; i < count; i++) {
            if (playlist[i] == song) {
                for (int j = i; j < count - 1; j++) {
                    playlist[j] = playlist[j + 1];
                }
                count--;
                cout << song << " removed from the playlist.\n";
                return;
            }
        }
        cout << song << " not found in the playlist.\n";
    }

    void playSong(string song) {
        for (int i = 0; i < count; i++) {
            if (playlist[i] == song) {
                currentlyPlayingSong = song;
                cout << "Now playing: " << song << "\n";
                return;
            }
        }
        cout << song << " is not in the playlist.\n";
    }

    void displayPlaylist() {
        if (count == 0){ 
            cout<<"Playlist is empty!!\n";
        }
        else {
        	cout<<"\n";
        	cout<<"------------------"<<endl;
            cout<<"Playlist:\n";
            cout<<"------------------"<<endl;
            for (int i=0; i<count; i++) {
                cout<<i+1<<". "<<playlist[i]<<"\n";
            }
            cout<<"------------------"<<endl;
            cout<<"\n";
        }
    }
};

int main() {
    MusicPlayer x;
    x.displayPlaylist();
    x.addSong("Calm Me Down");
    x.addSong("CO2");
    x.addSong("Melting");
    x.displayPlaylist();
    x.playSong("Calm Me Down");
    x.removeSong("Calm Me Down");
    x.displayPlaylist();
    return 0;
}
