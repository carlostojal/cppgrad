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
		void add_child(const std::unique_ptr<node>& new_child) noexcept;

		/**
		 * @brief Set the parent node.
		 * @param parent Reference to parent node.
		 */
		void set_parent(const std::unique_ptr<node>& parent) noexcept;

	private:

		/// Reference to parent node.
		const std::unique_ptr<node>& parent;

		/// Set of references to children nodes.
		std::unordered_set<const std::unique_ptr<node>&> children = {};
	};
}

#endif // __NODE_H__
