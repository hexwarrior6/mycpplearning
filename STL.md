# STL

## STL容器

>**序列容器**  
>序列容器维护你指定的插入元素的顺序。  
>
>1. `vector` 容器的行为类似于数组，但可以根据要求自动增长。 它可以随机访问、连续存储，长度也非常灵活。 基于上述和其他原因，`vector` 是多数应用程序的首选序列容器。 若不确定要使用哪种序列容器，请首先使用矢量！ 有关详细信息，请参阅 [`vector` 类](https://learn.microsoft.com/zh-cn/cpp/standard-library/vector-class?view=msvc-170)。  
>2. `array` 容器具备 `vector` 的某些优点，但长度不够灵活。 有关详细信息，请参阅 [`array` 类](https://learn.microsoft.com/zh-cn/cpp/standard-library/array-class-stl?view=msvc-170)。  
>3. `deque`（双端队列）容器支持在容器的起点和终点进行快速插入和删除。 它享有 `vector` 随机访问和长度灵活的优点，但是不具备连续性。 有关详细信息，请参阅 [`deque` 类](https://learn.microsoft.com/zh-cn/cpp/standard-library/deque-class?view=msvc-170)。  
>4. `list` 容器是双向链接列表，在容器内的任意位置启用了双向访问、快速插入和快速删除，但你不能随机访问此容器中的元素。 有关详细信息，请参阅 [`list` 类](https://learn.microsoft.com/zh-cn/cpp/standard-library/list-class?view=msvc-170)。  
>5. `forward_list` 容器是单独链表，`list` 的向前访问版本。 有关详细信息，请参阅 [`forward_list` 类](https://learn.microsoft.com/zh-cn/cpp/standard-library/forward-list-class?view=msvc-170)。

>**关联容器**  序列容器维护你指定的插入元素的顺序。  
>
>1. `map`，有时称为字典，包含键/值对。 键用于对序列排序，值与该键关联。 例如，`map`可能包含许多键（代表文本中每个独特的单词）和相应的值（代表每个单词在文本中出现的次数）。 `map`的无序版本是 `unordered_map`。 有关详细信息，请参阅 [`map` 类](https://learn.microsoft.com/zh-cn/cpp/standard-library/map-class?view=msvc-170)和 [`unordered_map` 类](https://learn.microsoft.com/zh-cn/cpp/standard-library/unordered-map-class?view=msvc-170)。  
>2. `set`仅是按升序排列每个元素的容器，值也是键。 `set`的无序版本是 `unordered_set`。 有关详细信息，请参阅 [`set` 类](https://learn.microsoft.com/zh-cn/cpp/standard-library/set-class?view=msvc-170)和 [`unordered_set` 类](https://learn.microsoft.com/zh-cn/cpp/standard-library/unordered-set-class?view=msvc-170)。   
>3. `map` 和 `set` 都仅允许将键或元素的一个实例插入容器中。 如果需要元素的多个实例，请使用`multimap`或`multiset`。 无序版本是 `unordered_multimap` 和 `unordered_multiset`。 有关详细信息，请参阅 [`multimap` 类](https://learn.microsoft.com/zh-cn/cpp/standard-library/multimap-class?view=msvc-170)、[`unordered_multimap` 类](https://learn.microsoft.com/zh-cn/cpp/standard-library/unordered-multimap-class?view=msvc-170)、[`multiset` 类](https://learn.microsoft.com/zh-cn/cpp/standard-library/multiset-class?view=msvc-170) 和 [`unordered_multiset` 类](https://learn.microsoft.com/zh-cn/cpp/standard-library/unordered-multiset-class?view=msvc-170)。

> 有序的映射和组集支持双向迭代器，其未排序副本支持向前迭代器。 有关更多信息，请参见 [迭代器](https://learn.microsoft.com/zh-cn/cpp/standard-library/iterators?view=msvc-170)。   
> [C++ 标准库容器 | Microsoft Learn](https://learn.microsoft.com/zh-cn/cpp/standard-library/stl-containers?view=msvc-170)

```cpp
共有函数
=：有赋值运算符以及复制构造函数。
begin()：返回指向开头元素的迭代器。
end()：返回指向末尾的下一个元素的迭代器。end() 不指向某个元素，但它是末尾元素的后继。
size()：返回容器内的元素个数。
max_size()：返回容器 理论上 能存储的最大元素个数。依容器类型和所存储变量的类型而变。
empty()：返回容器是否为空。
swap()：交换两个容器。
clear()：清空容器。
==/!=/</>/<=/>=：按 字典序 比较两个容器的大小。（比较元素大小时 map 的每个元素相当于 set<pair<key, value> >，无序容器不支持 </>/<=/>=。）
```

### vector

#### 函数

| 名称                                                         | 说明                                         | list           | deque          |
| ------------------------------------------------------------ | -------------------------------------------- | -------------- | -------------- |
| [`push_back`](https://learn.microsoft.com/zh-cn/cpp/standard-library/vector-class?view=msvc-170#push_back) | 在矢量末尾处添加一个元素。                   | 有`push_front` | 有`push_front` |
| [`pop_back`](https://learn.microsoft.com/zh-cn/cpp/standard-library/vector-class?view=msvc-170#pop_back) | 删除矢量末尾处的元素。                       | 有`pop_front`  | 有`pop_front`  |
| [`insert`](https://learn.microsoft.com/zh-cn/cpp/standard-library/vector-class?view=msvc-170#insert) | 将一个元素或多个元素插入到指定位置的向量中。 | X              |                |
| [`at`](https://learn.microsoft.com/zh-cn/cpp/standard-library/vector-class?view=msvc-170#at) | 返回对矢量中指定位置的元素的引用。           | X              |                |
| [`begin`](https://learn.microsoft.com/zh-cn/cpp/standard-library/vector-class?view=msvc-170#begin) | 对该向量中第一个元素返回随机访问迭代器。     |                |                |
| [`end`](https://learn.microsoft.com/zh-cn/cpp/standard-library/vector-class?view=msvc-170#end) | 返回指向矢量末尾的随机访问迭代器。           |                |                |
| [`front`](https://learn.microsoft.com/zh-cn/cpp/standard-library/vector-class?view=msvc-170#front) | 返回对向量中第一个元素的引用。               |                |                |
| [`back`](https://learn.microsoft.com/zh-cn/cpp/standard-library/vector-class?view=msvc-170#back) | 返回对向量中最后一个元素的引用。             |                |                |
| [`erase`](https://learn.microsoft.com/zh-cn/cpp/standard-library/vector-class?view=msvc-170#erase) | 从指定位置删除向量中的一个元素或一系列元素。 |                |                |
| [`clear`](https://learn.microsoft.com/zh-cn/cpp/standard-library/vector-class?view=msvc-170#clear) | 清除向量的元素。                             |                |                |
| [`empty`](https://learn.microsoft.com/zh-cn/cpp/standard-library/vector-class?view=msvc-170#empty) | 测试矢量容器是否为空。                       |                |                |
| [`swap`](https://learn.microsoft.com/zh-cn/cpp/standard-library/vector-class?view=msvc-170#swap) | 交换两个向量的元素。                         |                |                |
| [`resize`](https://learn.microsoft.com/zh-cn/cpp/standard-library/vector-class?view=msvc-170#resize) | 为矢量指定新的大小。                         | X              |                |
| [`size`](https://learn.microsoft.com/zh-cn/cpp/standard-library/vector-class?view=msvc-170#size) | 返回向量中的元素数量。                       |                |                |

#### 运算符

| 名称                                                         | 说明list                               | list | deque |
| ------------------------------------------------------------ | -------------------------------------- | ---- | ----- |
| [`operator[]`](https://learn.microsoft.com/zh-cn/cpp/standard-library/vector-class?view=msvc-170#op_at) | 返回对指定位置的矢量元素的引用。       | X    | Y     |
| [`operator=`](https://learn.microsoft.com/zh-cn/cpp/standard-library/vector-class?view=msvc-170#op_eq) | 用另一个向量的副本替换该向量中的元素。 | Y    | Y     |

### list（双向链表）

#### 函数

> 均为list特有

| 名称                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [`unique`](https://learn.microsoft.com/zh-cn/cpp/standard-library/list-class?view=msvc-170#unique) | 从列表中删除满足某些其他二元谓词的相邻重复元素或相邻元素。   |
| [`reverse`](https://learn.microsoft.com/zh-cn/cpp/standard-library/list-class?view=msvc-170#reverse) | 反转列表中元素的顺序。                                       |
| [`merge`](https://learn.microsoft.com/zh-cn/cpp/standard-library/list-class?view=msvc-170#merge) | 将元素从参数列表移除，将它们插入目标列表，将新的组合元素集以升序或其他指定顺序排序。 |
| [`remove`](https://learn.microsoft.com/zh-cn/cpp/standard-library/list-class?view=msvc-170#remove) | 清除列表中与指定值匹配的元素。                               |
| [`remove_if`](https://learn.microsoft.com/zh-cn/cpp/standard-library/list-class?view=msvc-170#remove_if) | 将满足指定谓词的元素从列表中消除。                           |
| [`sort`](https://learn.microsoft.com/zh-cn/cpp/standard-library/list-class?view=msvc-170#sort) | 按升序或其他顺序关系排列列表中的元素。                       |
| [`swap`](https://learn.microsoft.com/zh-cn/cpp/standard-library/list-class?view=msvc-170#swap) | 交换两个列表的元素。                                         |

[1]: 

### deque（双端队列）

> 与vector相近

### map(字典)



## STL算法

> 关于devcpp调试STL的问题：
> 添加查看`*&a[0]@5`：我们看到了整个数组    *这种方法只适用于连续空间的容器*
> ![图片](https://github.com/hexwarrior6/mycpplearning/assets/79214709/78abd0d9-6249-4502-ac86-53ffb306f34f)
> [今天才学会的DevC++调试器查看连续内存STL容器内值的方法（DevC++）](https://www.cnblogs.com/flashhu/p/15727005.html)
