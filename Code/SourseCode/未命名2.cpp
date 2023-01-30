#include<bits/stdc++.h>
#include<vector>
#include<utility>
using namespace std;
void TRCT(int node, vector<vector<int> > Map, vector<int>& S, vector<int>& W)
{
	//S[node]: ��[node]Ϊ���������Ľڵ���
	//W[node]: [node]���������
	int n = Map[0].size() - 1;//n: �ܽڵ��� 
	S[node] = 1;//����[node]�Լ� 
	W[node] = 0;
	for(int child = 1; child <= n; child++)
		if(Map[node][child] != -1)//[child]��[node]�ĺ��� 
		{
			TrCt(child, Map, S, W);//����[child]����������ͽڵ��� 
			S[node] += S[child];
			W[node] = max(W[node], S[child]);
		}
	W[node] = max(W[node], n - S[node]);//[n] - [S[node]]�ǡ����ϡ������� 
	return;
}
pair<int, int> TrCt(int node, vector<vector<int> > Map)
{
	//Warning��ALL NODEs START FROM 1 but not 0!
	//node: Root of the tree or The node that you want to start with
	//Map: A Map of the tree and -1 means it isn't conneted
	int n =  Map[0].size() - 1;
	vector<int> S(n);
	vector<int> W(n);
	pair<int, int> ans;
	TRCT(node, Map, S, W);
	ans.first = 0xffffff, ans.second;
	for(int i = 1; i <= n; i++)//���ݶ��������� 
		if(W[i] < ans.first)ans.first = W[i], ans.second = i;
	return ans;
}
int main()
{
	int n;
	cin>>n;
	vector<vector<int> > Map(n + 1, vector<int>(n + 1, -1));
	for(int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin>>a>>b;
		Map[a][b] = 1;
	}
	pair<int, int> temp = TrCt(1, Map);
	cout<<"The ans is: "<<temp.first<<endl<<"The ord of center is: "<<temp.second;
}

/* Sample
//**Start From 1** 
InPut: 
9
1 2
1 3
2 4
2 5
3 6
4 7
3 8
6 9
OutPut: 
4 1
*/
