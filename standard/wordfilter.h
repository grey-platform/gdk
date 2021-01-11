#ifndef __WORDFILTER_H__
#define __WORDFILTER_H__

#include <vector>

//dfa�Ķ����
#define DFA_TREE_NODE_LEN (256)
/**
* ���ڵ�
* ÿ���ڵ����һ������Ϊ256������
*/
struct TreeNode{
    bool end;//�ؼ��ʵ��ս�
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
    //���ڵ�
    TreeNode* rootNode;
    //�ؼ��ʻ���
    std::string keywordBuffer;
};


#endif

