#include<bits/stdc++.h>
using namespace std;
struct node // 区间节点
{
	int l, r; // ! 区间范围[l, r), 左闭右开
	// mutable: 强制变量可变, 即使在const函数中
	// 便于修改区间值
	mutable int k; // 区间值
	node(int L, int R = 0, int K = 0) : l(L), r(R), k(K) {}
	// 提前给R, K赋值, 使R, K在构造时可以不传入, 使用默认值
	// 构造函数, 在构造结构体时调用
	bool operator < (const node &x) const
	// 重载运算符: 
  // 返回值 operator 运算符 (const 数据类型 &参数名) const
  // {
  //   return 元素 运算符 参数;
  // }
  // 在这种方式下(使用时), 元素在运算符前, 参数在运算符后
	{
		return l < x.l;
	}
};
set<node> s;
auto split(int pos)
// 将原本包含点#pos的区间(设为[l, r))分裂为两个区间[l, pos - 1]和[pos, r), 
// 并返回指向后者的迭代器
{
	auto it = s.lower_bound((node)(pos) /* 调用构造函数构造node */ );
  // 返回首个l大于等于pos的元素的迭代器
	// 若没有找到, 返回end()("大于等于"在set源码中使用运算符<, 因此只需重载运算符<)
	// 这里用于找到点#pos**所在的区间的右边的区间** (需要再-1(见下5行))
	// ~~因此, 类型最好用auto(iterator记不住...)~~
	if (it != s.end() && it->l == pos)
	// "lower_bound()能找到区间#it"且"点#pos在区间#it的左端点"
		return it;
	--it; // 现在是点#pos的区间
	if (it->r < pos) // 若点#pos**不在**任何一个区间
		return s.end();
	int l = it->l, r = it->r, k = it->k;
	s.erase(it);
	s.insert((node){l, pos - 1, k} /* ! 这不是构造函数 */ );
	return s.insert((node){pos, r, k}).first;
	// insert()的返回值类型为pair<iterator, bool>, 
	// 其中iterator是一个指向所插入元素的迭代器, 
	// 而bool则代表元素是否插入成功
}
void upd(int l, int r, int k)
// 把[l, r)的所有区间权值更改为k, 
// 形成新区间
{
	auto R = split(r + 1), L = split(l);
	// ! **必须先分裂右区间再分裂左区间**
	// 在split()中, 点#pos在右端点时, 会修改区间; 在左端点时, 会直接返回. 
	// 而对于修改区间前的迭代器, 修改区间后便会失效, 
	// 所以必须先修改区间, 即先右后左. 
	s.erase(L, R); // 删除[L, R)中的所有区间
	s.insert((node){l, r, k}); // 插入新区间
}
int main()
{
  
}