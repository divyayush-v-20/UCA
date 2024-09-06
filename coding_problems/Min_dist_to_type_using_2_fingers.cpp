// Leetcode 1320

class Solution {
public:
    int getDistance(char c1, char c2){
        unordered_map<char, pair<int,int>> plane;
        for(char c = 'A'; c <= 'Z'; ++c) {
            plane[c] = {(c - 'A') / 6, (c - 'A') % 6};
        }
        if(c1 == NULL || c2 == NULL) return 0;

        int dist = abs(plane[c1].first - plane[c2].first) + abs(plane[c1].second - plane[c2].second);
        return dist;
    }

    int shortestDistance(string word, int index, char f1, char f2){
        if(index >= word.size()) return 0;
        char cur = word[index];
        int choice1 = getDistance(f1, cur) + shortestDistance(word, index + 1, cur, f2);
        int choice2 = getDistance(f2, cur) + shortestDistance(word, index + 1, f1, cur);
        return min(choice1, choice2);
    }

    int minimumDistance(string word) {
        return shortestDistance(word, 0, NULL, NULL);
    }
};
