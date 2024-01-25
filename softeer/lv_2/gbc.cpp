#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int main()
{
    vector<tuple<int, int, int>> standard_spec; // <start, end, velocity>
    vector<tuple<int, int, int>> test_spec;     // <start, end, velocity>

    int N, M;
    cin >> N >> M;

    // input data
    for (int i = 0; i < N; i++)
    {
        int pos, vel;
        cin >> pos >> vel;
        if (i == 0)
            standard_spec.push_back(make_tuple(0, pos, vel));
        else
            standard_spec.push_back(make_tuple(get<1>(standard_spec.at(i - 1)), get<1>(standard_spec.at(i - 1)) + pos, vel));
    }
    for (int i = 0; i < M; i++)
    {
        int pos, vel;
        cin >> pos >> vel;
        if (i == 0)
            test_spec.push_back(make_tuple(0, pos, vel));
        else
            test_spec.push_back(make_tuple(get<1>(test_spec.at(i - 1)), get<1>(test_spec.at(i - 1)) + pos, vel));
    }

    int n_idx = 0, m_idx = 0;
    int max_vel_gap = 0;
    while ((n_idx > N - 1 && m_idx > M - 1) != true)
    {
        int std_spec_end = get<1>(standard_spec.at(n_idx));
        int test_spec_end = get<1>(test_spec.at(m_idx));
        int tmp_vel_gap = get<2>(test_spec.at(m_idx)) - get<2>(standard_spec.at(n_idx));

        if (tmp_vel_gap > max_vel_gap)
            max_vel_gap = tmp_vel_gap;

        if (std_spec_end == test_spec_end)
        {
            n_idx++;
            m_idx++;
        }
        else if (std_spec_end < test_spec_end)
        {
            n_idx++;
        }
        else
        {
            m_idx++;
        }
    }

    cout << max_vel_gap;

    return 0;
}