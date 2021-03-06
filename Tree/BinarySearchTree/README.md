# 二叉查找树(Binary Search Tree)
&emsp;&emsp;二叉查找树是一种二叉树，对于其每一个parent节点来说，其lchild的元素小于他，其rchild的元素大于它。<br>
&emsp;&emsp;二叉查找树便于查找元素，其查找一个节点的平均时间复杂度为 O(log n)，二叉查找树种不能有相同元素。

## void travel();
&emsp;&emsp;对于二叉查找树来说，一个节点lchild元素小于它，rchild元素大于它，因此中序便利二叉查找树，得到的结果是由小到大排列。

## void remove(ElementType e);
&emsp;&emsp;在二叉查找树中删除给定的节点p有三种情况。
1. p没有lchild和rchild。把p的父节点指向p的这一边指为NULL，删除p节点。
2. p有一个孩子。把p的父节点指向p的这一边指向p的孩子，删除p节点。
3. p有lchild和rchild。
对于第三种情况，有多种处理方法：
- 找到p的右子树的最小节点node，把p的元素改为这个最小节点的元素，然后删除这个最小节点。由于node是p右子树的最小节点，node没有左节点，满足地二种情况，可以按第二种条件进行操作。
- 找到p的左子树的最大节点node，把p的元素改为这个最大节点的元素，然后删除这个最大节点。由于node是p左子树的最大节点，node没有右节点，满足地二种情况，可以按第二种条件进行操作。
