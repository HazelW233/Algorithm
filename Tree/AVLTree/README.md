# AVL Tree
&emsp;&emsp;AVL(Adelson-Velskii and Landis)树是一种带有平衡条件的二叉查找树。由于二叉查找树查找最坏的时间复杂度可能是O(n)，构造AVL树可以使其查找的最坏的时间复杂度变为O(log n)。<br>
&emsp;&emsp;AVL树平衡条件：每个node的lchild和rchild的高度最多相差1。

## 实现
&emsp;&emsp;AVL树的是通过在插入或删除节点后，找到那个最低的左右子树高度相差2的节点，通过旋转AVL树来，来达到左右子树高度相差小于等于1，这个过程通过*旋转*来实现。

## 旋转
&emsp;&emsp;旋转可以分为以下图片的四种情况，通过四个函数处理。
- AVLNode* singleRotateLeft(AVLNode* T);
- AVLNode* singleRotateRight(AVLNode* T);
- AVLNode* doubleRotateLeft(AVLNode* T);
- AVLNode* doubleRotateRight(AVLNode* T);

![single](single.png)
<br>
![double](double.png )
