int fa[MAXN];
void init(int n){
    for (int i = 1; i <= n; ++i)
        fa[i] = i;//下标为元素标记，值为父节点
}

int find(int x){
    if(fa[x] == x)//树根的值等于下标
        return x;
    return find(fa[x]);
}

void merge(int i, int j){//i,j可以不是根节点
    fa[find(i)] = find(j);//使i所在的树的根成为j所在树的根的子节点。
}
