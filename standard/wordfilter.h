#ifndef __WORDFILTER_H__
#define __WORDFILTER_H__

#include <vector>

//dfa的多叉树
#define DFA_TREE_NODE_LEN (256)
/**
* 树节点
* 每个节点包含一个长度为256的数组
*/
struct TreeNode{
    bool end;//关键词的终结
    std::vector<TreeNode*> subNodes;
    TreeNode(){
        end = false;
    }
    ~TreeNode(){
        for( int i = 0; i < subNodes.size(); ++i ){
            delete subNodes[i];
        }
        subNodes.clear();
    }
    bool setSubNode( int index, TreeNode* node ){
        if( subNodes.empty() ){
            subNodes.resize( DFA_TREE_NODE_LEN, NULL );
        }
        if( index >= subNodes.size() ){
            return false;
        }
        subNodes[index] = node;
        return true;
    }
    bool getSubNode( int index, TreeNode*& node )const{
        if( index >= subNodes.size() ){
            return false;
        }
        if( !subNodes[index] ){
            return false;
        }
        node = subNodes[index];
        return true;
    }
    bool isKeywordEnd()const{
        return end;
    }
    void setKeywordEnd( bool end = true ){
        this->end = end;
    }
};




class DFA{
public:
    DFA();
    ~DFA();
    bool createKeywordTree( const std::vector<std::string> &keywordList );
    bool searchKeyword( const std::string& tofilter, std::vector<std::string>& words );
    bool searchKeyword( const std::string& tofilter, std::string& filtered );
private:
    void change( std::string& filtered, int index, int size, char letter = '*' );
    //根节点
    TreeNode* rootNode;
    //关键词缓存
    std::string keywordBuffer;
};


#endif

