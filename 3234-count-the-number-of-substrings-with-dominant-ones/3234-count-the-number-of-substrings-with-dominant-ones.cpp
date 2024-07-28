/*

no. of 1's >= (no. of zeroes)*(no. of zeroes)


obviousely:

if length of substring =l

no. of ones = o

so no. of zeroes= l-o

so

l>= (l-o)*(l-o)

if no. of zeroes =0, than no. of ones>=1
if no. of zeroes =1, than no. of ones >=1
if no, of zeroes =2, than no. of ones >=4
if no. of zeroes=3, than no. of ones>=9
if no. of zeroes =4, than no. ones>=16
.
.
if no. of zeroes=200, than no. ones>=2*10^4

as length of string <= 2*10^4

so no. of substrings with dominant ones should have no. of zeroes < 200.


*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int result = 0;

        for (int k = 1; k * k <= n; ++k) {
            deque<int> zeros;       // Queue to store positions of zeros
            int lastzero = -1;      // Position of the zero before the first zero in our window
            int ones = 0;           // Count of ones in our current window

            // Scan through the string
            for (int right = 0; right < n; ++right) {
                if (s[right] == '0') {
                    zeros.push_back(right);
                    // If we have more than k zeros, remove the leftmost one
                    while (zeros.size() > k) {
                        ones -= (zeros.front() - lastzero - 1);  // Subtract ones between lastzero and the removed zero
                        lastzero = zeros.front();
                        zeros.pop_front();
                    }
                } else {
                    ones += 1;
                }

                // If we have exactly k zeros and at least k^2 ones
                if (zeros.size() == k && ones >= k * k) {
                    // Add the minimum of:
                    // 1. Number of ways to extend to the left (zeros.front() - lastzero)
                    // 2. Number of ways to extend to the right (ones - k^2 + 1)
                    result += std::min(zeros.front() - lastzero, ones - k * k + 1);
                }
            }
        }

        // Handle all-ones substrings
        int i = 0;
        while (i < n) {
            if (s[i] == '0') {
                i += 1;
                continue;
            }
            int sz = 0;
            while (i < n && s[i] == '1') {
                sz += 1;
                i += 1;
            }
            // Add number of all-ones substrings
            result += (sz * (sz + 1)) / 2;
        }

        return result;
    }
};

