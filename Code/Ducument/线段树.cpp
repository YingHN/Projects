#include<bits/stdc++.h>
using namespace std;
//#define int long long int
const int MAXN = 1e5 + 1;
int a[MAXN];
inline int leftSon(int x){return x << 1;}
inline int rightSon(int x){return (y << 1) + 1;};
// 注意运算优先级: 移 < +
struct NODE
{
	int sum, tag = 0;
}tr[MAXN << 2]; // 在非动态线段树中, 必须开到4倍大小
void psu(int id)
// 上传子区间的更新对父区间的影响
{
	tr[id].sum = tr[leftSon(id)].sum + tr[rightSon(id)].sum;
}
void psd(int l, int r, int id)
// 下传管理区间[l, r]的节点#id的懒标记tag
{
	int m = ((r - l) >> 1) + l, ls = leftSon(id), rs = rightSon(id);

	tr[ls].tag += tr[id].tag, tr[rs].tag += tr[id].tag; 
	// 注意是+=, 因为原来还有tag

	tr[ls].sum += (m - l + 1) * tr[id].tag; // 区间长度 * 懒标记

	tr[rs].sum += (r - m) * tr[id].tag;
	// ! 注意一定要**乘tr[id].tag**: ~~可以自己手模~~
	// 如果乘自己的tag: 
	//   在之前的psd()中, 原来的tag已经用过, 再次乘会得到错误结果. 
	// 如果乘父亲的tag: 
	//   这个tag之前并没有用过, 是刚刚下传的, 合理. 

	tr[id].tag = 0; // ! 不要忘记清除标记
}
void build(int l, int r, int id) 
// 对于区间[l, r]建树
{
	if(l == r) // 区间已退化为点
	{
		tr[id].sum = a[l];
		return;
	}
	int m = ((r - l) >> 1) + l; // 防溢出
	//递归对左右子区间建子树
	build(l, m, leftSon(id)), build(m + 1, r, rightSon(id));
	
	psu(id);
}
int getSum(int L, int R, int l, int r, int id)
// 得到区间[L, R]的区间和
{
	if(L <= l && R >= r)return tr[id].sum;
	// 不要写成 L >= l && R <= r, 很多人都会写错~~比如我~~
	// 意为"区间[l, r]是区间[L, R]的子集"
	// 这时, 可以直接返回区间[l, r]的和, 
	// 因为这只是上层getSum()所要加起来的区间之一, 
	// getSum()以小区间和拼凑大区间和. 

	int m = ((r - l) >> 1) + l, sum = 0;

	psd(l, r, id);

	if(L <= m)sum += getSum(L, R, l, m, leftSon(id));
	if(R > m)sum += getSum(L, R, m + 1, r, rightSon(id));

	return sum;
}
void add(int L, int R, int k, int l, int r, int id)
{
	if(L <= l && R >= r)
	// 同样, 不要写错
	{
		tr[id].tag += k;
		tr[id].sum += k * (r - l + 1);
		// 同样, 这里也要乘k, 而不是tag
		return;
	}

	int m = (r - l) >> 1 + l, sum = 0;

	psd(l, r, id);

	if(L <= m)add(L, R, k, l, m, leftSon(id));
	if(R > m)add(L, R, k, m + 1, r, rightSon(id));

	psu(id);
}
signed main()
{
	int n, m;
	cin>>n>>m;
	for(int i = 1; i <= n; ++i)
		cin>>a[i];

	build(1, n, 1);

	while(m--)
	{
		int typ, l, r;
		cin>>typ>>l>>r;
		if(typ == 1)
		// 区间加
		{
			int k;
			cin>>k;
			add(l, r, k, 1, n, 1);
		}
		if(typ == 2)
		// 区间查询
		{
			cout<<ask(l, r, 1, n, 1)<<endl;
		}
	}
}