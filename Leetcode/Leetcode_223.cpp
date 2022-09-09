
// 矩形面积
// 大数问题
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int a = min(C, G), b = max(A, E);
        int c = min(D, H), d = max(B, F);
        int coincide_area = 0; 
        if(b < a && d < c)
            coincide_area = (a - b) * (c - d);
        return (D - B) * (C - A) - coincide_area + (H - F) * (G - E);
    }
};