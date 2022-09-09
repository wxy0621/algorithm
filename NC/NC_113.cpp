// 验证IP地址
class Solution {
public:
    /**
     * 验证IP地址
     * @param IP string字符串 一个IP地址字符串
     * @return string字符串
     */
    bool judgeIPv4(string IP) {
        for (auto& c: IP) {
            if (c == ':') return false;
            if (c == '.') return true;
        }
        return false;
    }
    string parseIPv4(string IP) {
        int n = IP.size();
        string lastStr = "";
        int count = 1;
        for (int i = 0; i < n; ++i) {
            if (IP[i] == ':') return "Neither";
            if (IP[i] == '.') {
                if (lastStr == "" || (lastStr.size() >= 2 && lastStr[0] == '0')) return "Neither";
                int temp = stoi(lastStr);
                if (temp >= 256) return "Neither";
                lastStr = "";
                ++count;
            } else if ('0' <= IP[i] && IP[i] <= '9') {
                lastStr += IP[i];
            } else {
                return "Neither";
            }
        }
        if (lastStr == "" || (lastStr.size() >= 2 && lastStr[0] == '0')) return "Neither";
        int temp = stoi(lastStr);
        if (temp >= 256) return "Neither";
        if (count != 4) return "Neither";
        return "IPv4";
    }
    string parseIPv6(string IP) {
        int n = IP.size();
        string lastStr = "";
        int count = 1;
        for (int i = 0; i < n; ++i) {
            if (IP[i] == '.') return "Neither";
            if (IP[i] == ':') {
                if (lastStr == "" || lastStr.size() > 4) return "Neither";
                lastStr = "";
                ++count;
            } else if (('0' <= IP[i] && IP[i] <= '9') || ('a' <= IP[i] && IP[i]<= 'f') || ('A' <= IP[i] && IP[i]<= 'F')) {
                lastStr += IP[i];
            } else {
                return "Neither";
            }
        }
        if (lastStr == "" || lastStr.size() > 4) return "Neither";
        if (count != 8) return "Neither";
        return "IPv6";
    }
    string solve(string IP) {
        // write code here
        bool isIPv4 = judgeIPv4(IP);
        if (judgeIPv4(IP)) return parseIPv4(IP);
        return parseIPv6(IP);
    }
};