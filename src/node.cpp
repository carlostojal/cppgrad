#include "node.h"

using namespace cppgrad;

node::node(const std::unique_ptr<node>& parent) noexcept : parent_(parent)
{

}

void node::add_child(std::unique_ptr<node> new_child) noexcept
{
	this->children_.insert(std::move(new_child));
}

std::unordered_set<std::unique_ptr<node>>& node::get_children(void) noexcept
{
	return this->children_;
}

const std::unique_ptr<node>& node::get_parent(void) const noexcept
{
	return this->parent_;
}
