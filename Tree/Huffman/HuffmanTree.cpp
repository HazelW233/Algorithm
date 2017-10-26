#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
using namespace std;

//一个Huffman树节点
struct HuffmanTree{
    char alpha;
    unsigned int weight;
    HuffmanTree *parent, *lchild, *rchild;
};


/*
交换一个HuffmanTree指针数组中的两个元素
参数：HuffmanTree数组，要交换的两个数组下标
函数执行后便是交换后的数组
*/
void swap(HuffmanTree* trees[], int l, int r){
    HuffmanTree* temp = trees[l];
    trees[l]=trees[r];
    trees[r]=temp;
}

void Sort(HuffmanTree* trees[], int left, int right){
    if(left<right){
        int e=trees[right]->weight;
        int l=left;
        int r=right;
        while(l<r){
            while(trees[l]->weight>=e&&l<r){
                l++;
            }
            while(trees[r]->weight<=e&&l<r){
                r--;
            }
            if(l<r){
                swap(trees,l,r);
            }
        }
        swap(trees,l,right);
        Sort(trees,left,l-1);
        Sort(trees,l+1,right);
    }
}

/*
对HuffmanTree数组进行排序
参数：哈夫曼数组，数组长度
函数执行完成后便是按非递增顺序排序好的HuffmanTree数组
*/
void Sort(HuffmanTree* trees[], int n){
    Sort(trees, 0, n-1);
}

/*
根据生成对Huffman tree，获得每个字符对Huffman码
参数：字符编码保存数组codes，Huffman树根节点，记录Huffman码长度对参素count，一个做辅助对字符串temp
*/
void enCode(char** codes, HuffmanTree* node, int count, char* temp){
    if(node->lchild!=NULL){
        temp[count]='0';
        enCode(codes, node->lchild, ++count, temp);
        count--;
    }
    if(node->rchild!=NULL){
        temp[count]='1';
        enCode(codes, node->rchild, ++count, temp);
        count--;
    }
    if(node->lchild==NULL && node->rchild==NULL){
        int a = (int)node->alpha;
        codes[a]=new char[count];
        strncpy(codes[a], temp, count);
    }
}

/*
根据记录字符出现次数，构建Huffman树，进行编码
参数:记录字符出现次数的asc码数组asc，记录每个acs字符编码后的Huffman码的数组code，对HuffmanTree**的引用
结果：函数执行后，codes中保存Huffman码，trees为生成对Huffaman Tree
*/
void HuffmanCode(int asc[], char** codes, HuffmanTree**& trees){
    int n=0;
    for(int i=0; i<256; i++){
        if(asc[i]>0){
            n++;
        }
    }
    int m=2*n-1;
    trees = new HuffmanTree*[m];
    for(int i=0; i<m; i++){
        trees[i] = new HuffmanTree;
    }
    int t=0;
    for(int i=0; i<256; i++){
        if(asc[i]>0){
            trees[t]->alpha=(char)i;
            trees[t]->weight=asc[i];
            t++;
        }
    }

    //0到n的Huffman树按weight非递增排列
    Sort(trees, n);
    //构建HuffmanTree
    //构建后tree数组第一个元素便是HuffmanTree根节点
    for(int i=1; i<=m-n; i++){
        int a=n-1+i;
        int b=n-1-i;
        trees[a]->weight=trees[b]->weight+trees[b+1]->weight;
        trees[a]->lchild=trees[b+1];
        trees[a]->rchild=trees[b];
        trees[b]->parent=trees[a];
        trees[b+1]->parent=trees[a];
        swap(trees, b,a);
        int e=trees[b]->weight;
        while(b>=1&&trees[b-1]->weight<e){
            swap(trees,b,b-1);
            b--;
        }
    }
    
    //求出Huffman Code
    int count = 0;
    char* temp = new char[n]; 
    //根据生成对Huffman Tree，获得字符编码
    enCode(codes, trees[0], count, temp);
}

/*
根据输入对文件名把文件进行Huffman编码，结果存储在“new_file.txt”文件中
参数：对一个空对HuffmanTree指针数组tree对引用
input：要进行编码对文件名(文件格式只能是ascii，english)
函数执行后，编码写入“new_file.txt”中，tree中保存了HuffmanTree，可根据其进行解码
*/
void toHuffmanCode(HuffmanTree**& tree){
    cout<<"Enter the file name which to be translated to HuffmanCode:"<<endl;
    string filename;
    cin>>filename;
    ifstream fin(filename.c_str());
    if(!fin){
        cout<<"No such file!\n";
        return;
    }

    ofstream fout("new_file.txt");
    int asc[256]={0};
    char ch;
    while(!fin.eof()){
        fin.get(ch);
        //得到asc码中各字符出现对次数
        asc[ch]++;
    }
    char *codes[256];
    //构建Huffman树，获得每个字符的Huffman码
    HuffmanCode(asc, codes, tree);
    //因为fin已经读到了文件末尾，eof设为1,必须clear，不然seekg没有用
    fin.clear();
    fin.seekg(0, fin.beg);
    while(fin.get(ch)){
        int a = ch;
        fout<<codes[a];
    }

    cout<<"Done! New file name is \"new_file.txt\""<<endl;
    fin.close();
    fout.close();
}

/*
根据HuffmanTree*数组对“new_file.txt”进行解码
参数：HuffmanTree*数组tree
函数执行后解码完成，解码后对结果放在“decoded_file.txt”中
*/
void decoding(HuffmanTree** tree){
    if(!tree){
        std::cout<<"ss";
        return;
    }
    HuffmanTree* node = tree[0];
    char filename[] = "new_file.txt";
    ifstream fin(filename);
    if(!fin){
        return;
    }
    ofstream fout("decoded_file.txt");
    char ch;
    while(fin.get(ch)){
        if(ch=='0'){
            if(node->lchild!=NULL){
                node=node->lchild;
            }else{
                fout<<node->alpha;
                if(tree[0]->lchild!=NULL){
                    node=tree[0]->lchild;
                }
            }
        }else if(ch=='1'){
            if(node->rchild!=NULL){
                node=node->rchild;
            }else{
                fout<<node->alpha;
                if(tree[0]->rchild){
                    node=tree[0]->rchild;
                }
            }
        }
    }

    std::cout<<"Done! The decoded file is \"decoded_file\""<<std::endl;

    fin.close();
    fout.close();
    delete node;
}

int main(){
    HuffmanTree** tree;
    //编码，进行编码文件格式必须是ascii码，english
    toHuffmanCode(tree);
    //解码
    decoding(tree);
}
