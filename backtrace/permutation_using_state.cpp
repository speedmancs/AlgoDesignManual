#include <iostream>
#include <vector>

using namespace std;
class State
{
public:
    State(int _n);
    bool IsFinal();
    void Process();
    bool CanMove(int i);
    void Move(int i);
    void Recover(int i);
private:
    int k;  // solution[0:k] has been filled from among [1:n]
    vector<bool> used; // whether i has been selected in solution[0:k]
    vector<int> solution; // contains solution
    int n;
};

void State::Recover(int i)
{
    k --;
    used[i] = false;
}

void State::Move(int i)
{
    k ++;
    solution[k] = i;
    used[i] = true;
}

bool State::CanMove(int i)
{
    return !used[i];
}

void State::Process()
{
    for (int i = 0; i < n; i ++)
        cout << solution[i] << " ";
    cout << endl;
}

bool State::IsFinal()
{
    return k == n - 1;
}
State::State(int _n): n(_n), k(-1)
{
    used.assign(n + 1, false);
    solution.resize(n);
}

void Solve(State& state, int n)
{
    if (state.IsFinal())
    {
        state.Process();
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (state.CanMove(i))
        {
            state.Move(i);
            Solve(state, n);
            state.Recover(i);
        }

    }
}
int main(int argc, char const *argv[]) {
    int n = 9;
    State initState(n);
    Solve(initState, n);
    return 0;
}
