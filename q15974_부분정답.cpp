#include <stdio.h>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
 
typedef long long ll;
 
// 계산을 편리하게 하기 위한 Point구조체 및 몇가지 연산자 정의
struct Point{
	ll x,y,n;
};
Point operator - (Point a, Point b){
	return {a.x-b.x, a.y-b.y, a.n};
}
ll ccw(Point a, Point b){
	return a.x * b.y - a.y * b.x;
}
 
int N;
ll xbase = 0, ybase = 1e9;
ll X[5050], Y[5050];
vector<Point> v;
 
int dp1[5050][5050], dp2[5050][5050];
int prev1[5050][5050], prev2[5050][5050];
 
int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%lld%lld",&X[i],&Y[i]);
		if( ybase > Y[i] ){
			ybase = Y[i]; xbase = X[i];
		}
	}
 
	// 발뒤꿈치를 원점으로 하도록 점들을 평행이동시키자
	for(int i=1;i<=N;i++){
		X[i] -= xbase; Y[i] -= ybase;
		if( X[i] == 0 && Y[i] == 0 ) continue;
		v.push_back({X[i], Y[i], i});
	}
 
	// 나머지 점들(1,2,...,N-1)을 모두 반시계방향으로 정렬
	sort( v.begin(), v.end() , [](Point& a, Point& b){
		return ccw(a,b) > 0;
	} );
 
	v.push_back({0,0,0});
 
	// i를 고정시키고 슬라이딩 윈도우 기법으로 dp1[i][j], dp2[i][j]를 모두 채우자
	for(int i=0;i<v.size();i++){
 
		// 점들의 집합 L, R을 만들기
		// 세 점이 한 직선위에 있는 경우에 주의하자 
		vector<Point> L,R;
		for(int j=0;j<i;j++){
			if( ccw(v[j], v[i]) == 0 ) continue;
			R.push_back(v[j]);
		}
		for(int j=i+1;j<v.size();j++){
			if( j != v.size()-1 && ccw(v[j], v[i]) == 0 ) continue;
			L.push_back(v[j]);
		}
 
		// dp1을 채우기 위해 L,R을 반시계방향으로 정렬
		sort(L.begin(), L.end(), [i](Point a, Point b){
			return ccw(a-v[i], b-v[i]) > 0;
		});
		sort(R.begin(), R.end(), [i](Point a, Point b){
			return ccw(a-v[i], b-v[i]) > 0;
		});
 
 
		int pos = -1;
		int mx = 0, mxx = 0;
		
		// 슬라이딩 윈도우로 dp1 채우기
		for(auto p : L){
 
			while( pos+1 < R.size() && ccw( v[i]-p , R[pos+1]-p ) < 0 ){
				pos++;
				if( mx < dp2[ R[pos].n ][ v[i].n ] ){
					mx = dp2[ R[pos].n ][ v[i].n ];
					mxx = R[pos].n;
				}
			}
 
			if( dp1[ v[i].n ][ p.n ] < mx+1 ){
				dp1[ v[i].n ][ p.n ] = mx + 1;
				prev1[ v[i].n ][ p.n ] =mxx;
			}
			
		}
 
		// dp2를 채우기 위해 L,R을 시계방향으로 정렬
		sort(L.begin(), L.end(), [i](Point a, Point b){
			return ccw(a-v[i], b-v[i]) < 0;
		});
		sort(R.begin(), R.end(), [i](Point a, Point b){
			return ccw(a-v[i], b-v[i]) < 0;
		});
 
		// 슬라이딩 윈도우로 dp2 채우기
		pos = -1; mx = 0, mxx = 0;
		for(auto p : L){
			if( p.n == 0 ) continue;
			while( pos+1 < R.size() && ccw( v[i]-p , R[pos+1]-p ) > 0 ){
				pos++;
				if( mx < dp1[ R[pos].n ][ v[i].n ] ){
					mx = dp1[ R[pos].n ][ v[i].n ];
					mxx = R[pos].n;
				}
			}
 
			// 골은 적어도 두번째 점부터 시작하는 것에 유의
			if( mx >= 1 && dp2[ v[i].n ][ p.n ] < mx+1 ){
				dp2[ v[i].n ][ p.n ] = mx + 1;
				prev2[ v[i].n ][ p.n ] = mxx;
			}
			
		}
	}
 
	int mx = -1, mxx = 0;
	for(int i=1;i<=N;i++){
		if( mx < dp1[i][0] ){
			mx = dp1[i][0];
			mxx = i;
		}
	}
 
	// 발자국을 만들수 없는 경우 (발가락이 1개 이하)
	if( mx < 3 ){
		printf("0\n");
		return 0;
	}
 
	// 답이 되는 점들을 복원해 ansv에 넣기
	vector<pair<ll,ll>> ansv;
	int cur = mxx, nxt = 0;
	while( true ){
		ansv.push_back({X[cur]+xbase, Y[cur]+ybase});
		if( dp1[cur][nxt] == 1 ) break;
		int pre = prev1[cur][nxt];
		nxt = cur;
		cur = pre;
 
		ansv.push_back({X[cur]+xbase, Y[cur]+ybase});
		pre = prev2[cur][nxt];
		nxt = cur;
		cur = pre;
	}
	ansv.push_back({xbase, ybase});
 
	// 답 출력
	printf("%d\n", mx+1);
	reverse( ansv.begin(), ansv.end() );
	for(auto e : ansv) printf("%lld %lld\n",e.first, e.second);
}
