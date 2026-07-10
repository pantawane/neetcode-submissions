/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();

        vector<int> start;
        vector<int> end;

        for(auto& interval: intervals){
            start.push_back(interval.start);
            end.push_back(interval.end);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int rooms = 0;
        int maxRooms = 0;

        int i=0;
        int j=0;

        while(i < n){
            if(start[i] < end[j]){
                rooms++;
                maxRooms = max(maxRooms, rooms);
                i++;
            }else{
                rooms--;
                j++;
            }
        }
        return maxRooms;
    }
};
