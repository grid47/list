class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool bulky = false, heavy = false;
        double v = (double) length * width * height;
        if(length >= 10000 || width >= 10000 || 
           height >= 10000 || v >= 1000000000)
            bulky = true;
        if(mass >= 100)
            heavy = true;
        string category;
            if(bulky && heavy)
                category = "Both";
            else if (!bulky && !heavy)
                category = "Neither";
            else if (bulky)
                category = "Bulky";
            else if (heavy)
                category = "Heavy";
        return category;
    }
};