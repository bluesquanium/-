#include <stdio.h>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
 
typedef long long ll;
 
// ����� ���ϰ� �ϱ� ���� Point����ü �� ��� ������ ����
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
 
	// �ߵڲ�ġ�� �������� �ϵ��� ������ �����̵���Ű��
	for(int i=1;i<=N;i++){
		X[i] -= xbase; Y[i] -= ybase;
		if( X[i] == 0 && Y[i] == 0 ) continue;
		v.push_back({X[i], Y[i], i});
	}
 
	// ������ ����(1,2,...,N-1)�� ��� �ݽð�������� ����
	sort( v.begin(), v.end() , [](Point& a, Point& b){
		return ccw(a,b) > 0;
	} );
 
	v.push_back({0,0,0});
 
	// i�� ������Ű�� �����̵� ������ ������� dp1[i][j], dp2[i][j]�� ��� ä����
	for(int i=0;i<v.size();i++){
 
		// ������ ���� L, R�� �����
		// �� ���� �� �������� �ִ� ��쿡 �������� 
		vector<Point> L,R;
		for(int j=0;j<i;j++){
			if( ccw(v[j], v[i]) == 0 ) continue;
			R.push_back(v[j]);
		}
		for(int j=i+1;j<v.size();j++){
			if( j != v.size()-1 && ccw(v[j], v[i]) == 0 ) continue;
			L.push_back(v[j]);
		}
 
		// dp1�� ä��� ���� L,R�� �ݽð�������� ����
		sort(L.begin(), L.end(), [i](Point a, Point b){
			return ccw(a-v[i], b-v[i]) > 0;
		});
		sort(R.begin(), R.end(), [i](Point a, Point b){
			return ccw(a-v[i], b-v[i]) > 0;
		});
 
 
		int pos = -1;
		int mx = 0, mxx = 0;
		
		// �����̵� ������� dp1 ä���
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
 
		// dp2�� ä��� ���� L,R�� �ð�������� ����
		sort(L.begin(), L.end(), [i](Point a, Point b){
			return ccw(a-v[i], b-v[i]) < 0;
		});
		sort(R.begin(), R.end(), [i](Point a, Point b){
			return ccw(a-v[i], b-v[i]) < 0;
		});
 
		// �����̵� ������� dp2 ä���
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
 
			// ���� ��� �ι�° ������ �����ϴ� �Ϳ� ����
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
 
	// ���ڱ��� ����� ���� ��� (�߰����� 1�� ����)
	if( mx < 3 ){
		printf("0\n");
		return 0;
	}
 
	// ���� �Ǵ� ������ ������ ansv�� �ֱ�
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
 
	// �� ���
	printf("%d\n", mx+1);
	reverse( ansv.begin(), ansv.end() );
	for(auto e : ansv) printf("%lld %lld\n",e.first, e.second);
}
