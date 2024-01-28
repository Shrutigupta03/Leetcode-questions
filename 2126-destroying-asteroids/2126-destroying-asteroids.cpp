class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long x = mass;
        sort(asteroids.begin(), asteroids.end());
        int n = asteroids.size();
        for (int i=0;i<n;i++)
        {
            if (asteroids[i]<=x)
                x+=asteroids[i];
            else
                return false;
        }
        return true;
    }
};