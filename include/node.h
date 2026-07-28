#ifndef __NODE_H__
#define __NODE_H__

#include <unordered_set>
#include <memory>

namespace cppgrad
{
	/**
	 * @class node
	 * @brief Represents a graph node.
	 * A graph node contains references to its children and parent.
	 */
	template <typename ValueT>
	class node
	{
	public:

		/**
		 * @brief Constructor with parent node.
		 * @param parent Reference to parent node.
		 */
		node(const std::unique_ptr<node>& parent) noexcept;

		/**
		 * @brief Add a child node.
		 * @param new_child Reference to child node to add.
		 */
		void add_child(std::unique_ptr<node> new_child) noexcept;

		/**
		 * @brief Node children getter.
		 * @return Reference to set of children references.
		 */
		std::unordered_set<std::unique_ptr<node>>& get_children(void) noexcept;

		/**
		 * @brief Parent node getter.
		 * @return Reference to parent node.
		 */
		const std::unique_ptr<node>& get_parent(void) const noexcept;

	private:

		/// Reference to parent node.
		const std::unique_ptr<node>& parent_;

		/// Set of children nodes.
		std::unordered_set<std::unique_ptr<node>> children_ = {};

		/// Node internal value.
		ValueT value_;
	};
}

#endif // __NODE_H__
