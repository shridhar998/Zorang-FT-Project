#include<bits/stdc++.h>
using namespace std;
typedef double db;

// function to convert degrees into radians
double toRadians(double degree)
{
    double one_deg = (M_PI) / 180;
    return (one_deg * degree);
}

// function to find the distance between two geographical coordinates
double distance(double lat1, double long1, double lat2, double long2)
{
 
    lat1 = toRadians(lat1);
    long1 = toRadians(long1);
    lat2 = toRadians(lat2);
    long2 = toRadians(long2);
     
    double dlong = long2 - long1;
    double dlat = lat2 - lat1;
 
    double ans = pow(sin(dlat / 2), 2) +
                          cos(lat1) * cos(lat2) *
                          pow(sin(dlong / 2), 2);
 
    ans = 2 * asin(sqrt(ans));
    double R = 6371;
    ans = ans * R;
    return ans;
}
int main()
{
    db store_lat=28.9428,store_long=77.2276;       // coordinates of the store

    vector<int>visited(101);
    vector<pair<db,db> > delivery_loc(101);        // coordinates of the delivery locations
    vector<pair<db,db> > curr_pos(11,{store_lat,store_long});
    vector<db> dist_so_far(11);

    freopen("input.txt","r",stdin);

    for(int i=1; i<=100; i++){
        int id;
        cin>>id;
        cin>>delivery_loc[i].first;
        cin>>delivery_loc[i].second;
    }

    vector<vector<int> >plan(11);                 // plan[i] -> ordered list of the delivery locations that 'i' will be going to
    for(int i=0; i<100; i++){
        db min_distance=1e9;
        int agent=0;
        int destination=0;
        for(int j=1; j<=10; j++){
            for(int k=1; k<=100; k++){
                if(visited[k])
                 continue;
                db dist=dist_so_far[j]+distance(curr_pos[j].first,curr_pos[j].second,delivery_loc[k].first,delivery_loc[k].second);
                if(dist<min_distance){
                    min_distance=dist;
                    agent=j;
                    destination=k;
                }
            }
        }
        plan[agent].push_back(destination);
        visited[destination]=1;
        curr_pos[agent]=delivery_loc[destination];
        dist_so_far[agent]=min_distance;
    }

    for(int i=1; i<=10; i++){
        cout<<i<<" : ";
        for(auto var : plan[i])
         cout<<var<<" ";
        cout<<"\n";
    }

    return 0;
}
