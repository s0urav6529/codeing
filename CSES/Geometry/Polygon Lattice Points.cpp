#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);
#define reset(a,b)   memset(a, (b), sizeof(a))
#define sortv(k)     sort(k.begin(),k.end())
#define sortg(k)     sort(k.begin(),k.end(),greater<int>())
#define uniq(vec)    vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())))
#define rev(k)       reverse(k.begin(),k.end())
#define umin(a,b)    a=min(a,b)
#define umax(a,b)    a=max(a,b)
#define min3(a,b,c)  min(a, min(b,c))
#define pyes         cout<<"Yes"<<endl
#define pno          cout<<"No"<<endl
#define pf(a)        cout<<a<<endl
#define p2f(a,b)     cout<<a<<" "<<b<<endl
#define p3f(a,b,c)  cout<<a<<" "<<b<<" "<<c<<endl
#define p4f(a,b,c)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl
#define ff first
#define ss second
#define pb push_back
#define pi acos(-1.0)
//cin.get();
typedef long long int ll;
//typedef unsigned long long int llu;
//constexpr llu Mx=18446744073709551615;
constexpr ll MOD=1000000007;
const int limit=1e5+5;

ll poly_area(vector<pair<ll,ll>>&poly,int n){

    ll area = 0;
    for(int i=0;i<n;i++){

        area += (poly[i].first*poly[(i+1)%n].second) - (poly[(i+1)%n].first*poly[i].second);

    }
    area = abs(area);
    return area/2LL;

}

ll boundary_latticpoint(vector<pair<ll,ll>>&poly,int n){

    ll points = 0;
    for(int i=0;i<n;i++){

        ll delx = abs(poly[i].first - poly[(i+1)%n].first);
        ll dely = abs(poly[i].second - poly[(i+1)%n].second);

        points += __gcd(delx , dely) - 1;  ///Excluding endpoints because they count twice

    }

    return points+n;  ///Adding all the endpoints once
}

void an1nd1ta(int tc){

    int n;
    cin >> n;
    vector<pair<ll,ll>>poly(n);

    for(int i=0;i<n;i++){
        cin >> poly[i].first >> poly[i].second;
    }
    ll A = poly_area(poly,n);

    ll b = boundary_latticpoint(poly,n);

    ll i = A+1-(b/2LL);

    cout <<i<<" "<<b <<endl;

    return;
}

int main(){
    fast;
    int testcase=1;
    //cin >> testcase;
    for(int T=1;T<=testcase;T++) an1nd1ta(T);
    return 0;
}
