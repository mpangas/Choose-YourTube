#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include "Video.hpp"

class Graph {
    std::vector<std::string> rootVideoIDs;
    std::unordered_map<std::string, Video*> idToVideo;

    /// FIXME: How do I get the info to know
    /// what characteristics to filter out

    // ----------  TEMPORARY FILTER PLACEHOLDERS ---------- //
    static bool passesFilter(std::string videoID);

    // ----------  MEMORY AND DATA MANAGEMENT ---------- //
    void copyVals(const Graph& original);
    void deleteVals();
    Graph(const Graph& original);
    Graph& operator=(const Graph& original);
    ~Graph();

    // ----------  GRAPH TRAVERSAL HELPERS ---------- //
    Video* getCurrVideo(std::string currID) const;
    bool addToTraversal(std::unordered_set<std::string>& visited, std::string videoID) const;
    void helperTraversePostorderDepthFirstN(std::string currID,
    std::vector<Video*>& result, std::unordered_set<std::string>& visited, int n) const;


public:

    // ----------  GRAPH CREATION ---------- //
    /// TODO: Phase long insert out of use
    /*
    void insertRootVideo( // Insert a video from file 0.txt (the roots)
    std::string id,
    std::string uploaderUsername,
    int age,
    std::string category,
    int length,
    int numViews,
    float overallRating,
    int numRatings,
    int numComments,
    std::vector<std::string> relatedIDs);

    /// TODO: Phase long insert out of use
    void insertVideo( // Insert a video not from file 0.txt
    std::string id,
    std::string uploaderUsername,
    int age,
    std::string category,
    int length,
    int numViews,
    float overallRating,
    int numRatings,
    int numComments,
    std::vector<std::string> relatedIDs);
    */

    void insertRootVideo(std::vector<std::string> stats,
    std::vector<std::string> relatedIDs);  // Insert a video from file 0.txt (the roots)

    void insertVideo(std::vector<std::string> stats,
    std::vector<std::string> relatedIDs);  // Insert a video not from file 0.txt

    // ----------  GRAPH TRAVERSALS ---------- //
    std::vector<Video*> traverseBreadthFirstN(std::string id, int n) const; 
    std::vector<Video*> traversePostorderDepthFirstN(std::string id, int n) const;
     // id of the video from which we are starting, and n 'neighbors' to find from it
};