class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> car;

        // 1. Create pair of {position, time}
        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            car.push_back({position[i], time});
        }

        // 2. Sort by position in descending order
        sort(car.rbegin(), car.rend());

        int fleets = 0;
        double maxTime = 0.0;

        // 3. Iterate and count fleets
        for (auto& p : car) {
            if (p.second > maxTime) {
                fleets++;
                maxTime = p.second;
            }
            // else, car joins existing fleet (do nothing)
        }

        return fleets;
    }
};
