class Solution
{
    unordered_map<string, string> long_short;
    unordered_map<string, string> short_long;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        auto iter = long_short.find(longUrl);

        if (iter == long_short.end()) {
            string shortUrl = "http://tinyurl.com/" + to_string(long_short.size());
            long_short[longUrl] = shortUrl;
            short_long[shortUrl] = longUrl;
            return shortUrl;
        } else {
            return iter->second;
        }
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        auto iter = short_long.find(shortUrl);

        if (iter == short_long.end()) {
            return "";
        } else {
            return iter->second;
        }
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));