#include <bits/stdc++.h>

const int maxn =  5*1e4+5;
const int INF = 0x3f3f3f3f;
int c[maxn];

//求低位1
int lowbit(int x){
    return x&(-x);
}

//求[1,x]的区间和，如果想求区间[x1,x2]，可以用差分思维，即[1,x2]-[1,x1]
int getsum(int x){
    int ans = 0;
    for(int i=x;i;i-=lowbit(i))//寻找相邻的左侧子树
        ans += c[i];
    return ans;
}

//下标x处的数据加y，n为原始数组长度
void update(int x,int y,int n){
    //x为首个要更新的叶节点（奇数下标）或分支节点（偶数下标，其下方节点不在树中记录）
    for(int i=x;i<=n;i+=lowbit(i))//不断向树状数组的上级迭代
        c[i] += y;
}
