#include <iostream>
#include  <vector>
#include <string>
using namespace std;


struct Coord{
    float x,y;
};
int main()
{
    vector<Coord> O{Coord{0,0},Coord{2,1}};
    vector<float> R{4,3};
    vector<Coord> P{Coord{1,3},Coord{2,1.41},Coord{0.2,-7},Coord{-5,-1},Coord{0,9}};
    string man1 = "Manipulator1 |";
    string man2 = "Manipulator2 |";
    //int P_num;
//    cout << "Enter coordinates of Manipulator1:"; // Ввод значений  при необходимости
//    cin >> O[0].x >> O[0].y;
//    cout << "Enter radius of Manipulator1:";
//    cin >> R[0];
//    cout << "Enter coordinates of Manipulator2:";
//    cin >> O[1].x >> O[1].y;
//    cout << "Enter radius of Manipulator2:";
//    cin >> R[1];
//    cout << "Count of Targets:";
//    cin >> P_num;
//    for(int i = 0; i < P_num; i++)
//    {
//        float x,y;
//        cout << "Enter coordinates of Target[" << i << "]:";
//        cin >> x >> y;
//        P.push_back(Coord{x, y});
//    }
    for(int j = 0; j < P.size(); j++)
    {
        float min_dist;
        int num_man;
        for(int i = 0; i < O.size();  i++)
        {
            float dist = (O[i].x - P[j].x) * (O[i].x - P[j].x) + (O[i].y - P[j].y) * (O[i].y - P[j].y);
            if(i == 0)
                min_dist = dist;
            if(dist <= min_dist)
            {
                min_dist = dist;
                num_man = i;
            }
        }
        O[num_man].x = P[j].x;
        O[num_man].y = P[j].y;
        if(num_man == 0) // Вывод в таблицу
        {
            man1 += " {";
            man1 += to_string(O[num_man].x).substr(0, to_string(O[num_man].x).find(".") + 3);
            man1 += ",";
            man1 += to_string(O[num_man].y).substr(0, to_string(O[num_man].y).find(".") + 3);
            man1 += "} ";
            man2 += "             ";
        }
        else if(num_man == 1)
        {
            man1 += "             ";
            man2 += " {";
            man2 += to_string(O[num_man].x).substr(0, to_string(O[num_man].x).find(".") + 3);
            man2 += ",";
            man2 += to_string(O[num_man].y).substr(0, to_string(O[num_man].y).find(".") + 3);
            man2 += "} ";
        }
    }
    cout << man1 << endl;
    cout << man2 << endl;

}
