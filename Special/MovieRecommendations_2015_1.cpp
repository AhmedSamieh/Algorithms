// g++ -Wall -O3 MovieRecommendations.cpp -o MovieRecommendations

#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <algorithm>

using namespace std;

class Movie; // incomplete class declaration for rating_compare
bool rating_compare(Movie *x, Movie *y);

class Movie
{
private:
    int movieId;
    float rating;
    vector<Movie *> similarMovies; // Similarity is bidirectional
public:
    Movie(int movieId, float rating)
    {
        this->movieId = movieId;
        this->rating = rating;
    }
    int getId()
    {
        return movieId;
    }
    float getRating()
    {
        return rating;
    }
    void addSimilarMovie(Movie *movie)
    {
        similarMovies.push_back(movie);
        movie->similarMovies.push_back(this);
    }
    vector<Movie *> &getSimilarMovies()
    {
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
    static void getMovieRecommendations(Movie &movie, int numTopRatedSimilarMovies, vector<Movie *> &recommendedMovies)
    {
        // Implement me
        // Create internal queue for BFS
        list<Movie *> queue; // Worst case space complexity O(n)
        // we will save visited nodes in this set, in order to visit each node once
        set<Movie *> visited; // Worst case space complexity O(n)
        Movie *node;
        // start
        if (numTopRatedSimilarMovies > 0)
        {
            queue.push_back(&movie);
            visited.insert(&movie);
            // Worst case performance O(|V|+|E|) where V is number of movies, and E is number of similarity
            do
            {
                // Dequeue node from queue to search it's similarMovies
                node = queue.front();
                queue.pop_front();
                // scan all similarMovies, if the movie has not been visited mark it as visited and enqueue it
                for (vector<Movie *>::iterator iter = node->getSimilarMovies().begin();
                        iter != node->getSimilarMovies().end();
                        iter++)
                {
                    if (visited.find(*iter) == visited.end())
                    {
                        queue.push_back(*iter);
                        visited.insert(*iter);
                    }
                }
            }
            while (!queue.empty());
            // get unsorted list of entire similarity network
            recommendedMovies.assign(visited.begin(), visited.end());
            // sort the list by movie rating
            // Worst case performance O(n log n)
            sort(recommendedMovies.begin(), recommendedMovies.end(), rating_compare);
            // return numTopRatedSimilarMovies only
            if ((size_t) numTopRatedSimilarMovies < recommendedMovies.size())
            {
                recommendedMovies.erase(recommendedMovies.begin() + numTopRatedSimilarMovies, recommendedMovies.end());
            }
        }
        return;
    }
};
bool rating_compare(Movie *x, Movie *y)
{
    return (x->getRating() > y->getRating());
}
int main(int argc, char **argv)
{
    Movie m1(1, 1.4), m2(2, 3.7), m3(3, 4.1), m4(4, 4.0), m5(5, 2.9);
    vector<Movie *> output;
    m1.addSimilarMovie(&m2);
    m1.addSimilarMovie(&m3);
    m3.addSimilarMovie(&m4);
    m5.addSimilarMovie(&m4);
    Movie::getMovieRecommendations(m1, 3, output);
    cout << "Number of movies : " << output.size() << endl;
    for (vector<Movie *>::iterator iter = output.begin();
            iter != output.end();
            iter++)
    {
        cout << "Movie ID : " << (*iter)->getId() << ", Movie Rating = " << (*iter)->getRating() << endl;
    }
    return 0;
}
