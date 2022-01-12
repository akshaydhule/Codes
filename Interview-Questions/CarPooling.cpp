/**
 * There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).
 * You are given the integer capacity and an array trips where trip[i] = [numPassengersi, fromi, toi] 
 * indicates that the ith trip has numPassengersi passengers and the locations to pick them up and drop them off 
 * are fromi and toi respectively. The locations are given as the number of kilometers due east from the car's initial location.
 * Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.
 * 
 * Example 1:
 * Input: trips = [[2,1,5],[3,3,7]], capacity = 4
 * Output: false
 * Example 2:
 * Input: trips = [[2,1,5],[3,3,7]], capacity = 5
 * Output: true
 */

struct posVal {
    int pos;
    int value;
};

bool sortingFn(posVal a, posVal b) {
    if (a.pos < b.pos) {
        return true;
    }
    if (a.pos == b.pos && a.value < b.value) {
        return true;
    }
    return false;
}
class Solution {
public:
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        std::vector <posVal> inputlist;
        int rows = trips.size();
        for (int row = 0; row < rows; row++) {
            if (trips[row][1] > trips[row][2]) {
                // trip needs to travel west so fail
                return false;
            }
            if (trips[row][1] == trips[row][2]) {
                // no need to add
                continue;
            }
            inputlist.push_back(posVal{trips[row][1], trips[row][0]});
            inputlist.push_back(posVal{trips[row][2], -1 * trips[row][0]});
        }
        std::sort(inputlist.begin(), inputlist.end(), sortingFn);
        int count = 0;
        for (auto a : inputlist) {
            count += a.value;
            if (count > capacity) {
                return false;
            }
        }
        return true;
    }
};
