#include "node.h"

using namespace cppgrad;

template <typename ValueT>
node<ValueT>::node(const std::unique_ptr<node>& parent) noexcept : parent_(parent)
{

}

template <typename ValueT>
void node<ValueT>::add_child(std::unique_ptr<node> new_child) noexcept
{
	this->children_.insert(std::move(new_child));
}

template <typename ValueT>
std::unordered_set<std::unique_ptr<node<ValueT>>>& node<ValueT>::get_children(void) noexcept
{
	return this->children_;
}

template <typename ValueT>
const std::unique_ptr<node<ValueT>>& node<ValueT>::get_parent(void) const noexcept
{
	return this->parent_;
}
