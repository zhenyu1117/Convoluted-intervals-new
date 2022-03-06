#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 20000;

long long a[MAXN], b[MAXN];
long long in[MAXN];
long long out[MAXN];
long long ans[MAXN];

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++ i){
		int x, y;
		scanf("%d %d",&x, &y);
		++ a[x];
		++ b[y];
	}
	
	for(int i = 0; i <= m; ++ i)
		for(int j = 0; j <= m; ++ j)
			in[i + j] += a[i] * a[j], out[i + j] += b[i] * b[j];
		
	
	long long count = 0;
	for(int i = 0; i <= 2 * m; ++ i){
		count += in[i];
		ans[i] = count;
		count -= out[i];
	}
	
	for(int i = 0; i <= 2 * m; ++ i) cout << ans[i] << endl;
	return 0;
}

