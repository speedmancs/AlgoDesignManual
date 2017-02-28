#include <iostream>
#include <vector>
using namespace std;

/*
    print all the rearrangement of [1....n]
*/

vector<bool> used;
void solve(vector<int>& a, int k, int n);
void process_solution(vector<int>& a);
int main()
{
    int n = 9;
    used.assign(n + 1, false);
    vector<int> a(n);
    solve(a, -1, n);
    return 0;
}

// a[0:k] has been filled
void solve(vector<int>& a, int k, int n)
{
    if (k == n - 1)
    {
        process_solution(a);
        return;
    }

    // about to fill k + 1
    k ++;
    for (int i = 1; i <=n; i++)
    {
        if (!used[i])
        {
            a[k] = i;
            used[i] = true;
            solve(a, k, n);
            used[i] = false;
        }
    }
}

void process_solution(std::vector<int>& v)
{
    for (auto it = v.begin(); it != v.end(); it ++)
        cout << *it << " ";
    cout << endl;
}
