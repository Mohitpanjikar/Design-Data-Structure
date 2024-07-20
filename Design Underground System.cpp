//link - https://leetcode.com/problems/design-underground-system/description/

class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>>
        checkIn_mp; // ID -> {entryStation,entrytime}
    unordered_map<string, pair<int, int>>
        checkOut_mp; // route -> {totalTime,count}

    UndergroundSystem() {}

    void checkIn(int id, string stationName, int t) {
        checkIn_mp[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        string startStation = checkIn_mp[id].first;
        int entryTime = checkIn_mp[id].second;

        string endStation = stationName;
        int endTime = t;
        string route = startStation + "-" + endStation;

        int total_time = endTime - entryTime;

        checkOut_mp[route].first += total_time;
        checkOut_mp[route].second += 1; // freq

        checkIn_mp.erase(id);
    }

    double getAverageTime(string startStation, string endStation) {
        string route = startStation + "-" + endStation;
        int time = checkOut_mp[route].first;
        int freq = checkOut_mp[route].second;

        return (double)time / freq;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
