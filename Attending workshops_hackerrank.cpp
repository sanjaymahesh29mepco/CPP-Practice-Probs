#include<bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
// 1. struct Workshop
struct Workshop {
    int start_time;
    int duration;
    int end_time;
};

// 2. struct Available_Workshops
struct Available_Workshops {
    int n;
    Workshop* workshops;
};

// Implement initialize function
Available_Workshops* initialize(int start_time[], int duration[], int n) {
    Available_Workshops* ptr = new Available_Workshops;
    ptr->n = n;
    ptr->workshops = new Workshop[n];

    
    for (int i = 0; i < n; i++) {
        ptr->workshops[i].start_time = start_time[i];
        ptr->workshops[i].duration = duration[i];
        ptr->workshops[i].end_time = start_time[i] + duration[i];
    }
    
    return ptr;
}

// Implement CalculateMaxWorkshops function
// Uses Greedy Algorithm: Sort by end time to maximize attendance
int CalculateMaxWorkshops(Available_Workshops* ptr) {
    if (ptr->n == 0) return 0;

    // Convert to vector for easier sorting
    std::vector<Workshop> v;
    for (int i = 0; i < ptr->n; i++) {
        v.push_back(ptr->workshops[i]);
    }

    // Sort based on end_time
    std::sort(v.begin(), v.end(), [](const Workshop& a, const Workshop& b) {
        return a.end_time < b.end_time;
    });

    int count = 0;
    int current_end_time = 0;

    for (int i = 0; i < ptr->n; i++) {
        // "The next workshop cannot be attended until the previous workshop ends."
        if (v[i].start_time >= current_end_time) {
            count++;
            current_end_time = v[i].end_time;
        }
    }

    return count;
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
