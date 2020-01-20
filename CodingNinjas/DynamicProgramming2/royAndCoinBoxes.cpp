#include <bits/stdc++.h>
using namespace std;
// S and T - input strings
// You need to check if string T is present in S or not
#include<bits/stdc++.h>
using namespace std;
void computeLPSArray(char* S, int M, int* lps)
{
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) {
        if (S[i] == S[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0) {
                len = lps[len - 1];

                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
int findString(char S[], char T[]) {

    int M = strlen(T);
    int N = strlen(S);

    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(T, M, lps);
    cout<<"i am here"<<endl;

    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while (i < N) {
        if (T[j] == S[i]) {
            j++;
            i++;
        }

        if (j == M) {
            return (i-j);
            j = lps[j - 1];
        }

        // mismatch after j matches
        else if (i < N && T[j] != S[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }

}


int main() {
    char S[1000], T[1000];
    cin.getline(S, 1000);
    cin.getline(T, 1000);
    cout << findString(S, T) << endl;
}
