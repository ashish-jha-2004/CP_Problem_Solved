#include <bits/stdc++.h>

using namespace std;

#define int long long
#define F first
#define S second

map<char, pair<int, int>> direction_map;

bool validate_path(string path, int target_x, int target_y, string directions) 
{
    int current_x = 0;
    int current_y = 0;
    int horizontal_count = 0;
    int vertical_count = 0;
    
    for(int i = 0; i < path.size(); i++) 
    {
        if(path[i] == 'H') 
        {
            horizontal_count++;
        } 
        else 
        {
            vertical_count++;
        }
    }
    
    if(horizontal_count == 0 || vertical_count == 0) 
    {
        return false;
    }
    
    for (int i = 0; i < path.size(); i++) 
    {
        if (path[i] == 'H') 
        {
            pair<int, int> move = direction_map[directions[i]];
            current_x += move.F;
            current_y += move.S;
        }
    }
    
    if (current_x != target_x || current_y != target_y) 
    {
        return false;
    }
    
    return true;
}

signed main() 
{
    int test_cases;
    cin >> test_cases;
    
    direction_map['N'] = {0, 1};
    direction_map['S'] = {0, -1};
    direction_map['E'] = {1, 0};
    direction_map['W'] = {-1, 0};

    while (test_cases--) 
    {
        int path_length;
        cin >> path_length;
        
        string path;
        cin >> path;

        int final_x = 0, final_y = 0;
        for (int i = 0; i < path_length; i++) 
        {
            pair<int, int> move = direction_map[path[i]];
            final_x += move.F;
            final_y += move.S;
        }
        
        if (final_x % 2 != 0 || final_y % 2 != 0) 
        {
            cout << "NO" << endl;
            continue;
        }
        
        final_x = final_x / 2;
        final_y = final_y / 2;
        
        string result_path = path;
        
        if (final_x == 0 && final_y == 0) 
        {
            int counts[2] = {0, 0};
            for (int i = 0; i < path_length; i++) 
            {
                if (path[i] == 'N') 
                {
                    counts[0]++;
                }
                if (path[i] == 'S') 
                {
                    counts[1]++;
                }
            }
            
            bool valid_flag = false;
            
            if (counts[0] != 0 && counts[1] != 0) 
            {
                for (int i = 0; i < path_length; i++) 
                {
                    if (path[i] == 'N') 
                    {
                        result_path[i] = 'R';
                        break;
                    }
                }
                for (int i = 0; i < path_length; i++) 
                {
                    if (path[i] == 'S') 
                    {
                        result_path[i] = 'R';
                        break;
                    }
                }
                for (int i = 0; i < path_length; i++) 
                {
                    if (result_path[i] != 'R') 
                    {
                        result_path[i] = 'H';
                    }
                }
                if (validate_path(result_path, final_x, final_y, path)) 
                {
                    valid_flag = true;
                    cout << result_path << endl;
                }
            }
            
            if (!valid_flag) 
            {
                result_path = path;
                counts[0] = 0;
                counts[1] = 0;
                
                for (int i = 0; i < path_length; i++) 
                {
                    if (path[i] == 'E') 
                    {
                        counts[0]++;
                    }
                    if (path[i] == 'W') 
                    {
                        counts[1]++;
                    }
                }
                
                if (counts[0] != 0 && counts[1] != 0) 
                {
                    for (int i = 0; i < path_length; i++) 
                    {
                        if (path[i] == 'E') 
                        {
                            result_path[i] = 'R';
                            break;
                        }
                    }
                    for (int i = 0; i < path_length; i++) 
                    {
                        if (path[i] == 'W') 
                        {
                            result_path[i] = 'R';
                            break;
                        }
                    }
                    for (int i = 0; i < path_length; i++) 
                    {
                        if (result_path[i] != 'R') 
                        {
                            result_path[i] = 'H';
                        }
                    }
                    if (validate_path(result_path, final_x, final_y, path))
                    {
                        valid_flag = true;
                        cout << result_path << endl;
                    } 
                    else 
                    {
                        cout << "NO" << endl;
                    }
                } 
                else 
                {
                    cout << "NO" << endl;
                }
            }
        } 
        else if (final_x >= 0 && final_y >= 0) 
        {
            int temp_x = 0, temp_y = 0;
            for (int i = 0; i < path_length; i++) 
            {
                if (path[i] == 'E' && temp_x != final_x) 
                {
                    temp_x++;
                    result_path[i] = 'R';
                } 
                else if (path[i] == 'N' && temp_y != final_y) 
                {
                    temp_y++;
                    result_path[i] = 'R';
                }
            }
            for (int i = 0; i < path_length; i++) 
            {
                if (result_path[i] != 'R') 
                {
                    result_path[i] = 'H';
                }
            }
            if (validate_path(result_path, final_x, final_y, path)) 
            {
                cout << result_path << endl;
            } 
            else 
            {
                cout << "NO" << endl;
            }
        } 
        else if (final_x <= 0 && final_y >= 0) 
        {
            int temp_x = 0, temp_y = 0;
            for (int i = 0; i < path_length; i++) 
            {
                if (path[i] == 'W' && temp_x != final_x) 
                {
                    temp_x--;
                    result_path[i] = 'R';
                } 
                else if (path[i] == 'N' && temp_y != final_y) 
                {
                    temp_y++;
                    result_path[i] = 'R';
                }
            }
            for (int i = 0; i < path_length; i++) 
            {
                if (result_path[i] != 'R') 
                {
                    result_path[i] = 'H';
                }
            }
            if (validate_path(result_path, final_x, final_y, path)) 
            {
                cout << result_path << endl;
            } 
            else 
            {
                cout << "NO" << endl;
            }
        } 
        else if (final_x <= 0 && final_y <= 0) 
        {
            int temp_x = 0, temp_y = 0;
            for (int i = 0; i < path_length; i++) 
            {
                if (path[i] == 'W' && temp_x != final_x) 
                {
                    temp_x--;
                    result_path[i] = 'R';
                } 
                else if (path[i] == 'S' && temp_y != final_y) 
                {
                    temp_y--;
                    result_path[i] = 'R';
                }
            }
            for (int i = 0; i < path_length; i++) 
            {
                if (result_path[i] != 'R') 
                {
                    result_path[i] = 'H';
                }
            }
            if (validate_path(result_path, final_x, final_y, path)) 
            {
                cout << result_path << endl;
            } 
            else 
            {
                cout << "NO" << endl;
            }
        } 
        else 
        {
            int temp_x = 0, temp_y = 0;
            for (int i = 0; i < path_length; i++) 
            {
                if (path[i] == 'E' && temp_x != final_x) 
                {
                    temp_x++;
                    result_path[i] = 'R';
                } 
                else if (path[i] == 'S' && temp_y != final_y) 
                {
                    temp_y--;
                    result_path[i] = 'R';
                }
            }
            for (int i = 0; i < path_length; i++) 
            {
                if (result_path[i] != 'R') 
                {
                    result_path[i] = 'H';
                }
            }
            if (validate_path(result_path, final_x, final_y, path)) 
            {
                cout << result_path << endl;
            } 
            else 
            {
                cout << "NO" << endl;
            }
        }
    }
}
