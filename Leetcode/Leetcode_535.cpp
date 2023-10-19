// TinyURL 的加密与解密
class Solution {
public:
    Solution() {
        id = 0;
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        database[++id] = longUrl;
        return "http://tinyurl.com/" + to_string(id);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int place = shortUrl.rfind('/') + 1;
        int key = stoi(shortUrl.substr(place, shortUrl.size() - place));
        return database[key];
    }
private:
    int id;
    unordered_map<int, string> database;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));