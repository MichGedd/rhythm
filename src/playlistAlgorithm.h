#pragma once

#include <iostream>
#include <vector>
#include <string>

//number of milliseconds in a minute
#define MS_IN_MINUTE 60000

using namespace std;

typedef struct dataPoint{
    float value;
    int time_minutes;
}dataPoint;

typedef struct graph{
    string variableName;
    vector<dataPoint> points;
}graph;

class PlaylistGenerator{
public:
    PlaylistGenerator(vector<graph> inputGraphs, int playlistLength);
    void generatePlaylists();
    void addPlaylistToAccount();
    vector<string> getSongURIs();
private:
    //list of graphs (contains variable name and all data points)
    vector<graph> graphs;
    //total duration of the playlist
    int playlistDuration_ms;
    //current duration into the playlist while generating
    unsigned int currentDuration_ms;
    //output of songIDs used to access the songs
    vector<string> songURIs;
    //structure to hold the target values to get recommendations from
    typedef struct targetSong{
        string variableName;
        float value;
    }targetSong;
    targetSong target;

    void clamp(float min, float max, float &number);

};