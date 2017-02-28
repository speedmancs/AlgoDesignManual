#include <iostream>
#include <vector>

using namespace std;
class State
{
public:
    State(int _n);
    bool IsFinal();
    void Process();
    bool CanMove(bool f);
    void Move(bool f);
    void Recover(bool f);
private:
    int k;  // solution[0:k] has been filled from among [1:n]
    vector<bool> solution; // contains solution
    int n;
};

void State::Recover(bool flag)
{
    k --;
}

void State::Move(bool flag)
{
    k ++;
    solution[k] = flag;
}

bool State::CanMove(bool take)
{
    return true;
}

void State::Process()
{
    bool hasElement = false;
    for (int i = 0; i < n; i++)
    {
        if (solution[i])
        {
            hasElement = true;
            cout << i + 1<< " ";
        }
    }
    if (!hasElement)
    {
        cout << "No element";
    }
    cout << endl;
}

bool State::IsFinal()
{
    return k == n - 1;
}

State::State(int _n): n(_n), k(-1)
{
    solution.resize(n);
}

bool candidates[] = {false, true};
void Solve(State& state, int n)
{
    if (state.IsFinal())
    {
        state.Process();
        return;
    }

    for (int i = 0; i < 2; i++)
    {
        if (state.CanMove(candidates[i]))
        {
            state.Move(candidates[i]);
            Solve(state, n);
            state.Recover(candidates[i]);
        }

    }
}
int main(int argc, char const *argv[]) {
    int n = 9;
    State initState(n);
    Solve(initState, n);
    return 0;
}
