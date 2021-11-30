#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <SpotifyOAuth.h>
#include <future>

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
    void callgetRecommendationSlot();
    void searchGraphsSlot();


signals:
    void callgetRecommendationSignal();
    void searchGraphsSignal();
    void playlistGenerating();
    void playlistCompleted();


public:
    PlaylistGenerator(QObject *parent = nullptr);
    PlaylistGenerator(SpotifyOAuth *oauth, QObject *parent = nullptr);
    void getGraphs(vector<graph> inputGraphs, int playlistLength);
    void generatePlaylists();
    void addPlaylistToAccount(string playlistName);
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
