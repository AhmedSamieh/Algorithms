// g++ -Wall -O3 MovieRecommendations.cpp -std=c++11 -o MovieRecommendations
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

class Movie {
private:
    int movieId;
    float rating;
    vector<Movie*> similarMovies; // Similarity is bidirectional

public:
    Movie(int movieId, float rating) {
        this->movieId = movieId;
        this->rating = rating;
    }
    int getId() {
        return movieId;
    }
    float getRating() {
        return rating;
    }
    void addSimilarMovie(Movie* movie) {
        similarMovies.push_back(movie);
        movie->similarMovies.push_back(this);
    }
    vector<Movie *>& getSimilarMovies() {
        return similarMovies;
    }
    /*
     * Implement a function to return top rated movies in the network of movies
     * reachable from the current movie
     * eg:            A(Rating 1.2)
     *               /   \
     *            B(2.4)  C(3.6)
     *              \     /
     *               D(4.8)
     * In the above example edges represent similarity and the number is rating.
     * getMovieRecommendations(A,2) should return C and D (sorting order doesn't matter so it can also return D and C)
     * getMovieRecommendations(A,4) should return A, B, C, D (it can also return these in any order eg: B,C,D,A)
     * getMovieRecommendations(A,1) should return D. Note distance from A to D doesn't matter,
     *                             return the highest rated.
     *
     *     @param movie
     *     @param numTopRatedSimilarMovies
     *                      number of movies we want to return
     *     @return List of top rated similar movies
     */
    static void getMovieRecommendations(Movie& movie, int numTopRatedSimilarMovies, vector<Movie *>& recommendedMovies) {
        // Implement me
        if (numTopRatedSimilarMovies > 0) {
            unordered_set<Movie *> visited; // Space complexity O(n)
            queue<Movie *>         qu;      // Space complexity O(n)
            qu.push(&movie);
            visited.emplace(&movie);
            do {
                // Dequeue node from queue to search it's similarMovies
                Movie *mv = qu.front();
                qu.pop();
                // scan all similarMovies, if the movie has not been visited mark it as visited and enqueue it
                for (auto &rec_movie : mv->getSimilarMovies()) {
                    if (visited.find(rec_movie) == visited.end()) {
                        visited.emplace(rec_movie);
                        qu.push(rec_movie);
                    }
                }
            } while (!qu.empty());
            if ((size_t) numTopRatedSimilarMovies < visited.size())
            {
                // return numTopRatedSimilarMovies only
                // sort the list by movie rating
                // Worst case performance O(n log m) where n number of all movies, m number of top rated movies
                recommendedMovies.resize(numTopRatedSimilarMovies);
                partial_sort_copy(visited.begin(),
                                visited.end(),
                                recommendedMovies.begin(),
                                recommendedMovies.end(),
                                [](Movie *x, Movie *y) {
                                    return (x->getRating() > y->getRating());
                                });
            }
            else
            {
                // get unsorted list of entire similarity network
                // O(n)
                recommendedMovies.assign(visited.begin(), visited.end());
            }
        }
        return;
    }
};
int main(int argc, char **argv)
{
    Movie m1(1, 1.4), m2(2, 3.7), m3(3, 4.1), m4(4, 4.0), m5(5, 2.9);
    vector<Movie *> output;
    m1.addSimilarMovie(&m2);
    m1.addSimilarMovie(&m3);
    m3.addSimilarMovie(&m4);
    m5.addSimilarMovie(&m4);
    Movie::getMovieRecommendations(m1, 2, output);
    cout << "Number of movies : " << output.size() << endl;
    for (vector<Movie *>::iterator iter = output.begin();
            iter != output.end();
            iter++)
    {
        cout << "Movie ID : " << (*iter)->getId() << ", Movie Rating = " << (*iter)->getRating() << endl;
    }
    return 0;
}