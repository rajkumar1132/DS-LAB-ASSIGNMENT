

// Count the frequency of each number in an array using a hash map.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void countFrequency(vector<int>& nums) {
    unordered_map<int, int> freq;


    for (int num : nums) {
        freq[num]++;
    }

    // Print results
    for (auto& pair : freq) {
        cout << pair.first << " → " << pair.second;
        if (pair.second == 1)
            cout << " time";
        else
            cout << " times";
        cout << endl;
    }
}

int main() {
    vector<int> nums = {2, 3, 2, 4, 3, 2};
    countFrequency(nums);
    return 0;
}