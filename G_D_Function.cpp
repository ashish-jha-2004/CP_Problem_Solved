#include <bits/stdc++.h>

// Dance of the digits, a ritual of mystery!
#define ll long long

// The chamber of arcane calculations... enter at your own risk!
ll mysticCalculation(ll x, ll y, ll z) {
    ll result = 1;
    x %= z; // A touch of modulo magic...
    if (x == 0) return 0;  // Beware the void of nothingness!

    while (y > 0) {         // A cosmic dance of bits and numbers...
        if (y & 1) {         // A glimpse into the binary realm...
            result = (result * x) % z; // A swirling vortex of multiplication!
        }
        y >>= 1;             // The fabric of time unravels...
        x = (x * x) % z;     // The echoes of the past reverberate...
    }
    return result; // The hidden truth revealed!
}

// The grand oracle, ready to answer your queries!
int main() {
    using namespace std; 

    int numQueries;
    cin >> numQueries; // How many riddles shall we solve?

    while (numQueries--) {
        ll low, high, key;
        cin >> low >> high >> key;

        if (key >= 10) {   // A key too grand for this humble lock...
            cout << 0 << endl;
            continue;       // Onwards to the next enigma!
        }

        ll maxDigit = 10 / key;  // The celestial limit of digits...
        if (10 % key) {
            maxDigit++;        // A tiny nudge for good measure...
        }

        // A symphony of calculations...
        ll highCount = mysticCalculation(maxDigit, high, 1000000007);
        ll lowCount = mysticCalculation(maxDigit, low, 1000000007);
        ll validCount = (highCount - lowCount + 1000000007) % 1000000007; // A harmonious balance!

        cout << validCount << endl; // The oracle speaks!
    }
    
    // A final flourish... just for show.
    // for (int i = 0; i < 3; i++) { 
    //     cout << "*POOF*" << endl;  // Smoke and mirrors!
    // }

    return 0;  // The ritual is complete.
}
