/*
 * Group.h
 *
 *  Created on: May 24, 2012
 *      Author: sequoiahead
 */

#ifndef GROUP_H_
#define GROUP_H_

#include <list>
#include <string>
#include <algorithm>

namespace helmet {

template<typename Item>
class Group {
public:
	typedef std::list<Item> Container;
	typedef typename Container::const_iterator IteratorConst;

	explicit Group(const std::string& name);
	virtual ~Group();

	void add(const Item& item);
	void remove(const Item& item);
	bool contains(const Item& item) const;
	bool isEmpty() const;
	std::size_t size() const;

	IteratorConst begin() const;
	IteratorConst end() const;

	const std::string name;

protected:
	typedef typename Container::iterator Iterator;

	Iterator find(const Item& item);
	IteratorConst find(const Item& item) const;

private:
	Container container;
};

template<typename Item>
Group<Item>::Group(const std::string& name) :
		name(name), container() {
}

template<typename Item>
Group<Item>::~Group() {
}

template<typename Item>
void Group<Item>::add(const Item& item) {
	if (!contains(item)) {
		container.push_back(item);
	}
}

template<typename Item>
inline void Group<Item>::remove(const Item& item) {
	container.remove(item);
}

template<typename Item>
inline bool Group<Item>::contains(const Item& item) const {
	return std::find(begin(), end(), item) != end();
}

template<typename Item>
inline typename Group<Item>::IteratorConst Group<Item>::begin() const {
	return container.begin();
}

template<typename Item>
inline typename Group<Item>::IteratorConst Group<Item>::end() const {
	return container.end();
}

template<typename Item>
inline bool Group<Item>::isEmpty() const {
	return container.empty();
}

template<typename Item>
inline std::size_t Group<Item>::size() const {
	return container.size();
}

template<typename Item>
inline typename Group<Item>::Iterator Group<Item>::find(const Item& item) {
	return std::find(container.begin(), container.end(), item);
}

template<typename Item>
inline typename Group<Item>::IteratorConst Group<Item>::find(const Item& item) const {
	return std::find(begin(), end(), item);
}

}

#endif /* GROUP_H_ */
