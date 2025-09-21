#include <array>
#include <algorithm>
#include <numeric> 
#include <fstream>
#include <iostream>

using namespace std;

constexpr size_t DAYS = 30;
using Arr = array<int, DAYS>;

int main(){
    Arr steps{};
    ifstream fin("steps.txt");
    if (!fin) { 
        cerr << "Can't open steps.txt\n"; 
        return 1; 
    }

    for (size_t i = 0; i < steps.size(); ++i) {
        if (!(fin >> steps[i])) { cerr << "Not enough numbers\n"; return 1; }
    }

    cout << "Size = " << steps.size() << " days. First=" << steps.front() << " Last=" << steps.back() << "\n";

    try {
        cout << "Day 10 (at) = " << steps.at(9) << "\n";
    } catch(out_of_range& e){
        cout << "Out of range: " << e.what() << "\n";
    }

    int looking = 6899;
    array<int, DAYS>::iterator it;
    it = find(steps.begin(), steps.end(), looking);
    cout << "Find: " << looking;

    if (it != steps.end())
        cout << " found in position " << it - steps.begin() << endl;
    else
        cout << " was not found.\n";
    cout << "    Value: " << *it << endl;

    cout << "Empty? " << (steps.empty() ? "true" : "false") << "\n";

    int *raw = steps.data();
    cout << "data() pointer: " << raw << "\n"; //for the location

    cout << "Max: " << *max_element(steps.begin(), steps.end()) << endl;
    cout << "Min: " << *min_element(steps.begin(), steps.end()) << endl;
    cout << "Sum: " << accumulate(steps.begin(), steps.end(), 0) << endl;

    sort(steps.begin(), steps.end());
    cout << "Sorted: ";
    for (double val : steps) cout << val << " "; cout << endl;
    sort(steps.rbegin(), steps.rend());
    cout << "Reverse Sorted: ";
    for (double val : steps) cout << val << " "; cout << endl;

    cout << "Days 15-17 BEFORE FILL: " << steps[14] << " " << steps[15] << " " << steps[16] << "\n";
    fill(steps.begin() + 14, steps.begin() + 17, 0);
    cout << "Days 15-17 AFTER FILL:  "<< steps[14] << " " << steps[15] << " " << steps[16] << "\n";

    cout << "Days 12 and 13 BEFORE SWAP: " << steps[11] << " " << steps[12] << "\n";
    iter_swap(steps.begin() + 11, steps.begin() + 12);
    cout << "Days 12 and 13 AFTER SWAP: " << steps[11] << " " << steps[12] << "\n";
}