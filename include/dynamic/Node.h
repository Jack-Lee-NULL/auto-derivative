/**
 * 
 * @author Jingquan Lee
 * @email m13152143642@163.com
 * 
 **/
#include <iostream>

#ifndef NODE_H
#define NODE_H


struct Node{
	public:
		Node()=default;
		~Node()=default;
		///
		// compute the value of formulation
		// @return the value
		///
		virtual auto forward() -> float = 0;

		///
		// compute the derivative of formulation with given inputs
		// @return the derivative
		///
		virtual auto derivative() -> float = 0;
		inline auto operator + (const Node&) const -> Node&;
		inline auto operator - (const Node&) const -> Node&;
		inline auto operator * (const Node&) const -> Node&;
		inline auto operator / (const Node&) const -> Node&;
	
	protected:
		Node** list;
		float forwardVal;
};

struct PlaceHolderNode: Node{
	public:
		virtual auto forward() -> float override;
		virtual auto derivative() -> float override;
		auto set_init(float) -> int;
};

struct AddNode: Node{
	public:
		AddNode()=default;
		AddNode(const Node&, const Node&);
		~AddNode();
		virtual auto forward() -> float override;
		virtual auto derivative() -> float override;
};

struct MinorNode: Node{
	public:
		MinorNode()=default;
		MinorNode(const Node&, const Node&);
		~MinorNode();
		virtual auto forward() -> float override;
		virtual auto derivative() -> float override;
};

struct MultiplyNode: Node{
	public:
		MultiplyNode()=default;
		MultiplyNode(const Node&, const Node&);
		~MultiplyNode();
		virtual auto forward() -> float override;
		virtual auto derivative() -> float override;
};

struct DivideNode: Node{
	public:
		DivideNode()=default;
		DivideNode(const Node&, const Node&);
		~DivideNode();
		virtual auto forward() -> float override;
		virtual auto derivative() -> float override;
};

struct LnNode: Node{
	public:
		LnNode()=default;
		LnNode(const Node&);
		~LnNode();
		virtual auto forward() -> float override;
		virtual auto derivative() -> float override;
};

struct SinNode: Node{
	public:
		SinNode()=default;
		SinNode(const Node&);
		~SinNode();
		virtual auto forward() -> float override;
		virtual auto derivative() -> float override;
};

struct ExperNode: Node{
	public:
		ExperNode()=default;
		ExperNode(const Node&);
		~ExperNode();
		virtual auto forward() -> float override;
		virtual auto derivative() -> float override;
};

inline auto Node::operator + (const Node& n) const -> Node&{
			Node* a = (Node*) new AddNode(*this, n);
			return *a;
}

inline auto Node::operator - (const Node& n) const -> Node&{
			Node* a = (Node*) new MinorNode(*this, n);
			return *a;
}

inline auto Node::operator * (const Node& n) const -> Node&{
			Node* a = (Node*) new MultiplyNode(*this, n);
			return *a;
}

inline auto Node::operator / (const Node& n) const -> Node&{
		Node* a = (Node*) new DivideNode(*this, n);
		return *a;
}
#endif
