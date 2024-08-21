#include<iostream>
using namespace std;

class V3{
public:
    int x, y, z;
    static int count;
    V3(){
        this->x = 0;
        this->y = 0;
        this->z = 0;
        count++;
    }
    V3(int x, int y, int z){
        this->x = x;
        this->y = y;
        this->z = z;
    }
    friend ostream& operator <<(ostream &out, const V3 &v){
        out << "(" << v.x << ", " << v.y << ", " << v.z << ")";
        return out;
    }
    friend istream& operator >>(istream &inp, V3 &v){
        inp >> v.x >> v.y >> v.z;
        return inp;
    }
    V3 operator +(V3 &a){
        return V3(x+a.x, y+a.y, z+a.z);
    }
    V3 operator -(V3 &a){
        return V3(x-a.x, y-a.y, z-a.z);
    }
    V3 operator *(V3 &a){
        return V3(x*a.x, y*a.y, z*a.z);
    }
    V3 operator *(const int &k){
        return V3(x*k, y*k, z*k);
    }
    V3 operator /(const int &k){
        return V3(x/k, y/k, z/k);
    }
};

V3 operator *(const int &k, V3 &v){
    return V3(k*v.x, k*v.y, k*v.z);
}
int V3::count;

int main() 
{
    cout << fixed;
    cout.precision(2);
    cout << "current count of vectors: " << V3::count << endl;

    V3 v0;

    cout << "current count of vectors: " << V3::count << endl;

    int x, y, z;
    cin >> x >> y >> z;
    V3 v1(x, y, z); 

    cout << "current count of vectors: " << V3::count << endl;

    V3 v2;
    cin >> v2;
    
    cout << "v0 = " << v0 << endl;
    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;

    cout << "current count of vectors: " << V3::count << endl;

    V3 ans;
    ans = v1 + v2;
    cout << "v1 + v2 = " << ans << endl;
    ans = v1 - v2;
    cout << "v1 - v2 = " <<  ans << endl;

    cout << "current count of vectors: " << V3::count << endl;

    cout << "<v1 , v2> = " << v1 * v2 << endl;
    cout <<  "v1 * 4 = " << v1 * 4 << endl;
    cout <<  "5 * v1 = " << 5 * v1 << endl;
    cout << "v1 / 3 = " << v1 / 3 << endl;

    cout << "current count of vectors: " << V3::count << endl;
}