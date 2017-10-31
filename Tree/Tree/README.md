# Tree

## 树的存储结构
1. 树的parent表示法。这种存储结构利用了每个节点（除根以外）都有一个parent。parent(T, x)可以在常量时间内完成；寻找root可以通过反复调用parent，但是求node的child需要遍历整个结构。
2. 树的child表示法。便于实现child操作，但是实现parent操作需要遍历整个结构。
3. 孩子兄弟表示法。便于实现child操作，只要再加一个parent域，便可以实现parent操作。
