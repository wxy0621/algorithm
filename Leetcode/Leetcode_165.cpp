// 比较版本号
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        int n1 = version1.size(), n2 = version2.size();
        while(i < n1 || j < n2) {
            int a = 0, b = 0;
            while(i < n1 && version1[i] != '.') a = a * 10 + version1[i++] - '0';
            while(j < n2 && version2[j] != '.') b = b * 10 + version2[j++] - '0';
            if(a < b) return -1;
            else if(a > b) return 1;
            ++i;
            ++j;
        }
        return 0;
    }
};