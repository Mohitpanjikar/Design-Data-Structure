//Link - https://leetcode.com/problems/seat-reservation-manager/description/
class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int seat_number;

    SeatManager(int n) { seat_number = 1; }

    int reserve() {
        if (!pq.empty()) {
            int seat = pq.top();
            pq.pop();
            return seat;
        }
        int seat = seat_number;
        seat_number++;
        return seat;
    }

    void unreserve(int seatNumber) { pq.push(seatNumber); }
};
