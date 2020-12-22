#include "graphedge.h"
#include "graphnode.h"

#include <iostream>

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE (modified)
    ////
    // for(auto &element : _childEdges){
    //     element.reset();
    // }

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddParentEdge(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddChildEdge(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatbotIn)
{
    chatBot = std::move(chatbotIn);
    //chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(std::move(chatBot));
    //_chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE (modified)
    ////

    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}