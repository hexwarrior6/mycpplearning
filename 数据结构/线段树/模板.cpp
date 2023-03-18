#include<bits/stdc++.h>
#define maxn 100007  //元素总个数
#define ll long long
ll Sum[maxn<<2],Add[maxn<<2];//Sum求和，Add为懒惰标记 
ll A[maxn],n;//存原数组数据下标[1,n]

//上推区间统计值：自下向上更新区间统计值，根据两个子节点计算上级节点统计值 ，这里是求和
void PushUp(ll rt){
    Sum[rt]=Sum[rt<<1]+Sum[rt<<1|1];
}

//Build函数建树 
void Build(ll l,ll r,ll rt){ //l,r表示当前节点对应的原始序列区间，rt表示当前的树节点编号
	if(l==r) {//若到达叶节点 
		Sum[rt]=A[l];//储存数组值 
		return;
	}
	ll m=(l+r)>>1;
	//左右递归 
	Build(l,m,rt<<1);
	Build(m+1,r,rt<<1|1);
	//由两个子树上推区间统计值 
	PushUp(rt);
}

//点修改，一旦原始数组A建了树之后，就得在树里修改数据，所以要找到相应的叶节点。
void UpdateNode(ll L,ll C,ll l,ll r,ll rt)
{//L原始数据下标；C是要增加的值；l,r和rt是当前树节点信息，rt表示[l,r]区间所对应的树节点编号
	if(l==r){//到叶节点，修改 
		Sum[rt]+=C;
		return;
	}
	ll m=(l+r)>>1;
	//根据条件判断往左子树调用还是往右 
	if(L <= m) 
        UpdateNode(L,C,l,m,rt<<1);
	else       
        UpdateNode(L,C,m+1,r,rt<<1|1);
	//计算rt的统计值。L一定落在rt子树里，所以对rt有影响
	PushUp(rt);//子节点更新了，所以本节点也需要更新信息 
}

//下推懒惰标记：自上向下更新懒惰标记，由上级节点的懒惰标记，更新下级节点的统计值并添加懒惰标记
void PushDown(ll rt,ll ln,ll rn){
	//ln,rn为左子树，右子树的元素数量，要同步更新SUM，是Add的倍数。 
	if(Add[rt]){
		//下推标记 
		Add[rt<<1]+=Add[rt];
		Add[rt<<1|1]+=Add[rt];
      
		//修改子节点的Sum使之与对应的Add相对应 
		Sum[rt<<1]+=Add[rt]*ln;
		Sum[rt<<1|1]+=Add[rt]*rn;
      
		//清除本节点标记 
		Add[rt]=0;
	}
}

//区间修改
void UpdateSpan(ll L,ll R,ll C,ll l,ll r,ll rt)
{//L,R表示操作区间，l,r表示当前子树，rt表示[l,r]对应的树节点编号 
	if(L <= l && r <= R){//如果子树完全在操作区间[L,R]以内 
		Sum[rt]+=C*(r-l+1);//更新数字和，向上保持正确
		Add[rt]+=C;//增加Add标记，表示本区间的Sum正确，子区间的Sum仍需要根据Add的值来调整
		return ; 
	}
	ll m=(l+r)>>1;
    
    //子树区间[l,r]与操作区间[L,R]有交叉，则需与下推懒惰标记
  	//仅修改下一级rt<<1和rt<<1|1，清除rt
	PushDown(rt,m-l+1,r-m);
    
	//这里判断左右子树跟[L,R]有无交集，有交集才递归 
	if(L <= m) 
        UpdateSpan(L,R,C,l,m,rt<<1);
	if(R > m) 
        UpdateSpan(L,R,C,m+1,r,rt<<1|1); 
	PushUp(rt);//更新本节点信息，下级变化一定要更新上级节点，反之不亦然（懒惰标记）
}

//区间查询
ll Query(ll L,ll R,ll l,ll r,ll rt)
{//L,R表示要查询的区间，l,r表示当前节点区间，rt表示[l,r]对应的树节点编号
	if(L <= l && r <= R){
		//在区间内，直接返回 
		return Sum[rt];
	}
	ll m=(l+r)>>1;
  
	//下推标记，否则Sum可能不正确
	PushDown(rt,m-l+1,r-m); 
	
	//累计答案
	ll ANS=0;
	if(L <= m) 
        ANS+=Query(L,R,l,m,rt<<1);
	if(R >  m) 
        ANS+=Query(L,R,m+1,r,rt<<1|1);
	return ANS;
}


//建树 
Build(1,n,1); 
//点修改
UpdateNode(L,C,1,n,1);
//区间修改 
UpdateSpan(L,R,C,1,n,1);
//区间查询 
ll ANS=Query(L,R,1,n,1);
