Huffman Coding
====
Huffman编码是一种可变长的前缀编码，于1992年由Huffman提出。其根据字符出现的频率来提供对字符的唯一编码，同时保证了可变编码的平均编码最短，又称为最佳编码。<br>

原理
----
Huffman编码的构建需要借助于Huffman树。<br>
Huffman树是一种二叉树。从二叉树的根节点走起，走到一个叶子节点，用一个字符串temp表示这条路径，如果走的是该结点的lchild，则把temp加上'0',如果是rchild，则加上'1'，直到走到根结点。对于每一个叶子节点，都有一个temp。如果把每一个叶子节点加上一个属性'alpha'，表示这个结点代表的字符，即每一个字符的temp都不是另一个字符的temp的前缀，即temp可以作为叶子节点字符的编码，这种编码叫做前缀编码。<br>
如果在每个叶子节点上都加上一个属性'weight'，表示字符出现的次数/频率，使根节点到weight越大的叶子节点的路径越小，则出现频率越大的字符的编码最短，即保证了可变编码的平均编码最短。<br>

过程
----
    1、读入一个文件，统计文件中字符出现的频率，构成一个int类型的数组asc，作为weights。对于weight>0的字符(n个)生成n个Huffman节点，同时把这些节点按weight进行排序，按非递增顺序放入trees数组。
    2、根据这n个节点的weight构造Huffman树。从trees中选取两个weight最小的节点，构造一个新的节点，其weight为这两个结点之和，其lchild和rchild分别为这两个节点，同时把这两个节点的parent设为这个节点。把这两个节点从trees中删除，同时把新节点插入trees，排序。然后再从trees中选取两个weight最小的节点，重复上述操作，直到生成完n-1个新节点。trees[0]即为Huffman树的根节点。
    3、根据生成的Huffman树，得到各个字符的Huffman编码，放入codes数组。从根节点出发，递归到每一个根结点，到lchild则temp加上'0'，到rchild则temp加上'1'，到达根节点则把temp复制到相应的codes[i]。
    4、根据每个字符的Humman code，把文件转换成Huffman编码形式，写入新的文件。
    
解码
----
