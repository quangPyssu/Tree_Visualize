#include "SceneNode.h"

SceneNode::SceneNode()
{
    this->Parent = nullptr;
}

void SceneNode::attachChild(Ptr child) 
{
    child->Parent = this;
    Children.emplace_back(std::move(child));
}

SceneNode::Ptr SceneNode::detachChild(const SceneNode& node)
{
    auto found = find_if(Children.begin(), Children.end(),[&](Ptr& p) -> bool { return p.get() == &node; });
    //assert(found != Children.end());
    Ptr result = std::move(*found);
    result->Parent = nullptr;
    Children.erase(found);
    //ChildrenType.erase()
    return result;
}

void SceneNode::draw(RenderTarget& target, RenderStates states) const 
{
    states.transform *= getTransform();

    drawCurrent(target, states);

    for (const auto& child : Children) 
        if (child) child->draw(target, states);
}

void SceneNode::update(Event& event,Vector2f& MousePos) 
{
    updateCurrent(event,MousePos);
    for (const auto& child : Children) child->update(event,MousePos);
}

void SceneNode::takeTime(Time dt)
{

}