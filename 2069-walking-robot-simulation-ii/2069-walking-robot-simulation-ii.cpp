class Robot {
public:
    int w, h, x, y, dir;
    vector<string> d = {"East", "North", "West", "South"};
    
    Robot(int width, int height) {
        w = width;
        h = height;
        x = 0;
        y = 0;
        dir = 0;
    }
    
    void step(int num) {
        int per = 2 * (w + h) - 4;
        num %= per;
        
        if (num == 0 && x == 0 && y == 0) dir = 3;
        
        while (num--) {
            if (dir == 0) {
                if (x + 1 < w) x++;
                else dir = 1, y++;
            }
            else if (dir == 1) {
                if (y + 1 < h) y++;
                else dir = 2, x--;
            }
            else if (dir == 2) {
                if (x - 1 >= 0) x--;
                else dir = 3, y--;
            }
            else {
                if (y - 1 >= 0) y--;
                else dir = 0, x++;
            }
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        return d[dir];
    }
};