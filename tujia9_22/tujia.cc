//shouwangzhetaowang
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int maxn = 300000;
//
//int main()
//{
//    int M,S,T;
//    while(cin >> M >> S >> T)
//    {
//        vector<int> v(maxn,0);
//        for(int i = 1;i <= T;++i)
//        {
//            if(M >= 10)
//            {
//                v[i] = v[i-1]+ 50;
//                M -= 10;
//            }
//            else
//            {
//                v[i] = v[i-1];
//                M += 4;
//            }
//        }
//        for(int i = 1;i <= T;++i)
//        {
//            v[i] = max(v[i],v[i-1]+13);
//            if(v[i] >= S)
//            {
//                cout << "Yes " << i << endl;
//            }
//        }
//        if(S >= v[T])
//            cout << "No " << v[T] << endl;
//    }
//
//    return 0;
//}



//lvyouluxian
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int MinRoad(vector<vector<int>>& vv)
//{
//    int sum = 0;
//    for(int i = 0;i < vv.size();++i)
//    {
//        if(vv[i][0] == 4 && vv[i][1] == 3)
//            sum += vv[i][2];
//        if(vv[i][0] == 4 && vv[i][1] == 2)
//            sum += vv[i][2];
//    }
//    return sum;
//}
//
//int main()
//{
//    vector<vector<int>> vv;
//    int N,M,R;
//    vector<int> v;
//    cin >> N >> M >> R;
//    v.push_back(N);
//    v.push_back(M);
//    v.push_back(R);
//    vv.push_back(v);
//    v.clear();
//    for(int i = 0;i < R;i++)
//        {
//            int r = 0;
//            cin >> r;
//            v.push_back(r);
//        }
//    vv.push_back(v);
//    v.clear();
//    for(int i = 0;i < M;i++)
//        {
//		int a,b,c;
//            cin >> a >> b >> c;
//            v.push_back(a);
//            v.push_back(b);
//            v.push_back(c);
//            vv.push_back(v);
//    		v.clear();
//        }
//    cout << MinRoad(vv) << endl;
//    return 0;
//}

