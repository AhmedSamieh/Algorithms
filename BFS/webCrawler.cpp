/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */
class Solution {
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        unordered_set<string> visited;
        vector<string> ret;
        queue<string> q;
        q.push(startUrl);
        visited.insert(startUrl);
        int hostname_end = startUrl.find('/', 7);
        if (hostname_end == string::npos)
        {
            hostname_end = startUrl.size();
        }
        string hostname = startUrl.substr(7, hostname_end - 7);
        while (!q.empty())
        {
            auto urls = htmlParser.getUrls(q.front());
            q.pop();
            for (auto &url : urls)
            {
                if (url.substr(7, hostname_end - 7) == hostname)
                {
                    if (visited.find(url) == visited.end())
                    {
                        q.push(url);
                        visited.insert(url);
                    }
                }
            }
        }
        for (auto &url : visited)
        {
            ret.push_back(url);
        }
        return ret;
    }
};