#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <SpotifyOAuth.h>

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
    bool activeGraph;
}graph;

class PlaylistGenerator : public QObject {
    Q_OBJECT

public slots:
    void recommendationCallback();
    void calculate();

signals:
    void calculateSignal();


public:
    PlaylistGenerator(QObject *parent = nullptr);
    PlaylistGenerator(SpotifyOAuth *oauth, QObject *parent = nullptr);
    void getGraphs(vector<graph> inputGraphs, int playlistLength);
    void generatePlaylists();
    void addPlaylistToAccount();
private:
    //list of graphs (contains variable name and all data points)
    SpotifyOAuth *oauth;
    vector<graph> graphs;
    //total duration of the playlist
    int playlistDuration_ms;
    //current duration into the playlist while generating
    unsigned int currentDuration_ms;
    //output of songIDs used to access the songs
    vector<string> songURIs;
    //structure to hold the target values to get recommendations from
    vector<string> variableNames;
    vector<float> values;
    string currSong;



    void clamp(float min, float max, float &number);

};
