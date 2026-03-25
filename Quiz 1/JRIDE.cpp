#include <iostream>

using namespace std;

int main() {
    int total_routes;
    cin >> total_routes;

    for (int route = 1; route <= total_routes; ++route) {
        int num_stops;
        cin >> num_stops;

        int max_niceness = -1, cur_niceness = 0, best_start = 1, best_end = 1, cur_start = 1;    

        for (int i = 1; i < num_stops; ++i) {
            int segment_niceness;
            cin >> segment_niceness;

            cur_niceness += segment_niceness;

            if (cur_niceness > max_niceness || (cur_niceness == max_niceness && (i + 1 - cur_start) > (best_end - best_start))) {
                max_niceness = cur_niceness;
                best_start = cur_start;
                best_end = i + 1;
            }

            if (cur_niceness < 0) {
                cur_niceness = 0; 
                cur_start = i + 1; 
            }
        }

        if (max_niceness > 0) {
            cout << "The nicest part of route " << route << " is between stops " << best_start << " and " << best_end << endl;
        } else {
            cout << "Route " << route << " has no nice parts" << endl;
        }
    }

    return 0;
}
